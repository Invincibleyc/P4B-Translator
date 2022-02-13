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
type IPv4Address = bv32;

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
var hdr.ipv4.srcAddr:IPv4Address;
var hdr.ipv4.dstAddr:IPv4Address;

// Header tcp_t
var hdr.tcp:Ref;
var hdr.tcp.srcPort:bv16;
var hdr.tcp.dstPort:bv16;
var hdr.tcp.seqNo:bv32;
var hdr.tcp.ackNo:bv32;
var hdr.tcp.dataOffset:bv4;
var hdr.tcp.res:bv3;
var hdr.tcp.ecn:bv3;
var hdr.tcp.ctrl:bv6;
var hdr.tcp.window:bv16;
var hdr.tcp.checksum:bv16;
var hdr.tcp.urgentPtr:bv16;

// Struct mystruct1_t

// Struct metadata
var meta.mystruct1.a:bv4;
var meta.mystruct1.b:bv4;
var meta.hash1:bv16;
var tmp:IPv4_up_to_ihl_only_h;
var tmp_0:bv9;
var tmp_1:bv9;
var tmp_2:bv9;
var tmp_3:bv32;

function {:bvbuiltin "bvshl"} shl.bv9(left:bv9, right:bv9) returns(bv9);

function {:bvbuiltin "bvadd"} add.bv9(left:bv9, right:bv9) returns(bv9);

function {:bvbuiltin "bvsge"} bsge.bv4(left:bv4, right:bv4) returns(bool);

// Table t0_0 Actionlist Declaration
type t0_0.action;
const unique t0_0.action.foo1 : t0_0.action;
const unique t0_0.action.foo2 : t0_0.action;
var t0_0.action_run : t0_0.action;
var t0_0.hit : bool;

// Table t1_0 Actionlist Declaration
type t1_0.action;
const unique t1_0.action.foo1_3 : t1_0.action;
const unique t1_0.action.foo2_3 : t1_0.action;
var t1_0.action_run : t1_0.action;
var t1_0.hit : bool;

// Table t2_0 Actionlist Declaration
type t2_0.action;
const unique t2_0.action.foo1_4 : t2_0.action;
const unique t2_0.action.foo2_4 : t2_0.action;
var t2_0.action_run : t2_0.action;
var t2_0.hit : bool;

// Action NoAction_0
procedure {:inline 1} NoAction_0()
{
}

// Action NoAction_4
procedure {:inline 1} NoAction_4()
{
}

// Action NoAction_5
procedure {:inline 1} NoAction_5()
{
}
procedure {:inline 1} accept()
{
}

// Control cEgress
procedure {:inline 1} cEgress()
{
}

