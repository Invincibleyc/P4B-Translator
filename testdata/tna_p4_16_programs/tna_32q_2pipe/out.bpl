type Ref;
type error=int;
type HeaderStack = [int]Ref;
var last:[HeaderStack]Ref;
var forward:bool;
var isValid:[Ref]bool;
var emit:[Ref]bool;
var stack.index:[HeaderStack]int;
var size:[HeaderStack]int;
var drop:bool;
type PortId_t = int;
type MulticastGroupId_t = int;
type QueueId_t = int;
type MirrorType_t = int;
type MirrorId_t = int;
type ResubmitType_t = int;
type DigestType_t = int;
type L1ExclusionId_t = int;
type L2ExclusionId_t = int;

// Struct ingress_intrinsic_metadata_for_tm_t

// Struct ingress_intrinsic_metadata_from_parser_t

// Struct ingress_intrinsic_metadata_for_deparser_t

// Struct egress_intrinsic_metadata_from_parser_t

// Struct egress_intrinsic_metadata_for_deparser_t

// Struct egress_intrinsic_metadata_for_output_port_t
type mac_addr_t = int;
type ipv4_addr_t = int;

// Struct custom_header_t

// Struct digest_t
type pkt_color_t = int;

// Struct qos_metadata_a_t
type meter_index_t = int;

// Struct port_md_a_t

// Struct metadata_a_t
var qos_md_0:qos_metadata_a_t;
var tmp:int;
function {:inline true} add.bv8(left:int, right:int) : int{((left%power_2_8())+(right%power_2_8()))%power_2_8()}

// Table forward_0 Actionlist Declaration
type forward_0.action;
const unique forward_0.action.hit : forward_0.action;
const unique forward_0.action.miss : forward_0.action;
var forward_0.action_run : forward_0.action;
var forward_0.hit : bool;

// Table encap_custom_metadata_hdr_0 Actionlist Declaration
type encap_custom_metadata_hdr_0.action;
var encap_custom_metadata_hdr_0.encap_custom_metadata.tag:int;
const unique encap_custom_metadata_hdr_0.action.encap_custom_metadata : encap_custom_metadata_hdr_0.action;
const unique encap_custom_metadata_hdr_0.action.NoAction_0 : encap_custom_metadata_hdr_0.action;
var encap_custom_metadata_hdr_0.action_run : encap_custom_metadata_hdr_0.action;
var encap_custom_metadata_hdr_0.hit : bool;

// Table pinning_0 Actionlist Declaration
type pinning_0.action;
var pinning_0.modify_eg_port.port:PortId_t;
const unique pinning_0.action.NoAction_1 : pinning_0.action;
const unique pinning_0.action.modify_eg_port : pinning_0.action;
var pinning_0.action_run : pinning_0.action;
var pinning_0.hit : bool;

// Table storm_control_0 Actionlist Declaration
type storm_control_0.action;
var storm_control_0.set_color.index:meter_index_t;
const unique storm_control_0.action.NoAction_7 : storm_control_0.action;
const unique storm_control_0.action.set_color : storm_control_0.action;
var storm_control_0.action_run : storm_control_0.action;
var storm_control_0.hit : bool;

// Table stats_0 Actionlist Declaration
type stats_0.action;
const unique stats_0.action.NoAction_8 : stats_0.action;
const unique stats_0.action.count_1 : stats_0.action;
var stats_0.action_run : stats_0.action;
var stats_0.hit : bool;
function {:inline true} add.bv16(left:int, right:int) : int{((left%power_2_16())+(right%power_2_16()))%power_2_16()}

// Table forward_1 Actionlist Declaration
type forward_1.action;
const unique forward_1.action.hit_4 : forward_1.action;
const unique forward_1.action.miss_4 : forward_1.action;
var forward_1.action_run : forward_1.action;
var forward_1.hit : bool;

// Struct port_md_b_t

// Struct metadata_b_t

