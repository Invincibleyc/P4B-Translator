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
type egressSpec_t = bv9;
type macAddr_t = bv48;
type ip4Addr_t = bv32;

// Struct metadata

// Struct headers

// Header ethernet_t
var hdr.ethernet:Ref;
var hdr.ethernet.dstAddr:macAddr_t;
var hdr.ethernet.srcAddr:macAddr_t;
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
var hdr.ipv4.srcAddr:ip4Addr_t;
var hdr.ipv4.dstAddr:ip4Addr_t;

// Table ipv4_lpm_0 Actionlist Declaration
type ipv4_lpm_0.action;
const unique ipv4_lpm_0.action.NoAction_0 : ipv4_lpm_0.action;
const unique ipv4_lpm_0.action.ipv4_forward : ipv4_lpm_0.action;
var ipv4_lpm_0.action_run : ipv4_lpm_0.action;
var ipv4_lpm_0.hit : bool;

// Action NoAction_0
procedure {:inline 1} NoAction_0()
{
}

// Parser ParserImpl
procedure {:inline 1} ParserImpl()
	modifies drop, isValid;
{
    call start();
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

// Action drop
procedure {:inline 1} drop()
	modifies drop;
{
    call mark_to_drop();
}

// Action drop_2
procedure {:inline 1} drop_2()
	modifies drop;
{
    call mark_to_drop();
}

// Control egress
procedure {:inline 1} egress()
{
}

// Control ingress
procedure {:inline 1} ingress()
	modifies drop, hdr.ipv4.dstAddr;
{
    meta.test_bool := false;
    if(isValid[hdr.ipv4]){
        call ipv4_lpm_0.apply();
    }
    if(!(meta.test_bool)){
        call drop_2();
    }
}
procedure init.stack.index();
    ensures (forall s:HeaderStack::stack.index[s]==0);
	modifies stack.index;

// Action ipv4_forward
procedure {:inline 1} ipv4_forward(dstAddr:macAddr_t, port:egressSpec_t)
{
    meta.test_bool := true;
}

procedure ipv4_lpm_0.action_run.limit();
    ensures(ipv4_lpm_0.action_run==ipv4_lpm_0.action.NoAction_0 || ipv4_lpm_0.action_run==ipv4_lpm_0.action.ipv4_forward);
	modifies ipv4_lpm_0.action_run;

// Table ipv4_lpm_0
procedure {:inline 1} ipv4_lpm_0.apply()
	modifies hdr.ipv4.dstAddr;
{
    var ipv4_forward.port:egressSpec_t;
    var ipv4_forward.dstAddr:macAddr_t;
    hdr.ipv4.dstAddr := hdr.ipv4.dstAddr;

    call ipv4_lpm_0.apply_table_entry();

    action_NoAction_0:
    if(ipv4_lpm_0.action_run == ipv4_lpm_0.action.NoAction_0){
        call NoAction_0();
    }

    action_ipv4_forward:
    if(ipv4_lpm_0.action_run == ipv4_lpm_0.action.ipv4_forward){
        call ipv4_forward(ipv4_forward.dstAddr, ipv4_forward.port);
    }
}

// Table Entry ipv4_lpm_0.apply_table_entry
procedure ipv4_lpm_0.apply_table_entry();

// Table Exit ipv4_lpm_0.apply_table_exit
procedure ipv4_lpm_0.apply_table_exit();
procedure {:inline 1} main()
	modifies drop, hdr.ipv4.dstAddr, isValid;
{
    call ParserImpl();
    call verifyChecksum();
    call ingress();
    call egress();
    call computeChecksum();
}
procedure mainProcedure()
	modifies drop, emit, forward, hdr.ipv4.dstAddr, ipv4_lpm_0.action_run, isValid, stack.index;
{
    call ipv4_lpm_0.action_run.limit();
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

//Parser State parse_ipv4
procedure {:inline 1} parse_ipv4()
	modifies isValid;
{
    call packet_in.extract(hdr.ipv4);
    call accept();
}
procedure reject();
    ensures drop==true;
	modifies drop;
procedure {:inline 1} setInvalid(header:Ref);
    ensures (isValid[header] == false);
	modifies isValid;
procedure {:inline 1} setValid(header:Ref);

//Parser State start
procedure {:inline 1} start()
	modifies drop, isValid;
{
    call packet_in.extract(hdr.ethernet);
    if(hdr.ethernet.etherType == 2048bv16){
        call parse_ipv4();
    }
}

// Control verifyChecksum
procedure {:inline 1} verifyChecksum()
{
}
