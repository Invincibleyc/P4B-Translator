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

// Struct metadata

// Header elem
var meta.temp:Ref;
var meta.temp.bos:bv1;
var meta.temp.value:bv31;

// Struct headers
const hdr.stack:HeaderStack;

// Header elem
var hdr.stack.last:Ref;
var hdr.stack.last.bos:bv1;
var hdr.stack.last.value:bv31;

// Header elem
var hdr.stack.0:Ref;
var hdr.stack.0.bos:bv1;
var hdr.stack.0.value:bv31;

// Header elem
var hdr.stack.1:Ref;
var hdr.stack.1.bos:bv1;
var hdr.stack.1.value:bv31;

// Header elem
var hdr.stack.2:Ref;
var hdr.stack.2.bos:bv1;
var hdr.stack.2.value:bv31;

// Header elem
var hdr.stack.3:Ref;
var hdr.stack.3.bos:bv1;
var hdr.stack.3.value:bv31;

// Header elem
var hdr.stack.4:Ref;
var hdr.stack.4.bos:bv1;
var hdr.stack.4.value:bv31;

// Header elem
var hdr.stack.5:Ref;
var hdr.stack.5.bos:bv1;
var hdr.stack.5.value:bv31;

// Header elem
var hdr.stack.6:Ref;
var hdr.stack.6.bos:bv1;
var hdr.stack.6.value:bv31;

// Header elem
var hdr.stack.7:Ref;
var hdr.stack.7.bos:bv1;
var hdr.stack.7.value:bv31;

// Header elem
var hdr.stack.8:Ref;
var hdr.stack.8.bos:bv1;
var hdr.stack.8.value:bv31;

// Header elem
var hdr.stack.9:Ref;
var hdr.stack.9.bos:bv1;
var hdr.stack.9.value:bv31;

// Header elem
var hdr.stack.10:Ref;
var hdr.stack.10.bos:bv1;
var hdr.stack.10.value:bv31;

// Header elem
var hdr.stack.11:Ref;
var hdr.stack.11.bos:bv1;
var hdr.stack.11.value:bv31;

// Header elem
var hdr.stack.12:Ref;
var hdr.stack.12.bos:bv1;
var hdr.stack.12.value:bv31;

// Header elem
var hdr.stack.13:Ref;
var hdr.stack.13.bos:bv1;
var hdr.stack.13.value:bv31;

// Header elem
var hdr.stack.14:Ref;
var hdr.stack.14.bos:bv1;
var hdr.stack.14.value:bv31;

// Header elem
var hdr.stack.15:Ref;
var hdr.stack.15.bos:bv1;
var hdr.stack.15.value:bv31;

// Header elem
var hdr.stack.16:Ref;
var hdr.stack.16.bos:bv1;
var hdr.stack.16.value:bv31;

// Header elem
var hdr.stack.17:Ref;
var hdr.stack.17.bos:bv1;
var hdr.stack.17.value:bv31;

// Header elem
var hdr.stack.18:Ref;
var hdr.stack.18.bos:bv1;
var hdr.stack.18.value:bv31;

// Header elem
var hdr.stack.19:Ref;
var hdr.stack.19.bos:bv1;
var hdr.stack.19.value:bv31;

// Header elem
var hdr.stack.20:Ref;
var hdr.stack.20.bos:bv1;
var hdr.stack.20.value:bv31;

// Header elem
var hdr.stack.21:Ref;
var hdr.stack.21.bos:bv1;
var hdr.stack.21.value:bv31;

// Header elem
var hdr.stack.22:Ref;
var hdr.stack.22.bos:bv1;
var hdr.stack.22.value:bv31;

// Header elem
var hdr.stack.23:Ref;
var hdr.stack.23.bos:bv1;
var hdr.stack.23.value:bv31;

// Header elem
var hdr.stack.24:Ref;
var hdr.stack.24.bos:bv1;
var hdr.stack.24.value:bv31;

// Header elem
var hdr.stack.25:Ref;
var hdr.stack.25.bos:bv1;
var hdr.stack.25.value:bv31;