// Table forward_2 Actionlist Declaration
type forward_2.action;
const unique forward_2.action.hit_5 : forward_2.action;
const unique forward_2.action.miss_5 : forward_2.action;
var forward_2.action_run : forward_2.action;
var forward_2.hit : bool;

// Table learning_0 Actionlist Declaration
type learning_0.action;
const unique learning_0.action.dmac_hit : learning_0.action;
const unique learning_0.action.dmac_miss : learning_0.action;
var learning_0.action_run : learning_0.action;
var learning_0.hit : bool;

// Table pinning_1 Actionlist Declaration
type pinning_1.action;
var pinning_1.modify_eg_port_2.port:PortId_t;
const unique pinning_1.action.NoAction_9 : pinning_1.action;
const unique pinning_1.action.modify_eg_port_2 : pinning_1.action;
var pinning_1.action_run : pinning_1.action;
var pinning_1.hit : bool;

// Table forward_3 Actionlist Declaration
type forward_3.action;
const unique forward_3.action.hit_6 : forward_3.action;
const unique forward_3.action.miss_6 : forward_3.action;
var forward_3.action_run : forward_3.action;
var forward_3.hit : bool;
function {:inline true} power_2_0() : int{1}
function {:inline true} power_2_1() : int{2}
function {:inline true} power_2_2() : int{4}
function {:inline true} power_2_3() : int{8}
function {:inline true} power_2_4() : int{16}
function {:inline true} power_2_5() : int{32}
function {:inline true} power_2_6() : int{64}
function {:inline true} power_2_7() : int{128}
function {:inline true} power_2_8() : int{256}
function {:inline true} power_2_9() : int{512}
function {:inline true} power_2_10() : int{1024}
function {:inline true} power_2_11() : int{2048}
function {:inline true} power_2_12() : int{4096}
function {:inline true} power_2_13() : int{8192}
function {:inline true} power_2_14() : int{16384}
function {:inline true} power_2_15() : int{32768}
function {:inline true} power_2_16() : int{65536}
function {:inline true} power_2_17() : int{131072}
function {:inline true} power_2_18() : int{262144}
function {:inline true} power_2_19() : int{524288}
function {:inline true} power_2_20() : int{1048576}
function {:inline true} power_2_21() : int{2097152}
function {:inline true} power_2_22() : int{4194304}
function {:inline true} power_2_23() : int{8388608}
function {:inline true} power_2_24() : int{16777216}
function {:inline true} power_2_25() : int{33554432}
function {:inline true} power_2_26() : int{67108864}
function {:inline true} power_2_27() : int{134217728}
function {:inline true} power_2_28() : int{268435456}
function {:inline true} power_2_29() : int{536870912}
function {:inline true} power_2_30() : int{1073741824}
function {:inline true} power_2_31() : int{2147483648}
function {:inline true} power_2_32() : int{4294967296}
function {:inline true} power_2_33() : int{8589934592}
function {:inline true} power_2_34() : int{17179869184}
function {:inline true} power_2_35() : int{34359738368}
function {:inline true} power_2_36() : int{68719476736}
function {:inline true} power_2_37() : int{137438953472}
function {:inline true} power_2_38() : int{274877906944}
function {:inline true} power_2_39() : int{549755813888}
function {:inline true} power_2_40() : int{1099511627776}
function {:inline true} power_2_41() : int{2199023255552}
function {:inline true} power_2_42() : int{4398046511104}
function {:inline true} power_2_43() : int{8796093022208}
function {:inline true} power_2_44() : int{17592186044416}
function {:inline true} power_2_45() : int{35184372088832}
function {:inline true} power_2_46() : int{70368744177664}
function {:inline true} power_2_47() : int{140737488355328}
function {:inline true} power_2_48() : int{281474976710656}
function {:inline true} power_2_49() : int{562949953421312}
function {:inline true} power_2_50() : int{1125899906842624}
function {:inline true} band(left:int, right:int) : int{((left+right)-(left+right)%2)/2}
function {:inline true} bxor(left:int, right:int) : int{(left+right)%2}
function {:inline true} bor(left:int, right:int) : int{(left+right)%2+((left+right)-((left+right)%2))/2}
function {:inline true} bnot(num:int) : int{1-num%2}

