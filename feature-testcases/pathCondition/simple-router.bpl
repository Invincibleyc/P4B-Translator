type Ref;
type error=bv1;
type HeaderStack = [int]Ref;
var last:[HeaderStack]Ref;
var forward:bool;
var isValid:[Ref]bool;
var emit:[Ref]bool;
var stack.index:[HeaderStack]int;
var size:[HeaderStack]int;
var drop:bool;

// Struct standard_metadata_t
var standard_metadata.ingress_port:bv9;
var standard_metadata.egress_spec:bv9;
var standard_metadata.egress_port:bv9;
var standard_metadata.instance_type:bv32;
var standard_metadata.packet_length:bv32;
var standard_metadata.enq_timestamp:bv32;
var standard_metadata.enq_qdepth:bv19;
var standard_metadata.deq_timedelta:bv32;
var standard_metadata.deq_qdepth:bv19;
var standard_metadata.ingress_global_timestamp:bv48;
var standard_metadata.egress_global_timestamp:bv48;
var standard_metadata.mcast_grp:bv16;
var standard_metadata.egress_rid:bv16;
var standard_metadata.checksum_error:bv1;
var standard_metadata.parser_error:error;
var standard_metadata.priority:bv3;

// Struct routing_metadata_t

// Struct metadata
var meta.routing_metadata.nhop_ipv4:bv32;

// Struct headers

// Header ethernet_t
var hdr.ethernet:Ref;
var hdr.ethernet.dstAddr:bv48;
var hdr.ethernet.srcAddr:bv48;
var hdr.ethernet.etherType:bv16;

// Header ipv4_t
var hdr.ipv4:Ref;
var hdr.ipv4.version:bv4;
var hdr.ipv4.ihl:bv4;
var hdr.ipv4.diffserv:bv8;
var hdr.ipv4.totalLen:bv16;
var hdr.ipv4.identification:bv16;
var hdr.ipv4.flags:bv3;
var hdr.ipv4.fragOffset:bv13;
var hdr.ipv4.ttl:bv8;
var hdr.ipv4.protocol:bv8;
var hdr.ipv4.hdrChecksum:bv16;
var hdr.ipv4.srcAddr:bv32;
var hdr.ipv4.dstAddr:bv32;

// Table send_frame_0 Actionlist Declaration
type send_frame_0.action;
const unique send_frame_0.action.rewrite_mac : send_frame_0.action;
const unique send_frame_0.action._drop : send_frame_0.action;
const unique send_frame_0.action.NoAction_0 : send_frame_0.action;
var send_frame_0.action_run : send_frame_0.action;
var send_frame_0.hit : bool;

function {:bvbuiltin "bvugt"} bugt.bv8(left:bv8, right:bv8) returns(bool);

function {:bvbuiltin "bvadd"} add.bv8(left:bv8, right:bv8) returns(bv8);

// Table drop_all_0 Actionlist Declaration
type drop_all_0.action;
const unique drop_all_0.action._drop_2 : drop_all_0.action;
var drop_all_0.action_run : drop_all_0.action;
var drop_all_0.hit : bool;

// Table forward_0 Actionlist Declaration
type forward_0.action;
const unique forward_0.action.set_dmac : forward_0.action;
const unique forward_0.action._drop_5 : forward_0.action;
const unique forward_0.action.NoAction_1 : forward_0.action;
var forward_0.action_run : forward_0.action;
var forward_0.hit : bool;

// Table ipv4_lpm_0 Actionlist Declaration
type ipv4_lpm_0.action;
const unique ipv4_lpm_0.action.set_nhop : ipv4_lpm_0.action;
const unique ipv4_lpm_0.action._drop_6 : ipv4_lpm_0.action;
var ipv4_lpm_0.action_run : ipv4_lpm_0.action;
var ipv4_lpm_0.hit : bool;

// Action NoAction_0
procedure {:inline 1} NoAction_0()
{
}

// Action NoAction_1
procedure {:inline 1} NoAction_1()
{
}

// Parser ParserImpl
procedure {:inline 1} ParserImpl()
	modifies drop, isValid;
{
    goto State$start;

        State$parse_ethernet:
    call packet_in.extract(hdr.ethernet);
    goto State$parse_ethernet$parse_ipv4_2, State$parse_ethernet$DEFAULT;
    
State$parse_ethernet$parse_ipv4_2:
    assume (hdr.ethernet.etherType == 2048bv16);
    goto State$parse_ipv4;

    State$parse_ethernet$DEFAULT:
    assume(!(hdr.ethernet.etherType == 2048bv16));
    goto State$accept;

        State$parse_ipv4:
    call packet_in.extract(hdr.ipv4);
    goto State$accept;

        State$start:
    goto State$parse_ethernet;

    State$accept:
    call accept();
    goto Exit;

    State$reject:
    call reject();
    goto Exit;

    Exit:
}

// Action _drop
procedure {:inline 1} _drop()
	modifies drop;
{
    call mark_to_drop();
}

