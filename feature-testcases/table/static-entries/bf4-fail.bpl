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
var standard_metadata.clone_spec:bv32;
var standard_metadata.instance_type:bv32;
var standard_metadata.drop:bv1;
var standard_metadata.recirculate_port:bv16;
var standard_metadata.packet_length:bv32;
var standard_metadata.enq_timestamp:bv32;
var standard_metadata.enq_qdepth:bv19;
var standard_metadata.deq_timedelta:bv32;
var standard_metadata.deq_qdepth:bv19;
var standard_metadata.ingress_global_timestamp:bv48;
var standard_metadata.egress_global_timestamp:bv48;
var standard_metadata.lf_field_list:bv32;
var standard_metadata.mcast_grp:bv16;
var standard_metadata.resubmit_flag:bv32;
var standard_metadata.egress_rid:bv16;
var standard_metadata.recirculate_flag:bv32;
var standard_metadata.checksum_error:bv1;
var standard_metadata.parser_error:error;
var standard_metadata.priority:bv3;
var standard_metadata.deflection_flag:bv1;
var standard_metadata.deflect_on_drop:bv1;
var standard_metadata.enq_congest_stat:bv2;
var standard_metadata.deq_congest_stat:bv2;
var standard_metadata.mcast_hash:bv13;
var standard_metadata.ingress_cos:bv3;
var standard_metadata.packet_color:bv2;
var standard_metadata.qid:bv5;

// Struct metadata
var meta.trap:bool;

// Struct headers

// Header ethernet_t
var hdr.ethernet:Ref;
var hdr.ethernet.dstAddr:bv48;
var hdr.ethernet.srcAddr:bv48;
var hdr.ethernet.ethertype:bv16;
var hdr.ethernet.e:bv8;

// Header trap_t
var hdr.trap:Ref;
var hdr.trap.trap:bv8;

function {:bvbuiltin "bvadd"} add.bv8(left:bv8, right:bv8) returns(bv8);

// Table t_exact_0 Actionlist Declaration
type t_exact_0.action;
const unique t_exact_0.action.a : t_exact_0.action;
const unique t_exact_0.action.a_with_control_params : t_exact_0.action;
var t_exact_0.action_run : t_exact_0.action;
var t_exact_0.hit : bool;

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

// Action a
procedure {:inline 1} a()
	modifies forward, standard_metadata.egress_spec;
{
    standard_metadata.egress_spec := 0bv9;
    forward := true;
}

// Action a_with_control_params
procedure {:inline 1} a_with_control_params(x:bv9)
	modifies forward, standard_metadata.egress_spec, meta.trap;
{
    standard_metadata.egress_spec := x;
    forward := true;
    if(((hdr.ethernet.e) == (1bv8)) && ((x) == (1bv9))){
        meta.trap := false;
    }
    else{
        //assert(false);
        meta.trap := true;
    }
    //assert(meta.trap == false);
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

// Control egress
procedure {:inline 1} egress()
{
}

// Control ingress
procedure {:inline 1} ingress()
	modifies forward, hdr.ethernet.e, hdr.trap.trap, standard_metadata.egress_spec, t_exact_0.action_run, meta.trap;
{
    hdr.ethernet.e := 1bv8;
    meta.trap := true;
    call t_exact_0.apply();
    if(meta.trap){
        assert(false);
        hdr.trap.trap := add.bv8(hdr.trap.trap, 1bv8);
    }
}
procedure init.stack.index();
    ensures (forall s:HeaderStack::stack.index[s]==0);
	modifies stack.index;
procedure {:inline 1} main()
	modifies drop, forward, hdr.ethernet.e, hdr.trap.trap, isValid, standard_metadata.egress_spec, t_exact_0.action_run, meta.trap;
{
    call ParserImpl();
    call verifyChecksum();
    call ingress();
    call egress();
    call computeChecksum();
}
procedure mainProcedure()
	modifies drop, emit, forward, hdr.ethernet.e, hdr.trap.trap, isValid, stack.index, standard_metadata.egress_spec, t_exact_0.action_run, meta.trap;
{
    call t_exact_0.action_run.limit();
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
procedure {:inline 1} setInvalid(header:Ref);
    ensures (isValid[header] == false);
	modifies isValid;
procedure {:inline 1} setValid(header:Ref);

procedure t_exact_0.action_run.limit();
    ensures(t_exact_0.action_run==t_exact_0.action.a || t_exact_0.action_run==t_exact_0.action.a_with_control_params);
	modifies t_exact_0.action_run;

// Table t_exact_0
procedure {:inline 1} t_exact_0.apply()
	modifies forward, hdr.ethernet.e, standard_metadata.egress_spec, t_exact_0.action_run, meta.trap;
{
    var a_with_control_params.x:bv9;
    hdr.ethernet.e := hdr.ethernet.e;


    call t_exact_0.apply_table_entry();

    if(hdr.ethernet.e == 1bv8){
        call a_with_control_params(1bv9);
        //assert(meta.trap == false);
        goto Exit;
    }
    else{
        //assert(false);
        goto action_a, action_a_with_control_params, Exit;
    }
    
    goto action_a, action_a_with_control_params, Exit;


    action_a:
    t_exact_0.action_run := t_exact_0.action.a;
    call a();
    //assert(false);
    goto Exit;

    action_a_with_control_params:
    t_exact_0.action_run := t_exact_0.action.a_with_control_params;
    call a_with_control_params(a_with_control_params.x);
    //assert(false);
    goto Exit;

    Exit:
        assert(meta.trap == false);
        call t_exact_0.apply_table_exit();
}

// Table Entry t_exact_0.apply_table_entry
procedure t_exact_0.apply_table_entry();

// Table Exit t_exact_0.apply_table_exit
procedure t_exact_0.apply_table_exit();

// Control verifyChecksum
procedure {:inline 1} verifyChecksum()
{
}