// Header elem
var hdr.stack.26:Ref;
var hdr.stack.26.bos:bv1;
var hdr.stack.26.value:bv31;

// Header elem
var hdr.stack.27:Ref;
var hdr.stack.27.bos:bv1;
var hdr.stack.27.value:bv31;

// Header elem
var hdr.stack.28:Ref;
var hdr.stack.28.bos:bv1;
var hdr.stack.28.value:bv31;

// Header elem
var hdr.stack.29:Ref;
var hdr.stack.29.bos:bv1;
var hdr.stack.29.value:bv31;

// Header elem
var hdr.stack.30:Ref;
var hdr.stack.30.bos:bv1;
var hdr.stack.30.value:bv31;

// Header elem
var hdr.stack.31:Ref;
var hdr.stack.31.bos:bv1;
var hdr.stack.31.value:bv31;

// Header elem
var hdr.stack.32:Ref;
var hdr.stack.32.bos:bv1;
var hdr.stack.32.value:bv31;

// Header elem
var hdr.stack.33:Ref;
var hdr.stack.33.bos:bv1;
var hdr.stack.33.value:bv31;

// Header elem
var hdr.stack.34:Ref;
var hdr.stack.34.bos:bv1;
var hdr.stack.34.value:bv31;

// Header elem
var hdr.stack.35:Ref;
var hdr.stack.35.bos:bv1;
var hdr.stack.35.value:bv31;

// Header elem
var hdr.stack.36:Ref;
var hdr.stack.36.bos:bv1;
var hdr.stack.36.value:bv31;

// Header elem
var hdr.stack.37:Ref;
var hdr.stack.37.bos:bv1;
var hdr.stack.37.value:bv31;

// Header elem
var hdr.stack.38:Ref;
var hdr.stack.38.bos:bv1;
var hdr.stack.38.value:bv31;

// Header elem
var hdr.stack.39:Ref;
var hdr.stack.39.bos:bv1;
var hdr.stack.39.value:bv31;

// Header elem
var hdr.stack.40:Ref;
var hdr.stack.40.bos:bv1;
var hdr.stack.40.value:bv31;

// Header elem
var hdr.stack.41:Ref;
var hdr.stack.41.bos:bv1;
var hdr.stack.41.value:bv31;

// Header elem
var hdr.stack.42:Ref;
var hdr.stack.42.bos:bv1;
var hdr.stack.42.value:bv31;

// Header elem
var hdr.stack.43:Ref;
var hdr.stack.43.bos:bv1;
var hdr.stack.43.value:bv31;

// Header elem
var hdr.stack.44:Ref;
var hdr.stack.44.bos:bv1;
var hdr.stack.44.value:bv31;

// Header elem
var hdr.stack.45:Ref;
var hdr.stack.45.bos:bv1;
var hdr.stack.45.value:bv31;

// Header elem
var hdr.stack.46:Ref;
var hdr.stack.46.bos:bv1;
var hdr.stack.46.value:bv31;

// Header elem
var hdr.stack.47:Ref;
var hdr.stack.47.bos:bv1;
var hdr.stack.47.value:bv31;

// Header elem
var hdr.stack.48:Ref;
var hdr.stack.48.bos:bv1;
var hdr.stack.48.value:bv31;

// Header elem
var hdr.stack.49:Ref;
var hdr.stack.49.bos:bv1;
var hdr.stack.49.value:bv31;

// Header elem
var hdr.stack.50:Ref;
var hdr.stack.50.bos:bv1;
var hdr.stack.50.value:bv31;

// Header elem
var hdr.stack.51:Ref;
var hdr.stack.51.bos:bv1;
var hdr.stack.51.value:bv31;

// Header elem
var hdr.stack.52:Ref;
var hdr.stack.52.bos:bv1;
var hdr.stack.52.value:bv31;

// Header elem
var hdr.stack.53:Ref;
var hdr.stack.53.bos:bv1;
var hdr.stack.53.value:bv31;

// Header elem
var hdr.stack.54:Ref;
var hdr.stack.54.bos:bv1;
var hdr.stack.54.value:bv31;