// Action NoAction_0
procedure {:inline 1} NoAction_0()
{
}

// Action NoAction_1
procedure {:inline 1} NoAction_1()
{
}

// Action NoAction_7
procedure {:inline 1} NoAction_7()
{
}

// Action NoAction_8
procedure {:inline 1} NoAction_8()
{
}

// Action NoAction_9
procedure {:inline 1} NoAction_9()
{
}

// Control SwitchEgressDeparser_a
procedure {:inline 1} SwitchEgressDeparser_a()
{
    hdr.ipv4.hdr_checksum := ipv4_checksum_1.update();
    call pkt.emit(hdr.ethernet);
    call pkt.emit(hdr.ipv4);
}

// Control SwitchEgressDeparser_b
procedure {:inline 1} SwitchEgressDeparser_b()
{
    hdr.ipv4.hdr_checksum := ipv4_checksum_3.update();
    call pkt.emit(hdr.ethernet);
    call pkt.emit(hdr.ipv4);
    call pkt.emit(hdr.custom_metadata);
}

// Control SwitchEgress_a
procedure {:inline 1} SwitchEgress_a()
{
    call forward_1.apply();
}

// Control SwitchEgress_b
procedure {:inline 1} SwitchEgress_b()
{
    call forward_3.apply();
}

// Control SwitchIngressDeparser_a
procedure {:inline 1} SwitchIngressDeparser_a()
{
    hdr.ipv4.hdr_checksum := ipv4_checksum_0.update();
    call pkt.emit(hdr.ethernet);
    call pkt.emit(hdr.ipv4);
    call pkt.emit(hdr.custom_metadata);
}

// Control SwitchIngressDeparser_b
procedure {:inline 1} SwitchIngressDeparser_b()
{
    if((ig_dprsr_md.digest_type == 0)){
    }
    hdr.ipv4.hdr_checksum := ipv4_checksum_2.update();
    call pkt.emit(hdr.ethernet);
    call pkt.emit(hdr.ipv4);
    call pkt.emit(hdr.custom_metadata);
}

// Control SwitchIngress_a
procedure {:inline 1} SwitchIngress_a()
	modifies isValid, tmp;
{
    qos_md_0.color := 0;
    call storm_control_0.apply();
    call stats_0.apply();
    call forward_0.apply();
    call encap_custom_metadata_hdr_0.apply();
    call pinning_0.apply();
}

// Control SwitchIngress_b
procedure {:inline 1} SwitchIngress_b()
{
    call forward_2.apply();
    call learning_0.apply();
    call pinning_1.apply();
}
procedure ULTIMATE.start()
{
    call mainProcedure();
}

// Parser _parser_SwitchEgressParser_a
procedure {:inline 1} _parser_SwitchEgressParser_a()
	modifies drop;
{
    call start();
}

// Parser _parser_SwitchEgressParser_b
procedure {:inline 1} _parser_SwitchEgressParser_b()
	modifies drop;
{
    call start();
}

// Parser _parser_SwitchIngressParser_a
procedure {:inline 1} _parser_SwitchIngressParser_a()
	modifies drop;
{
    call start();
}

// Parser _parser_SwitchIngressParser_b
procedure {:inline 1} _parser_SwitchIngressParser_b()
	modifies drop;
{
    call start();
}
procedure {:inline 1} accept()
{
}

// Action count_1
procedure {:inline 1} count_1()
{
    // count
}

// Action dmac_hit
procedure {:inline 1} dmac_hit()
{
}

// Action dmac_miss
procedure {:inline 1} dmac_miss()
{
    ig_dprsr_md.digest_type := 0;
}