// Action _drop_2
procedure {:inline 1} _drop_2()
	modifies drop;
{
    call mark_to_drop();
}

// Action _drop_5
procedure {:inline 1} _drop_5()
	modifies drop;
{
    call mark_to_drop();
}

// Action _drop_6
procedure {:inline 1} _drop_6()
	modifies drop;
{
    call mark_to_drop();
}
procedure {:inline 1} accept()
{
}
procedure clear_drop();
    ensures drop==false;
	modifies drop;
procedure clear_emit();
    ensures (forall header:Ref:: emit[header]==false);
	modifies emit;
procedure clear_forward();
    ensures forward==false;
	modifies forward;
procedure clear_valid();
    ensures (forall header:Ref:: isValid[header]==false);
	modifies isValid;

// Control computeChecksum
procedure {:inline 1} computeChecksum()
{
    // update_checksum
}

procedure drop_all_0.action_run.limit();
    ensures(drop_all_0.action_run==drop_all_0.action._drop_2);
	modifies drop_all_0.action_run;

// Table drop_all_0
procedure {:inline 1} drop_all_0.apply()
	modifies drop, drop_all_0.action_run;
{

    call drop_all_0.apply_table_entry();
    goto action__drop_2, Exit;

    action__drop_2:
    drop_all_0.action_run := drop_all_0.action._drop_2;
    call _drop_2();
    goto Exit;

    Exit:
        call drop_all_0.apply_table_exit();
}

// Table Entry drop_all_0.apply_table_entry
procedure drop_all_0.apply_table_entry();

// Table Exit drop_all_0.apply_table_exit
procedure drop_all_0.apply_table_exit();

// Control egress
procedure {:inline 1} egress()
	modifies drop, hdr.ethernet.srcAddr, send_frame_0.action_run, standard_metadata.egress_port;
{
    call send_frame_0.apply();
}

procedure forward_0.action_run.limit();
    ensures(forward_0.action_run==forward_0.action.set_dmac || forward_0.action_run==forward_0.action._drop_5 || forward_0.action_run==forward_0.action.NoAction_1);
	modifies forward_0.action_run;

// Table forward_0
procedure {:inline 1} forward_0.apply()
	modifies drop, forward_0.action_run, hdr.ethernet.dstAddr, meta.routing_metadata.nhop_ipv4;
{
    var set_dmac.dmac:bv48;
    meta.routing_metadata.nhop_ipv4 := meta.routing_metadata.nhop_ipv4;

    call forward_0.apply_table_entry();
    goto action_set_dmac, action__drop_5, action_NoAction_1, Exit;

    action_set_dmac:
    forward_0.action_run := forward_0.action.set_dmac;
    call set_dmac(set_dmac.dmac);
    goto Exit;

    action__drop_5:
    forward_0.action_run := forward_0.action._drop_5;
    call _drop_5();
    goto Exit;

    action_NoAction_1:
    forward_0.action_run := forward_0.action.NoAction_1;
    call NoAction_1();
    goto Exit;

    Exit:
        call forward_0.apply_table_exit();
}

// Table Entry forward_0.apply_table_entry
procedure forward_0.apply_table_entry();

// Table Exit forward_0.apply_table_exit
procedure forward_0.apply_table_exit();

// Control ingress
procedure {:inline 1} ingress()
	modifies drop, drop_all_0.action_run, forward, forward_0.action_run, hdr.ethernet.dstAddr, hdr.ipv4.dstAddr, hdr.ipv4.ttl, ipv4_lpm_0.action_run, meta.routing_metadata.nhop_ipv4, standard_metadata.egress_spec;
{
    if((isValid[hdr.ipv4]) && (bugt.bv8(hdr.ipv4.ttl, 0bv8))){
        call ipv4_lpm_0.apply();
        call forward_0.apply();
    }
    else{
        call drop_all_0.apply();
    }
}
procedure init.stack.index();
    ensures (forall s:HeaderStack::stack.index[s]==0);
	modifies stack.index;

procedure ipv4_lpm_0.action_run.limit();
    ensures(ipv4_lpm_0.action_run==ipv4_lpm_0.action.set_nhop || ipv4_lpm_0.action_run==ipv4_lpm_0.action._drop_6);
	modifies ipv4_lpm_0.action_run;

// Table ipv4_lpm_0
procedure {:inline 1} ipv4_lpm_0.apply()
	modifies drop, forward, hdr.ipv4.dstAddr, hdr.ipv4.ttl, ipv4_lpm_0.action_run, meta.routing_metadata.nhop_ipv4, standard_metadata.egress_spec;
{
    var set_nhop.port:bv9;
    var set_nhop.nhop_ipv4:bv32;
    hdr.ipv4.dstAddr := hdr.ipv4.dstAddr;

    call ipv4_lpm_0.apply_table_entry();
    goto action_set_nhop, action__drop_6, Exit;

    action_set_nhop:
    ipv4_lpm_0.action_run := ipv4_lpm_0.action.set_nhop;
    call set_nhop(set_nhop.nhop_ipv4, set_nhop.port);
    goto Exit;

    action__drop_6:
    ipv4_lpm_0.action_run := ipv4_lpm_0.action._drop_6;
    call _drop_6();
    goto Exit;

    Exit:
        call ipv4_lpm_0.apply_table_exit();
}