// Control cIngress
procedure {:inline 1} cIngress()
	modifies hdr.ipv4.dstAddr, hdr.ipv4.srcAddr, hdr.tcp.dstPort, hdr.tcp.srcPort, meta.hash1, t0_0.action_run, t1_0.action_run, t2_0.action_run;
{
    call t0_0.apply();
    call t1_0.apply();
    meta.hash1 := hdr.ipv4.dstAddr[16:0];
    call t2_0.apply();
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

// Action foo1
procedure {:inline 1} foo1(dstAddr:IPv4Address)
	modifies hdr.ipv4.dstAddr;
{
    hdr.ipv4.dstAddr := dstAddr;
}

// Action foo1_3
procedure {:inline 1} foo1_3(dstAddr:IPv4Address)
	modifies hdr.ipv4.dstAddr;
{
    hdr.ipv4.dstAddr := dstAddr;
}

// Action foo1_4
procedure {:inline 1} foo1_4(dstAddr:IPv4Address)
	modifies hdr.ipv4.dstAddr;
{
    hdr.ipv4.dstAddr := dstAddr;
}

// Action foo2
procedure {:inline 1} foo2(srcAddr:IPv4Address)
	modifies hdr.ipv4.srcAddr;
{
    hdr.ipv4.srcAddr := srcAddr;
}

// Action foo2_3
procedure {:inline 1} foo2_3(srcAddr:IPv4Address)
	modifies hdr.ipv4.srcAddr;
{
    hdr.ipv4.srcAddr := srcAddr;
}

// Action foo2_4
procedure {:inline 1} foo2_4(srcAddr:IPv4Address)
	modifies hdr.ipv4.srcAddr;
{
    hdr.ipv4.srcAddr := srcAddr;
}
procedure init.stack.index();
    ensures (forall s:HeaderStack::stack.index[s]==0);
	modifies stack.index;
procedure {:inline 1} main()
	modifies drop, hdr.ipv4.dstAddr, hdr.ipv4.srcAddr, hdr.tcp.dstPort, hdr.tcp.srcPort, isValid, meta.hash1, t0_0.action_run, t1_0.action_run, t2_0.action_run, tmp, tmp_0, tmp_1, tmp_2, tmp_3;
{
    call parserI();
    call vc();
    call cIngress();
    call cEgress();
    call uc();
}
procedure mainProcedure()
	modifies drop, emit, forward, hdr.ipv4.dstAddr, hdr.ipv4.srcAddr, hdr.tcp.dstPort, hdr.tcp.srcPort, isValid, meta.hash1, stack.index, t0_0.action_run, t1_0.action_run, t2_0.action_run, tmp, tmp_0, tmp_1, tmp_2, tmp_3;
{
    call t2_0.action_run.limit();
    call t1_0.action_run.limit();
    call t0_0.action_run.limit();
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

// Parser parserI
procedure {:inline 1} parserI()
var tmp:IPv4_up_to_ihl_only_h;
var tmp_0:bv9;
var tmp_1:bv9;
var tmp_2:bv9;
var tmp_3:bv32;
	modifies drop, isValid, tmp, tmp_0, tmp_1, tmp_2, tmp_3;
{
    goto State$start;

        State$start:
    call packet_in.extract(hdr.ethernet);
    goto State$start$parse_ipv4_2, State$start$DEFAULT;
    
State$start$parse_ipv4_2:
    assume (hdr.ethernet.etherType == 2048bv16);
    goto State$parse_ipv4;

    State$start$DEFAULT:
    assume(!(hdr.ethernet.etherType == 2048bv16));
    goto State$accept;

        State$parse_ipv4:
    havoc tmp;
    tmp_0 := shl.bv9(0bv5++tmp.ihl, 2bv9);
    tmp_1 := add.bv9(tmp_0, 492bv9);
    tmp_2 := shl.bv9(tmp_1, 3bv9);
    tmp_3 := 0bv23++tmp_2;
    call packet_in.extract(hdr.ipv4);
    // verify
    assert((hdr.ipv4.version) == (4bv4));
    // verify
    assert(bsge.bv4(hdr.ipv4.ihl, 5bv4));
    goto State$parse_ipv4$parse_tcp_2, State$parse_ipv4$DEFAULT;
    
State$parse_ipv4$parse_tcp_2:
    assume (hdr.ipv4.protocol == 6bv8);
    goto State$parse_tcp;

    State$parse_ipv4$DEFAULT:
    assume(!(hdr.ipv4.protocol == 6bv8));
    goto State$accept;

        State$parse_tcp:
    call packet_in.extract(hdr.tcp);
    goto State$accept;

    State$accept:
    call accept();
    goto Exit;

    State$reject:
    call reject();
    goto Exit;

    Exit:
}
procedure reject();
    ensures drop==true;
	modifies drop;
procedure {:inline 1} setInvalid(header:Ref);
    ensures (isValid[header] == false);
	modifies isValid;
procedure {:inline 1} setValid(header:Ref);

procedure t0_0.action_run.limit();
    ensures(t0_0.action_run==t0_0.action.foo1 || t0_0.action_run==t0_0.action.foo2);
	modifies t0_0.action_run;

// Table t0_0
procedure {:inline 1} t0_0.apply()
	modifies hdr.ipv4.dstAddr, hdr.ipv4.srcAddr, hdr.tcp.dstPort, t0_0.action_run;
{
    var foo2.srcAddr:IPv4Address;
    var foo1.dstAddr:IPv4Address;
    hdr.tcp.dstPort := hdr.tcp.dstPort;

    call t0_0.apply_table_entry();
    goto action_foo1, action_foo2;

    action_foo1:
    assume t0_0.action_run == t0_0.action.foo1;
    call foo1(foo1.dstAddr);
    goto Exit;

    action_foo2:
    assume t0_0.action_run == t0_0.action.foo2;
    call foo2(foo2.srcAddr);
    goto Exit;

    Exit:
        call t0_0.apply_table_exit();
}

// Table Entry t0_0.apply_table_entry
procedure t0_0.apply_table_entry();

// Table Exit t0_0.apply_table_exit
procedure t0_0.apply_table_exit();

procedure t1_0.action_run.limit();
    ensures(t1_0.action_run==t1_0.action.foo1_3 || t1_0.action_run==t1_0.action.foo2_3);
	modifies t1_0.action_run;

// Table t1_0
procedure {:inline 1} t1_0.apply()
	modifies hdr.ipv4.dstAddr, hdr.ipv4.srcAddr, hdr.tcp.dstPort, t1_0.action_run;
{
    var foo2_3.srcAddr:IPv4Address;
    var foo1_3.dstAddr:IPv4Address;
    hdr.tcp.dstPort := hdr.tcp.dstPort;

    call t1_0.apply_table_entry();
    goto action_foo1_3, action_foo2_3;

    action_foo1_3:
    assume t1_0.action_run == t1_0.action.foo1_3;
    call foo1_3(foo1_3.dstAddr);
    goto Exit;

    action_foo2_3:
    assume t1_0.action_run == t1_0.action.foo2_3;
    call foo2_3(foo2_3.srcAddr);
    goto Exit;

    Exit:
        call t1_0.apply_table_exit();
}

// Table Entry t1_0.apply_table_entry
procedure t1_0.apply_table_entry();

// Table Exit t1_0.apply_table_exit
procedure t1_0.apply_table_exit();

procedure t2_0.action_run.limit();
    ensures(t2_0.action_run==t2_0.action.foo1_4 || t2_0.action_run==t2_0.action.foo2_4);
	modifies t2_0.action_run;

// Table t2_0
procedure {:inline 1} t2_0.apply()
	modifies hdr.ipv4.dstAddr, hdr.ipv4.srcAddr, hdr.tcp.srcPort, meta.hash1, t2_0.action_run;
{
    var foo2_4.srcAddr:IPv4Address;
    var foo1_4.dstAddr:IPv4Address;
    hdr.tcp.srcPort := hdr.tcp.srcPort;
    meta.hash1 := meta.hash1;

    call t2_0.apply_table_entry();
    goto action_foo1_4, action_foo2_4;

    action_foo1_4:
    assume t2_0.action_run == t2_0.action.foo1_4;
    call foo1_4(foo1_4.dstAddr);
    goto Exit;

    action_foo2_4:
    assume t2_0.action_run == t2_0.action.foo2_4;
    call foo2_4(foo2_4.srcAddr);
    goto Exit;

    Exit:
        call t2_0.apply_table_exit();
}

// Table Entry t2_0.apply_table_entry
procedure t2_0.apply_table_entry();

// Table Exit t2_0.apply_table_exit
procedure t2_0.apply_table_exit();

// Control uc
procedure {:inline 1} uc()
{
}

// Control vc
procedure {:inline 1} vc()
{
}
