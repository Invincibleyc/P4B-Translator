
#include <core.p4>
#include <v1model.p4>


header ethernet_t {
    bit<48> dstAddr;
    bit<48> srcAddr;
    bit<16> ethertype;
    bit<8>  e;
}

header trap_t {
    bit<8> trap;
}

struct metadata {
    bool trap;
}

struct headers {
    ethernet_t ethernet;
    trap_t trap;
}

parser ParserImpl(packet_in packet, out headers hdr, inout metadata meta, inout standard_metadata_t standard_metadata) {
    @name(".start") state start {
        packet.extract(hdr.ethernet);
        transition accept;
    }
}

control egress(inout headers hdr, inout metadata meta, inout standard_metadata_t standard_metadata) {
    apply {
    }
}

control ingress(inout headers hdr, inout metadata meta, inout standard_metadata_t standard_metadata) {
    action a() { standard_metadata.egress_spec = 0; }
    action a_with_control_params(bit<9> x) { 
        standard_metadata.egress_spec = x;
        if(hdr.ethernet.e == 0x01 && x == 1) meta.trap = true;
        else meta.trap = false;
    }

    table t_exact {
        key = {
            hdr.ethernet.e : exact;
        }

        actions = {
            a;
            a_with_control_params;
        }

        default_action = a;

        const entries = {
            0x01 : a_with_control_params(1);
            0x02 : a_with_control_params(2);
        }
    }

    apply {
        hdr.ethernet.e = 0x01;
        t_exact.apply();
        if(meta.trap)
            hdr.trap.trap = hdr.trap.trap + 1;
    }
}

control DeparserImpl(packet_out packet, in headers hdr) {
    apply {
        packet.emit(hdr.ethernet);
    }
}

control verifyChecksum(inout headers hdr, inout metadata meta) {
    apply {
    }
}

control computeChecksum(inout headers hdr, inout metadata meta) {
    apply {
    }
}

V1Switch(ParserImpl(), verifyChecksum(), ingress(), egress(), computeChecksum(), DeparserImpl()) main;
