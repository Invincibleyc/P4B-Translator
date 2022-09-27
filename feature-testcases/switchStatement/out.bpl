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
type std_meta_t = standard_metadata_t;

// Struct H

// Struct M

// Table t_0 Actionlist Declaration
type t_0.action;
var t_0.action_run : t_0.action;
var t_0.hit : bool;
var hasReturned:bool;

// Control ComputeChecksumI
procedure {:inline 1} ComputeChecksumI()
{
}

// Control EgressI
procedure {:inline 1} EgressI()
	modifies hasReturned;
{
    hasReturned := false;
    t_0.apply();
    if(t_0.action_run == a){
        hasReturned := true;
    }
}

// Control IngressI
procedure {:inline 1} IngressI()
{
}

// Parser ParserI
procedure {:inline 1} ParserI()
	modifies drop;
{
    call start();
}

// Control VerifyChecksumI
procedure {:inline 1} VerifyChecksumI()
{
}

// Action a
procedure {:inline 1} a()
{
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
procedure init.stack.index();
    ensures (forall s:HeaderStack::stack.index[s]==0);
	modifies stack.index;
procedure {:inline 1} main()
	modifies drop, hasReturned;
{
    call ParserI();
    call VerifyChecksumI();
    call IngressI();
    call EgressI();
    call ComputeChecksumI();
}
procedure mainProcedure()
	modifies drop, emit, forward, hasReturned, isValid, stack.index, t_0.action_run;
{
    call t_0.action_run.limit();
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

//Parser State start
procedure {:inline 1} start()
{
    call accept();
}

procedure t_0.action_run.limit();
    ensures();
	modifies t_0.action_run;

// Table t_0
procedure {:inline 1} t_0.apply()
{

    call t_0.apply_table_entry();
}

// Table Entry t_0.apply_table_entry
procedure t_0.apply_table_entry();

// Table Exit t_0.apply_table_exit
procedure t_0.apply_table_exit();