// Header elem
var hdr.stack.55:Ref;
var hdr.stack.55.bos:bv1;
var hdr.stack.55.value:bv31;

// Header elem
var hdr.stack.56:Ref;
var hdr.stack.56.bos:bv1;
var hdr.stack.56.value:bv31;

// Header elem
var hdr.stack.57:Ref;
var hdr.stack.57.bos:bv1;
var hdr.stack.57.value:bv31;

// Header elem
var hdr.stack.58:Ref;
var hdr.stack.58.bos:bv1;
var hdr.stack.58.value:bv31;

// Header elem
var hdr.stack.59:Ref;
var hdr.stack.59.bos:bv1;
var hdr.stack.59.value:bv31;

// Header elem
var hdr.stack.60:Ref;
var hdr.stack.60.bos:bv1;
var hdr.stack.60.value:bv31;

// Header elem
var hdr.stack.61:Ref;
var hdr.stack.61.bos:bv1;
var hdr.stack.61.value:bv31;

// Header elem
var hdr.stack.62:Ref;
var hdr.stack.62.bos:bv1;
var hdr.stack.62.value:bv31;

// Header elem
var hdr.stack.63:Ref;
var hdr.stack.63.bos:bv1;
var hdr.stack.63.value:bv31;

// Header elem
var hdr.stack.64:Ref;
var hdr.stack.64.bos:bv1;
var hdr.stack.64.value:bv31;

// Header elem
var hdr.stack.65:Ref;
var hdr.stack.65.bos:bv1;
var hdr.stack.65.value:bv31;

// Header elem
var hdr.stack.66:Ref;
var hdr.stack.66.bos:bv1;
var hdr.stack.66.value:bv31;

// Header elem
var hdr.stack.67:Ref;
var hdr.stack.67.bos:bv1;
var hdr.stack.67.value:bv31;

// Header elem
var hdr.stack.68:Ref;
var hdr.stack.68.bos:bv1;
var hdr.stack.68.value:bv31;

// Header elem
var hdr.stack.69:Ref;
var hdr.stack.69.bos:bv1;
var hdr.stack.69.value:bv31;

// Header elem
var hdr.stack.70:Ref;
var hdr.stack.70.bos:bv1;
var hdr.stack.70.value:bv31;

// Header elem
var hdr.stack.71:Ref;
var hdr.stack.71.bos:bv1;
var hdr.stack.71.value:bv31;

// Header elem
var hdr.stack.72:Ref;
var hdr.stack.72.bos:bv1;
var hdr.stack.72.value:bv31;

// Header elem
var hdr.stack.73:Ref;
var hdr.stack.73.bos:bv1;
var hdr.stack.73.value:bv31;

// Header elem
var hdr.stack.74:Ref;
var hdr.stack.74.bos:bv1;
var hdr.stack.74.value:bv31;

// Header elem
var hdr.stack.75:Ref;
var hdr.stack.75.bos:bv1;
var hdr.stack.75.value:bv31;

// Header elem
var hdr.stack.76:Ref;
var hdr.stack.76.bos:bv1;
var hdr.stack.76.value:bv31;

// Header elem
var hdr.stack.77:Ref;
var hdr.stack.77.bos:bv1;
var hdr.stack.77.value:bv31;

// Header elem
var hdr.stack.78:Ref;
var hdr.stack.78.bos:bv1;
var hdr.stack.78.value:bv31;

// Header elem
var hdr.stack.79:Ref;
var hdr.stack.79.bos:bv1;
var hdr.stack.79.value:bv31;

// Header elem
var hdr.stack.80:Ref;
var hdr.stack.80.bos:bv1;
var hdr.stack.80.value:bv31;

// Header elem
var hdr.stack.81:Ref;
var hdr.stack.81.bos:bv1;
var hdr.stack.81.value:bv31;

// Header elem
var hdr.stack.82:Ref;
var hdr.stack.82.bos:bv1;
var hdr.stack.82.value:bv31;

// Header elem
var hdr.stack.83:Ref;
var hdr.stack.83.bos:bv1;
var hdr.stack.83.value:bv31;