// Action encap_custom_metadata
procedure {:inline 1} encap_custom_metadata(tag:int)
	modifies isValid;
{
    call setValid(hdr.custom_metadata);
    hdr.custom_metadata.custom_tag := tag;
}

// Table encap_custom_metadata_hdr_0
procedure {:inline 1} encap_custom_metadata_hdr_0.apply()
	modifies isValid;
{
    if(encap_custom_metadata_hdr_0.action_run == encap_custom_metadata_hdr_0.action.encap_custom_metadata){
        call encap_custom_metadata(encap_custom_metadata_hdr_0.encap_custom_metadata.tag);
    }
    else if(encap_custom_metadata_hdr_0.action_run == encap_custom_metadata_hdr_0.action.NoAction_0){
        call NoAction_0();
    }
    else {
        call NoAction_0();
    }
}

// Table forward_0
procedure {:inline 1} forward_0.apply()
{
    if(forward_0.action_run == forward_0.action.hit){
        call hit();
    }
    else if(forward_0.action_run == forward_0.action.miss){
        call miss();
    }
    else {
        call miss();
    }
}

// Table forward_1
procedure {:inline 1} forward_1.apply()
{
    if(forward_1.action_run == forward_1.action.hit_4){
        call hit_4();
    }
    else if(forward_1.action_run == forward_1.action.miss_4){
        call miss_4();
    }
    else {
        call miss_4();
    }
}

// Table forward_2
procedure {:inline 1} forward_2.apply()
{
    if(forward_2.action_run == forward_2.action.hit_5){
        call hit_5();
    }
    else if(forward_2.action_run == forward_2.action.miss_5){
        call miss_5();
    }
    else {
        call miss_5();
    }
}

// Table forward_3
procedure {:inline 1} forward_3.apply()
{
    if(forward_3.action_run == forward_3.action.hit_6){
        call hit_6();
    }
    else if(forward_3.action_run == forward_3.action.miss_6){
        call miss_6();
    }
    else {
        call miss_6();
    }
}
procedure {:inline 1} havocProcedure()
	modifies drop, encap_custom_metadata_hdr_0.action_run, encap_custom_metadata_hdr_0.encap_custom_metadata.tag, forward, forward_0.action_run, forward_1.action_run, forward_2.action_run, forward_3.action_run, learning_0.action_run, pinning_0.action_run, pinning_0.modify_eg_port.port, pinning_1.action_run, pinning_1.modify_eg_port_2.port, stats_0.action_run, storm_control_0.action_run, storm_control_0.set_color.index;
{
    drop := false;
    forward := false;
    havoc forward_0.action_run;
    havoc encap_custom_metadata_hdr_0.encap_custom_metadata.tag;
    havoc encap_custom_metadata_hdr_0.action_run;
    havoc pinning_0.modify_eg_port.port;
    havoc pinning_0.action_run;
    havoc storm_control_0.set_color.index;
    havoc storm_control_0.action_run;
    havoc stats_0.action_run;
    havoc forward_1.action_run;
    havoc forward_2.action_run;
    havoc learning_0.action_run;
    havoc pinning_1.modify_eg_port_2.port;
    havoc pinning_1.action_run;
    havoc forward_3.action_run;
}

// Action hit
procedure {:inline 1} hit()
{
    hdr.ipv4.ttl := add.bv8(hdr.ipv4.ttl, 255);
}

// Action hit_4
procedure {:inline 1} hit_4()
{
    hdr.ipv4.ttl := add.bv8(hdr.ipv4.ttl, 255);
    hdr.custom_metadata.custom_tag := add.bv16(hdr.custom_metadata.custom_tag, 1);
    // count
}

// Action hit_5
procedure {:inline 1} hit_5()
{
    hdr.ipv4.ttl := add.bv8(hdr.ipv4.ttl, 255);
    hdr.custom_metadata.custom_tag := add.bv16(hdr.custom_metadata.custom_tag, 1);
}

