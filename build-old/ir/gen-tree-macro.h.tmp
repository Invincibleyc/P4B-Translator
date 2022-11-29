#define IRNODE_ALL_SUBCLASSES_AND_DIRECT_AND_INDIRECT_BASES(M, T, D, B, ...) \
  M(Type, D(Node), ##__VA_ARGS__) \
    M(Type_Base, D(Type) B(Node), ##__VA_ARGS__) \
      M(Type_Unknown, D(Type_Base) B(Type) B(Node), ##__VA_ARGS__) \
  M(StatOrDecl, D(Node), ##__VA_ARGS__) \
    M(Declaration, D(StatOrDecl) B(Node), ##__VA_ARGS__) \
    M(Type_Declaration, D(Type) B(Node), ##__VA_ARGS__) \
  M(Expression, D(Node), ##__VA_ARGS__) \
    M(Operation, D(Expression) B(Node), ##__VA_ARGS__) \
  M(Path, D(Node), ##__VA_ARGS__) \
      M(NamedExpression, D(Declaration) B(StatOrDecl) B(Node), ##__VA_ARGS__) \
  M(AnnotationToken, D(Node), ##__VA_ARGS__) \
  M(Annotation, D(Node), ##__VA_ARGS__) \
  M(Annotations, D(Node), ##__VA_ARGS__) \
  M(Argument, D(Node), ##__VA_ARGS__) \
    M(Type_Type, D(Type) B(Node), ##__VA_ARGS__) \
      M(Type_Boolean, D(Type_Base) B(Type) B(Node), ##__VA_ARGS__) \
      M(Type_State, D(Type_Base) B(Type) B(Node), ##__VA_ARGS__) \
      M(Type_Bits, D(Type_Base) B(Type) B(Node), ##__VA_ARGS__) \
      M(Type_Varbits, D(Type_Base) B(Type) B(Node), ##__VA_ARGS__) \
      M(Parameter, D(Declaration) B(StatOrDecl) B(Node), ##__VA_ARGS__) \
  M(ParameterList, D(Node), ##__VA_ARGS__) \
      M(Type_Var, D(Type_Declaration) B(Type) B(Node), ##__VA_ARGS__) \
    M(Type_InfInt, D(Type) B(Node), ##__VA_ARGS__) \
      M(Type_Dontcare, D(Type_Base) B(Type) B(Node), ##__VA_ARGS__) \
      M(Type_Void, D(Type_Base) B(Type) B(Node), ##__VA_ARGS__) \
      M(Type_MatchKind, D(Type_Base) B(Type) B(Node), ##__VA_ARGS__) \
  M(TypeParameters, D(Node), ##__VA_ARGS__) \
      M(StructField, D(Declaration) B(StatOrDecl) B(Node), ##__VA_ARGS__) \
      M(Type_StructLike, D(Type_Declaration) B(Type) B(Node), ##__VA_ARGS__) \
        M(Type_Struct, D(Type_StructLike) B(Type_Declaration) B(Type) B(Node), ##__VA_ARGS__) \
        M(Type_UnknownStruct, D(Type_StructLike) B(Type_Declaration) B(Type) B(Node), ##__VA_ARGS__) \
        M(Type_HeaderUnion, D(Type_StructLike) B(Type_Declaration) B(Type) B(Node), ##__VA_ARGS__) \
        M(Type_Header, D(Type_StructLike) B(Type_Declaration) B(Type) B(Node), ##__VA_ARGS__) \
    M(Type_Set, D(Type) B(Node), ##__VA_ARGS__) \
    M(Type_BaseList, D(Type) B(Node), ##__VA_ARGS__) \
      M(Type_List, D(Type_BaseList) B(Type) B(Node), ##__VA_ARGS__) \
      M(Type_Tuple, D(Type_BaseList) B(Type) B(Node), ##__VA_ARGS__) \
      M(Type_ArchBlock, D(Type_Declaration) B(Type) B(Node), ##__VA_ARGS__) \
        M(Type_Package, D(Type_ArchBlock) B(Type_Declaration) B(Type) B(Node), ##__VA_ARGS__) \
        M(Type_Parser, D(Type_ArchBlock) B(Type_Declaration) B(Type) B(Node), ##__VA_ARGS__) \
        M(Type_Control, D(Type_ArchBlock) B(Type_Declaration) B(Type) B(Node), ##__VA_ARGS__) \
    M(Type_Name, D(Type) B(Node), ##__VA_ARGS__) \
    M(Type_Stack, D(Type) B(Node), ##__VA_ARGS__) \
    M(Type_Specialized, D(Type) B(Node), ##__VA_ARGS__) \
    M(Type_SpecializedCanonical, D(Type) B(Node), ##__VA_ARGS__) \
      M(Declaration_ID, D(Declaration) B(StatOrDecl) B(Node), ##__VA_ARGS__) \
      M(Type_String, D(Type_Base) B(Type) B(Node), ##__VA_ARGS__) \
      M(Type_Enum, D(Type_Declaration) B(Type) B(Node), ##__VA_ARGS__) \
      M(SerEnumMember, D(Declaration) B(StatOrDecl) B(Node), ##__VA_ARGS__) \
      M(Type_SerEnum, D(Type_Declaration) B(Type) B(Node), ##__VA_ARGS__) \
    M(Type_Table, D(Type) B(Node), ##__VA_ARGS__) \
    M(Type_ActionEnum, D(Type) B(Node), ##__VA_ARGS__) \
    M(Type_MethodBase, D(Type) B(Node), ##__VA_ARGS__) \
      M(Type_Method, D(Type_MethodBase) B(Type) B(Node), ##__VA_ARGS__) \
  M(ArgumentInfo, D(Node), ##__VA_ARGS__) \
    M(Type_MethodCall, D(Type) B(Node), ##__VA_ARGS__) \
      M(Type_Action, D(Type_MethodBase) B(Type) B(Node), ##__VA_ARGS__) \
      M(Method, D(Declaration) B(StatOrDecl) B(Node), ##__VA_ARGS__) \
      M(Type_Typedef, D(Type_Declaration) B(Type) B(Node), ##__VA_ARGS__) \
      M(Type_Newtype, D(Type_Declaration) B(Type) B(Node), ##__VA_ARGS__) \
      M(Type_Extern, D(Type_Declaration) B(Type) B(Node), ##__VA_ARGS__) \
      M(Operation_Unary, D(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
        M(Neg, D(Operation_Unary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
        M(Cmpl, D(Operation_Unary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
        M(LNot, D(Operation_Unary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
      M(Operation_Binary, D(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
      M(Operation_Ternary, D(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
        M(Operation_Relation, D(Operation_Binary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
        M(Mul, D(Operation_Binary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
        M(Div, D(Operation_Binary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
        M(Mod, D(Operation_Binary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
        M(Add, D(Operation_Binary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
        M(Sub, D(Operation_Binary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
        M(AddSat, D(Operation_Binary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
        M(SubSat, D(Operation_Binary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
        M(Shl, D(Operation_Binary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
        M(Shr, D(Operation_Binary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
          M(Equ, D(Operation_Relation) B(Operation_Binary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
          M(Neq, D(Operation_Relation) B(Operation_Binary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
          M(Lss, D(Operation_Relation) B(Operation_Binary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
          M(Leq, D(Operation_Relation) B(Operation_Binary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
          M(Grt, D(Operation_Relation) B(Operation_Binary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
          M(Geq, D(Operation_Relation) B(Operation_Binary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
        M(BAnd, D(Operation_Binary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
        M(BOr, D(Operation_Binary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
        M(BXor, D(Operation_Binary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
        M(LAnd, D(Operation_Binary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
        M(LOr, D(Operation_Binary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
    M(Literal, D(Expression) B(Node), ##__VA_ARGS__) \
      M(Constant, D(Literal) B(Expression) B(Node), ##__VA_ARGS__) \
      M(BoolLiteral, D(Literal) B(Expression) B(Node), ##__VA_ARGS__) \
      M(StringLiteral, D(Literal) B(Expression) B(Node), ##__VA_ARGS__) \
    M(PathExpression, D(Expression) B(Node), ##__VA_ARGS__) \
    M(TypeNameExpression, D(Expression) B(Node), ##__VA_ARGS__) \
        M(Slice, D(Operation_Ternary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
        M(Member, D(Operation_Unary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
        M(Concat, D(Operation_Binary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
        M(ArrayIndex, D(Operation_Binary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
        M(Range, D(Operation_Binary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
        M(Mask, D(Operation_Binary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
        M(Mux, D(Operation_Ternary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
    M(DefaultExpression, D(Expression) B(Node), ##__VA_ARGS__) \
    M(This, D(Expression) B(Node), ##__VA_ARGS__) \
        M(Cast, D(Operation_Unary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
  M(SelectCase, D(Node), ##__VA_ARGS__) \
    M(SelectExpression, D(Expression) B(Node), ##__VA_ARGS__) \
    M(MethodCallExpression, D(Expression) B(Node), ##__VA_ARGS__) \
    M(ConstructorCallExpression, D(Expression) B(Node), ##__VA_ARGS__) \
    M(ListExpression, D(Expression) B(Node), ##__VA_ARGS__) \
    M(StructExpression, D(Expression) B(Node), ##__VA_ARGS__) \
  M(ListCompileTimeValue, D(Node), ##__VA_ARGS__) \
      M(CompileTimeMethodCall, D(MethodCallExpression) B(Expression) B(Node), ##__VA_ARGS__) \
      M(ParserState, D(Declaration) B(StatOrDecl) B(Node), ##__VA_ARGS__) \
      M(P4Parser, D(Type_Declaration) B(Type) B(Node), ##__VA_ARGS__) \
      M(P4Control, D(Type_Declaration) B(Type) B(Node), ##__VA_ARGS__) \
      M(P4Action, D(Declaration) B(StatOrDecl) B(Node), ##__VA_ARGS__) \
      M(Type_Error, D(Type_Declaration) B(Type) B(Node), ##__VA_ARGS__) \
  M(Declaration_MatchKind, D(Node), ##__VA_ARGS__) \
  M(PropertyValue, D(Node), ##__VA_ARGS__) \
    M(ExpressionValue, D(PropertyValue) B(Node), ##__VA_ARGS__) \
    M(ExpressionListValue, D(PropertyValue) B(Node), ##__VA_ARGS__) \
  M(ActionListElement, D(Node), ##__VA_ARGS__) \
    M(ActionList, D(PropertyValue) B(Node), ##__VA_ARGS__) \
  M(KeyElement, D(Node), ##__VA_ARGS__) \
    M(Key, D(PropertyValue) B(Node), ##__VA_ARGS__) \
  M(Entry, D(Node), ##__VA_ARGS__) \
    M(EntriesList, D(PropertyValue) B(Node), ##__VA_ARGS__) \
      M(Property, D(Declaration) B(StatOrDecl) B(Node), ##__VA_ARGS__) \
  M(TableProperties, D(Node), ##__VA_ARGS__) \
      M(P4Table, D(Declaration) B(StatOrDecl) B(Node), ##__VA_ARGS__) \
      M(P4ValueSet, D(Declaration) B(StatOrDecl) B(Node), ##__VA_ARGS__) \
      M(Declaration_Variable, D(Declaration) B(StatOrDecl) B(Node), ##__VA_ARGS__) \
      M(Declaration_Constant, D(Declaration) B(StatOrDecl) B(Node), ##__VA_ARGS__) \
      M(Declaration_Instance, D(Declaration) B(StatOrDecl) B(Node), ##__VA_ARGS__) \
  M(P4Program, D(Node), ##__VA_ARGS__) \
    M(Statement, D(StatOrDecl) B(Node), ##__VA_ARGS__) \
      M(ExitStatement, D(Statement) B(StatOrDecl) B(Node), ##__VA_ARGS__) \
      M(ReturnStatement, D(Statement) B(StatOrDecl) B(Node), ##__VA_ARGS__) \
      M(EmptyStatement, D(Statement) B(StatOrDecl) B(Node), ##__VA_ARGS__) \
      M(AssignmentStatement, D(Statement) B(StatOrDecl) B(Node), ##__VA_ARGS__) \
      M(IfStatement, D(Statement) B(StatOrDecl) B(Node), ##__VA_ARGS__) \
      M(BlockStatement, D(Statement) B(StatOrDecl) B(Node), ##__VA_ARGS__) \
      M(MethodCallStatement, D(Statement) B(StatOrDecl) B(Node), ##__VA_ARGS__) \
  M(SwitchCase, D(Node), ##__VA_ARGS__) \
      M(SwitchStatement, D(Statement) B(StatOrDecl) B(Node), ##__VA_ARGS__) \
      M(Function, D(Declaration) B(StatOrDecl) B(Node), ##__VA_ARGS__) \
  M(Block, D(Node), ##__VA_ARGS__) \
    M(TableBlock, D(Block) B(Node), ##__VA_ARGS__) \
    M(InstantiatedBlock, D(Block) B(Node), ##__VA_ARGS__) \
      M(ParserBlock, D(InstantiatedBlock) B(Block) B(Node), ##__VA_ARGS__) \
      M(ControlBlock, D(InstantiatedBlock) B(Block) B(Node), ##__VA_ARGS__) \
      M(PackageBlock, D(InstantiatedBlock) B(Block) B(Node), ##__VA_ARGS__) \
      M(ExternBlock, D(InstantiatedBlock) B(Block) B(Node), ##__VA_ARGS__) \
    M(ToplevelBlock, D(Block) B(Node), ##__VA_ARGS__) \
      M(Type_Block, D(Type_Base) B(Type) B(Node), ##__VA_ARGS__) \
      M(Type_Counter, D(Type_Base) B(Type) B(Node), ##__VA_ARGS__) \
      M(Type_Expression, D(Type_Base) B(Type) B(Node), ##__VA_ARGS__) \
      M(Type_FieldListCalculation, D(Type_Base) B(Type) B(Node), ##__VA_ARGS__) \
      M(Type_Meter, D(Type_Base) B(Type) B(Node), ##__VA_ARGS__) \
      M(Type_Register, D(Type_Base) B(Type) B(Node), ##__VA_ARGS__) \
      M(Type_AnyTable, D(Type_Base) B(Type) B(Node), ##__VA_ARGS__) \
  M(HeaderOrMetadata, D(Node), ##__VA_ARGS__) \
    M(Header, D(HeaderOrMetadata) B(Node), ##__VA_ARGS__) \
    M(HeaderStack, D(HeaderOrMetadata) B(Node), ##__VA_ARGS__) \
    M(Metadata, D(HeaderOrMetadata) B(Node), ##__VA_ARGS__) \
    M(HeaderRef, D(Expression) B(Node), ##__VA_ARGS__) \
      M(ConcreteHeaderRef, D(HeaderRef) B(Expression) B(Node), ##__VA_ARGS__) \
      M(HeaderStackItemRef, D(HeaderRef) B(Expression) B(Node), ##__VA_ARGS__) \
    M(If, D(Expression) B(Node), ##__VA_ARGS__) \
      M(NamedCond, D(If) B(Expression) B(Node), ##__VA_ARGS__) \
    M(Apply, D(Expression) B(Node), ##__VA_ARGS__) \
      M(Primitive, D(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
  M(FieldList, D(Node), ##__VA_ARGS__) \
  M(FieldListCalculation, D(Node), ##__VA_ARGS__) \
  M(CalculatedField, D(Node), ##__VA_ARGS__) \
  M(ParserValueSet, D(Node), ##__VA_ARGS__) \
  M(CaseEntry, D(Node), ##__VA_ARGS__) \
  M(V1Parser, D(Node), ##__VA_ARGS__) \
  M(ParserException, D(Node), ##__VA_ARGS__) \
  M(Attached, D(Node), ##__VA_ARGS__) \
    M(Stateful, D(Attached) B(Node), ##__VA_ARGS__) \
      M(CounterOrMeter, D(Stateful) B(Attached) B(Node), ##__VA_ARGS__) \
        M(Counter, D(CounterOrMeter) B(Stateful) B(Attached) B(Node), ##__VA_ARGS__) \
        M(Meter, D(CounterOrMeter) B(Stateful) B(Attached) B(Node), ##__VA_ARGS__) \
      M(Register, D(Stateful) B(Attached) B(Node), ##__VA_ARGS__) \
  M(PrimitiveAction, D(Node), ##__VA_ARGS__) \
  M(NameList, D(Node), ##__VA_ARGS__) \
    M(ActionArg, D(Expression) B(Node), ##__VA_ARGS__) \
  M(ActionFunction, D(Node), ##__VA_ARGS__) \
    M(ActionProfile, D(Attached) B(Node), ##__VA_ARGS__) \
    M(ActionSelector, D(Attached) B(Node), ##__VA_ARGS__) \
  M(V1Table, D(Node), ##__VA_ARGS__) \
  M(V1Control, D(Node), ##__VA_ARGS__) \
    M(AttribLocal, D(Expression) B(Node), ##__VA_ARGS__) \
  M(AttribLocals, D(Node), ##__VA_ARGS__) \
      M(Attribute, D(Declaration) B(StatOrDecl) B(Node), ##__VA_ARGS__) \
    M(GlobalRef, D(Expression) B(Node), ##__VA_ARGS__) \
    M(AttributeRef, D(Expression) B(Node), ##__VA_ARGS__) \
  M(V1Program, D(Node), ##__VA_ARGS__) \
  M(DpdkDeclaration, D(Node), ##__VA_ARGS__) \
          M(DpdkHeaderType, D(Type_Header) B(Type_StructLike) B(Type_Declaration) B(Type) B(Node), ##__VA_ARGS__) \
          M(DpdkStructType, D(Type_Struct) B(Type_StructLike) B(Type_Declaration) B(Type) B(Node), ##__VA_ARGS__) \
  M(DpdkAsmStatement, D(Node), ##__VA_ARGS__) \
  M(DpdkAction, D(Node), ##__VA_ARGS__) \
  M(DpdkTable, D(Node), ##__VA_ARGS__) \
  M(DpdkAsmProgram, D(Node), ##__VA_ARGS__) \
    M(DpdkListStatement, D(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
    M(DpdkApplyStatement, D(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
    M(DpdkEmitStatement, D(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
    M(DpdkExtractStatement, D(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
    M(DpdkJmpStatement, D(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
      M(DpdkJmpLabelStatement, D(DpdkJmpStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
      M(DpdkJmpHitStatement, D(DpdkJmpStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
      M(DpdkJmpMissStatement, D(DpdkJmpStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
      M(DpdkJmpHeaderStatement, D(DpdkJmpStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkJmpIfInvalidStatement, D(DpdkJmpHeaderStatement) B(DpdkJmpStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkJmpIfValidStatement, D(DpdkJmpHeaderStatement) B(DpdkJmpStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
      M(DpdkJmpCondStatement, D(DpdkJmpStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkJmpEqualStatement, D(DpdkJmpCondStatement) B(DpdkJmpStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkJmpNotEqualStatement, D(DpdkJmpCondStatement) B(DpdkJmpStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkJmpGreaterEqualStatement, D(DpdkJmpCondStatement) B(DpdkJmpStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkJmpGreaterStatement, D(DpdkJmpCondStatement) B(DpdkJmpStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkJmpLessOrEqualStatement, D(DpdkJmpCondStatement) B(DpdkJmpStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkJmpLessStatement, D(DpdkJmpCondStatement) B(DpdkJmpStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
    M(DpdkRxStatement, D(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
    M(DpdkTxStatement, D(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
    M(DpdkAssignmentStatement, D(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
      M(DpdkUnaryStatement, D(DpdkAssignmentStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkMovStatement, D(DpdkUnaryStatement) B(DpdkAssignmentStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkNegStatement, D(DpdkUnaryStatement) B(DpdkAssignmentStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkCmplStatement, D(DpdkUnaryStatement) B(DpdkAssignmentStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkLNotStatement, D(DpdkUnaryStatement) B(DpdkAssignmentStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
      M(DpdkBinaryStatement, D(DpdkAssignmentStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkAddStatement, D(DpdkBinaryStatement) B(DpdkAssignmentStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkAndStatement, D(DpdkBinaryStatement) B(DpdkAssignmentStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkShlStatement, D(DpdkBinaryStatement) B(DpdkAssignmentStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkShrStatement, D(DpdkBinaryStatement) B(DpdkAssignmentStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkSubStatement, D(DpdkBinaryStatement) B(DpdkAssignmentStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkOrStatement, D(DpdkBinaryStatement) B(DpdkAssignmentStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkEquStatement, D(DpdkBinaryStatement) B(DpdkAssignmentStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkXorStatement, D(DpdkBinaryStatement) B(DpdkAssignmentStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkCmpStatement, D(DpdkBinaryStatement) B(DpdkAssignmentStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkLAndStatement, D(DpdkBinaryStatement) B(DpdkAssignmentStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkLeqStatement, D(DpdkBinaryStatement) B(DpdkAssignmentStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkLssStatement, D(DpdkBinaryStatement) B(DpdkAssignmentStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkGrtStatement, D(DpdkBinaryStatement) B(DpdkAssignmentStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkGeqStatement, D(DpdkBinaryStatement) B(DpdkAssignmentStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
        M(DpdkNeqStatement, D(DpdkBinaryStatement) B(DpdkAssignmentStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
    M(DpdkExternObjStatement, D(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
    M(DpdkExternFuncStatement, D(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
    M(DpdkReturnStatement, D(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
    M(DpdkLabelStatement, D(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
    M(DpdkChecksumAddStatement, D(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
    M(DpdkGetHashStatement, D(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
    M(DpdkGetChecksumStatement, D(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
    M(DpdkCastStatement, D(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
    M(DpdkVerifyStatement, D(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
    M(DpdkMeterExecuteStatement, D(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
    M(DpdkCounterCountStatement, D(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
      M(DpdkRegisterReadStatement, D(DpdkAssignmentStatement) B(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
    M(DpdkRegisterWriteStatement, D(DpdkAsmStatement) B(Node), ##__VA_ARGS__) \
  M(v1HeaderType, D(Node), ##__VA_ARGS__) \
        M(IntMod, D(Operation_Unary) B(Operation) B(Expression) B(Node), ##__VA_ARGS__) \
T(Vector<IR::Node>, D(Node), ##__VA_ARGS__) \
T(IndexedVector<IR::Node>, D(Vector<IR::Node>) B(Node), ##__VA_ARGS__) \
T(Vector<IR::Type>, D(Node), ##__VA_ARGS__) \
T(Vector<IR::StatOrDecl>, D(Node), ##__VA_ARGS__) \
T(IndexedVector<IR::StatOrDecl>, D(Vector<IR::StatOrDecl>) B(Node), ##__VA_ARGS__) \
T(Vector<IR::Declaration>, D(Node), ##__VA_ARGS__) \
T(IndexedVector<IR::Declaration>, D(Vector<IR::Declaration>) B(Node), ##__VA_ARGS__) \
T(Vector<IR::Expression>, D(Node), ##__VA_ARGS__) \
T(Vector<IR::NamedExpression>, D(Node), ##__VA_ARGS__) \
T(IndexedVector<IR::NamedExpression>, D(Vector<IR::NamedExpression>) B(Node), ##__VA_ARGS__) \
T(Vector<IR::AnnotationToken>, D(Node), ##__VA_ARGS__) \
T(Vector<IR::Annotation>, D(Node), ##__VA_ARGS__) \
T(Vector<IR::Argument>, D(Node), ##__VA_ARGS__) \
T(Vector<IR::Parameter>, D(Node), ##__VA_ARGS__) \
T(IndexedVector<IR::Parameter>, D(Vector<IR::Parameter>) B(Node), ##__VA_ARGS__) \
T(Vector<IR::Type_Var>, D(Node), ##__VA_ARGS__) \
T(IndexedVector<IR::Type_Var>, D(Vector<IR::Type_Var>) B(Node), ##__VA_ARGS__) \
T(Vector<IR::StructField>, D(Node), ##__VA_ARGS__) \
T(IndexedVector<IR::StructField>, D(Vector<IR::StructField>) B(Node), ##__VA_ARGS__) \
T(Vector<IR::Declaration_ID>, D(Node), ##__VA_ARGS__) \
T(IndexedVector<IR::Declaration_ID>, D(Vector<IR::Declaration_ID>) B(Node), ##__VA_ARGS__) \
T(Vector<IR::SerEnumMember>, D(Node), ##__VA_ARGS__) \
T(IndexedVector<IR::SerEnumMember>, D(Vector<IR::SerEnumMember>) B(Node), ##__VA_ARGS__) \
T(Vector<IR::ArgumentInfo>, D(Node), ##__VA_ARGS__) \
T(Vector<IR::Method>, D(Node), ##__VA_ARGS__) \
T(Vector<IR::SelectCase>, D(Node), ##__VA_ARGS__) \
T(Vector<IR::ParserState>, D(Node), ##__VA_ARGS__) \
T(IndexedVector<IR::ParserState>, D(Vector<IR::ParserState>) B(Node), ##__VA_ARGS__) \
T(Vector<IR::ActionListElement>, D(Node), ##__VA_ARGS__) \
T(IndexedVector<IR::ActionListElement>, D(Vector<IR::ActionListElement>) B(Node), ##__VA_ARGS__) \
T(Vector<IR::KeyElement>, D(Node), ##__VA_ARGS__) \
T(Vector<IR::Entry>, D(Node), ##__VA_ARGS__) \
T(Vector<IR::Property>, D(Node), ##__VA_ARGS__) \
T(IndexedVector<IR::Property>, D(Vector<IR::Property>) B(Node), ##__VA_ARGS__) \
T(Vector<IR::SwitchCase>, D(Node), ##__VA_ARGS__) \
T(Vector<IR::Primitive>, D(Node), ##__VA_ARGS__) \
T(Vector<IR::CaseEntry>, D(Node), ##__VA_ARGS__) \
T(Vector<IR::DpdkDeclaration>, D(Node), ##__VA_ARGS__) \
T(IndexedVector<IR::DpdkDeclaration>, D(Vector<IR::DpdkDeclaration>) B(Node), ##__VA_ARGS__) \
T(Vector<IR::DpdkHeaderType>, D(Node), ##__VA_ARGS__) \
T(IndexedVector<IR::DpdkHeaderType>, D(Vector<IR::DpdkHeaderType>) B(Node), ##__VA_ARGS__) \
T(Vector<IR::DpdkStructType>, D(Node), ##__VA_ARGS__) \
T(IndexedVector<IR::DpdkStructType>, D(Vector<IR::DpdkStructType>) B(Node), ##__VA_ARGS__) \
T(Vector<IR::DpdkAsmStatement>, D(Node), ##__VA_ARGS__) \
T(IndexedVector<IR::DpdkAsmStatement>, D(Vector<IR::DpdkAsmStatement>) B(Node), ##__VA_ARGS__) \
T(Vector<IR::DpdkAction>, D(Node), ##__VA_ARGS__) \
T(IndexedVector<IR::DpdkAction>, D(Vector<IR::DpdkAction>) B(Node), ##__VA_ARGS__) \
T(Vector<IR::DpdkTable>, D(Node), ##__VA_ARGS__) \
T(IndexedVector<IR::DpdkTable>, D(Vector<IR::DpdkTable>) B(Node), ##__VA_ARGS__) \

namespace IR {
class CompileTimeValue;
class Type;
class IMayBeGenericType;
class IApply;
class INamespace;
class ISimpleNamespace;
class IGeneralNamespace;
class INestedNamespace;
class IFunctional;
class ITypeVar;
class IContainer;
class Type_Base;
class Type_Unknown;
class StatOrDecl;
class Declaration;
class Type_Declaration;
class Expression;
class Operation;
class Path;
class NamedExpression;
class AnnotationToken;
class Annotation;
class Annotations;
class IAnnotated;
class IInstance;
class Argument;
class Type_Type;
class Type_Boolean;
class Type_State;
class Type_Bits;
class Type_Varbits;
class Parameter;
class ParameterList;
class Type_Var;
class Type_InfInt;
class Type_Dontcare;
class Type_Void;
class Type_MatchKind;
class TypeParameters;
class StructField;
class Type_StructLike;
class Type_Struct;
class Type_UnknownStruct;
class Type_HeaderUnion;
class Type_Header;
class Type_Set;
class Type_BaseList;
class Type_List;
class Type_Tuple;
class Type_ArchBlock;
class Type_Package;
class Type_Parser;
class Type_Control;
class Type_Name;
class Type_Stack;
class Type_Specialized;
class Type_SpecializedCanonical;
class Declaration_ID;
class Type_String;
class Type_Enum;
class SerEnumMember;
class Type_SerEnum;
class Type_Table;
class Type_ActionEnum;
class Type_MethodBase;
class Type_Method;
class ArgumentInfo;
class Type_MethodCall;
class Type_Action;
class Method;
class Type_Typedef;
class Type_Newtype;
class Type_Extern;
class Operation_Unary;
class Neg;
class Cmpl;
class LNot;
class Operation_Binary;
class Operation_Ternary;
class Operation_Relation;
class Mul;
class Div;
class Mod;
class Add;
class Sub;
class AddSat;
class SubSat;
class Shl;
class Shr;
class Equ;
class Neq;
class Lss;
class Leq;
class Grt;
class Geq;
class BAnd;
class BOr;
class BXor;
class LAnd;
class LOr;
class Literal;
class Constant;
class BoolLiteral;
class StringLiteral;
class PathExpression;
class TypeNameExpression;
class Slice;
class Member;
class Concat;
class ArrayIndex;
class Range;
class Mask;
class Mux;
class DefaultExpression;
class This;
class Cast;
class SelectCase;
class SelectExpression;
class MethodCallExpression;
class ConstructorCallExpression;
class ListExpression;
class StructExpression;
class ListCompileTimeValue;
class CompileTimeMethodCall;
class ParserState;
class P4Parser;
class P4Control;
class P4Action;
class Type_Error;
class Declaration_MatchKind;
class PropertyValue;
class ExpressionValue;
class ExpressionListValue;
class ActionListElement;
class ActionList;
class KeyElement;
class Key;
class Entry;
class EntriesList;
class Property;
class TableProperties;
class P4Table;
class P4ValueSet;
class Declaration_Variable;
class Declaration_Constant;
class Declaration_Instance;
class P4Program;
class Statement;
class ExitStatement;
class ReturnStatement;
class EmptyStatement;
class AssignmentStatement;
class IfStatement;
class BlockStatement;
class MethodCallStatement;
class SwitchCase;
class SwitchStatement;
class Function;
class Block;
class TableBlock;
class InstantiatedBlock;
class ParserBlock;
class ControlBlock;
class PackageBlock;
class ExternBlock;
class ToplevelBlock;
class Type_Block;
class Type_Counter;
class Type_Expression;
class Type_FieldListCalculation;
class Type_Meter;
class Type_Register;
class Type_AnyTable;
class HeaderOrMetadata;
class Header;
class HeaderStack;
class Metadata;
class HeaderRef;
class ConcreteHeaderRef;
class HeaderStackItemRef;
class If;
class NamedCond;
class Apply;
class Primitive;
class FieldList;
class FieldListCalculation;
class CalculatedField;
class ParserValueSet;
class CaseEntry;
class V1Parser;
class ParserException;
class Attached;
class Stateful;
class CounterOrMeter;
class Counter;
class Meter;
class Register;
class PrimitiveAction;
class NameList;
class ActionArg;
class ActionFunction;
class ActionProfile;
class ActionSelector;
class V1Table;
class V1Control;
class AttribLocal;
class AttribLocals;
class Attribute;
class GlobalRef;
class AttributeRef;
class V1Program;
class IDPDKNode;
class DpdkDeclaration;
class DpdkHeaderType;
class DpdkStructType;
class DpdkAsmStatement;
class DpdkAction;
class DpdkTable;
class DpdkAsmProgram;
class DpdkListStatement;
class DpdkApplyStatement;
class DpdkEmitStatement;
class DpdkExtractStatement;
class DpdkJmpStatement;
class DpdkJmpLabelStatement;
class DpdkJmpHitStatement;
class DpdkJmpMissStatement;
class DpdkJmpHeaderStatement;
class DpdkJmpIfInvalidStatement;
class DpdkJmpIfValidStatement;
class DpdkJmpCondStatement;
class DpdkJmpEqualStatement;
class DpdkJmpNotEqualStatement;
class DpdkJmpGreaterEqualStatement;
class DpdkJmpGreaterStatement;
class DpdkJmpLessOrEqualStatement;
class DpdkJmpLessStatement;
class DpdkRxStatement;
class DpdkTxStatement;
class DpdkAssignmentStatement;
class DpdkUnaryStatement;
class DpdkMovStatement;
class DpdkNegStatement;
class DpdkCmplStatement;
class DpdkLNotStatement;
class DpdkBinaryStatement;
class DpdkAddStatement;
class DpdkAndStatement;
class DpdkShlStatement;
class DpdkShrStatement;
class DpdkSubStatement;
class DpdkOrStatement;
class DpdkEquStatement;
class DpdkXorStatement;
class DpdkCmpStatement;
class DpdkLAndStatement;
class DpdkLeqStatement;
class DpdkLssStatement;
class DpdkGrtStatement;
class DpdkGeqStatement;
class DpdkNeqStatement;
class DpdkExternObjStatement;
class DpdkExternFuncStatement;
class DpdkReturnStatement;
class DpdkLabelStatement;
class DpdkChecksumAddStatement;
class DpdkGetHashStatement;
class DpdkGetChecksumStatement;
class DpdkCastStatement;
class DpdkVerifyStatement;
class DpdkMeterExecuteStatement;
class DpdkCounterCountStatement;
class DpdkRegisterReadStatement;
class DpdkRegisterWriteStatement;
class v1HeaderType;
class IntMod;
}  // namespace IR