// Table Entry ipv4_lpm_0.apply_table_entry
procedure ipv4_lpm_0.apply_table_entry();

// Table Exit ipv4_lpm_0.apply_table_exit
procedure ipv4_lpm_0.apply_table_exit();
procedure {:inline 1} main()
	modifies drop, drop_all_0.action_run, forward, forward_0.action_run, hdr.ethernet.dstAddr, hdr.ethernet.srcAddr, hdr.ipv4.dstAddr, hdr.ipv4.ttl, ipv4_lpm_0.action_run, isValid, meta.routing_metadata.nhop_ipv4, send_frame_0.action_run, standard_metadata.egress_port, standard_metadata.egress_spec;
{
    while (true)
    invariant(true);
    {
        call ParserImpl();
        call verifyChecksum();
        call ingress();
        call egress();
        call computeChecksum();
    }
}
procedure mainProcedure()
	modifies drop, drop_all_0.action_run, emit, forward, forward_0.action_run, hdr.ethernet.dstAddr, hdr.ethernet.srcAddr, hdr.ipv4.dstAddr, hdr.ipv4.ttl, ipv4_lpm_0.action_run, isValid, meta.routing_metadata.nhop_ipv4, send_frame_0.action_run, stack.index, standard_metadata.egress_port, standard_metadata.egress_spec;
{
    call ipv4_lpm_0.action_run.limit();
    call forward_0.action_run.limit();
    call drop_all_0.action_run.limit();
    call send_frame_0.action_run.limit();
    call clear_forward();
    call clear_drop();
    call clear_valid();
    call clear_emit();
    call init.stack.index();
    call main();
}
procedure mark_to_drop();
    ensures drop==true;
	modifies drop;
procedure packet_in.extract(header:Ref);
    ensures (isValid[header] == true);
	modifies isValid;
procedure reject();
    ensures drop==true;
	modifies drop;

// Action rewrite_mac
procedure {:inline 1} rewrite_mac(smac:bv48)
	modifies hdr.ethernet.srcAddr;
{
    hdr.ethernet.srcAddr := smac;
}

procedure send_frame_0.action_run.limit();
    ensures(send_frame_0.action_run==send_frame_0.action.rewrite_mac || send_frame_0.action_run==send_frame_0.action._drop || send_frame_0.action_run==send_frame_0.action.NoAction_0);
	modifies send_frame_0.action_run;

// Table send_frame_0
procedure {:inline 1} send_frame_0.apply()
	modifies drop, hdr.ethernet.srcAddr, send_frame_0.action_run, standard_metadata.egress_port;
{
    var rewrite_mac.smac:bv48;
    standard_metadata.egress_port := standard_metadata.egress_port;

    call send_frame_0.apply_table_entry();
    goto action_rewrite_mac, action__drop, action_NoAction_0, Exit;

    action_rewrite_mac:
    send_frame_0.action_run := send_frame_0.action.rewrite_mac;
    call rewrite_mac(rewrite_mac.smac);
    goto Exit;

    action__drop:
    send_frame_0.action_run := send_frame_0.action._drop;
    call _drop();
    goto Exit;

    action_NoAction_0:
    send_frame_0.action_run := send_frame_0.action.NoAction_0;
    call NoAction_0();
    goto Exit;

    Exit:
        call send_frame_0.apply_table_exit();
}

// Table Entry send_frame_0.apply_table_entry
procedure send_frame_0.apply_table_entry();

// Table Exit send_frame_0.apply_table_exit
procedure send_frame_0.apply_table_exit();
procedure {:inline 1} setInvalid(header:Ref);
    ensures (isValid[header] == false);
	modifies isValid;
procedure {:inline 1} setValid(header:Ref);

// Action set_dmac
procedure {:inline 1} set_dmac(dmac:bv48)
	modifies hdr.ethernet.dstAddr;
{
    hdr.ethernet.dstAddr := dmac;
}

// Action set_nhop
procedure {:inline 1} set_nhop(nhop_ipv4:bv32, port:bv9)
	modifies forward, hdr.ipv4.ttl, meta.routing_metadata.nhop_ipv4, standard_metadata.egress_spec;
{
    meta.routing_metadata.nhop_ipv4 := nhop_ipv4;
    standard_metadata.egress_spec := port;
    forward := true;
    hdr.ipv4.ttl := add.bv8(hdr.ipv4.ttl, 255bv8);
}

// Control verifyChecksum
procedure {:inline 1} verifyChecksum()
{
    // verify_checksum
}
