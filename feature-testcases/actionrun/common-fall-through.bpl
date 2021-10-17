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

// Struct ingress_metadata_t

// Struct metadata
var meta.ing_metadata.drop:bv8;
var meta.ing_metadata.egress_port:bv8;
var meta.ing_metadata.f1:bv8;
var meta.ing_metadata.f2:bv16;
var meta.ing_metadata.f3:bv32;
var meta.ing_metadata.f4:bv64;

// Struct headers

// Header ethernet_t
var hdr.ethernet:Ref;
var hdr.ethernet.dstAddr:bv48;
var hdr.ethernet.srcAddr:bv48;
var hdr.ethernet.ethertype:bv16;

// Table e_t1_0 Actionlist Declaration
type e_t1_0.action;
const unique e_t1_0.action.nop : e_t1_0.action;
const unique e_t1_0.action.NoAction_0 : e_t1_0.action;
var e_t1_0.action_run : e_t1_0.action;
var e_t1_0.hit : bool;

// Table i_t1_0 Actionlist Declaration
type i_t1_0.action;
const unique i_t1_0.action.nop_2 : i_t1_0.action;
const unique i_t1_0.action.ing_drop : i_t1_0.action;
const unique i_t1_0.action.set_f1 : i_t1_0.action;
const unique i_t1_0.action.set_f2 : i_t1_0.action;
const unique i_t1_0.action.set_f3 : i_t1_0.action;
const unique i_t1_0.action.set_egress_port : i_t1_0.action;
const unique i_t1_0.action.NoAction_1 : i_t1_0.action;
var i_t1_0.action_run : i_t1_0.action;
var i_t1_0.hit : bool;

// Table i_t2_0 Actionlist Declaration
type i_t2_0.action;
const unique i_t2_0.action.nop_5 : i_t2_0.action;
const unique i_t2_0.action.set_f2_2 : i_t2_0.action;
const unique i_t2_0.action.NoAction_6 : i_t2_0.action;
var i_t2_0.action_run : i_t2_0.action;
var i_t2_0.hit : bool;

// Table i_t3_0 Actionlist Declaration
type i_t3_0.action;
const unique i_t3_0.action.nop_6 : i_t3_0.action;
const unique i_t3_0.action.set_f3_2 : i_t3_0.action;
const unique i_t3_0.action.NoAction_7 : i_t3_0.action;
var i_t3_0.action_run : i_t3_0.action;
var i_t3_0.hit : bool;

// Action NoAction_0
procedure {:inline 1} NoAction_0()
{
}

// Action NoAction_1
procedure {:inline 1} NoAction_1()
{
}

// Action NoAction_6
procedure {:inline 1} NoAction_6()
{
}

// Action NoAction_7
procedure {:inline 1} NoAction_7()
{
}

// Parser ParserImpl
procedure {:inline 1} ParserImpl()
	modifies drop, isValid;
{
    goto State$start;

        State$start:
    call packet_in.extract(hdr.ethernet);
    goto State$accept;

    State$accept:
    call accept();
    goto Exit;

    State$reject:
    call reject();
    goto Exit;

    Exit:
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
}

procedure e_t1_0.action_run.limit();
    ensures(e_t1_0.action_run==e_t1_0.action.nop || e_t1_0.action_run==e_t1_0.action.NoAction_0);
	modifies e_t1_0.action_run;

// Table e_t1_0
procedure {:inline 1} e_t1_0.apply()
	modifies hdr.ethernet.srcAddr;
{
    hdr.ethernet.srcAddr := hdr.ethernet.srcAddr;

    call e_t1_0.apply_table_entry();
    goto action_nop, action_NoAction_0, Exit;

    action_nop:
    call nop();
    goto Exit;

    action_NoAction_0:
    call NoAction_0();
    goto Exit;

    Exit:
        call e_t1_0.apply_table_exit();
}

// Table Entry e_t1_0.apply_table_entry
procedure e_t1_0.apply_table_entry();

// Table Exit e_t1_0.apply_table_exit
procedure e_t1_0.apply_table_exit();

// Control egress
procedure {:inline 1} egress()
	modifies hdr.ethernet.srcAddr;
{
    call e_t1_0.apply();
}

procedure i_t1_0.action_run.limit();
    ensures(i_t1_0.action_run==i_t1_0.action.nop_2 || i_t1_0.action_run==i_t1_0.action.ing_drop || i_t1_0.action_run==i_t1_0.action.set_f1 || i_t1_0.action_run==i_t1_0.action.set_f2 || i_t1_0.action_run==i_t1_0.action.set_f3 || i_t1_0.action_run==i_t1_0.action.set_egress_port || i_t1_0.action_run==i_t1_0.action.NoAction_1);
	modifies i_t1_0.action_run;