// Header elem
var hdr.stack.84:Ref;
var hdr.stack.84.bos:bv1;
var hdr.stack.84.value:bv31;

// Header elem
var hdr.stack.85:Ref;
var hdr.stack.85.bos:bv1;
var hdr.stack.85.value:bv31;

// Header elem
var hdr.stack.86:Ref;
var hdr.stack.86.bos:bv1;
var hdr.stack.86.value:bv31;

// Header elem
var hdr.stack.87:Ref;
var hdr.stack.87.bos:bv1;
var hdr.stack.87.value:bv31;

// Header elem
var hdr.stack.88:Ref;
var hdr.stack.88.bos:bv1;
var hdr.stack.88.value:bv31;

// Header elem
var hdr.stack.89:Ref;
var hdr.stack.89.bos:bv1;
var hdr.stack.89.value:bv31;

// Header elem
var hdr.stack.90:Ref;
var hdr.stack.90.bos:bv1;
var hdr.stack.90.value:bv31;

// Header elem
var hdr.stack.91:Ref;
var hdr.stack.91.bos:bv1;
var hdr.stack.91.value:bv31;

// Header elem
var hdr.stack.92:Ref;
var hdr.stack.92.bos:bv1;
var hdr.stack.92.value:bv31;

// Header elem
var hdr.stack.93:Ref;
var hdr.stack.93.bos:bv1;
var hdr.stack.93.value:bv31;

// Header elem
var hdr.stack.94:Ref;
var hdr.stack.94.bos:bv1;
var hdr.stack.94.value:bv31;

// Header elem
var hdr.stack.95:Ref;
var hdr.stack.95.bos:bv1;
var hdr.stack.95.value:bv31;

// Header elem
var hdr.stack.96:Ref;
var hdr.stack.96.bos:bv1;
var hdr.stack.96.value:bv31;

// Header elem
var hdr.stack.97:Ref;
var hdr.stack.97.bos:bv1;
var hdr.stack.97.value:bv31;

// Header elem
var hdr.stack.98:Ref;
var hdr.stack.98.bos:bv1;
var hdr.stack.98.value:bv31;

// Header elem
var hdr.stack.99:Ref;
var hdr.stack.99.bos:bv1;
var hdr.stack.99.value:bv31;

// Control MyComputeChecksum
procedure {:inline 1} MyComputeChecksum()
{
}

// Control MyEgress
procedure {:inline 1} MyEgress()
{
}

// Control MyIngress
procedure {:inline 1} MyIngress()
	modifies hdr.stack.0.bos, hdr.stack.50.value;
{
    assert (0<100);
    hdr.stack.0.bos := 0bv1;
    assert (50<100);
    hdr.stack.50.value := 1000bv31;
}

// Parser MyParser
procedure {:inline 1} MyParser()
	modifies drop, isValid, meta.temp, stack.index;
{
    goto State$start;

        State$start:
    call packet_in.extract.headers.stack.next(hdr.stack);
    meta.temp := hdr.stack.last;
    goto State$accept;

    State$accept:
    call accept();
    goto Exit;

    State$reject:
    call reject();
    goto Exit;

    Exit:
}

// Control MyVerifyChecksum
procedure {:inline 1} MyVerifyChecksum()
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
	modifies drop, hdr.stack.0.bos, hdr.stack.50.value, isValid, meta.temp, stack.index;
{
    call MyParser();
    call MyVerifyChecksum();
    call MyIngress();
    call MyEgress();
    call MyComputeChecksum();
}
procedure mainProcedure()
	modifies drop, emit, forward, hdr.stack.0.bos, hdr.stack.50.value, isValid, meta.temp, stack.index;
{
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
procedure {:inline 1} packet_in.extract.headers.stack.next(stack:HeaderStack);
ensures(isValid[stack[stack.index[stack]]]==true && stack.index[stack]==old(stack.index[stack])+1);
	modifies isValid, stack.index;
procedure reject();
    ensures drop==true;
	modifies drop;
procedure {:inline 1} setInvalid(header:Ref);
    ensures (isValid[header] == false);
	modifies isValid;
procedure {:inline 1} setValid(header:Ref);