// Action hit_6
procedure {:inline 1} hit_6()
{
    hdr.ipv4.ttl := add.bv8(hdr.ipv4.ttl, 255);
    hdr.custom_metadata.custom_tag := add.bv16(hdr.custom_metadata.custom_tag, 1);
}

// Table learning_0
procedure {:inline 1} learning_0.apply()
{
    if(learning_0.action_run == learning_0.action.dmac_hit){
        call dmac_hit();
    }
    else if(learning_0.action_run == learning_0.action.dmac_miss){
        call dmac_miss();
    }
    else {
        call dmac_miss();
    }
}
procedure mainProcedure()
{
}
procedure mark_to_drop();
    ensures drop==true;
	modifies drop;

// Action miss
procedure {:inline 1} miss()
{
    ig_dprsr_md.drop_ctl := 1;
}

// Action miss_4
procedure {:inline 1} miss_4()
{
    eg_intr_md_for_dprs.drop_ctl := 1;
}

// Action miss_5
procedure {:inline 1} miss_5()
{
    ig_dprsr_md.drop_ctl := 1;
}

// Action miss_6
procedure {:inline 1} miss_6()
{
    eg_intr_md_for_dprs.drop_ctl := 1;
}

// Action modify_eg_port
procedure {:inline 1} modify_eg_port(port:PortId_t)
{
    ig_tm_md.ucast_egress_port := port;
}

// Action modify_eg_port_2
procedure {:inline 1} modify_eg_port_2(port:PortId_t)
{
    ig_tm_md.ucast_egress_port := port;
}

//Parser State parse_ipv4
procedure {:inline 1} parse_ipv4()
{
    hdr.ipv4.valid := true;
    call accept();
}

// Table pinning_0
procedure {:inline 1} pinning_0.apply()
{
    if(pinning_0.action_run == pinning_0.action.NoAction_1){
        call NoAction_1();
    }
    else if(pinning_0.action_run == pinning_0.action.modify_eg_port){
        call modify_eg_port(pinning_0.modify_eg_port.port);
    }
    else {
        call NoAction_1();
    }
}

// Table pinning_1
procedure {:inline 1} pinning_1.apply()
{
    if(pinning_1.action_run == pinning_1.action.NoAction_9){
        call NoAction_9();
    }
    else if(pinning_1.action_run == pinning_1.action.modify_eg_port_2){
        call modify_eg_port_2(pinning_1.modify_eg_port_2.port);
    }
    else {
        call NoAction_9();
    }
}
procedure reject();
    ensures drop==true;
	modifies drop;
procedure {:inline 1} setInvalid(header:Ref);
    ensures (isValid[header] == false);
	modifies isValid;
procedure {:inline 1} setValid(header:Ref);

// Action set_color
procedure {:inline 1} set_color(index:meter_index_t)
	modifies tmp;
{
    tmp := meter_0.execute(index);
    qos_md_0.color := tmp;
}

//Parser State start
procedure {:inline 1} start()
	modifies drop;
{
    ig_intr_md.valid := true;
    ig_md.port_md := port_metadata_unpack(pkt);
    hdr.ethernet.valid := true;
    if(hdr.ethernet.ether_type == 2048){
        call parse_ipv4();
    }
    else{
        call reject();
    }
}

// Table stats_0
procedure {:inline 1} stats_0.apply()
{
    if(stats_0.action_run == stats_0.action.NoAction_8){
        call NoAction_8();
    }
    else if(stats_0.action_run == stats_0.action.count_1){
        call count_1();
    }
    else {
        call NoAction_8();
    }
}

// Table storm_control_0
procedure {:inline 1} storm_control_0.apply()
	modifies tmp;
{
    if(storm_control_0.action_run == storm_control_0.action.NoAction_7){
        call NoAction_7();
    }
    else if(storm_control_0.action_run == storm_control_0.action.set_color){
        call set_color(storm_control_0.set_color.index);
    }
    else {
        call NoAction_7();
    }
}