// Table i_t1_0
procedure {:inline 1} i_t1_0.apply()
	modifies hdr.ethernet.dstAddr, meta.ing_metadata.drop, meta.ing_metadata.egress_port, meta.ing_metadata.f1, meta.ing_metadata.f2, meta.ing_metadata.f3;
{
    var set_egress_port.egress_port:bv8;
    var set_f3.f3:bv32;
    var set_f2.f2:bv16;
    var set_f1.f1:bv8;
    hdr.ethernet.dstAddr := hdr.ethernet.dstAddr;

    call i_t1_0.apply_table_entry();
    goto action_nop_2, action_ing_drop, action_set_f1, action_set_f2, action_set_f3, action_set_egress_port, action_NoAction_1, Exit;

    action_nop_2:
    call nop_2();
    goto Exit;

    action_ing_drop:
    call ing_drop();
    goto Exit;

    action_set_f1:
    call set_f1(set_f1.f1);
    goto Exit;

    action_set_f2:
    call set_f2(set_f2.f2);
    goto Exit;

    action_set_f3:
    call set_f3(set_f3.f3);
    goto Exit;

    action_set_egress_port:
    call set_egress_port(set_egress_port.egress_port);
    goto Exit;

    action_NoAction_1:
    call NoAction_1();
    goto Exit;

    Exit:
        call i_t1_0.apply_table_exit();
}

// Table Entry i_t1_0.apply_table_entry
procedure i_t1_0.apply_table_entry();

// Table Exit i_t1_0.apply_table_exit
procedure i_t1_0.apply_table_exit();

procedure i_t2_0.action_run.limit();
    ensures(i_t2_0.action_run==i_t2_0.action.nop_5 || i_t2_0.action_run==i_t2_0.action.set_f2_2 || i_t2_0.action_run==i_t2_0.action.NoAction_6);
	modifies i_t2_0.action_run;

// Table i_t2_0
procedure {:inline 1} i_t2_0.apply()
	modifies hdr.ethernet.dstAddr, meta.ing_metadata.f2;
{
    var set_f2_2.f2:bv16;
    hdr.ethernet.dstAddr := hdr.ethernet.dstAddr;

    call i_t2_0.apply_table_entry();
    goto action_nop_5, action_set_f2_2, action_NoAction_6, Exit;

    action_nop_5:
    call nop_5();
    goto Exit;

    action_set_f2_2:
    call set_f2_2(set_f2_2.f2);
    goto Exit;

    action_NoAction_6:
    call NoAction_6();
    goto Exit;

    Exit:
        call i_t2_0.apply_table_exit();
}

// Table Entry i_t2_0.apply_table_entry
procedure i_t2_0.apply_table_entry();

// Table Exit i_t2_0.apply_table_exit
procedure i_t2_0.apply_table_exit();

procedure i_t3_0.action_run.limit();
    ensures(i_t3_0.action_run==i_t3_0.action.nop_6 || i_t3_0.action_run==i_t3_0.action.set_f3_2 || i_t3_0.action_run==i_t3_0.action.NoAction_7);
	modifies i_t3_0.action_run;

// Table i_t3_0
procedure {:inline 1} i_t3_0.apply()
	modifies hdr.ethernet.dstAddr, meta.ing_metadata.f3;
{
    var set_f3_2.f3:bv32;
    hdr.ethernet.dstAddr := hdr.ethernet.dstAddr;

    call i_t3_0.apply_table_entry();
    goto action_nop_6, action_set_f3_2, action_NoAction_7, Exit;

    action_nop_6:
    call nop_6();
    goto Exit;

    action_set_f3_2:
    call set_f3_2(set_f3_2.f3);
    goto Exit;

    action_NoAction_7:
    call NoAction_7();
    goto Exit;

    Exit:
        call i_t3_0.apply_table_exit();
}

// Table Entry i_t3_0.apply_table_entry
procedure i_t3_0.apply_table_entry();

// Table Exit i_t3_0.apply_table_exit
procedure i_t3_0.apply_table_exit();

// Action ing_drop
procedure {:inline 1} ing_drop()
	modifies meta.ing_metadata.drop;
{
    meta.ing_metadata.drop := 1bv8;
}

// Control ingress
procedure {:inline 1} ingress()
	modifies hdr.ethernet.dstAddr, meta.ing_metadata.drop, meta.ing_metadata.egress_port, meta.ing_metadata.f1, meta.ing_metadata.f2, meta.ing_metadata.f3;
{
    var set_egress_port.egress_port:bv8;
    var set_f3.f3:bv32;
    var set_f2.f2:bv16;
    var set_f1.f1:bv8;
    call i_t2_0.apply();
    goto Switch$i_t1_0$nop_2, Switch$i_t1_0$ing_drop, Switch$i_t1_0$set_f1, Switch$i_t1_0$set_f2, Switch$i_t1_0$set_f3, Switch$i_t1_0$set_egress_port, Switch$i_t1_0$NoAction_1;

    Switch$i_t1_0$nop_2:
        call i_t1_0.apply_table_entry();
        call nop_2();
        call i_t1_0.apply_table_exit();
        call i_t3_0.apply();
        goto Switch$i_t1_0$Continue;

    Switch$i_t1_0$set_egress_port:
        call i_t1_0.apply_table_entry();
        call set_egress_port(set_egress_port.egress_port);
        call i_t1_0.apply_table_exit();
        call i_t3_0.apply();
        goto Switch$i_t1_0$Continue;

    Switch$i_t1_0$ing_drop:
        call i_t1_0.apply_table_entry();
        call ing_drop();
        call i_t1_0.apply_table_exit();
        goto Switch$i_t1_0$Continue;

    Switch$i_t1_0$set_f1:
        call i_t1_0.apply_table_entry();
        call set_f1(set_f1.f1);
        call i_t1_0.apply_table_exit();
        goto Switch$i_t1_0$Continue;

    Switch$i_t1_0$set_f2:
        call i_t1_0.apply_table_entry();
        call set_f2(set_f2.f2);
        call i_t1_0.apply_table_exit();
        goto Switch$i_t1_0$Continue;

    Switch$i_t1_0$set_f3:
        call i_t1_0.apply_table_entry();
        call set_f3(set_f3.f3);
        call i_t1_0.apply_table_exit();
        goto Switch$i_t1_0$Continue;

    Switch$i_t1_0$NoAction_1:
        call i_t1_0.apply_table_entry();
        call NoAction_1();
        call i_t1_0.apply_table_exit();
        goto Switch$i_t1_0$Continue;

    Switch$i_t1_0$Continue:
}
procedure init.stack.index();
    ensures (forall s:HeaderStack::stack.index[s]==0);
	modifies stack.index;
procedure {:inline 1} main()
	modifies drop, hdr.ethernet.dstAddr, hdr.ethernet.srcAddr, isValid, meta.ing_metadata.drop, meta.ing_metadata.egress_port, meta.ing_metadata.f1, meta.ing_metadata.f2, meta.ing_metadata.f3;
{
    call ParserImpl();
    call verifyChecksum();
    call ingress();
    call egress();
    call computeChecksum();
}
procedure mainProcedure()
	modifies drop, e_t1_0.action_run, emit, forward, hdr.ethernet.dstAddr, hdr.ethernet.srcAddr, i_t1_0.action_run, i_t2_0.action_run, i_t3_0.action_run, isValid, meta.ing_metadata.drop, meta.ing_metadata.egress_port, meta.ing_metadata.f1, meta.ing_metadata.f2, meta.ing_metadata.f3, stack.index;
{
    call i_t3_0.action_run.limit();
    call i_t2_0.action_run.limit();
    call i_t1_0.action_run.limit();
    call e_t1_0.action_run.limit();
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

// Action nop
procedure {:inline 1} nop()
{
}

// Action nop_2
procedure {:inline 1} nop_2()
{
}

// Action nop_5
procedure {:inline 1} nop_5()
{
}

// Action nop_6
procedure {:inline 1} nop_6()
{
}
procedure packet_in.extract(header:Ref);
    ensures (isValid[header] == true);
	modifies isValid;
procedure reject();
    ensures drop==true;
	modifies drop;
procedure {:inline 1} setInvalid(header:Ref);
    ensures (isValid[header] == false);
	modifies isValid;
procedure {:inline 1} setValid(header:Ref);

// Action set_egress_port
procedure {:inline 1} set_egress_port(egress_port:bv8)
	modifies meta.ing_metadata.egress_port;
{
    meta.ing_metadata.egress_port := egress_port;
}

// Action set_f1
procedure {:inline 1} set_f1(f1:bv8)
	modifies meta.ing_metadata.f1;
{
    meta.ing_metadata.f1 := f1;
}

// Action set_f2
procedure {:inline 1} set_f2(f2:bv16)
	modifies meta.ing_metadata.f2;
{
    meta.ing_metadata.f2 := f2;
}

// Action set_f2_2
procedure {:inline 1} set_f2_2(f2:bv16)
	modifies meta.ing_metadata.f2;
{
    meta.ing_metadata.f2 := f2;
}

// Action set_f3
procedure {:inline 1} set_f3(f3:bv32)
	modifies meta.ing_metadata.f3;
{
    meta.ing_metadata.f3 := f3;
}

// Action set_f3_2
procedure {:inline 1} set_f3_2(f3:bv32)
	modifies meta.ing_metadata.f3;
{
    meta.ing_metadata.f3 := f3;
}

// Control verifyChecksum
procedure {:inline 1} verifyChecksum()
{
}
