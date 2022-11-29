#include "ir/ir.h"
#include "ir/visitor.h"
#include "ir/json_loader.h"

std::map<cstring, NodeFactoryFn> IR::unpacker_table = {
{"Type_Unknown", NodeFactoryFn(&IR::Type_Unknown::fromJSON)},
{"Path", NodeFactoryFn(&IR::Path::fromJSON)},
{"NamedExpression", NodeFactoryFn(&IR::NamedExpression::fromJSON)},
{"AnnotationToken", NodeFactoryFn(&IR::AnnotationToken::fromJSON)},
{"Annotation", NodeFactoryFn(&IR::Annotation::fromJSON)},
{"Annotations", NodeFactoryFn(&IR::Annotations::fromJSON)},
{"Argument", NodeFactoryFn(&IR::Argument::fromJSON)},
{"Type_Type", NodeFactoryFn(&IR::Type_Type::fromJSON)},
{"Type_Boolean", NodeFactoryFn(&IR::Type_Boolean::fromJSON)},
{"Type_State", NodeFactoryFn(&IR::Type_State::fromJSON)},
{"Type_Bits", NodeFactoryFn(&IR::Type_Bits::fromJSON)},
{"Type_Varbits", NodeFactoryFn(&IR::Type_Varbits::fromJSON)},
{"Parameter", NodeFactoryFn(&IR::Parameter::fromJSON)},
{"ParameterList", NodeFactoryFn(&IR::ParameterList::fromJSON)},
{"Type_Var", NodeFactoryFn(&IR::Type_Var::fromJSON)},
{"Type_InfInt", NodeFactoryFn(&IR::Type_InfInt::fromJSON)},
{"Type_Dontcare", NodeFactoryFn(&IR::Type_Dontcare::fromJSON)},
{"Type_Void", NodeFactoryFn(&IR::Type_Void::fromJSON)},
{"Type_MatchKind", NodeFactoryFn(&IR::Type_MatchKind::fromJSON)},
{"TypeParameters", NodeFactoryFn(&IR::TypeParameters::fromJSON)},
{"StructField", NodeFactoryFn(&IR::StructField::fromJSON)},
{"Type_Struct", NodeFactoryFn(&IR::Type_Struct::fromJSON)},
{"Type_UnknownStruct", NodeFactoryFn(&IR::Type_UnknownStruct::fromJSON)},
{"Type_HeaderUnion", NodeFactoryFn(&IR::Type_HeaderUnion::fromJSON)},
{"Type_Header", NodeFactoryFn(&IR::Type_Header::fromJSON)},
{"Type_Set", NodeFactoryFn(&IR::Type_Set::fromJSON)},
{"Type_List", NodeFactoryFn(&IR::Type_List::fromJSON)},
{"Type_Tuple", NodeFactoryFn(&IR::Type_Tuple::fromJSON)},
{"Type_Package", NodeFactoryFn(&IR::Type_Package::fromJSON)},
{"Type_Parser", NodeFactoryFn(&IR::Type_Parser::fromJSON)},
{"Type_Control", NodeFactoryFn(&IR::Type_Control::fromJSON)},
{"Type_Name", NodeFactoryFn(&IR::Type_Name::fromJSON)},
{"Type_Stack", NodeFactoryFn(&IR::Type_Stack::fromJSON)},
{"Type_Specialized", NodeFactoryFn(&IR::Type_Specialized::fromJSON)},
{"Type_SpecializedCanonical", NodeFactoryFn(&IR::Type_SpecializedCanonical::fromJSON)},
{"Declaration_ID", NodeFactoryFn(&IR::Declaration_ID::fromJSON)},
{"Type_String", NodeFactoryFn(&IR::Type_String::fromJSON)},
{"Type_Enum", NodeFactoryFn(&IR::Type_Enum::fromJSON)},
{"SerEnumMember", NodeFactoryFn(&IR::SerEnumMember::fromJSON)},
{"Type_SerEnum", NodeFactoryFn(&IR::Type_SerEnum::fromJSON)},
{"Type_Table", NodeFactoryFn(&IR::Type_Table::fromJSON)},
{"Type_ActionEnum", NodeFactoryFn(&IR::Type_ActionEnum::fromJSON)},
{"Type_Method", NodeFactoryFn(&IR::Type_Method::fromJSON)},
{"ArgumentInfo", NodeFactoryFn(&IR::ArgumentInfo::fromJSON)},
{"Type_MethodCall", NodeFactoryFn(&IR::Type_MethodCall::fromJSON)},
{"Type_Action", NodeFactoryFn(&IR::Type_Action::fromJSON)},
{"Method", NodeFactoryFn(&IR::Method::fromJSON)},
{"Type_Typedef", NodeFactoryFn(&IR::Type_Typedef::fromJSON)},
{"Type_Newtype", NodeFactoryFn(&IR::Type_Newtype::fromJSON)},
{"Type_Extern", NodeFactoryFn(&IR::Type_Extern::fromJSON)},
{"Neg", NodeFactoryFn(&IR::Neg::fromJSON)},
{"Cmpl", NodeFactoryFn(&IR::Cmpl::fromJSON)},
{"LNot", NodeFactoryFn(&IR::LNot::fromJSON)},
{"Mul", NodeFactoryFn(&IR::Mul::fromJSON)},
{"Div", NodeFactoryFn(&IR::Div::fromJSON)},
{"Mod", NodeFactoryFn(&IR::Mod::fromJSON)},
{"Add", NodeFactoryFn(&IR::Add::fromJSON)},
{"Sub", NodeFactoryFn(&IR::Sub::fromJSON)},
{"AddSat", NodeFactoryFn(&IR::AddSat::fromJSON)},
{"SubSat", NodeFactoryFn(&IR::SubSat::fromJSON)},
{"Shl", NodeFactoryFn(&IR::Shl::fromJSON)},
{"Shr", NodeFactoryFn(&IR::Shr::fromJSON)},
{"Equ", NodeFactoryFn(&IR::Equ::fromJSON)},
{"Neq", NodeFactoryFn(&IR::Neq::fromJSON)},
{"Lss", NodeFactoryFn(&IR::Lss::fromJSON)},
{"Leq", NodeFactoryFn(&IR::Leq::fromJSON)},
{"Grt", NodeFactoryFn(&IR::Grt::fromJSON)},
{"Geq", NodeFactoryFn(&IR::Geq::fromJSON)},
{"BAnd", NodeFactoryFn(&IR::BAnd::fromJSON)},
{"BOr", NodeFactoryFn(&IR::BOr::fromJSON)},
{"BXor", NodeFactoryFn(&IR::BXor::fromJSON)},
{"LAnd", NodeFactoryFn(&IR::LAnd::fromJSON)},
{"LOr", NodeFactoryFn(&IR::LOr::fromJSON)},
{"Constant", NodeFactoryFn(&IR::Constant::fromJSON)},
{"BoolLiteral", NodeFactoryFn(&IR::BoolLiteral::fromJSON)},
{"StringLiteral", NodeFactoryFn(&IR::StringLiteral::fromJSON)},
{"PathExpression", NodeFactoryFn(&IR::PathExpression::fromJSON)},
{"TypeNameExpression", NodeFactoryFn(&IR::TypeNameExpression::fromJSON)},
{"Slice", NodeFactoryFn(&IR::Slice::fromJSON)},
{"Member", NodeFactoryFn(&IR::Member::fromJSON)},
{"Concat", NodeFactoryFn(&IR::Concat::fromJSON)},
{"ArrayIndex", NodeFactoryFn(&IR::ArrayIndex::fromJSON)},
{"Range", NodeFactoryFn(&IR::Range::fromJSON)},
{"Mask", NodeFactoryFn(&IR::Mask::fromJSON)},
{"Mux", NodeFactoryFn(&IR::Mux::fromJSON)},
{"DefaultExpression", NodeFactoryFn(&IR::DefaultExpression::fromJSON)},
{"This", NodeFactoryFn(&IR::This::fromJSON)},
{"Cast", NodeFactoryFn(&IR::Cast::fromJSON)},
{"SelectCase", NodeFactoryFn(&IR::SelectCase::fromJSON)},
{"SelectExpression", NodeFactoryFn(&IR::SelectExpression::fromJSON)},
{"MethodCallExpression", NodeFactoryFn(&IR::MethodCallExpression::fromJSON)},
{"ConstructorCallExpression", NodeFactoryFn(&IR::ConstructorCallExpression::fromJSON)},
{"ListExpression", NodeFactoryFn(&IR::ListExpression::fromJSON)},
{"StructExpression", NodeFactoryFn(&IR::StructExpression::fromJSON)},
{"ListCompileTimeValue", NodeFactoryFn(&IR::ListCompileTimeValue::fromJSON)},
{"CompileTimeMethodCall", NodeFactoryFn(&IR::CompileTimeMethodCall::fromJSON)},
{"ParserState", NodeFactoryFn(&IR::ParserState::fromJSON)},
{"P4Parser", NodeFactoryFn(&IR::P4Parser::fromJSON)},
{"P4Control", NodeFactoryFn(&IR::P4Control::fromJSON)},
{"P4Action", NodeFactoryFn(&IR::P4Action::fromJSON)},
{"Type_Error", NodeFactoryFn(&IR::Type_Error::fromJSON)},
{"Declaration_MatchKind", NodeFactoryFn(&IR::Declaration_MatchKind::fromJSON)},
{"ExpressionValue", NodeFactoryFn(&IR::ExpressionValue::fromJSON)},
{"ExpressionListValue", NodeFactoryFn(&IR::ExpressionListValue::fromJSON)},
{"ActionListElement", NodeFactoryFn(&IR::ActionListElement::fromJSON)},
{"ActionList", NodeFactoryFn(&IR::ActionList::fromJSON)},
{"KeyElement", NodeFactoryFn(&IR::KeyElement::fromJSON)},
{"Key", NodeFactoryFn(&IR::Key::fromJSON)},
{"Entry", NodeFactoryFn(&IR::Entry::fromJSON)},
{"EntriesList", NodeFactoryFn(&IR::EntriesList::fromJSON)},
{"Property", NodeFactoryFn(&IR::Property::fromJSON)},
{"TableProperties", NodeFactoryFn(&IR::TableProperties::fromJSON)},
{"P4Table", NodeFactoryFn(&IR::P4Table::fromJSON)},
{"P4ValueSet", NodeFactoryFn(&IR::P4ValueSet::fromJSON)},
{"Declaration_Variable", NodeFactoryFn(&IR::Declaration_Variable::fromJSON)},
{"Declaration_Constant", NodeFactoryFn(&IR::Declaration_Constant::fromJSON)},
{"Declaration_Instance", NodeFactoryFn(&IR::Declaration_Instance::fromJSON)},
{"P4Program", NodeFactoryFn(&IR::P4Program::fromJSON)},
{"ExitStatement", NodeFactoryFn(&IR::ExitStatement::fromJSON)},
{"ReturnStatement", NodeFactoryFn(&IR::ReturnStatement::fromJSON)},
{"EmptyStatement", NodeFactoryFn(&IR::EmptyStatement::fromJSON)},
{"AssignmentStatement", NodeFactoryFn(&IR::AssignmentStatement::fromJSON)},
{"IfStatement", NodeFactoryFn(&IR::IfStatement::fromJSON)},
{"BlockStatement", NodeFactoryFn(&IR::BlockStatement::fromJSON)},
{"MethodCallStatement", NodeFactoryFn(&IR::MethodCallStatement::fromJSON)},
{"SwitchCase", NodeFactoryFn(&IR::SwitchCase::fromJSON)},
{"SwitchStatement", NodeFactoryFn(&IR::SwitchStatement::fromJSON)},
{"Function", NodeFactoryFn(&IR::Function::fromJSON)},
{"TableBlock", NodeFactoryFn(&IR::TableBlock::fromJSON)},
{"ParserBlock", NodeFactoryFn(&IR::ParserBlock::fromJSON)},
{"ControlBlock", NodeFactoryFn(&IR::ControlBlock::fromJSON)},
{"PackageBlock", NodeFactoryFn(&IR::PackageBlock::fromJSON)},
{"ExternBlock", NodeFactoryFn(&IR::ExternBlock::fromJSON)},
{"ToplevelBlock", NodeFactoryFn(&IR::ToplevelBlock::fromJSON)},
{"Type_Block", NodeFactoryFn(&IR::Type_Block::fromJSON)},
{"Type_Counter", NodeFactoryFn(&IR::Type_Counter::fromJSON)},
{"Type_Expression", NodeFactoryFn(&IR::Type_Expression::fromJSON)},
{"Type_FieldListCalculation", NodeFactoryFn(&IR::Type_FieldListCalculation::fromJSON)},
{"Type_Meter", NodeFactoryFn(&IR::Type_Meter::fromJSON)},
{"Type_Register", NodeFactoryFn(&IR::Type_Register::fromJSON)},
{"Type_AnyTable", NodeFactoryFn(&IR::Type_AnyTable::fromJSON)},
{"Header", NodeFactoryFn(&IR::Header::fromJSON)},
{"HeaderStack", NodeFactoryFn(&IR::HeaderStack::fromJSON)},
{"Metadata", NodeFactoryFn(&IR::Metadata::fromJSON)},
{"ConcreteHeaderRef", NodeFactoryFn(&IR::ConcreteHeaderRef::fromJSON)},
{"HeaderStackItemRef", NodeFactoryFn(&IR::HeaderStackItemRef::fromJSON)},
{"If", NodeFactoryFn(&IR::If::fromJSON)},
{"NamedCond", NodeFactoryFn(&IR::NamedCond::fromJSON)},
{"Apply", NodeFactoryFn(&IR::Apply::fromJSON)},
{"Primitive", NodeFactoryFn(&IR::Primitive::fromJSON)},
{"FieldList", NodeFactoryFn(&IR::FieldList::fromJSON)},
{"FieldListCalculation", NodeFactoryFn(&IR::FieldListCalculation::fromJSON)},
{"CalculatedField", NodeFactoryFn(&IR::CalculatedField::fromJSON)},
{"ParserValueSet", NodeFactoryFn(&IR::ParserValueSet::fromJSON)},
{"CaseEntry", NodeFactoryFn(&IR::CaseEntry::fromJSON)},
{"V1Parser", NodeFactoryFn(&IR::V1Parser::fromJSON)},
{"ParserException", NodeFactoryFn(&IR::ParserException::fromJSON)},
{"Counter", NodeFactoryFn(&IR::Counter::fromJSON)},
{"Meter", NodeFactoryFn(&IR::Meter::fromJSON)},
{"Register", NodeFactoryFn(&IR::Register::fromJSON)},
{"PrimitiveAction", NodeFactoryFn(&IR::PrimitiveAction::fromJSON)},
{"NameList", NodeFactoryFn(&IR::NameList::fromJSON)},
{"ActionArg", NodeFactoryFn(&IR::ActionArg::fromJSON)},
{"ActionFunction", NodeFactoryFn(&IR::ActionFunction::fromJSON)},
{"ActionProfile", NodeFactoryFn(&IR::ActionProfile::fromJSON)},
{"ActionSelector", NodeFactoryFn(&IR::ActionSelector::fromJSON)},
{"V1Table", NodeFactoryFn(&IR::V1Table::fromJSON)},
{"V1Control", NodeFactoryFn(&IR::V1Control::fromJSON)},
{"AttribLocal", NodeFactoryFn(&IR::AttribLocal::fromJSON)},
{"AttribLocals", NodeFactoryFn(&IR::AttribLocals::fromJSON)},
{"Attribute", NodeFactoryFn(&IR::Attribute::fromJSON)},
{"GlobalRef", NodeFactoryFn(&IR::GlobalRef::fromJSON)},
{"AttributeRef", NodeFactoryFn(&IR::AttributeRef::fromJSON)},
{"V1Program", NodeFactoryFn(&IR::V1Program::fromJSON)},
{"DpdkDeclaration", NodeFactoryFn(&IR::DpdkDeclaration::fromJSON)},
{"DpdkHeaderType", NodeFactoryFn(&IR::DpdkHeaderType::fromJSON)},
{"DpdkStructType", NodeFactoryFn(&IR::DpdkStructType::fromJSON)},
{"DpdkAction", NodeFactoryFn(&IR::DpdkAction::fromJSON)},
{"DpdkTable", NodeFactoryFn(&IR::DpdkTable::fromJSON)},
{"DpdkAsmProgram", NodeFactoryFn(&IR::DpdkAsmProgram::fromJSON)},
{"DpdkListStatement", NodeFactoryFn(&IR::DpdkListStatement::fromJSON)},
{"DpdkApplyStatement", NodeFactoryFn(&IR::DpdkApplyStatement::fromJSON)},
{"DpdkEmitStatement", NodeFactoryFn(&IR::DpdkEmitStatement::fromJSON)},
{"DpdkExtractStatement", NodeFactoryFn(&IR::DpdkExtractStatement::fromJSON)},
{"DpdkJmpLabelStatement", NodeFactoryFn(&IR::DpdkJmpLabelStatement::fromJSON)},
{"DpdkJmpHitStatement", NodeFactoryFn(&IR::DpdkJmpHitStatement::fromJSON)},
{"DpdkJmpMissStatement", NodeFactoryFn(&IR::DpdkJmpMissStatement::fromJSON)},
{"DpdkJmpIfInvalidStatement", NodeFactoryFn(&IR::DpdkJmpIfInvalidStatement::fromJSON)},
{"DpdkJmpIfValidStatement", NodeFactoryFn(&IR::DpdkJmpIfValidStatement::fromJSON)},
{"DpdkJmpEqualStatement", NodeFactoryFn(&IR::DpdkJmpEqualStatement::fromJSON)},
{"DpdkJmpNotEqualStatement", NodeFactoryFn(&IR::DpdkJmpNotEqualStatement::fromJSON)},
{"DpdkJmpGreaterEqualStatement", NodeFactoryFn(&IR::DpdkJmpGreaterEqualStatement::fromJSON)},
{"DpdkJmpGreaterStatement", NodeFactoryFn(&IR::DpdkJmpGreaterStatement::fromJSON)},
{"DpdkJmpLessOrEqualStatement", NodeFactoryFn(&IR::DpdkJmpLessOrEqualStatement::fromJSON)},
{"DpdkJmpLessStatement", NodeFactoryFn(&IR::DpdkJmpLessStatement::fromJSON)},
{"DpdkRxStatement", NodeFactoryFn(&IR::DpdkRxStatement::fromJSON)},
{"DpdkTxStatement", NodeFactoryFn(&IR::DpdkTxStatement::fromJSON)},
{"DpdkMovStatement", NodeFactoryFn(&IR::DpdkMovStatement::fromJSON)},
{"DpdkNegStatement", NodeFactoryFn(&IR::DpdkNegStatement::fromJSON)},
{"DpdkCmplStatement", NodeFactoryFn(&IR::DpdkCmplStatement::fromJSON)},
{"DpdkLNotStatement", NodeFactoryFn(&IR::DpdkLNotStatement::fromJSON)},
{"DpdkAddStatement", NodeFactoryFn(&IR::DpdkAddStatement::fromJSON)},
{"DpdkAndStatement", NodeFactoryFn(&IR::DpdkAndStatement::fromJSON)},
{"DpdkShlStatement", NodeFactoryFn(&IR::DpdkShlStatement::fromJSON)},
{"DpdkShrStatement", NodeFactoryFn(&IR::DpdkShrStatement::fromJSON)},
{"DpdkSubStatement", NodeFactoryFn(&IR::DpdkSubStatement::fromJSON)},
{"DpdkOrStatement", NodeFactoryFn(&IR::DpdkOrStatement::fromJSON)},
{"DpdkEquStatement", NodeFactoryFn(&IR::DpdkEquStatement::fromJSON)},
{"DpdkXorStatement", NodeFactoryFn(&IR::DpdkXorStatement::fromJSON)},
{"DpdkCmpStatement", NodeFactoryFn(&IR::DpdkCmpStatement::fromJSON)},
{"DpdkLAndStatement", NodeFactoryFn(&IR::DpdkLAndStatement::fromJSON)},
{"DpdkLeqStatement", NodeFactoryFn(&IR::DpdkLeqStatement::fromJSON)},
{"DpdkLssStatement", NodeFactoryFn(&IR::DpdkLssStatement::fromJSON)},
{"DpdkGrtStatement", NodeFactoryFn(&IR::DpdkGrtStatement::fromJSON)},
{"DpdkGeqStatement", NodeFactoryFn(&IR::DpdkGeqStatement::fromJSON)},
{"DpdkNeqStatement", NodeFactoryFn(&IR::DpdkNeqStatement::fromJSON)},
{"DpdkExternObjStatement", NodeFactoryFn(&IR::DpdkExternObjStatement::fromJSON)},
{"DpdkExternFuncStatement", NodeFactoryFn(&IR::DpdkExternFuncStatement::fromJSON)},
{"DpdkReturnStatement", NodeFactoryFn(&IR::DpdkReturnStatement::fromJSON)},
{"DpdkLabelStatement", NodeFactoryFn(&IR::DpdkLabelStatement::fromJSON)},
{"DpdkChecksumAddStatement", NodeFactoryFn(&IR::DpdkChecksumAddStatement::fromJSON)},
{"DpdkGetHashStatement", NodeFactoryFn(&IR::DpdkGetHashStatement::fromJSON)},
{"DpdkGetChecksumStatement", NodeFactoryFn(&IR::DpdkGetChecksumStatement::fromJSON)},
{"DpdkCastStatement", NodeFactoryFn(&IR::DpdkCastStatement::fromJSON)},
{"DpdkVerifyStatement", NodeFactoryFn(&IR::DpdkVerifyStatement::fromJSON)},
{"DpdkMeterExecuteStatement", NodeFactoryFn(&IR::DpdkMeterExecuteStatement::fromJSON)},
{"DpdkCounterCountStatement", NodeFactoryFn(&IR::DpdkCounterCountStatement::fromJSON)},
{"DpdkRegisterReadStatement", NodeFactoryFn(&IR::DpdkRegisterReadStatement::fromJSON)},
{"DpdkRegisterWriteStatement", NodeFactoryFn(&IR::DpdkRegisterWriteStatement::fromJSON)},
{"v1HeaderType", NodeFactoryFn(&IR::v1HeaderType::fromJSON)},
{"IntMod", NodeFactoryFn(&IR::IntMod::fromJSON)} };


#line 21 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
bool IR::CompileTimeValue::equiv(IR::CompileTimeValue const & other) const {
        return this->getNode()->equiv(*other.getNode());
    }
#line 244 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
/// Well-defined only for types with fixed width
#line 37 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
int IR::Type::width_bits() const { return 0; }
#line 248 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
/// When possible returns the corresponding type that can be inserted
/// in a P4 program; may return a Type_Name
bool IR::Type::operator==(IR::Type const & a) const {
        return typeid(*this) == typeid(a);
    }
bool IR::Type::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        return true;
    }
void IR::Type::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
}
IR::Type::Type(JSONLoader & json) : Node(json) {
}
IR::Type::Type(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::Type::Type() 
    { validate(); }
/// Allows the retrieval of type parameters
/// @returns the type signature of the apply method
/// prints an error if it finds duplicate names
#line 74 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
void IR::IGeneralNamespace::validate() const { checkDuplicateDeclarations(); }
#line 274 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
/// The parameters of the functional object
/// Returns true if the parameters can be matched with the
/// supplied arguments.
/// The type of the constructor as a method

#line 107 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
const IR::ParameterList *IR::IContainer::getParameters() const { return getConstructorParameters(); }
#line 282 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 113 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
IR::Type const * IR::Type_Base::getP4Type() const { return this; }
#line 285 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Base::operator==(IR::Type_Base const & a) const {
        return Type::operator==(static_cast<const Type &>(a));
    }
bool IR::Type_Base::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        return true;
    }
void IR::Type_Base::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
}
IR::Type_Base::Type_Base(JSONLoader & json) : Type(json) {
}
IR::Type_Base::Type_Base(Util::SourceInfo srcInfo) :
    Type(srcInfo)
    { validate(); }
IR::Type_Base::Type_Base() 
    { validate(); }
#line 120 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
cstring IR::Type_Unknown::toString() const { return "Unknown type"; }
#line 306 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Unknown::operator==(IR::Type_Unknown const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Unknown::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Unknown::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Unknown::Type_Unknown(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Unknown::fromJSON(JSONLoader & json) { return new Type_Unknown(json); }
IR::Type_Unknown::Type_Unknown(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_Unknown::Type_Unknown() 
    { validate(); }
bool IR::StatOrDecl::operator==(IR::StatOrDecl const & a) const {
        return typeid(*this) == typeid(a);
    }
bool IR::StatOrDecl::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        return true;
    }
void IR::StatOrDecl::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
}
IR::StatOrDecl::StatOrDecl(JSONLoader & json) : Node(json) {
}
IR::StatOrDecl::StatOrDecl(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::StatOrDecl::StatOrDecl() 
    { validate(); }
#line 131 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
IR::ID IR::Declaration::getName() const { return name; }
#line 346 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 132 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
bool IR::Declaration::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!StatOrDecl::equiv(a_)) return false;
        auto &a = static_cast<const Declaration &>(a_);

#line 132 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
{ return name == a.name; /* ignore declid */ }    }
#line 355 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 136 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
cstring IR::Declaration::toString() const { return externalName(); }
#line 358 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Declaration::operator==(IR::Declaration const & a) const {
        return StatOrDecl::operator==(static_cast<const StatOrDecl &>(a))
        && name == a.name
        && declid == a.declid;
    }
void IR::Declaration::dump_fields(std::ostream & out) const {
    StatOrDecl::dump_fields(out);
        out << " name=" << name;
        out << " declid=" << declid;
}
void IR::Declaration::toJSON(JSONGenerator & json) const {
    StatOrDecl::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"declid\" : " << this->declid;
}
IR::Declaration::Declaration(JSONLoader & json) : StatOrDecl(json) {
    json.load("name", name);
    json.load("declid", declid);
}
IR::Declaration::Declaration(Util::SourceInfo srcInfo, IR::ID name) :
    StatOrDecl(srcInfo), name(name)
    { validate(); }
IR::Declaration::Declaration(IR::ID name) :
    name(name)
    { validate(); }
#line 147 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
IR::ID IR::Type_Declaration::getName() const { return name; }
#line 386 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 148 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
bool IR::Type_Declaration::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_Declaration &>(a_);

#line 148 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
{ return name == a.name; /* ignore declid */ }    }
#line 395 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 152 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
cstring IR::Type_Declaration::toString() const { return externalName(); }
#line 398 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 153 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
IR::Type const * IR::Type_Declaration::getP4Type() const { return new Type_Name(name); }
#line 401 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Declaration::operator==(IR::Type_Declaration const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && name == a.name
        && declid == a.declid;
    }
void IR::Type_Declaration::dump_fields(std::ostream & out) const {
    Type::dump_fields(out);
        out << " name=" << name;
        out << " declid=" << declid;
}
void IR::Type_Declaration::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"declid\" : " << this->declid;
}
IR::Type_Declaration::Type_Declaration(JSONLoader & json) : Type(json) {
    json.load("name", name);
    json.load("declid", declid);
}
IR::Type_Declaration::Type_Declaration(Util::SourceInfo srcInfo, IR::ID name) :
    Type(srcInfo), name(name)
    { validate(); }
IR::Type_Declaration::Type_Declaration(IR::ID name) :
    name(name)
    { validate(); }
/// Note that the type field is not visited.
/// Most P4_16 passes don't use this field.
/// It is a used to hold the result of TypeInferencing for the expression.
/// It is used by the P4_14 front-end and by some back-ends.
/// It is not visited by the visitors by default (can be visited explicitly in preorder)
#line 164 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
void IR::Expression::visit_children(Visitor & v) { (void)v; }
#line 164 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
void IR::Expression::visit_children(Visitor & v) const { (void)v; }
#line 436 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
IRNODE_DEFINE_APPLY_OVERLOAD(Expression, , )
bool IR::Expression::operator==(IR::Expression const & a) const {
        return typeid(*this) == typeid(a)
        && type == a.type;
    }
bool IR::Expression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const Expression &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr);
    }
void IR::Expression::validate() const {
#line 449 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(type); }
void IR::Expression::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
}
IR::Expression::Expression(JSONLoader & json) : Node(json) {
    json.load("type", type);
}
IR::Expression::Expression(Util::SourceInfo srcInfo, const IR::Type* type) :
    Node(srcInfo), type(type)
    { validate(); }
IR::Expression::Expression(const IR::Type* type) :
    type(type)
    { validate(); }
IR::Expression::Expression(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::Expression::Expression() 
    { validate(); }
#line 176 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
cstring IR::Operation::toString() const { return getStringOp(); }
#line 472 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Operation::operator==(IR::Operation const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a));
    }
bool IR::Operation::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        return true;
    }
void IR::Operation::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
}
IR::Operation::Operation(JSONLoader & json) : Expression(json) {
}
IR::Operation::Operation(Util::SourceInfo srcInfo, const IR::Type* type) :
    Expression(srcInfo, type)
    { validate(); }
IR::Operation::Operation(const IR::Type* type) :
    Expression(type)
    { validate(); }
IR::Operation::Operation(Util::SourceInfo srcInfo) :
    Expression(srcInfo)
    { validate(); }
IR::Operation::Operation() 
    { validate(); }
#line 186 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
bool IR::Path::isDontCare() const { return name.isDontCare(); }
#line 499 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 187 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
cstring IR::Path::toString() const {
        // This is the ORIGINAL name the user used
        if (absolute)
            return cstring(".") + name.toString();
        return name.toString();
    }
#line 507 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 193 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
cstring IR::Path::asString() const {
        // The CURRENT internal name
        if (absolute)
            return cstring(".") + name;
        return name;
    }
#line 515 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 199 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
void IR::Path::dbprint(std::ostream & out) const { out << name; }
#line 518 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 200 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
void IR::Path::validate() const {
#line 521 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

#line 200 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
{ BUG_CHECK(!name.name.isNullOrEmpty(), "Empty path"); } }
#line 525 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Path::operator==(IR::Path const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && absolute == a.absolute;
    }
bool IR::Path::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const Path &>(a_);
        return name == a.name
        && absolute == a.absolute;
    }
void IR::Path::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
        out << " absolute=" << absolute;
}
void IR::Path::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"absolute\" : " << this->absolute;
}
IR::Path::Path(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("absolute", absolute);
}
IR::Node * IR::Path::fromJSON(JSONLoader & json) { return new Path(json); }
IR::Path::Path(Util::SourceInfo srcInfo, IR::ID name, bool absolute) :
    Node(srcInfo), name(name), absolute(absolute)
    {
#line 185 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 558 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Path::Path(IR::ID name, bool absolute) :
    name(name), absolute(absolute)
    {
#line 185 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 565 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Path::Path(Util::SourceInfo srcInfo, IR::ID name) :
    Node(srcInfo), name(name)
    {
#line 185 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 572 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Path::Path(IR::ID name) :
    name(name)
    {
#line 185 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 579 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
bool IR::NamedExpression::operator==(IR::NamedExpression const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && expression == a.expression;
    }
bool IR::NamedExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const NamedExpression &>(a_);
        return (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr);
    }
void IR::NamedExpression::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(expression, "expression");
}
void IR::NamedExpression::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(expression, "expression");
}
void IR::NamedExpression::validate() const {
#line 600 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(expression); }
void IR::NamedExpression::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"expression\" : " << this->expression;
}
IR::NamedExpression::NamedExpression(JSONLoader & json) : Declaration(json) {
    json.load("expression", expression);
}
IR::Node * IR::NamedExpression::fromJSON(JSONLoader & json) { return new NamedExpression(json); }
IR::NamedExpression::NamedExpression(Util::SourceInfo srcInfo, IR::ID name, const IR::Expression* expression) :
    Declaration(srcInfo, name), expression(expression)
    { validate(); }
IR::NamedExpression::NamedExpression(IR::ID name, const IR::Expression* expression) :
    Declaration(name), expression(expression)
    { validate(); }

#line 215 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
void IR::AnnotationToken::dbprint(std::ostream & out) const { out << text; }
#line 620 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::AnnotationToken::operator==(IR::AnnotationToken const & a) const {
        return typeid(*this) == typeid(a)
        && token_type == a.token_type
        && text == a.text
        && constInfo == a.constInfo;
    }
bool IR::AnnotationToken::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const AnnotationToken &>(a_);
        return token_type == a.token_type
        && text == a.text
        && constInfo == a.constInfo;
    }
void IR::AnnotationToken::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " token_type=" << token_type;
        out << " text=" << text;
        out << " constInfo=" << constInfo;
}
void IR::AnnotationToken::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"token_type\" : " << this->token_type;
    json << "," << std::endl << json.indent << "\"text\" : " << this->text;
    if (constInfo != nullptr)     json << "," << std::endl << json.indent << "\"constInfo\" : " << this->constInfo;
}
IR::AnnotationToken::AnnotationToken(JSONLoader & json) : Node(json) {
    json.load("token_type", token_type);
    json.load("text", text);
    json.load("constInfo", constInfo);
}
IR::Node * IR::AnnotationToken::fromJSON(JSONLoader & json) { return new AnnotationToken(json); }
IR::AnnotationToken::AnnotationToken(Util::SourceInfo srcInfo, int token_type, cstring text, UnparsedConstant * constInfo) :
    Node(srcInfo), token_type(token_type), text(text), constInfo(constInfo)
    { validate(); }
IR::AnnotationToken::AnnotationToken(int token_type, cstring text, UnparsedConstant * constInfo) :
    token_type(token_type), text(text), constInfo(constInfo)
    { validate(); }
IR::AnnotationToken::AnnotationToken(Util::SourceInfo srcInfo, int token_type, cstring text) :
    Node(srcInfo), token_type(token_type), text(text)
    { validate(); }
IR::AnnotationToken::AnnotationToken(int token_type, cstring text) :
    token_type(token_type), text(text)
    { validate(); }
/// An unparsed annotation body
/// Whether the annotation body needs to be parsed.
/// Invariant: if this is true, then expr and kv must both be empty. If the
/// annotation is compiler-generated (e.g., derived from a P4₁₄ pragma),
/// then needsParsing will be false and the body will be empty, but expr or
/// kv may be populated.
/// Annotations that are simple expressions
/// Annotations described as key-value pairs
/// If this is true this is a structured annotation, and there are some
/// constraints on its contents.
/// For annotations parsed from P4-16 source.
#line 246 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
IR::Annotation::Annotation(Util::SourceInfo si, IR::ID n, IR::Vector<IR::AnnotationToken> const & a) : Node(si), name(n), body(a), needsParsing(true), structured(false) {}
#line 678 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

#line 249 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
IR::Annotation::Annotation(Util::SourceInfo si, IR::ID n, IR::Vector<IR::AnnotationToken> const & a, bool structured) : Node(si), name(n), body(a), needsParsing(true), structured(structured) {}
#line 682 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

#line 253 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
IR::Annotation::Annotation(Util::SourceInfo si, IR::ID n, std::initializer_list<IR::Expression const *> const & a, bool structured) : Node(si), name(n), needsParsing(false), expr(a), structured(structured) {}
#line 686 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 256 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
IR::Annotation::Annotation(Util::SourceInfo si, IR::ID n, IR::Vector<IR::Expression> const & a, bool structured) : Node(si), name(n), needsParsing(false), expr(a), structured(structured) {}
#line 689 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 258 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
IR::Annotation::Annotation(Util::SourceInfo si, IR::ID n, IR::IndexedVector<IR::NamedExpression> const & kv, bool structured) : Node(si), name(n), needsParsing(false), kv(kv), structured(structured) {}
#line 692 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 261 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
IR::Annotation::Annotation(IR::ID n, std::initializer_list<IR::Expression const *> const & a, bool structured) : name(n), needsParsing(false), expr(a), structured(structured) {}
#line 695 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 263 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
IR::Annotation::Annotation(IR::ID n, IR::Vector<IR::Expression> const & a, bool structured) : name(n), needsParsing(false), expr(a), structured(structured) {}
#line 698 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 265 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
IR::Annotation::Annotation(IR::ID n, intmax_t v, bool structured) : name(n), needsParsing(false), structured(structured) {
        expr.push_back(new Constant(v)); }
#line 702 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 268 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
IR::Annotation::Annotation(IR::ID n, cstring v, bool structured) : name(n), needsParsing(false), structured(structured) {
        expr.push_back(new StringLiteral(v)); }
#line 706 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
/// Indicates the control-plane name.
/// Action cannot be a default_action.
/// action can only be a default_action.
/// Code should be executed atomically.
/// Object should not be exposed to the control-plane.
/// P4-14 annotation for varbit fields.
/// Optional parameter annotation
/// Package documentation annotation.
/// Deprecation annotation.
/// Synchronous annotation.
/// extern function/method annotation.
/// extern function/method annotation.
/// noWarn annotation.
/// Match annotation (for value sets).
#line 286 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
cstring IR::Annotation::toString() const { return cstring("@") + name; }
#line 723 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 287 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
void IR::Annotation::validate() const {
#line 726 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        body.validate();
        expr.validate();
        kv.validate();
#line 287 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
{
        BUG_CHECK(!name.name.isNullOrEmpty(), "empty annotation name");
        BUG_CHECK(!(needsParsing && !expr.empty()),
            "unparsed annotation body with non-empty expr");
        BUG_CHECK(!(needsParsing && !kv.empty()),
            "unparsed annotation body with non-empty kv");
    } }
#line 739 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
/// Extracts name value from a name annotation
/// Extracts a single string argument; error if the argument is not a string
bool IR::Annotation::operator==(IR::Annotation const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && body == a.body
        && needsParsing == a.needsParsing
        && expr == a.expr
        && kv == a.kv
        && structured == a.structured;
    }
bool IR::Annotation::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const Annotation &>(a_);
        return name == a.name
        && body.equiv(a.body)
        && needsParsing == a.needsParsing
        && expr.equiv(a.expr)
        && kv.equiv(a.kv)
        && structured == a.structured;
    }
void IR::Annotation::visit_children(Visitor & v) {
    Node::visit_children(v);
    body.visit_children(v);
    expr.visit_children(v);
    kv.visit_children(v);
}
void IR::Annotation::visit_children(Visitor & v) const {
    Node::visit_children(v);
    body.visit_children(v);
    expr.visit_children(v);
    kv.visit_children(v);
}
void IR::Annotation::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
        out << " needsParsing=" << needsParsing;
        out << " structured=" << structured;
}
void IR::Annotation::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"body\" : " << this->body;
    json << "," << std::endl << json.indent << "\"needsParsing\" : " << this->needsParsing;
    json << "," << std::endl << json.indent << "\"expr\" : " << this->expr;
    json << "," << std::endl << json.indent << "\"kv\" : " << this->kv;
    json << "," << std::endl << json.indent << "\"structured\" : " << this->structured;
}
IR::Annotation::Annotation(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("body", body);
    json.load("needsParsing", needsParsing);
    json.load("expr", expr);
    json.load("kv", kv);
    json.load("structured", structured);
}
IR::Node * IR::Annotation::fromJSON(JSONLoader & json) { return new Annotation(json); }
IR::Annotation::Annotation(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::AnnotationToken> body, bool needsParsing, IR::Vector<IR::Expression> expr, IR::IndexedVector<IR::NamedExpression> kv, bool structured) :
    Node(srcInfo), name(name), body(body), needsParsing(needsParsing), expr(expr), kv(kv), structured(structured)
    {
#line 243 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 803 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Annotation::Annotation(IR::ID name, IR::Vector<IR::AnnotationToken> body, bool needsParsing, IR::Vector<IR::Expression> expr, IR::IndexedVector<IR::NamedExpression> kv, bool structured) :
    name(name), body(body), needsParsing(needsParsing), expr(expr), kv(kv), structured(structured)
    {
#line 243 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 810 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }

#line 327 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
size_t IR::Annotations::size() const { return annotations.size(); }
#line 815 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"


#line 330 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
const IR::Annotation *IR::Annotations::getSingle(cstring name) const { return get(annotations, name); }
#line 820 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 331 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
const IR::Annotations *IR::Annotations::add(const IR::Annotation* annot) {
        if (annot->srcInfo) srcInfo += annot->srcInfo;
        annotations.push_back(annot);
        return this; }
#line 826 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 335 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
const IR::Annotations *IR::Annotations::add(const IR::Annotation* annot) const { return clone()->add(annot); }
#line 829 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 336 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
const IR::Annotations *IR::Annotations::addAnnotation(cstring name, const IR::Expression* expr, bool structured) {
        return add(new Annotation(name, Vector<Expression>(expr), structured)); }
#line 833 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 338 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
const IR::Annotations *IR::Annotations::addAnnotation(cstring name, const IR::Expression* expr, bool structured) const {
        return add(new Annotation(name, Vector<Expression>(expr), structured)); }
#line 837 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"


#line 342 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
const IR::Annotations *IR::Annotations::addAnnotationIfNew(cstring name, const IR::Expression* expr, bool structured) const {
        return getSingle(name) ? this : addAnnotation(name, expr, structured); }
#line 843 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"


#line 346 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
const IR::Annotations *IR::Annotations::addOrReplace(cstring name, const IR::Expression* expr, bool structured) const {
        auto rv = clone();
        remove_if(rv->annotations, [name](const Annotation *a)->bool { return a->name == name; });
        rv->annotations.push_back(new Annotation(name, Vector<Expression>(expr), structured));
        return rv; }
#line 852 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 354 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
const IR::Annotations *IR::Annotations::where(Filter func) const {
        auto rv = empty->clone();
        std::copy_if(annotations.begin(), annotations.end(),
                     std::back_insert_iterator<Vector<Annotation>>(rv->annotations), func);
        if (rv->annotations.size() == annotations.size()) return this;
        return rv; }
#line 860 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 360 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
void IR::Annotations::validate() const {
#line 863 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        annotations.validate();
#line 360 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
{ annotations.check_null(); } }
#line 868 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 361 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
void IR::Annotations::dbprint(std::ostream & out) const { for (auto a : annotations) out << a << ' '; }
#line 871 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Annotations::operator==(IR::Annotations const & a) const {
        return typeid(*this) == typeid(a)
        && annotations == a.annotations;
    }
bool IR::Annotations::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const Annotations &>(a_);
        return annotations.equiv(a.annotations);
    }
void IR::Annotations::visit_children(Visitor & v) {
    Node::visit_children(v);
    annotations.visit_children(v);
}
void IR::Annotations::visit_children(Visitor & v) const {
    Node::visit_children(v);
    annotations.visit_children(v);
}
void IR::Annotations::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
}
IR::Annotations::Annotations(JSONLoader & json) : Node(json) {
    json.load("annotations", annotations);
}
IR::Node * IR::Annotations::fromJSON(JSONLoader & json) { return new Annotations(json); }
IR::Annotations::Annotations(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations) :
    Node(srcInfo), annotations(annotations)
    {
#line 325 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
{ if (!srcInfo && !annotations.empty()) srcInfo = annotations[0]->srcInfo; }
#line 903 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Annotations::Annotations(IR::Vector<IR::Annotation> annotations) :
    annotations(annotations)
    {
#line 325 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
{ if (!srcInfo && !annotations.empty()) srcInfo = annotations[0]->srcInfo; }
#line 910 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Annotations::Annotations(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    {
#line 325 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
{ if (!srcInfo && !annotations.empty()) srcInfo = annotations[0]->srcInfo; }
#line 917 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Annotations::Annotations() 
    {
#line 325 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
{ if (!srcInfo && !annotations.empty()) srcInfo = annotations[0]->srcInfo; }
#line 923 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
#line 367 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
const IR::Annotation *IR::IAnnotated::getAnnotation(cstring name) const {
        return getAnnotations()->getSingle(name); }
#line 928 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
/// If an argument has no name the name.name is nullptr.
#line 383 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
void IR::Argument::dbprint(std::ostream & out) const { out << (name.name.isNullOrEmpty() ? "" : name.name + " = ") << expression; }
#line 932 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 384 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
void IR::Argument::validate() const {
#line 935 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(expression);
#line 384 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
{ CHECK_NULL(expression); } }
#line 940 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 385 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
cstring IR::Argument::toString() const {
        cstring result = "";
        if (!name.name.isNullOrEmpty())
            result = name.toString() + " = ";
        return result + expression->toString();
    }
#line 948 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Argument::operator==(IR::Argument const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && expression == a.expression;
    }
bool IR::Argument::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const Argument &>(a_);
        return name == a.name
        && (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr);
    }
void IR::Argument::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(expression, "expression");
}
void IR::Argument::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(expression, "expression");
}
void IR::Argument::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
}
void IR::Argument::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"expression\" : " << this->expression;
}
IR::Argument::Argument(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("expression", expression);
}
IR::Node * IR::Argument::fromJSON(JSONLoader & json) { return new Argument(json); }
IR::Argument::Argument(Util::SourceInfo srcInfo, IR::ID name, const IR::Expression* expression) :
    Node(srcInfo), name(name), expression(expression)
    {
#line 382 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
{ if (!srcInfo && expression) srcInfo = expression->srcInfo; }
#line 988 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Argument::Argument(IR::ID name, const IR::Expression* expression) :
    name(name), expression(expression)
    {
#line 382 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
{ if (!srcInfo && expression) srcInfo = expression->srcInfo; }
#line 995 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Argument::Argument(Util::SourceInfo srcInfo, const IR::Expression* expression) :
    Node(srcInfo), expression(expression)
    {
#line 382 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
{ if (!srcInfo && expression) srcInfo = expression->srcInfo; }
#line 1002 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Argument::Argument(const IR::Expression* expression) :
    expression(expression)
    {
#line 382 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/base.def"
{ if (!srcInfo && expression) srcInfo = expression->srcInfo; }
#line 1009 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
/** @} */
/* end group irdefs */
/* -*-C++-*- */
/** \addtogroup irdefs
  * @{
  */
/*
   This file contains IR related to representating the type hierarchy.
   Some of these classes never appear in the IR tree, they are just
   synthesized by the type-checker.
*/
#line 74 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_Type::toString() const { return "Type(" + type->toString() + ")"; }
#line 1024 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 75 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::Type_Type::dbprint(std::ostream & out) const { out << "Type(" << type << ")"; }
#line 1027 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 76 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::Type *IR::Type_Type::getP4Type() const { return type; }
#line 1030 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 77 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::Type_Type::validate() const {
#line 1033 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(type);
#line 77 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
{ BUG_CHECK(!type->is<IR::Type_Type>(), "%1%: nested Type_Type", type); } }
#line 1038 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Type::operator==(IR::Type_Type const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && type == a.type;
    }
bool IR::Type_Type::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_Type &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr);
    }
void IR::Type_Type::visit_children(Visitor & v) {
    Type::visit_children(v);
    v.visit(type, "type");
}
void IR::Type_Type::visit_children(Visitor & v) const {
    Type::visit_children(v);
    v.visit(type, "type");
}
void IR::Type_Type::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
}
IR::Type_Type::Type_Type(JSONLoader & json) : Type(json) {
    json.load("type", type);
}
IR::Node * IR::Type_Type::fromJSON(JSONLoader & json) { return new Type_Type(json); }
IR::Type_Type::Type_Type(Util::SourceInfo srcInfo, const IR::Type* type) :
    Type(srcInfo), type(type)
    { validate(); }
IR::Type_Type::Type_Type(const IR::Type* type) :
    type(type)
    { validate(); }
#line 82 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
int IR::Type_Boolean::width_bits() const { return 1; }
#line 1073 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 83 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_Boolean::toString() const { return "bool"; }
#line 1076 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 84 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::Type_Boolean::dbprint(std::ostream & out) const { out << "bool"; }
#line 1079 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Boolean::operator==(IR::Type_Boolean const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Boolean::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Boolean::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Boolean::Type_Boolean(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Boolean::fromJSON(JSONLoader & json) { return new Type_Boolean(json); }
IR::Type_Boolean::Type_Boolean(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_Boolean::Type_Boolean() 
    { validate(); }
#line 90 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_State::toString() const { return "state"; }
#line 1101 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 91 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::Type_State::dbprint(std::ostream & out) const { out << "state"; }
#line 1104 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_State::operator==(IR::Type_State const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_State::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_State::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_State::Type_State(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_State::fromJSON(JSONLoader & json) { return new Type_State(json); }
IR::Type_State::Type_State(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_State::Type_State() 
    { validate(); }


#line 101 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_Bits::baseName() const { return isSigned ? "int" : "bit"; }
#line 1128 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 102 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
int IR::Type_Bits::width_bits() const { return size; }
#line 1131 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 104 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_Bits::toString() const { return baseName() + "<" + Util::toString(size) + ">"; }
#line 1134 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 105 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::Type_Bits::dbprint(std::ostream & out) const { out << toString(); }
#line 1137 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Bits::operator==(IR::Type_Bits const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a))
        && size == a.size
        && expression == a.expression
        && isSigned == a.isSigned;
    }
bool IR::Type_Bits::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        auto &a = static_cast<const Type_Bits &>(a_);
        return size == a.size
        && (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr)
        && isSigned == a.isSigned;
    }
void IR::Type_Bits::visit_children(Visitor & v) {
    Type_Base::visit_children(v);
    v.visit(expression, "expression");
}
void IR::Type_Bits::visit_children(Visitor & v) const {
    Type_Base::visit_children(v);
    v.visit(expression, "expression");
}
void IR::Type_Bits::dump_fields(std::ostream & out) const {
    Type_Base::dump_fields(out);
        out << " size=" << size;
        out << " isSigned=" << isSigned;
}
void IR::Type_Bits::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
    json << "," << std::endl << json.indent << "\"size\" : " << this->size;
    if (expression != nullptr)     json << "," << std::endl << json.indent << "\"expression\" : " << this->expression;
    json << "," << std::endl << json.indent << "\"isSigned\" : " << this->isSigned;
}
IR::Type_Bits::Type_Bits(JSONLoader & json) : Type_Base(json) {
    json.load("size", size);
    json.load("expression", expression);
    json.load("isSigned", isSigned);
}
IR::Node * IR::Type_Bits::fromJSON(JSONLoader & json) { return new Type_Bits(json); }
IR::Type_Bits::Type_Bits(Util::SourceInfo srcInfo, int size, const IR::Expression* expression, bool isSigned) :
    Type_Base(srcInfo), size(size), expression(expression), isSigned(isSigned)
    { validate(); }
IR::Type_Bits::Type_Bits(int size, const IR::Expression* expression, bool isSigned) :
    size(size), expression(expression), isSigned(isSigned)
    { validate(); }
IR::Type_Bits::Type_Bits(Util::SourceInfo srcInfo, const IR::Expression* expression, bool isSigned) :
    Type_Base(srcInfo), expression(expression), isSigned(isSigned)
    { validate(); }
IR::Type_Bits::Type_Bits(const IR::Expression* expression, bool isSigned) :
    expression(expression), isSigned(isSigned)
    { validate(); }
IR::Type_Bits::Type_Bits(Util::SourceInfo srcInfo, int size, bool isSigned) :
    Type_Base(srcInfo), size(size), isSigned(isSigned)
    { validate(); }
IR::Type_Bits::Type_Bits(int size, bool isSigned) :
    size(size), isSigned(isSigned)
    { validate(); }
IR::Type_Bits::Type_Bits(Util::SourceInfo srcInfo, bool isSigned) :
    Type_Base(srcInfo), isSigned(isSigned)
    { validate(); }
IR::Type_Bits::Type_Bits(bool isSigned) :
    isSigned(isSigned)
    { validate(); }


#line 113 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_Varbits::toString() const { return cstring("varbit<") + Util::toString(size) + ">"; }
#line 1205 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 114 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::Type_Varbits::dbprint(std::ostream & out) const { out << "varbit<" << size << ">"; }
#line 1208 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Varbits::operator==(IR::Type_Varbits const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a))
        && size == a.size
        && expression == a.expression;
    }
bool IR::Type_Varbits::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        auto &a = static_cast<const Type_Varbits &>(a_);
        return size == a.size
        && (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr);
    }
void IR::Type_Varbits::visit_children(Visitor & v) {
    Type_Base::visit_children(v);
    v.visit(expression, "expression");
}
void IR::Type_Varbits::visit_children(Visitor & v) const {
    Type_Base::visit_children(v);
    v.visit(expression, "expression");
}
void IR::Type_Varbits::dump_fields(std::ostream & out) const {
    Type_Base::dump_fields(out);
        out << " size=" << size;
}
void IR::Type_Varbits::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
    json << "," << std::endl << json.indent << "\"size\" : " << this->size;
    if (expression != nullptr)     json << "," << std::endl << json.indent << "\"expression\" : " << this->expression;
}
IR::Type_Varbits::Type_Varbits(JSONLoader & json) : Type_Base(json) {
    json.load("size", size);
    json.load("expression", expression);
}
IR::Node * IR::Type_Varbits::fromJSON(JSONLoader & json) { return new Type_Varbits(json); }
IR::Type_Varbits::Type_Varbits(Util::SourceInfo srcInfo, int size, const IR::Expression* expression) :
    Type_Base(srcInfo), size(size), expression(expression)
    { validate(); }
IR::Type_Varbits::Type_Varbits(int size, const IR::Expression* expression) :
    size(size), expression(expression)
    { validate(); }
IR::Type_Varbits::Type_Varbits(Util::SourceInfo srcInfo, const IR::Expression* expression) :
    Type_Base(srcInfo), expression(expression)
    { validate(); }
IR::Type_Varbits::Type_Varbits(const IR::Expression* expression) :
    expression(expression)
    { validate(); }
IR::Type_Varbits::Type_Varbits(Util::SourceInfo srcInfo, int size) :
    Type_Base(srcInfo), size(size)
    { validate(); }
IR::Type_Varbits::Type_Varbits(int size) :
    size(size)
    { validate(); }
IR::Type_Varbits::Type_Varbits(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_Varbits::Type_Varbits() 
    { validate(); }
#line 122 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::Annotations *IR::Parameter::getAnnotations() const { return annotations; }
#line 1268 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 123 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
bool IR::Parameter::hasOut() const { return direction == IR::Direction::Out || direction == IR::Direction::InOut; }
#line 1271 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 125 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
bool IR::Parameter::isOptional() const {
        return getAnnotation(Annotation::optionalAnnotation) != nullptr; }
#line 1275 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 127 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::Parameter::dbprint(std::ostream & out) const { out << annotations << direction << (direction != IR::Direction::None ? " " : "")
                  << type << ' ' << name; }
#line 1279 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Parameter::operator==(IR::Parameter const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && direction == a.direction
        && type == a.type
        && defaultValue == a.defaultValue;
    }
bool IR::Parameter::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Parameter &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && direction == a.direction
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (defaultValue ? a.defaultValue ? defaultValue->equiv(*a.defaultValue) : false : a.defaultValue == nullptr);
    }
void IR::Parameter::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
    v.visit(defaultValue, "defaultValue");
}
void IR::Parameter::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
    v.visit(defaultValue, "defaultValue");
}
void IR::Parameter::validate() const {
#line 1309 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(type); }
void IR::Parameter::dump_fields(std::ostream & out) const {
    Declaration::dump_fields(out);
        out << " direction=" << direction;
}
void IR::Parameter::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"direction\" : " << this->direction;
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
    if (defaultValue != nullptr)     json << "," << std::endl << json.indent << "\"defaultValue\" : " << this->defaultValue;
}
IR::Parameter::Parameter(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("direction", direction);
    json.load("type", type);
    json.load("defaultValue", defaultValue);
}
IR::Node * IR::Parameter::fromJSON(JSONLoader & json) { return new Parameter(json); }
IR::Parameter::Parameter(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, Direction direction, const IR::Type* type, const IR::Expression* defaultValue) :
    Declaration(srcInfo, name), annotations(annotations), direction(direction), type(type), defaultValue(defaultValue)
    { validate(); }
IR::Parameter::Parameter(IR::ID name, const IR::Annotations* annotations, Direction direction, const IR::Type* type, const IR::Expression* defaultValue) :
    Declaration(name), annotations(annotations), direction(direction), type(type), defaultValue(defaultValue)
    { validate(); }
IR::Parameter::Parameter(Util::SourceInfo srcInfo, IR::ID name, Direction direction, const IR::Type* type, const IR::Expression* defaultValue) :
    Declaration(srcInfo, name), direction(direction), type(type), defaultValue(defaultValue)
    { validate(); }
IR::Parameter::Parameter(IR::ID name, Direction direction, const IR::Type* type, const IR::Expression* defaultValue) :
    Declaration(name), direction(direction), type(type), defaultValue(defaultValue)
    { validate(); }
IR::Parameter::Parameter(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, Direction direction, const IR::Type* type) :
    Declaration(srcInfo, name), annotations(annotations), direction(direction), type(type)
    { validate(); }
IR::Parameter::Parameter(IR::ID name, const IR::Annotations* annotations, Direction direction, const IR::Type* type) :
    Declaration(name), annotations(annotations), direction(direction), type(type)
    { validate(); }
IR::Parameter::Parameter(Util::SourceInfo srcInfo, IR::ID name, Direction direction, const IR::Type* type) :
    Declaration(srcInfo, name), direction(direction), type(type)
    { validate(); }
IR::Parameter::Parameter(IR::ID name, Direction direction, const IR::Type* type) :
    Declaration(name), direction(direction), type(type)
    { validate(); }
#line 133 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::ParameterList::validate() const {
#line 1357 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        parameters.validate();
#line 133 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
{ parameters.check_null(); } }
#line 1362 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 134 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
Util::Enumerator<const IR::Parameter *> * IR::ParameterList::getEnumerator() const {
        return parameters.getEnumerator(); }
#line 1366 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 136 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::ParameterList::getDeclarations() const {
        return parameters.getDeclarations(); }
#line 1370 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 138 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
size_t IR::ParameterList::size() const { return parameters.size(); }
#line 1373 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 139 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
bool IR::ParameterList::empty() const { return size() == 0; }
#line 1376 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 140 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::Parameter *IR::ParameterList::getParameter(cstring name) const {
        return parameters.getDeclaration<Parameter>(name); }
#line 1380 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 142 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::Parameter *IR::ParameterList::getParameter(unsigned index) const {
        for (auto &param : parameters)
            if (0 == index--) return param;
        BUG("Only %1% parameters; index #%2% requested", size(), size()+index); }
#line 1386 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 146 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::IDeclaration *IR::ParameterList::getDeclByName(cstring name) const { return getParameter(name); }
#line 1389 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 147 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::ParameterList::push_back(IR::Parameter const * p) { parameters.push_back(p); }
#line 1392 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 148 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::ParameterList::toString() const {
        cstring result = "";
        bool first = true;
        for (auto p : parameters) {
            if (!first)
                result += ", ";
            first = false;
            result += p->toString();
        }
        return result;
    }
#line 1405 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::ParameterList::operator==(IR::ParameterList const & a) const {
        return typeid(*this) == typeid(a)
        && parameters == a.parameters;
    }
bool IR::ParameterList::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const ParameterList &>(a_);
        return parameters.equiv(a.parameters);
    }
void IR::ParameterList::visit_children(Visitor & v) {
    Node::visit_children(v);
    parameters.visit_children(v);
}
void IR::ParameterList::visit_children(Visitor & v) const {
    Node::visit_children(v);
    parameters.visit_children(v);
}
void IR::ParameterList::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"parameters\" : " << this->parameters;
}
IR::ParameterList::ParameterList(JSONLoader & json) : Node(json) {
    json.load("parameters", parameters);
}
IR::Node * IR::ParameterList::fromJSON(JSONLoader & json) { return new ParameterList(json); }
IR::ParameterList::ParameterList(Util::SourceInfo srcInfo, IR::IndexedVector<IR::Parameter> parameters) :
    Node(srcInfo), parameters(parameters)
    { validate(); }
IR::ParameterList::ParameterList(IR::IndexedVector<IR::Parameter> parameters) :
    parameters(parameters)
    { validate(); }
IR::ParameterList::ParameterList(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::ParameterList::ParameterList() 
    { validate(); }
#line 167 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_Var::getVarName() const { return getName(); }
#line 1445 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 168 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
int IR::Type_Var::getDeclId() const { return declid; }
#line 1448 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 169 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::Type_Var::dbprint(std::ostream & out) const { out << name << "/" << getDeclId(); }
#line 1451 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 170 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_Var::toString() const { return getName().toString(); }
#line 1454 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Var::operator==(IR::Type_Var const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a));
    }
bool IR::Type_Var::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        return true;
    }
void IR::Type_Var::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
}
IR::Type_Var::Type_Var(JSONLoader & json) : Type_Declaration(json) {
}
IR::Node * IR::Type_Var::fromJSON(JSONLoader & json) { return new Type_Var(json); }
IR::Type_Var::Type_Var(Util::SourceInfo srcInfo, IR::ID name) :
    Type_Declaration(srcInfo, name)
    { validate(); }
IR::Type_Var::Type_Var(IR::ID name) :
    Type_Declaration(name)
    { validate(); }
#line 182 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_InfInt::getVarName() const { return "int_" + Util::toString(declid); }
#line 1477 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 183 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
int IR::Type_InfInt::getDeclId() const { return declid; }
#line 1480 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 184 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::Type_InfInt::dbprint(std::ostream & out) const { out << "int/" << declid; }
#line 1483 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 185 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_InfInt::toString() const { return "int"; }
#line 1486 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 186 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
bool IR::Type_InfInt::operator==(IR::Type_InfInt const & a) const { return declid == a.declid; }
#line 1489 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 187 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
bool IR::Type_InfInt::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_InfInt &>(a_);

#line 187 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
{
        (void)a;  // silence unused warning
        return true; /* ignore declid */
    }    }
#line 1501 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 191 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
IR::Type const * IR::Type_InfInt::getP4Type() const { return this; }
#line 1504 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
void IR::Type_InfInt::dump_fields(std::ostream & out) const {
    Type::dump_fields(out);
        out << " declid=" << declid;
}
void IR::Type_InfInt::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"declid\" : " << this->declid;
}
IR::Type_InfInt::Type_InfInt(JSONLoader & json) : Type(json) {
    json.load("declid", declid);
}
IR::Node * IR::Type_InfInt::fromJSON(JSONLoader & json) { return new Type_InfInt(json); }
IR::Type_InfInt::Type_InfInt(Util::SourceInfo srcInfo) :
    Type(srcInfo)
    { validate(); }
IR::Type_InfInt::Type_InfInt() 
    { validate(); }
#line 195 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_Dontcare::toString() const { return "_"; }
#line 1524 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 197 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::Type_Dontcare::dbprint(std::ostream & out) const { out << "_"; }
#line 1527 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Dontcare::operator==(IR::Type_Dontcare const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Dontcare::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Dontcare::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Dontcare::Type_Dontcare(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Dontcare::fromJSON(JSONLoader & json) { return new Type_Dontcare(json); }
IR::Type_Dontcare::Type_Dontcare(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_Dontcare::Type_Dontcare() 
    { validate(); }
#line 201 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_Void::toString() const { return "void"; }
#line 1549 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 203 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::Type_Void::dbprint(std::ostream & out) const { out << "void"; }
#line 1552 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Void::operator==(IR::Type_Void const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Void::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Void::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Void::Type_Void(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Void::fromJSON(JSONLoader & json) { return new Type_Void(json); }
IR::Type_Void::Type_Void(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_Void::Type_Void() 
    { validate(); }
#line 207 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_MatchKind::toString() const { return "match_kind"; }
#line 1574 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 209 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::Type_MatchKind::dbprint(std::ostream & out) const { out << "match_kind"; }
#line 1577 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_MatchKind::operator==(IR::Type_MatchKind const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_MatchKind::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_MatchKind::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_MatchKind::Type_MatchKind(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_MatchKind::fromJSON(JSONLoader & json) { return new Type_MatchKind(json); }
IR::Type_MatchKind::Type_MatchKind(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_MatchKind::Type_MatchKind() 
    { validate(); }
#line 214 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::TypeParameters::getDeclarations() const {
        return parameters.getDeclarations(); }
#line 1600 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 216 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
bool IR::TypeParameters::empty() const { return parameters.empty(); }
#line 1603 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 217 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
size_t IR::TypeParameters::size() const { return parameters.size(); }
#line 1606 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 218 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::IDeclaration *IR::TypeParameters::getDeclByName(cstring name) const {
        return parameters.getDeclaration(name); }
#line 1610 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 220 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::TypeParameters::push_back(const IR::Type_Var* tv) { parameters.push_back(tv); }
#line 1613 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 221 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::TypeParameters::validate() const {
#line 1616 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        parameters.validate();
#line 221 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
{ parameters.check_null(); } }
#line 1621 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 222 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::TypeParameters::toString() const {
        if (parameters.size() == 0)
            return "";
        cstring result = "<";
        bool first = true;
        for (auto p : parameters) {
            if (!first)
                result += ", ";
            first = false;
            result += p->toString();
        }
        result += ">";
        return result;
    }
#line 1637 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::TypeParameters::operator==(IR::TypeParameters const & a) const {
        return typeid(*this) == typeid(a)
        && parameters == a.parameters;
    }
bool IR::TypeParameters::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const TypeParameters &>(a_);
        return parameters.equiv(a.parameters);
    }
void IR::TypeParameters::visit_children(Visitor & v) {
    Node::visit_children(v);
    parameters.visit_children(v);
}
void IR::TypeParameters::visit_children(Visitor & v) const {
    Node::visit_children(v);
    parameters.visit_children(v);
}
void IR::TypeParameters::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"parameters\" : " << this->parameters;
}
IR::TypeParameters::TypeParameters(JSONLoader & json) : Node(json) {
    json.load("parameters", parameters);
}
IR::Node * IR::TypeParameters::fromJSON(JSONLoader & json) { return new TypeParameters(json); }
IR::TypeParameters::TypeParameters(Util::SourceInfo srcInfo, IR::IndexedVector<IR::Type_Var> parameters) :
    Node(srcInfo), parameters(parameters)
    { validate(); }
IR::TypeParameters::TypeParameters(IR::IndexedVector<IR::Type_Var> parameters) :
    parameters(parameters)
    { validate(); }
IR::TypeParameters::TypeParameters(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::TypeParameters::TypeParameters() 
    { validate(); }
#line 241 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::Annotations *IR::StructField::getAnnotations() const { return annotations; }
#line 1677 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::StructField::operator==(IR::StructField const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && type == a.type;
    }
bool IR::StructField::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const StructField &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr);
    }
void IR::StructField::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
}
void IR::StructField::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
}
void IR::StructField::validate() const {
#line 1701 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(type); }
void IR::StructField::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
}
IR::StructField::StructField(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("type", type);
}
IR::Node * IR::StructField::fromJSON(JSONLoader & json) { return new StructField(json); }
IR::StructField::StructField(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type) :
    Declaration(srcInfo, name), annotations(annotations), type(type)
    { validate(); }
IR::StructField::StructField(IR::ID name, const IR::Annotations* annotations, const IR::Type* type) :
    Declaration(name), annotations(annotations), type(type)
    { validate(); }
IR::StructField::StructField(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type) :
    Declaration(srcInfo, name), type(type)
    { validate(); }
IR::StructField::StructField(IR::ID name, const IR::Type* type) :
    Declaration(name), type(type)
    { validate(); }
#line 250 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::TypeParameters *IR::Type_StructLike::getTypeParameters() const { return typeParameters; }
#line 1729 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 251 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
std::vector<const IR::INamespace *> IR::Type_StructLike::getNestedNamespaces() const { return { typeParameters }; }
#line 1732 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 252 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::Annotations *IR::Type_StructLike::getAnnotations() const { return annotations; }
#line 1735 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 253 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Type_StructLike::getDeclarations() const {
        return fields.getDeclarations(); }
#line 1739 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 255 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::StructField *IR::Type_StructLike::getField(cstring name) const {
        return fields.getDeclaration<StructField>(name); }
#line 1743 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 257 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
int IR::Type_StructLike::getFieldIndex(cstring name) const {
        int index_pos = 0;
        for (auto f : fields) {
            if (f->name == name)
                return index_pos;
	    index_pos++;
        }
        return -1;
    }
#line 1754 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 266 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
int IR::Type_StructLike::width_bits() const {
        int rv = 0;
        for (auto f : fields) {
            rv += f->type->width_bits();
        }
        return rv; }
#line 1762 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 272 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::IDeclaration *IR::Type_StructLike::getDeclByName(cstring name) const {
        return fields.getDeclaration(name); }
#line 1766 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 274 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::Type_StructLike::validate() const {
#line 1769 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(typeParameters);
        fields.validate();
#line 274 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
{ fields.check_null(); } }
#line 1776 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
IRNODE_DEFINE_APPLY_OVERLOAD(Type_StructLike, , )
bool IR::Type_StructLike::operator==(IR::Type_StructLike const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && annotations == a.annotations
        && typeParameters == a.typeParameters
        && fields == a.fields;
    }
bool IR::Type_StructLike::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Type_StructLike &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (typeParameters ? a.typeParameters ? typeParameters->equiv(*a.typeParameters) : false : a.typeParameters == nullptr)
        && fields.equiv(a.fields);
    }
void IR::Type_StructLike::visit_children(Visitor & v) {
    Type_Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(typeParameters, "typeParameters");
    fields.visit_children(v);
}
void IR::Type_StructLike::visit_children(Visitor & v) const {
    Type_Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(typeParameters, "typeParameters");
    fields.visit_children(v);
}
void IR::Type_StructLike::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"typeParameters\" : " << this->typeParameters;
    json << "," << std::endl << json.indent << "\"fields\" : " << this->fields;
}
IR::Type_StructLike::Type_StructLike(JSONLoader & json) : Type_Declaration(json) {
    json.load("annotations", annotations);
    json.load("typeParameters", typeParameters);
    json.load("fields", fields);
}
IR::Type_StructLike::Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Declaration(srcInfo, name), annotations(annotations), typeParameters(typeParameters), fields(fields)
    { validate(); }
IR::Type_StructLike::Type_StructLike(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Declaration(name), annotations(annotations), typeParameters(typeParameters), fields(fields)
    { validate(); }
IR::Type_StructLike::Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters), fields(fields)
    { validate(); }
IR::Type_StructLike::Type_StructLike(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Declaration(name), typeParameters(typeParameters), fields(fields)
    { validate(); }
IR::Type_StructLike::Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_Declaration(srcInfo, name), annotations(annotations), fields(fields)
    { validate(); }
IR::Type_StructLike::Type_StructLike(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_Declaration(name), annotations(annotations), fields(fields)
    { validate(); }
IR::Type_StructLike::Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_Declaration(srcInfo, name), fields(fields)
    { validate(); }
IR::Type_StructLike::Type_StructLike(IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_Declaration(name), fields(fields)
    { validate(); }
IR::Type_StructLike::Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_Declaration(srcInfo, name), annotations(annotations), typeParameters(typeParameters)
    { validate(); }
IR::Type_StructLike::Type_StructLike(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_Declaration(name), annotations(annotations), typeParameters(typeParameters)
    { validate(); }
IR::Type_StructLike::Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters)
    { validate(); }
IR::Type_StructLike::Type_StructLike(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Declaration(name), typeParameters(typeParameters)
    { validate(); }
IR::Type_StructLike::Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Type_Declaration(srcInfo, name), annotations(annotations)
    { validate(); }
IR::Type_StructLike::Type_StructLike(IR::ID name, const IR::Annotations* annotations) :
    Type_Declaration(name), annotations(annotations)
    { validate(); }
IR::Type_StructLike::Type_StructLike(Util::SourceInfo srcInfo, IR::ID name) :
    Type_Declaration(srcInfo, name)
    { validate(); }
IR::Type_StructLike::Type_StructLike(IR::ID name) :
    Type_Declaration(name)
    { validate(); }
#line 281 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_Struct::toString() const { return cstring("struct ") + externalName(); }
#line 1865 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Struct::operator==(IR::Type_Struct const & a) const {
        return Type_StructLike::operator==(static_cast<const Type_StructLike &>(a));
    }
bool IR::Type_Struct::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_StructLike::equiv(a_)) return false;
        return true;
    }
void IR::Type_Struct::toJSON(JSONGenerator & json) const {
    Type_StructLike::toJSON(json);
}
IR::Type_Struct::Type_Struct(JSONLoader & json) : Type_StructLike(json) {
}
IR::Node * IR::Type_Struct::fromJSON(JSONLoader & json) { return new Type_Struct(json); }
IR::Type_Struct::Type_Struct(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, annotations, typeParameters, fields)
    { validate(); }
IR::Type_Struct::Type_Struct(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, annotations, typeParameters, fields)
    { validate(); }
IR::Type_Struct::Type_Struct(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, typeParameters, fields)
    { validate(); }
IR::Type_Struct::Type_Struct(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, typeParameters, fields)
    { validate(); }
IR::Type_Struct::Type_Struct(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, annotations, fields)
    { validate(); }
IR::Type_Struct::Type_Struct(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, annotations, fields)
    { validate(); }
IR::Type_Struct::Type_Struct(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, fields)
    { validate(); }
IR::Type_Struct::Type_Struct(IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, fields)
    { validate(); }
IR::Type_Struct::Type_Struct(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_StructLike(srcInfo, name, annotations, typeParameters)
    { validate(); }
IR::Type_Struct::Type_Struct(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_StructLike(name, annotations, typeParameters)
    { validate(); }
IR::Type_Struct::Type_Struct(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_StructLike(srcInfo, name, typeParameters)
    { validate(); }
IR::Type_Struct::Type_Struct(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_StructLike(name, typeParameters)
    { validate(); }
IR::Type_Struct::Type_Struct(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Type_StructLike(srcInfo, name, annotations)
    { validate(); }
IR::Type_Struct::Type_Struct(IR::ID name, const IR::Annotations* annotations) :
    Type_StructLike(name, annotations)
    { validate(); }
IR::Type_Struct::Type_Struct(Util::SourceInfo srcInfo, IR::ID name) :
    Type_StructLike(srcInfo, name)
    { validate(); }
IR::Type_Struct::Type_Struct(IR::ID name) :
    Type_StructLike(name)
    { validate(); }
bool IR::Type_UnknownStruct::operator==(IR::Type_UnknownStruct const & a) const {
        return Type_StructLike::operator==(static_cast<const Type_StructLike &>(a));
    }
bool IR::Type_UnknownStruct::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_StructLike::equiv(a_)) return false;
        return true;
    }
void IR::Type_UnknownStruct::toJSON(JSONGenerator & json) const {
    Type_StructLike::toJSON(json);
}
IR::Type_UnknownStruct::Type_UnknownStruct(JSONLoader & json) : Type_StructLike(json) {
}
IR::Node * IR::Type_UnknownStruct::fromJSON(JSONLoader & json) { return new Type_UnknownStruct(json); }
IR::Type_UnknownStruct::Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, annotations, typeParameters, fields)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, annotations, typeParameters, fields)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, typeParameters, fields)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, typeParameters, fields)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, annotations, fields)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, annotations, fields)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, fields)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, fields)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_StructLike(srcInfo, name, annotations, typeParameters)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_StructLike(name, annotations, typeParameters)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_StructLike(srcInfo, name, typeParameters)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_StructLike(name, typeParameters)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Type_StructLike(srcInfo, name, annotations)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(IR::ID name, const IR::Annotations* annotations) :
    Type_StructLike(name, annotations)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name) :
    Type_StructLike(srcInfo, name)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(IR::ID name) :
    Type_StructLike(name)
    { validate(); }
#line 293 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_HeaderUnion::toString() const { return cstring("header_union ") + externalName(); }
#line 1992 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

#line 295 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
int IR::Type_HeaderUnion::width_bits() const {
        int rv = 0;
        for (auto f : fields)
            rv = std::max(rv, f->type->width_bits());
        return rv; }
#line 2000 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_HeaderUnion::operator==(IR::Type_HeaderUnion const & a) const {
        return Type_StructLike::operator==(static_cast<const Type_StructLike &>(a));
    }
bool IR::Type_HeaderUnion::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_StructLike::equiv(a_)) return false;
        return true;
    }
void IR::Type_HeaderUnion::toJSON(JSONGenerator & json) const {
    Type_StructLike::toJSON(json);
}
IR::Type_HeaderUnion::Type_HeaderUnion(JSONLoader & json) : Type_StructLike(json) {
}
IR::Node * IR::Type_HeaderUnion::fromJSON(JSONLoader & json) { return new Type_HeaderUnion(json); }
IR::Type_HeaderUnion::Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, annotations, typeParameters, fields)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, annotations, typeParameters, fields)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, typeParameters, fields)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, typeParameters, fields)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, annotations, fields)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, annotations, fields)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, fields)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, fields)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_StructLike(srcInfo, name, annotations, typeParameters)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_StructLike(name, annotations, typeParameters)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_StructLike(srcInfo, name, typeParameters)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_StructLike(name, typeParameters)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Type_StructLike(srcInfo, name, annotations)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(IR::ID name, const IR::Annotations* annotations) :
    Type_StructLike(name, annotations)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name) :
    Type_StructLike(srcInfo, name)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(IR::ID name) :
    Type_StructLike(name)
    { validate(); }
#line 307 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_Header::toString() const { return cstring("header ") + externalName(); }
#line 2065 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Header::operator==(IR::Type_Header const & a) const {
        return Type_StructLike::operator==(static_cast<const Type_StructLike &>(a));
    }
bool IR::Type_Header::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_StructLike::equiv(a_)) return false;
        return true;
    }
void IR::Type_Header::toJSON(JSONGenerator & json) const {
    Type_StructLike::toJSON(json);
}
IR::Type_Header::Type_Header(JSONLoader & json) : Type_StructLike(json) {
}
IR::Node * IR::Type_Header::fromJSON(JSONLoader & json) { return new Type_Header(json); }
IR::Type_Header::Type_Header(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, annotations, typeParameters, fields)
    { validate(); }
IR::Type_Header::Type_Header(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, annotations, typeParameters, fields)
    { validate(); }
IR::Type_Header::Type_Header(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, typeParameters, fields)
    { validate(); }
IR::Type_Header::Type_Header(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, typeParameters, fields)
    { validate(); }
IR::Type_Header::Type_Header(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, annotations, fields)
    { validate(); }
IR::Type_Header::Type_Header(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, annotations, fields)
    { validate(); }
IR::Type_Header::Type_Header(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, fields)
    { validate(); }
IR::Type_Header::Type_Header(IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, fields)
    { validate(); }
IR::Type_Header::Type_Header(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_StructLike(srcInfo, name, annotations, typeParameters)
    { validate(); }
IR::Type_Header::Type_Header(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_StructLike(name, annotations, typeParameters)
    { validate(); }
IR::Type_Header::Type_Header(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_StructLike(srcInfo, name, typeParameters)
    { validate(); }
IR::Type_Header::Type_Header(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_StructLike(name, typeParameters)
    { validate(); }
IR::Type_Header::Type_Header(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Type_StructLike(srcInfo, name, annotations)
    { validate(); }
IR::Type_Header::Type_Header(IR::ID name, const IR::Annotations* annotations) :
    Type_StructLike(name, annotations)
    { validate(); }
IR::Type_Header::Type_Header(Util::SourceInfo srcInfo, IR::ID name) :
    Type_StructLike(srcInfo, name)
    { validate(); }
IR::Type_Header::Type_Header(IR::ID name) :
    Type_StructLike(name)
    { validate(); }
#line 312 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::Type_Set::dbprint(std::ostream & out) const { Node::dbprint(out); out << "<" << elementType << ">"; }
#line 2130 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 313 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_Set::toString() const { return cstring("set<") + elementType->toString() + ">"; }
#line 2133 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 314 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
IR::Type const * IR::Type_Set::getP4Type() const { return nullptr; }
#line 2136 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 315 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
int IR::Type_Set::width_bits() const {
        /// returning the width of the set elements, not the set itself, which doesn't
        /// really have a sensible size
        return elementType->width_bits(); }
#line 2142 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Set::operator==(IR::Type_Set const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && elementType == a.elementType;
    }
bool IR::Type_Set::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_Set &>(a_);
        return (elementType ? a.elementType ? elementType->equiv(*a.elementType) : false : a.elementType == nullptr);
    }
void IR::Type_Set::visit_children(Visitor & v) {
    Type::visit_children(v);
    v.visit(elementType, "elementType");
}
void IR::Type_Set::visit_children(Visitor & v) const {
    Type::visit_children(v);
    v.visit(elementType, "elementType");
}
void IR::Type_Set::validate() const {
#line 2162 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(elementType); }
void IR::Type_Set::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"elementType\" : " << this->elementType;
}
IR::Type_Set::Type_Set(JSONLoader & json) : Type(json) {
    json.load("elementType", elementType);
}
IR::Node * IR::Type_Set::fromJSON(JSONLoader & json) { return new Type_Set(json); }
IR::Type_Set::Type_Set(Util::SourceInfo srcInfo, const IR::Type* elementType) :
    Type(srcInfo), elementType(elementType)
    { validate(); }
IR::Type_Set::Type_Set(const IR::Type* elementType) :
    elementType(elementType)
    { validate(); }
#line 324 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::Type_BaseList::validate() const {
#line 2181 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        components.validate();
#line 324 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
{ components.check_null(); } }
#line 2186 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 325 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
size_t IR::Type_BaseList::size() const { return components.size(); }
#line 2189 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 326 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
int IR::Type_BaseList::width_bits() const {
        /// returning sum of the width of the elements
        int rv = 0;
        for (auto f : components) {
            rv += f->width_bits();
        }
        return rv; }
#line 2198 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_BaseList::operator==(IR::Type_BaseList const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && components == a.components;
    }
bool IR::Type_BaseList::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_BaseList &>(a_);
        return components.equiv(a.components);
    }
void IR::Type_BaseList::visit_children(Visitor & v) {
    Type::visit_children(v);
    components.visit_children(v);
}
void IR::Type_BaseList::visit_children(Visitor & v) const {
    Type::visit_children(v);
    components.visit_children(v);
}
void IR::Type_BaseList::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"components\" : " << this->components;
}
IR::Type_BaseList::Type_BaseList(JSONLoader & json) : Type(json) {
    json.load("components", components);
}
IR::Type_BaseList::Type_BaseList(Util::SourceInfo srcInfo, IR::Vector<IR::Type> components) :
    Type(srcInfo), components(components)
    { validate(); }
IR::Type_BaseList::Type_BaseList(IR::Vector<IR::Type> components) :
    components(components)
    { validate(); }
IR::Type_BaseList::Type_BaseList(Util::SourceInfo srcInfo) :
    Type(srcInfo)
    { validate(); }
IR::Type_BaseList::Type_BaseList() 
    { validate(); }

#line 338 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_List::toString() const { return "Tuple(" + Util::toString(components.size()) + ")"; }
#line 2238 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_List::operator==(IR::Type_List const & a) const {
        return Type_BaseList::operator==(static_cast<const Type_BaseList &>(a));
    }
bool IR::Type_List::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_BaseList::equiv(a_)) return false;
        return true;
    }
void IR::Type_List::toJSON(JSONGenerator & json) const {
    Type_BaseList::toJSON(json);
}
IR::Type_List::Type_List(JSONLoader & json) : Type_BaseList(json) {
}
IR::Node * IR::Type_List::fromJSON(JSONLoader & json) { return new Type_List(json); }
IR::Type_List::Type_List(Util::SourceInfo srcInfo, IR::Vector<IR::Type> components) :
    Type_BaseList(srcInfo, components)
    { validate(); }
IR::Type_List::Type_List(IR::Vector<IR::Type> components) :
    Type_BaseList(components)
    { validate(); }
IR::Type_List::Type_List(Util::SourceInfo srcInfo) :
    Type_BaseList(srcInfo)
    { validate(); }
IR::Type_List::Type_List() 
    { validate(); }
#line 344 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_Tuple::toString() const { return "Tuple(" + Util::toString(components.size()) + ")"; }
#line 2266 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
/// Return a field index if given a legal tuple field name.
/// Otherwise return -1.
bool IR::Type_Tuple::operator==(IR::Type_Tuple const & a) const {
        return Type_BaseList::operator==(static_cast<const Type_BaseList &>(a));
    }
bool IR::Type_Tuple::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_BaseList::equiv(a_)) return false;
        return true;
    }
void IR::Type_Tuple::toJSON(JSONGenerator & json) const {
    Type_BaseList::toJSON(json);
}
IR::Type_Tuple::Type_Tuple(JSONLoader & json) : Type_BaseList(json) {
}
IR::Node * IR::Type_Tuple::fromJSON(JSONLoader & json) { return new Type_Tuple(json); }
IR::Type_Tuple::Type_Tuple(Util::SourceInfo srcInfo, IR::Vector<IR::Type> components) :
    Type_BaseList(srcInfo, components)
    { validate(); }
IR::Type_Tuple::Type_Tuple(IR::Vector<IR::Type> components) :
    Type_BaseList(components)
    { validate(); }
IR::Type_Tuple::Type_Tuple(Util::SourceInfo srcInfo) :
    Type_BaseList(srcInfo)
    { validate(); }
IR::Type_Tuple::Type_Tuple() 
    { validate(); }
#line 356 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::Annotations *IR::Type_ArchBlock::getAnnotations() const { return annotations; }
#line 2296 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 357 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::TypeParameters *IR::Type_ArchBlock::getTypeParameters() const { return typeParameters; }
#line 2299 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 358 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Type_ArchBlock::getDeclarations() const {
        return typeParameters->getDeclarations(); }
#line 2303 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 360 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::IDeclaration *IR::Type_ArchBlock::getDeclByName(cstring name) const {
        return typeParameters->getDeclByName(name); }
#line 2307 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_ArchBlock::operator==(IR::Type_ArchBlock const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && annotations == a.annotations
        && typeParameters == a.typeParameters;
    }
bool IR::Type_ArchBlock::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Type_ArchBlock &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (typeParameters ? a.typeParameters ? typeParameters->equiv(*a.typeParameters) : false : a.typeParameters == nullptr);
    }
void IR::Type_ArchBlock::visit_children(Visitor & v) {
    Type_Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(typeParameters, "typeParameters");
}
void IR::Type_ArchBlock::visit_children(Visitor & v) const {
    Type_Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(typeParameters, "typeParameters");
}
void IR::Type_ArchBlock::validate() const {
#line 2331 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(typeParameters); }
void IR::Type_ArchBlock::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"typeParameters\" : " << this->typeParameters;
}
IR::Type_ArchBlock::Type_ArchBlock(JSONLoader & json) : Type_Declaration(json) {
    json.load("annotations", annotations);
    json.load("typeParameters", typeParameters);
}
IR::Type_ArchBlock::Type_ArchBlock(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_Declaration(srcInfo, name), annotations(annotations), typeParameters(typeParameters)
    { validate(); }
IR::Type_ArchBlock::Type_ArchBlock(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_Declaration(name), annotations(annotations), typeParameters(typeParameters)
    { validate(); }
IR::Type_ArchBlock::Type_ArchBlock(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters)
    { validate(); }
IR::Type_ArchBlock::Type_ArchBlock(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Declaration(name), typeParameters(typeParameters)
    { validate(); }
IR::Type_ArchBlock::Type_ArchBlock(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Type_Declaration(srcInfo, name), annotations(annotations)
    { validate(); }
IR::Type_ArchBlock::Type_ArchBlock(IR::ID name, const IR::Annotations* annotations) :
    Type_Declaration(name), annotations(annotations)
    { validate(); }
IR::Type_ArchBlock::Type_ArchBlock(Util::SourceInfo srcInfo, IR::ID name) :
    Type_Declaration(srcInfo, name)
    { validate(); }
IR::Type_ArchBlock::Type_ArchBlock(IR::ID name) :
    Type_Declaration(name)
    { validate(); }
#line 367 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::ParameterList *IR::Type_Package::getConstructorParameters() const { return constructorParams; }
#line 2370 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 368 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_Package::toString() const { return cstring("package ") + externalName(); }
#line 2373 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 369 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Type_Package::getDeclarations() const {
        return typeParameters->getDeclarations()->concat(constructorParams->getDeclarations()); }
#line 2377 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 371 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::IDeclaration *IR::Type_Package::getDeclByName(cstring name) const {
        auto decl = constructorParams->getDeclByName(name);
        if (!decl) decl = typeParameters->getDeclByName(name);
        return decl; }
#line 2383 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Package::operator==(IR::Type_Package const & a) const {
        return Type_ArchBlock::operator==(static_cast<const Type_ArchBlock &>(a))
        && constructorParams == a.constructorParams;
    }
bool IR::Type_Package::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_ArchBlock::equiv(a_)) return false;
        auto &a = static_cast<const Type_Package &>(a_);
        return (constructorParams ? a.constructorParams ? constructorParams->equiv(*a.constructorParams) : false : a.constructorParams == nullptr);
    }
void IR::Type_Package::visit_children(Visitor & v) {
    Type_ArchBlock::visit_children(v);
    v.visit(constructorParams, "constructorParams");
}
void IR::Type_Package::visit_children(Visitor & v) const {
    Type_ArchBlock::visit_children(v);
    v.visit(constructorParams, "constructorParams");
}
void IR::Type_Package::validate() const {
#line 2403 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(constructorParams); }
void IR::Type_Package::toJSON(JSONGenerator & json) const {
    Type_ArchBlock::toJSON(json);
    json << "," << std::endl << json.indent << "\"constructorParams\" : " << this->constructorParams;
}
IR::Type_Package::Type_Package(JSONLoader & json) : Type_ArchBlock(json) {
    json.load("constructorParams", constructorParams);
}
IR::Node * IR::Type_Package::fromJSON(JSONLoader & json) { return new Type_Package(json); }
IR::Type_Package::Type_Package(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, const IR::ParameterList* constructorParams) :
    Type_ArchBlock(srcInfo, name, annotations, typeParameters), constructorParams(constructorParams)
    { validate(); }
IR::Type_Package::Type_Package(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, const IR::ParameterList* constructorParams) :
    Type_ArchBlock(name, annotations, typeParameters), constructorParams(constructorParams)
    { validate(); }
IR::Type_Package::Type_Package(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, const IR::ParameterList* constructorParams) :
    Type_ArchBlock(srcInfo, name, typeParameters), constructorParams(constructorParams)
    { validate(); }
IR::Type_Package::Type_Package(IR::ID name, const IR::TypeParameters* typeParameters, const IR::ParameterList* constructorParams) :
    Type_ArchBlock(name, typeParameters), constructorParams(constructorParams)
    { validate(); }
IR::Type_Package::Type_Package(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::ParameterList* constructorParams) :
    Type_ArchBlock(srcInfo, name, annotations), constructorParams(constructorParams)
    { validate(); }
IR::Type_Package::Type_Package(IR::ID name, const IR::Annotations* annotations, const IR::ParameterList* constructorParams) :
    Type_ArchBlock(name, annotations), constructorParams(constructorParams)
    { validate(); }
IR::Type_Package::Type_Package(Util::SourceInfo srcInfo, IR::ID name, const IR::ParameterList* constructorParams) :
    Type_ArchBlock(srcInfo, name), constructorParams(constructorParams)
    { validate(); }
IR::Type_Package::Type_Package(IR::ID name, const IR::ParameterList* constructorParams) :
    Type_ArchBlock(name), constructorParams(constructorParams)
    { validate(); }
#line 380 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::ParameterList *IR::Type_Parser::getApplyParameters() const { return applyParams; }
#line 2440 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 381 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_Parser::toString() const { return cstring("parser ") + externalName(); }
#line 2443 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Parser::operator==(IR::Type_Parser const & a) const {
        return Type_ArchBlock::operator==(static_cast<const Type_ArchBlock &>(a))
        && applyParams == a.applyParams;
    }
bool IR::Type_Parser::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_ArchBlock::equiv(a_)) return false;
        auto &a = static_cast<const Type_Parser &>(a_);
        return (applyParams ? a.applyParams ? applyParams->equiv(*a.applyParams) : false : a.applyParams == nullptr);
    }
void IR::Type_Parser::visit_children(Visitor & v) {
    Type_ArchBlock::visit_children(v);
    v.visit(applyParams, "applyParams");
}
void IR::Type_Parser::visit_children(Visitor & v) const {
    Type_ArchBlock::visit_children(v);
    v.visit(applyParams, "applyParams");
}
void IR::Type_Parser::validate() const {
#line 2463 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(applyParams); }
void IR::Type_Parser::toJSON(JSONGenerator & json) const {
    Type_ArchBlock::toJSON(json);
    json << "," << std::endl << json.indent << "\"applyParams\" : " << this->applyParams;
}
IR::Type_Parser::Type_Parser(JSONLoader & json) : Type_ArchBlock(json) {
    json.load("applyParams", applyParams);
}
IR::Node * IR::Type_Parser::fromJSON(JSONLoader & json) { return new Type_Parser(json); }
IR::Type_Parser::Type_Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams) :
    Type_ArchBlock(srcInfo, name, annotations, typeParameters), applyParams(applyParams)
    { validate(); }
IR::Type_Parser::Type_Parser(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams) :
    Type_ArchBlock(name, annotations, typeParameters), applyParams(applyParams)
    { validate(); }
IR::Type_Parser::Type_Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams) :
    Type_ArchBlock(srcInfo, name, typeParameters), applyParams(applyParams)
    { validate(); }
IR::Type_Parser::Type_Parser(IR::ID name, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams) :
    Type_ArchBlock(name, typeParameters), applyParams(applyParams)
    { validate(); }
IR::Type_Parser::Type_Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::ParameterList* applyParams) :
    Type_ArchBlock(srcInfo, name, annotations), applyParams(applyParams)
    { validate(); }
IR::Type_Parser::Type_Parser(IR::ID name, const IR::Annotations* annotations, const IR::ParameterList* applyParams) :
    Type_ArchBlock(name, annotations), applyParams(applyParams)
    { validate(); }
IR::Type_Parser::Type_Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::ParameterList* applyParams) :
    Type_ArchBlock(srcInfo, name), applyParams(applyParams)
    { validate(); }
IR::Type_Parser::Type_Parser(IR::ID name, const IR::ParameterList* applyParams) :
    Type_ArchBlock(name), applyParams(applyParams)
    { validate(); }
#line 387 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::ParameterList *IR::Type_Control::getApplyParameters() const { return applyParams; }
#line 2500 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 388 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_Control::toString() const { return cstring("control ") + externalName(); }
#line 2503 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Control::operator==(IR::Type_Control const & a) const {
        return Type_ArchBlock::operator==(static_cast<const Type_ArchBlock &>(a))
        && applyParams == a.applyParams;
    }
bool IR::Type_Control::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_ArchBlock::equiv(a_)) return false;
        auto &a = static_cast<const Type_Control &>(a_);
        return (applyParams ? a.applyParams ? applyParams->equiv(*a.applyParams) : false : a.applyParams == nullptr);
    }
void IR::Type_Control::visit_children(Visitor & v) {
    Type_ArchBlock::visit_children(v);
    v.visit(applyParams, "applyParams");
}
void IR::Type_Control::visit_children(Visitor & v) const {
    Type_ArchBlock::visit_children(v);
    v.visit(applyParams, "applyParams");
}
void IR::Type_Control::validate() const {
#line 2523 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(applyParams); }
void IR::Type_Control::toJSON(JSONGenerator & json) const {
    Type_ArchBlock::toJSON(json);
    json << "," << std::endl << json.indent << "\"applyParams\" : " << this->applyParams;
}
IR::Type_Control::Type_Control(JSONLoader & json) : Type_ArchBlock(json) {
    json.load("applyParams", applyParams);
}
IR::Node * IR::Type_Control::fromJSON(JSONLoader & json) { return new Type_Control(json); }
IR::Type_Control::Type_Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams) :
    Type_ArchBlock(srcInfo, name, annotations, typeParameters), applyParams(applyParams)
    { validate(); }
IR::Type_Control::Type_Control(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams) :
    Type_ArchBlock(name, annotations, typeParameters), applyParams(applyParams)
    { validate(); }
IR::Type_Control::Type_Control(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams) :
    Type_ArchBlock(srcInfo, name, typeParameters), applyParams(applyParams)
    { validate(); }
IR::Type_Control::Type_Control(IR::ID name, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams) :
    Type_ArchBlock(name, typeParameters), applyParams(applyParams)
    { validate(); }
IR::Type_Control::Type_Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::ParameterList* applyParams) :
    Type_ArchBlock(srcInfo, name, annotations), applyParams(applyParams)
    { validate(); }
IR::Type_Control::Type_Control(IR::ID name, const IR::Annotations* annotations, const IR::ParameterList* applyParams) :
    Type_ArchBlock(name, annotations), applyParams(applyParams)
    { validate(); }
IR::Type_Control::Type_Control(Util::SourceInfo srcInfo, IR::ID name, const IR::ParameterList* applyParams) :
    Type_ArchBlock(srcInfo, name), applyParams(applyParams)
    { validate(); }
IR::Type_Control::Type_Control(IR::ID name, const IR::ParameterList* applyParams) :
    Type_ArchBlock(name), applyParams(applyParams)
    { validate(); }
#line 394 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
IR::Type_Name::Type_Name(IR::ID id) : Type(id.srcInfo), path(new IR::Path(id)) {}
#line 2560 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 395 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_Name::toString() const { return path->name; }
#line 2563 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 396 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::Type_Name::dbprint(std::ostream & out) const { out << path->toString(); }
#line 2566 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 397 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
IR::Type const * IR::Type_Name::getP4Type() const { return this; }
#line 2569 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 398 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
int IR::Type_Name::width_bits() const {
        BUG("Type_Name is not a canonical type, use getTypeType()?");
        return 0;
    }
#line 2575 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Name::operator==(IR::Type_Name const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && path == a.path;
    }
bool IR::Type_Name::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_Name &>(a_);
        return (path ? a.path ? path->equiv(*a.path) : false : a.path == nullptr);
    }
void IR::Type_Name::visit_children(Visitor & v) {
    Type::visit_children(v);
    v.visit(path, "path");
}
void IR::Type_Name::visit_children(Visitor & v) const {
    Type::visit_children(v);
    v.visit(path, "path");
}
void IR::Type_Name::validate() const {
#line 2595 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(path); }
void IR::Type_Name::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"path\" : " << this->path;
}
IR::Type_Name::Type_Name(JSONLoader & json) : Type(json) {
    json.load("path", path);
}
IR::Node * IR::Type_Name::fromJSON(JSONLoader & json) { return new Type_Name(json); }
IR::Type_Name::Type_Name(Util::SourceInfo srcInfo, const IR::Path* path) :
    Type(srcInfo), path(path)
    { validate(); }
IR::Type_Name::Type_Name(const IR::Path* path) :
    path(path)
    { validate(); }
#line 407 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_Stack::toString() const { return elementType->toString() + "[" +
                (sizeKnown() ? Util::toString(getSize()) : "?") + "]"; }
#line 2615 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 409 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::Type_Stack::dbprint(std::ostream & out) const { out << elementType << "[" << size << "]"; }
#line 2618 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 418 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
IR::Type const * IR::Type_Stack::getP4Type() const { return new IR::Type_Stack(srcInfo, elementType->getP4Type(), size); }
#line 2621 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Stack::operator==(IR::Type_Stack const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && elementType == a.elementType
        && size == a.size;
    }
bool IR::Type_Stack::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_Stack &>(a_);
        return (elementType ? a.elementType ? elementType->equiv(*a.elementType) : false : a.elementType == nullptr)
        && (size ? a.size ? size->equiv(*a.size) : false : a.size == nullptr);
    }
void IR::Type_Stack::visit_children(Visitor & v) {
    Type::visit_children(v);
    v.visit(elementType, "elementType");
    v.visit(size, "size");
}
void IR::Type_Stack::visit_children(Visitor & v) const {
    Type::visit_children(v);
    v.visit(elementType, "elementType");
    v.visit(size, "size");
}
void IR::Type_Stack::validate() const {
#line 2645 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(elementType);
        CHECK_NULL(size); }
void IR::Type_Stack::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"elementType\" : " << this->elementType;
    json << "," << std::endl << json.indent << "\"size\" : " << this->size;
}
IR::Type_Stack::Type_Stack(JSONLoader & json) : Type(json) {
    json.load("elementType", elementType);
    json.load("size", size);
}
IR::Node * IR::Type_Stack::fromJSON(JSONLoader & json) { return new Type_Stack(json); }
IR::Type_Stack::Type_Stack(Util::SourceInfo srcInfo, const IR::Type* elementType, const IR::Expression* size) :
    Type(srcInfo), elementType(elementType), size(size)
    { validate(); }
IR::Type_Stack::Type_Stack(const IR::Type* elementType, const IR::Expression* size) :
    elementType(elementType), size(size)
    { validate(); }
#line 430 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_Specialized::toString() const { return baseType->toString() + "<...>"; }
#line 2667 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 431 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::Type_Specialized::validate() const {
#line 2670 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(baseType);
        CHECK_NULL(arguments);
#line 431 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
{ arguments->check_null(); } }
#line 2676 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Specialized::operator==(IR::Type_Specialized const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && baseType == a.baseType
        && arguments == a.arguments;
    }
bool IR::Type_Specialized::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_Specialized &>(a_);
        return (baseType ? a.baseType ? baseType->equiv(*a.baseType) : false : a.baseType == nullptr)
        && (arguments ? a.arguments ? arguments->equiv(*a.arguments) : false : a.arguments == nullptr);
    }
void IR::Type_Specialized::visit_children(Visitor & v) {
    Type::visit_children(v);
    v.visit(baseType, "baseType");
    v.visit(arguments, "arguments");
}
void IR::Type_Specialized::visit_children(Visitor & v) const {
    Type::visit_children(v);
    v.visit(baseType, "baseType");
    v.visit(arguments, "arguments");
}
void IR::Type_Specialized::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"baseType\" : " << this->baseType;
    json << "," << std::endl << json.indent << "\"arguments\" : " << this->arguments;
}
IR::Type_Specialized::Type_Specialized(JSONLoader & json) : Type(json) {
    json.load("baseType", baseType);
    json.load("arguments", arguments);
}
IR::Node * IR::Type_Specialized::fromJSON(JSONLoader & json) { return new Type_Specialized(json); }
IR::Type_Specialized::Type_Specialized(Util::SourceInfo srcInfo, const IR::Type_Name* baseType, const IR::Vector<IR::Type>* arguments) :
    Type(srcInfo), baseType(baseType), arguments(arguments)
    { validate(); }
IR::Type_Specialized::Type_Specialized(const IR::Type_Name* baseType, const IR::Vector<IR::Type>* arguments) :
    baseType(baseType), arguments(arguments)
    { validate(); }
/// canonical baseType; always IMayBeGenericType
/// canonical type arguments
/// 'substituted' is baseType with all type
/// variables substituted with the arguments.

#line 444 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::Type_SpecializedCanonical::validate() const {
#line 2722 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(baseType);
        CHECK_NULL(arguments);
        CHECK_NULL(substituted);
#line 444 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
{
        arguments->check_null();
        BUG_CHECK(baseType->is<IMayBeGenericType>(), "base type %1% is not generic", baseType);
        BUG_CHECK(substituted->is<IMayBeGenericType>(), "substituted %1% is not generic", substituted);
    } }
#line 2733 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_SpecializedCanonical::operator==(IR::Type_SpecializedCanonical const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && baseType == a.baseType
        && arguments == a.arguments
        && substituted == a.substituted;
    }
bool IR::Type_SpecializedCanonical::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_SpecializedCanonical &>(a_);
        return (baseType ? a.baseType ? baseType->equiv(*a.baseType) : false : a.baseType == nullptr)
        && (arguments ? a.arguments ? arguments->equiv(*a.arguments) : false : a.arguments == nullptr)
        && (substituted ? a.substituted ? substituted->equiv(*a.substituted) : false : a.substituted == nullptr);
    }
void IR::Type_SpecializedCanonical::visit_children(Visitor & v) {
    Type::visit_children(v);
    v.visit(baseType, "baseType");
    v.visit(arguments, "arguments");
    v.visit(substituted, "substituted");
}
void IR::Type_SpecializedCanonical::visit_children(Visitor & v) const {
    Type::visit_children(v);
    v.visit(baseType, "baseType");
    v.visit(arguments, "arguments");
    v.visit(substituted, "substituted");
}
void IR::Type_SpecializedCanonical::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"baseType\" : " << this->baseType;
    json << "," << std::endl << json.indent << "\"arguments\" : " << this->arguments;
    json << "," << std::endl << json.indent << "\"substituted\" : " << this->substituted;
}
IR::Type_SpecializedCanonical::Type_SpecializedCanonical(JSONLoader & json) : Type(json) {
    json.load("baseType", baseType);
    json.load("arguments", arguments);
    json.load("substituted", substituted);
}
IR::Node * IR::Type_SpecializedCanonical::fromJSON(JSONLoader & json) { return new Type_SpecializedCanonical(json); }
IR::Type_SpecializedCanonical::Type_SpecializedCanonical(Util::SourceInfo srcInfo, const IR::Type* baseType, const IR::Vector<IR::Type>* arguments, const IR::Type* substituted) :
    Type(srcInfo), baseType(baseType), arguments(arguments), substituted(substituted)
    { validate(); }
IR::Type_SpecializedCanonical::Type_SpecializedCanonical(const IR::Type* baseType, const IR::Vector<IR::Type>* arguments, const IR::Type* substituted) :
    baseType(baseType), arguments(arguments), substituted(substituted)
    { validate(); }
bool IR::Declaration_ID::operator==(IR::Declaration_ID const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a));
    }
bool IR::Declaration_ID::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        return true;
    }
void IR::Declaration_ID::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
}
IR::Declaration_ID::Declaration_ID(JSONLoader & json) : Declaration(json) {
}
IR::Node * IR::Declaration_ID::fromJSON(JSONLoader & json) { return new Declaration_ID(json); }
IR::Declaration_ID::Declaration_ID(Util::SourceInfo srcInfo, IR::ID name) :
    Declaration(srcInfo, name)
    { validate(); }
IR::Declaration_ID::Declaration_ID(IR::ID name) :
    Declaration(name)
    { validate(); }
#line 461 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_String::toString() const { return "string"; }
#line 2800 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_String::operator==(IR::Type_String const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_String::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_String::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_String::Type_String(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_String::fromJSON(JSONLoader & json) { return new Type_String(json); }
IR::Type_String::Type_String(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_String::Type_String() 
    { validate(); }
#line 467 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::Annotations *IR::Type_Enum::getAnnotations() const { return annotations; }
#line 2822 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 468 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Type_Enum::getDeclarations() const {
        return members.getDeclarations(); }
#line 2826 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 470 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::IDeclaration *IR::Type_Enum::getDeclByName(cstring name) const {
        return members.getDeclaration(name); }
#line 2830 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 473 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::Type_Enum::validate() const {
#line 2833 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        members.validate();
#line 473 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
{ members.check_null(); } }
#line 2839 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Enum::operator==(IR::Type_Enum const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && annotations == a.annotations
        && members == a.members;
    }
bool IR::Type_Enum::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Type_Enum &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && members.equiv(a.members);
    }
void IR::Type_Enum::visit_children(Visitor & v) {
    Type_Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    members.visit_children(v);
}
void IR::Type_Enum::visit_children(Visitor & v) const {
    Type_Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    members.visit_children(v);
}
void IR::Type_Enum::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"members\" : " << this->members;
}
IR::Type_Enum::Type_Enum(JSONLoader & json) : Type_Declaration(json) {
    json.load("annotations", annotations);
    json.load("members", members);
}
IR::Node * IR::Type_Enum::fromJSON(JSONLoader & json) { return new Type_Enum(json); }
IR::Type_Enum::Type_Enum(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::Declaration_ID> members) :
    Type_Declaration(srcInfo, name), annotations(annotations), members(members)
    { validate(); }
IR::Type_Enum::Type_Enum(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::Declaration_ID> members) :
    Type_Declaration(name), annotations(annotations), members(members)
    { validate(); }
IR::Type_Enum::Type_Enum(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::Declaration_ID> members) :
    Type_Declaration(srcInfo, name), members(members)
    { validate(); }
IR::Type_Enum::Type_Enum(IR::ID name, IR::IndexedVector<IR::Declaration_ID> members) :
    Type_Declaration(name), members(members)
    { validate(); }
#line 479 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::SerEnumMember::validate() const {
#line 2886 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(value);
#line 479 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
{ CHECK_NULL(value); } }
#line 2891 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::SerEnumMember::operator==(IR::SerEnumMember const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && value == a.value;
    }
bool IR::SerEnumMember::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const SerEnumMember &>(a_);
        return (value ? a.value ? value->equiv(*a.value) : false : a.value == nullptr);
    }
void IR::SerEnumMember::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(value, "value");
}
void IR::SerEnumMember::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(value, "value");
}
void IR::SerEnumMember::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"value\" : " << this->value;
}
IR::SerEnumMember::SerEnumMember(JSONLoader & json) : Declaration(json) {
    json.load("value", value);
}
IR::Node * IR::SerEnumMember::fromJSON(JSONLoader & json) { return new SerEnumMember(json); }
IR::SerEnumMember::SerEnumMember(Util::SourceInfo srcInfo, IR::ID name, const IR::Expression* value) :
    Declaration(srcInfo, name), value(value)
    { validate(); }
IR::SerEnumMember::SerEnumMember(IR::ID name, const IR::Expression* value) :
    Declaration(name), value(value)
    { validate(); }
#line 488 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::Annotations *IR::Type_SerEnum::getAnnotations() const { return annotations; }
#line 2926 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 489 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Type_SerEnum::getDeclarations() const {
        return members.getDeclarations(); }
#line 2930 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 491 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::IDeclaration *IR::Type_SerEnum::getDeclByName(cstring name) const {
        return members.getDeclaration(name); }
#line 2934 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 494 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::Type_SerEnum::validate() const {
#line 2937 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(type);
        members.validate();
#line 494 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
{ members.check_null(); } }
#line 2944 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_SerEnum::operator==(IR::Type_SerEnum const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && annotations == a.annotations
        && type == a.type
        && members == a.members;
    }
bool IR::Type_SerEnum::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Type_SerEnum &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && members.equiv(a.members);
    }
void IR::Type_SerEnum::visit_children(Visitor & v) {
    Type_Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
    members.visit_children(v);
}
void IR::Type_SerEnum::visit_children(Visitor & v) const {
    Type_Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
    members.visit_children(v);
}
void IR::Type_SerEnum::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
    json << "," << std::endl << json.indent << "\"members\" : " << this->members;
}
IR::Type_SerEnum::Type_SerEnum(JSONLoader & json) : Type_Declaration(json) {
    json.load("annotations", annotations);
    json.load("type", type);
    json.load("members", members);
}
IR::Node * IR::Type_SerEnum::fromJSON(JSONLoader & json) { return new Type_SerEnum(json); }
IR::Type_SerEnum::Type_SerEnum(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type, IR::IndexedVector<IR::SerEnumMember> members) :
    Type_Declaration(srcInfo, name), annotations(annotations), type(type), members(members)
    { validate(); }
IR::Type_SerEnum::Type_SerEnum(IR::ID name, const IR::Annotations* annotations, const IR::Type* type, IR::IndexedVector<IR::SerEnumMember> members) :
    Type_Declaration(name), annotations(annotations), type(type), members(members)
    { validate(); }
IR::Type_SerEnum::Type_SerEnum(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type, IR::IndexedVector<IR::SerEnumMember> members) :
    Type_Declaration(srcInfo, name), type(type), members(members)
    { validate(); }
IR::Type_SerEnum::Type_SerEnum(IR::ID name, const IR::Type* type, IR::IndexedVector<IR::SerEnumMember> members) :
    Type_Declaration(name), type(type), members(members)
    { validate(); }
#line 500 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::ParameterList *IR::Type_Table::getApplyParameters() const { return new ParameterList(); }
#line 2997 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
/// names for the fields of the struct returned
/// by applying a table
#line 506 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
IR::Type const * IR::Type_Table::getP4Type() const { return nullptr; }
#line 3002 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 507 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::Type_Table::dbprint(std::ostream & out) const { out << table->name; }
#line 3005 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Table::operator==(IR::Type_Table const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && table == a.table;
    }
bool IR::Type_Table::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_Table &>(a_);
        return (table ? a.table ? table->equiv(*a.table) : false : a.table == nullptr);
    }
void IR::Type_Table::visit_children(Visitor & v) {
    Type::visit_children(v);
    v.visit(table, "table");
}
void IR::Type_Table::visit_children(Visitor & v) const {
    Type::visit_children(v);
    v.visit(table, "table");
}
void IR::Type_Table::validate() const {
#line 3025 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(table); }
void IR::Type_Table::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"table\" : " << this->table;
}
IR::Type_Table::Type_Table(JSONLoader & json) : Type(json) {
    json.load("table", table);
}
IR::Node * IR::Type_Table::fromJSON(JSONLoader & json) { return new Type_Table(json); }
IR::Type_Table::Type_Table(Util::SourceInfo srcInfo, const IR::P4Table* table) :
    Type(srcInfo), table(table)
    { validate(); }
IR::Type_Table::Type_Table(const IR::P4Table* table) :
    table(table)
    { validate(); }
#line 516 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
IR::Type const * IR::Type_ActionEnum::getP4Type() const { return nullptr; }
#line 3044 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_ActionEnum::operator==(IR::Type_ActionEnum const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && actionList == a.actionList;
    }
bool IR::Type_ActionEnum::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_ActionEnum &>(a_);
        return (actionList ? a.actionList ? actionList->equiv(*a.actionList) : false : a.actionList == nullptr);
    }
void IR::Type_ActionEnum::visit_children(Visitor & v) {
    Type::visit_children(v);
    v.visit(actionList, "actionList");
}
void IR::Type_ActionEnum::visit_children(Visitor & v) const {
    Type::visit_children(v);
    v.visit(actionList, "actionList");
}
void IR::Type_ActionEnum::validate() const {
#line 3064 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(actionList); }
void IR::Type_ActionEnum::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"actionList\" : " << this->actionList;
}
IR::Type_ActionEnum::Type_ActionEnum(JSONLoader & json) : Type(json) {
    json.load("actionList", actionList);
}
IR::Node * IR::Type_ActionEnum::fromJSON(JSONLoader & json) { return new Type_ActionEnum(json); }
IR::Type_ActionEnum::Type_ActionEnum(Util::SourceInfo srcInfo, const IR::ActionList* actionList) :
    Type(srcInfo), actionList(actionList)
    { validate(); }
IR::Type_ActionEnum::Type_ActionEnum(const IR::ActionList* actionList) :
    actionList(actionList)
    { validate(); }


#line 526 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
size_t IR::Type_MethodBase::maxParameterCount() const { return parameters->size(); }
#line 3085 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 528 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::TypeParameters *IR::Type_MethodBase::getTypeParameters() const { return typeParameters; }
#line 3088 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 530 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_MethodBase::toString() const { return "<Method>"; }
#line 3091 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 531 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
IR::Type const * IR::Type_MethodBase::getP4Type() const { return nullptr; }
#line 3094 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 532 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Type_MethodBase::getDeclarations() const {
        return typeParameters->getDeclarations()->concat(parameters->getDeclarations()); }
#line 3098 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 534 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::IDeclaration *IR::Type_MethodBase::getDeclByName(cstring name) const {
        auto decl = parameters->getDeclByName(name);
        if (!decl) decl = typeParameters->getDeclByName(name);
        return decl; }
#line 3104 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_MethodBase::operator==(IR::Type_MethodBase const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && typeParameters == a.typeParameters
        && returnType == a.returnType
        && parameters == a.parameters;
    }
bool IR::Type_MethodBase::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_MethodBase &>(a_);
        return (typeParameters ? a.typeParameters ? typeParameters->equiv(*a.typeParameters) : false : a.typeParameters == nullptr)
        && (returnType ? a.returnType ? returnType->equiv(*a.returnType) : false : a.returnType == nullptr)
        && (parameters ? a.parameters ? parameters->equiv(*a.parameters) : false : a.parameters == nullptr);
    }
void IR::Type_MethodBase::visit_children(Visitor & v) {
    Type::visit_children(v);
    v.visit(typeParameters, "typeParameters");
    v.visit(returnType, "returnType");
    v.visit(parameters, "parameters");
}
void IR::Type_MethodBase::visit_children(Visitor & v) const {
    Type::visit_children(v);
    v.visit(typeParameters, "typeParameters");
    v.visit(returnType, "returnType");
    v.visit(parameters, "parameters");
}
void IR::Type_MethodBase::validate() const {
#line 3132 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(typeParameters);
        CHECK_NULL(parameters); }
void IR::Type_MethodBase::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"typeParameters\" : " << this->typeParameters;
    if (returnType != nullptr)     json << "," << std::endl << json.indent << "\"returnType\" : " << this->returnType;
    json << "," << std::endl << json.indent << "\"parameters\" : " << this->parameters;
}
IR::Type_MethodBase::Type_MethodBase(JSONLoader & json) : Type(json) {
    json.load("typeParameters", typeParameters);
    json.load("returnType", returnType);
    json.load("parameters", parameters);
}
IR::Type_MethodBase::Type_MethodBase(Util::SourceInfo srcInfo, const IR::TypeParameters* typeParameters, const IR::Type* returnType, const IR::ParameterList* parameters) :
    Type(srcInfo), typeParameters(typeParameters), returnType(returnType), parameters(parameters)
    { validate(); }
IR::Type_MethodBase::Type_MethodBase(const IR::TypeParameters* typeParameters, const IR::Type* returnType, const IR::ParameterList* parameters) :
    typeParameters(typeParameters), returnType(returnType), parameters(parameters)
    { validate(); }
IR::Type_MethodBase::Type_MethodBase(Util::SourceInfo srcInfo, const IR::Type* returnType, const IR::ParameterList* parameters) :
    Type(srcInfo), returnType(returnType), parameters(parameters)
    { validate(); }
IR::Type_MethodBase::Type_MethodBase(const IR::Type* returnType, const IR::ParameterList* parameters) :
    returnType(returnType), parameters(parameters)
    { validate(); }
IR::Type_MethodBase::Type_MethodBase(Util::SourceInfo srcInfo, const IR::TypeParameters* typeParameters, const IR::ParameterList* parameters) :
    Type(srcInfo), typeParameters(typeParameters), parameters(parameters)
    { validate(); }
IR::Type_MethodBase::Type_MethodBase(const IR::TypeParameters* typeParameters, const IR::ParameterList* parameters) :
    typeParameters(typeParameters), parameters(parameters)
    { validate(); }
IR::Type_MethodBase::Type_MethodBase(Util::SourceInfo srcInfo, const IR::ParameterList* parameters) :
    Type(srcInfo), parameters(parameters)
    { validate(); }
IR::Type_MethodBase::Type_MethodBase(const IR::ParameterList* parameters) :
    parameters(parameters)
    { validate(); }

#line 545 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_Method::toString() const { return name; }
#line 3174 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Method::operator==(IR::Type_Method const & a) const {
        return Type_MethodBase::operator==(static_cast<const Type_MethodBase &>(a))
        && name == a.name;
    }
bool IR::Type_Method::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_MethodBase::equiv(a_)) return false;
        auto &a = static_cast<const Type_Method &>(a_);
        return name == a.name;
    }
void IR::Type_Method::dump_fields(std::ostream & out) const {
    Type_MethodBase::dump_fields(out);
        out << " name=" << name;
}
void IR::Type_Method::toJSON(JSONGenerator & json) const {
    Type_MethodBase::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
}
IR::Type_Method::Type_Method(JSONLoader & json) : Type_MethodBase(json) {
    json.load("name", name);
}
IR::Node * IR::Type_Method::fromJSON(JSONLoader & json) { return new Type_Method(json); }
IR::Type_Method::Type_Method(Util::SourceInfo srcInfo, const IR::TypeParameters* typeParameters, const IR::Type* returnType, const IR::ParameterList* parameters, cstring name) :
    Type_MethodBase(srcInfo, typeParameters, returnType, parameters), name(name)
    { validate(); }
IR::Type_Method::Type_Method(const IR::TypeParameters* typeParameters, const IR::Type* returnType, const IR::ParameterList* parameters, cstring name) :
    Type_MethodBase(typeParameters, returnType, parameters), name(name)
    { validate(); }
IR::Type_Method::Type_Method(Util::SourceInfo srcInfo, const IR::Type* returnType, const IR::ParameterList* parameters, cstring name) :
    Type_MethodBase(srcInfo, returnType, parameters), name(name)
    { validate(); }
IR::Type_Method::Type_Method(const IR::Type* returnType, const IR::ParameterList* parameters, cstring name) :
    Type_MethodBase(returnType, parameters), name(name)
    { validate(); }
IR::Type_Method::Type_Method(Util::SourceInfo srcInfo, const IR::TypeParameters* typeParameters, const IR::ParameterList* parameters, cstring name) :
    Type_MethodBase(srcInfo, typeParameters, parameters), name(name)
    { validate(); }
IR::Type_Method::Type_Method(const IR::TypeParameters* typeParameters, const IR::ParameterList* parameters, cstring name) :
    Type_MethodBase(typeParameters, parameters), name(name)
    { validate(); }
IR::Type_Method::Type_Method(Util::SourceInfo srcInfo, const IR::ParameterList* parameters, cstring name) :
    Type_MethodBase(srcInfo, parameters), name(name)
    { validate(); }
IR::Type_Method::Type_Method(const IR::ParameterList* parameters, cstring name) :
    Type_MethodBase(parameters), name(name)
    { validate(); }
#line 555 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::ArgumentInfo::toString() const { return argument->toString(); }
#line 3223 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::ArgumentInfo::operator==(IR::ArgumentInfo const & a) const {
        return typeid(*this) == typeid(a)
        && leftValue == a.leftValue
        && compileTimeConstant == a.compileTimeConstant
        && type == a.type
        && argument == a.argument;
    }
bool IR::ArgumentInfo::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const ArgumentInfo &>(a_);
        return leftValue == a.leftValue
        && compileTimeConstant == a.compileTimeConstant
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (argument ? a.argument ? argument->equiv(*a.argument) : false : a.argument == nullptr);
    }
void IR::ArgumentInfo::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(type, "type");
    v.visit(argument, "argument");
}
void IR::ArgumentInfo::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(type, "type");
    v.visit(argument, "argument");
}
void IR::ArgumentInfo::validate() const {
#line 3251 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(type);
        CHECK_NULL(argument); }
void IR::ArgumentInfo::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " leftValue=" << leftValue;
        out << " compileTimeConstant=" << compileTimeConstant;
}
void IR::ArgumentInfo::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"leftValue\" : " << this->leftValue;
    json << "," << std::endl << json.indent << "\"compileTimeConstant\" : " << this->compileTimeConstant;
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
    json << "," << std::endl << json.indent << "\"argument\" : " << this->argument;
}
IR::ArgumentInfo::ArgumentInfo(JSONLoader & json) : Node(json) {
    json.load("leftValue", leftValue);
    json.load("compileTimeConstant", compileTimeConstant);
    json.load("type", type);
    json.load("argument", argument);
}
IR::Node * IR::ArgumentInfo::fromJSON(JSONLoader & json) { return new ArgumentInfo(json); }
IR::ArgumentInfo::ArgumentInfo(Util::SourceInfo srcInfo, bool leftValue, bool compileTimeConstant, const IR::Type* type, const IR::Argument* argument) :
    Node(srcInfo), leftValue(leftValue), compileTimeConstant(compileTimeConstant), type(type), argument(argument)
    { validate(); }
IR::ArgumentInfo::ArgumentInfo(bool leftValue, bool compileTimeConstant, const IR::Type* type, const IR::Argument* argument) :
    leftValue(leftValue), compileTimeConstant(compileTimeConstant), type(type), argument(argument)
    { validate(); }
#line 566 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::Type_MethodCall::validate() const {
#line 3282 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(typeArguments);
        CHECK_NULL(returnType);
        CHECK_NULL(arguments);
#line 566 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
{ typeArguments->check_null(); arguments->check_null(); } }
#line 3289 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 567 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
IR::Type const * IR::Type_MethodCall::getP4Type() const { return nullptr; }
#line 3292 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 568 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
cstring IR::Type_MethodCall::toString() const { return "<Method call>"; }
#line 3295 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_MethodCall::operator==(IR::Type_MethodCall const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && typeArguments == a.typeArguments
        && returnType == a.returnType
        && arguments == a.arguments;
    }
bool IR::Type_MethodCall::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_MethodCall &>(a_);
        return (typeArguments ? a.typeArguments ? typeArguments->equiv(*a.typeArguments) : false : a.typeArguments == nullptr)
        && (returnType ? a.returnType ? returnType->equiv(*a.returnType) : false : a.returnType == nullptr)
        && (arguments ? a.arguments ? arguments->equiv(*a.arguments) : false : a.arguments == nullptr);
    }
void IR::Type_MethodCall::visit_children(Visitor & v) {
    Type::visit_children(v);
    v.visit(typeArguments, "typeArguments");
    v.visit(returnType, "returnType");
    v.visit(arguments, "arguments");
}
void IR::Type_MethodCall::visit_children(Visitor & v) const {
    Type::visit_children(v);
    v.visit(typeArguments, "typeArguments");
    v.visit(returnType, "returnType");
    v.visit(arguments, "arguments");
}
void IR::Type_MethodCall::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"typeArguments\" : " << this->typeArguments;
    json << "," << std::endl << json.indent << "\"returnType\" : " << this->returnType;
    json << "," << std::endl << json.indent << "\"arguments\" : " << this->arguments;
}
IR::Type_MethodCall::Type_MethodCall(JSONLoader & json) : Type(json) {
    json.load("typeArguments", typeArguments);
    json.load("returnType", returnType);
    json.load("arguments", arguments);
}
IR::Node * IR::Type_MethodCall::fromJSON(JSONLoader & json) { return new Type_MethodCall(json); }
IR::Type_MethodCall::Type_MethodCall(Util::SourceInfo srcInfo, const IR::Vector<IR::Type>* typeArguments, const IR::Type_Var* returnType, const IR::Vector<IR::ArgumentInfo>* arguments) :
    Type(srcInfo), typeArguments(typeArguments), returnType(returnType), arguments(arguments)
    { validate(); }
IR::Type_MethodCall::Type_MethodCall(const IR::Vector<IR::Type>* typeArguments, const IR::Type_Var* returnType, const IR::Vector<IR::ArgumentInfo>* arguments) :
    typeArguments(typeArguments), returnType(returnType), arguments(arguments)
    { validate(); }
bool IR::Type_Action::operator==(IR::Type_Action const & a) const {
        return Type_MethodBase::operator==(static_cast<const Type_MethodBase &>(a));
    }
bool IR::Type_Action::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_MethodBase::equiv(a_)) return false;
        return true;
    }
void IR::Type_Action::toJSON(JSONGenerator & json) const {
    Type_MethodBase::toJSON(json);
}
IR::Type_Action::Type_Action(JSONLoader & json) : Type_MethodBase(json) {
}
IR::Node * IR::Type_Action::fromJSON(JSONLoader & json) { return new Type_Action(json); }
IR::Type_Action::Type_Action(Util::SourceInfo srcInfo, const IR::TypeParameters* typeParameters, const IR::Type* returnType, const IR::ParameterList* parameters) :
    Type_MethodBase(srcInfo, typeParameters, returnType, parameters)
    { validate(); }
IR::Type_Action::Type_Action(const IR::TypeParameters* typeParameters, const IR::Type* returnType, const IR::ParameterList* parameters) :
    Type_MethodBase(typeParameters, returnType, parameters)
    { validate(); }
IR::Type_Action::Type_Action(Util::SourceInfo srcInfo, const IR::Type* returnType, const IR::ParameterList* parameters) :
    Type_MethodBase(srcInfo, returnType, parameters)
    { validate(); }
IR::Type_Action::Type_Action(const IR::Type* returnType, const IR::ParameterList* parameters) :
    Type_MethodBase(returnType, parameters)
    { validate(); }
IR::Type_Action::Type_Action(Util::SourceInfo srcInfo, const IR::TypeParameters* typeParameters, const IR::ParameterList* parameters) :
    Type_MethodBase(srcInfo, typeParameters, parameters)
    { validate(); }
IR::Type_Action::Type_Action(const IR::TypeParameters* typeParameters, const IR::ParameterList* parameters) :
    Type_MethodBase(typeParameters, parameters)
    { validate(); }
IR::Type_Action::Type_Action(Util::SourceInfo srcInfo, const IR::ParameterList* parameters) :
    Type_MethodBase(srcInfo, parameters)
    { validate(); }
IR::Type_Action::Type_Action(const IR::ParameterList* parameters) :
    Type_MethodBase(parameters)
    { validate(); }
#line 582 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
size_t IR::Method::maxParameterCount() const { return type->maxParameterCount(); }
#line 3380 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 583 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
size_t IR::Method::minParameterCount() const { return type->minParameterCount(); }
#line 3383 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 584 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::Method::setAbstract() { isAbstract = true; }
#line 3386 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 585 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::Annotations *IR::Method::getAnnotations() const { return annotations; }
#line 3389 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 586 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::ParameterList *IR::Method::getParameters() const { return type->parameters; }
#line 3392 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

#line 588 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::IDeclaration *IR::Method::getDeclByName(cstring name) const {
        return type->parameters->getDeclByName(name); }
#line 3397 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 590 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Method::getDeclarations() const {
        return type->parameters->getDeclarations(); }
#line 3401 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Method::operator==(IR::Method const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && type == a.type
        && isAbstract == a.isAbstract
        && annotations == a.annotations;
    }
bool IR::Method::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Method &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && isAbstract == a.isAbstract
        && (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr);
    }
void IR::Method::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(type, "type");
    v.visit(annotations, "annotations");
}
void IR::Method::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(type, "type");
    v.visit(annotations, "annotations");
}
void IR::Method::validate() const {
#line 3427 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(type);
        CHECK_NULL(annotations); }
void IR::Method::dump_fields(std::ostream & out) const {
    Declaration::dump_fields(out);
        out << " isAbstract=" << isAbstract;
}
void IR::Method::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
    json << "," << std::endl << json.indent << "\"isAbstract\" : " << this->isAbstract;
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
}
IR::Method::Method(JSONLoader & json) : Declaration(json) {
    json.load("type", type);
    json.load("isAbstract", isAbstract);
    json.load("annotations", annotations);
}
IR::Node * IR::Method::fromJSON(JSONLoader & json) { return new Method(json); }
IR::Method::Method(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Method* type, bool isAbstract, const IR::Annotations* annotations) :
    Declaration(srcInfo, name), type(type), isAbstract(isAbstract), annotations(annotations)
    { validate(); }
IR::Method::Method(IR::ID name, const IR::Type_Method* type, bool isAbstract, const IR::Annotations* annotations) :
    Declaration(name), type(type), isAbstract(isAbstract), annotations(annotations)
    { validate(); }
IR::Method::Method(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Method* type, const IR::Annotations* annotations) :
    Declaration(srcInfo, name), type(type), annotations(annotations)
    { validate(); }
IR::Method::Method(IR::ID name, const IR::Type_Method* type, const IR::Annotations* annotations) :
    Declaration(name), type(type), annotations(annotations)
    { validate(); }
IR::Method::Method(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Method* type, bool isAbstract) :
    Declaration(srcInfo, name), type(type), isAbstract(isAbstract)
    { validate(); }
IR::Method::Method(IR::ID name, const IR::Type_Method* type, bool isAbstract) :
    Declaration(name), type(type), isAbstract(isAbstract)
    { validate(); }
IR::Method::Method(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Method* type) :
    Declaration(srcInfo, name), type(type)
    { validate(); }
IR::Method::Method(IR::ID name, const IR::Type_Method* type) :
    Declaration(name), type(type)
    { validate(); }
#line 597 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
int IR::Type_Typedef::width_bits() const { return type->width_bits(); }
#line 3473 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 598 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::Annotations *IR::Type_Typedef::getAnnotations() const { return annotations; }
#line 3476 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Typedef::operator==(IR::Type_Typedef const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && annotations == a.annotations
        && type == a.type;
    }
bool IR::Type_Typedef::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Type_Typedef &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr);
    }
void IR::Type_Typedef::visit_children(Visitor & v) {
    Type_Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
}
void IR::Type_Typedef::visit_children(Visitor & v) const {
    Type_Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
}
void IR::Type_Typedef::validate() const {
#line 3500 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(type); }
void IR::Type_Typedef::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
}
IR::Type_Typedef::Type_Typedef(JSONLoader & json) : Type_Declaration(json) {
    json.load("annotations", annotations);
    json.load("type", type);
}
IR::Node * IR::Type_Typedef::fromJSON(JSONLoader & json) { return new Type_Typedef(json); }
IR::Type_Typedef::Type_Typedef(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type) :
    Type_Declaration(srcInfo, name), annotations(annotations), type(type)
    { validate(); }
IR::Type_Typedef::Type_Typedef(IR::ID name, const IR::Annotations* annotations, const IR::Type* type) :
    Type_Declaration(name), annotations(annotations), type(type)
    { validate(); }
IR::Type_Typedef::Type_Typedef(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type) :
    Type_Declaration(srcInfo, name), type(type)
    { validate(); }
IR::Type_Typedef::Type_Typedef(IR::ID name, const IR::Type* type) :
    Type_Declaration(name), type(type)
    { validate(); }
#line 610 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
int IR::Type_Newtype::width_bits() const { return type->width_bits(); }
#line 3528 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 611 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::Annotations *IR::Type_Newtype::getAnnotations() const { return annotations; }
#line 3531 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Newtype::operator==(IR::Type_Newtype const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && annotations == a.annotations
        && type == a.type;
    }
bool IR::Type_Newtype::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Type_Newtype &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr);
    }
void IR::Type_Newtype::visit_children(Visitor & v) {
    Type_Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
}
void IR::Type_Newtype::visit_children(Visitor & v) const {
    Type_Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
}
void IR::Type_Newtype::validate() const {
#line 3555 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(type); }
void IR::Type_Newtype::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
}
IR::Type_Newtype::Type_Newtype(JSONLoader & json) : Type_Declaration(json) {
    json.load("annotations", annotations);
    json.load("type", type);
}
IR::Node * IR::Type_Newtype::fromJSON(JSONLoader & json) { return new Type_Newtype(json); }
IR::Type_Newtype::Type_Newtype(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type) :
    Type_Declaration(srcInfo, name), annotations(annotations), type(type)
    { validate(); }
IR::Type_Newtype::Type_Newtype(IR::ID name, const IR::Annotations* annotations, const IR::Type* type) :
    Type_Declaration(name), annotations(annotations), type(type)
    { validate(); }
IR::Type_Newtype::Type_Newtype(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type) :
    Type_Declaration(srcInfo, name), type(type)
    { validate(); }
IR::Type_Newtype::Type_Newtype(IR::ID name, const IR::Type* type) :
    Type_Declaration(name), type(type)
    { validate(); }


#line 623 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
std::vector<const IR::INamespace *> IR::Type_Extern::getNestedNamespaces() const { return { typeParameters }; }
#line 3585 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 624 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Type_Extern::getDeclarations() const {
        return attributes.valueEnumerator()->as<const IDeclaration*>()
            ->concat(methods.getEnumerator()->as<const IDeclaration*>()); }
#line 3590 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 627 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::TypeParameters *IR::Type_Extern::getTypeParameters() const { return typeParameters; }
#line 3593 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 628 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
void IR::Type_Extern::validate() const {
#line 3596 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(typeParameters);
        methods.validate();
        attributes.validate();
        CHECK_NULL(annotations);
#line 628 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
{ methods.check_null(); } }
#line 3604 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 629 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::Annotations *IR::Type_Extern::getAnnotations() const { return annotations; }
#line 3607 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
/// Returns the method that matches the specified arguments.
/// Returns nullptr if no method or more than one method match.
/// In the latter case it also reports an error.
/// Returns the constructor that matches the specified arguments.
/// Returns nullptr if no constructor or more than one constructor matches.
/// In the latter case it also reports an error.
#line 637 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/type.def"
const IR::Method *IR::Type_Extern::lookupConstructor(const IR::Vector<IR::Argument>* arguments) const { return lookupMethod(name, arguments); }
#line 3616 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Extern::operator==(IR::Type_Extern const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && typeParameters == a.typeParameters
        && methods == a.methods
        && attributes == a.attributes
        && annotations == a.annotations;
    }
bool IR::Type_Extern::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Type_Extern &>(a_);
        return (typeParameters ? a.typeParameters ? typeParameters->equiv(*a.typeParameters) : false : a.typeParameters == nullptr)
        && methods.equiv(a.methods)
        && attributes.equiv(a.attributes)
        && (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr);
    }
void IR::Type_Extern::visit_children(Visitor & v) {
    Type_Declaration::visit_children(v);
    v.visit(typeParameters, "typeParameters");
    methods.visit_children(v);
    attributes.visit_children(v);
    v.visit(annotations, "annotations");
}
void IR::Type_Extern::visit_children(Visitor & v) const {
    Type_Declaration::visit_children(v);
    v.visit(typeParameters, "typeParameters");
    methods.visit_children(v);
    attributes.visit_children(v);
    v.visit(annotations, "annotations");
}
void IR::Type_Extern::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"typeParameters\" : " << this->typeParameters;
    json << "," << std::endl << json.indent << "\"methods\" : " << this->methods;
    json << "," << std::endl << json.indent << "\"attributes\" : " << this->attributes;
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
}
IR::Type_Extern::Type_Extern(JSONLoader & json) : Type_Declaration(json) {
    json.load("typeParameters", typeParameters);
    json.load("methods", methods);
    json.load("attributes", attributes);
    json.load("annotations", annotations);
}
IR::Node * IR::Type_Extern::fromJSON(JSONLoader & json) { return new Type_Extern(json); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes, const IR::Annotations* annotations) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters), methods(methods), attributes(attributes), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes, const IR::Annotations* annotations) :
    Type_Declaration(name), typeParameters(typeParameters), methods(methods), attributes(attributes), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes, const IR::Annotations* annotations) :
    Type_Declaration(srcInfo, name), methods(methods), attributes(attributes), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes, const IR::Annotations* annotations) :
    Type_Declaration(name), methods(methods), attributes(attributes), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::NameMap<IR::Attribute, ordered_map> attributes, const IR::Annotations* annotations) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters), attributes(attributes), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, IR::NameMap<IR::Attribute, ordered_map> attributes, const IR::Annotations* annotations) :
    Type_Declaration(name), typeParameters(typeParameters), attributes(attributes), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, IR::NameMap<IR::Attribute, ordered_map> attributes, const IR::Annotations* annotations) :
    Type_Declaration(srcInfo, name), attributes(attributes), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, IR::NameMap<IR::Attribute, ordered_map> attributes, const IR::Annotations* annotations) :
    Type_Declaration(name), attributes(attributes), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods, const IR::Annotations* annotations) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters), methods(methods), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods, const IR::Annotations* annotations) :
    Type_Declaration(name), typeParameters(typeParameters), methods(methods), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Method> methods, const IR::Annotations* annotations) :
    Type_Declaration(srcInfo, name), methods(methods), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, IR::Vector<IR::Method> methods, const IR::Annotations* annotations) :
    Type_Declaration(name), methods(methods), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, const IR::Annotations* annotations) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, const IR::Annotations* annotations) :
    Type_Declaration(name), typeParameters(typeParameters), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Type_Declaration(srcInfo, name), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, const IR::Annotations* annotations) :
    Type_Declaration(name), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters), methods(methods), attributes(attributes)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes) :
    Type_Declaration(name), typeParameters(typeParameters), methods(methods), attributes(attributes)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes) :
    Type_Declaration(srcInfo, name), methods(methods), attributes(attributes)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes) :
    Type_Declaration(name), methods(methods), attributes(attributes)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::NameMap<IR::Attribute, ordered_map> attributes) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters), attributes(attributes)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, IR::NameMap<IR::Attribute, ordered_map> attributes) :
    Type_Declaration(name), typeParameters(typeParameters), attributes(attributes)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, IR::NameMap<IR::Attribute, ordered_map> attributes) :
    Type_Declaration(srcInfo, name), attributes(attributes)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, IR::NameMap<IR::Attribute, ordered_map> attributes) :
    Type_Declaration(name), attributes(attributes)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters), methods(methods)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods) :
    Type_Declaration(name), typeParameters(typeParameters), methods(methods)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Method> methods) :
    Type_Declaration(srcInfo, name), methods(methods)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, IR::Vector<IR::Method> methods) :
    Type_Declaration(name), methods(methods)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Declaration(name), typeParameters(typeParameters)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name) :
    Type_Declaration(srcInfo, name)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name) :
    Type_Declaration(name)
    { validate(); }
bool IR::Operation_Unary::operator==(IR::Operation_Unary const & a) const {
        return Operation::operator==(static_cast<const Operation &>(a))
        && expr == a.expr;
    }
bool IR::Operation_Unary::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation::equiv(a_)) return false;
        auto &a = static_cast<const Operation_Unary &>(a_);
        return (expr ? a.expr ? expr->equiv(*a.expr) : false : a.expr == nullptr);
    }
void IR::Operation_Unary::visit_children(Visitor & v) {
    Operation::visit_children(v);
    v.visit(expr, "expr");
}
void IR::Operation_Unary::visit_children(Visitor & v) const {
    Operation::visit_children(v);
    v.visit(expr, "expr");
}
void IR::Operation_Unary::validate() const {
#line 3776 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(expr); }
void IR::Operation_Unary::toJSON(JSONGenerator & json) const {
    Operation::toJSON(json);
    json << "," << std::endl << json.indent << "\"expr\" : " << this->expr;
}
IR::Operation_Unary::Operation_Unary(JSONLoader & json) : Operation(json) {
    json.load("expr", expr);
}
IR::Operation_Unary::Operation_Unary(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr) :
    Operation(srcInfo, type), expr(expr)
    {
#line 11 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        if (!srcInfo && expr) srcInfo = expr->srcInfo;
        if (type->is<Type::Unknown>() && expr) type = expr->type; }
#line 3793 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Operation_Unary::Operation_Unary(const IR::Type* type, const IR::Expression* expr) :
    Operation(type), expr(expr)
    {
#line 11 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        if (!srcInfo && expr) srcInfo = expr->srcInfo;
        if (type->is<Type::Unknown>() && expr) type = expr->type; }
#line 3802 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Operation_Unary::Operation_Unary(Util::SourceInfo srcInfo, const IR::Expression* expr) :
    Operation(srcInfo), expr(expr)
    {
#line 11 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        if (!srcInfo && expr) srcInfo = expr->srcInfo;
        if (type->is<Type::Unknown>() && expr) type = expr->type; }
#line 3811 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Operation_Unary::Operation_Unary(const IR::Expression* expr) :
    expr(expr)
    {
#line 11 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        if (!srcInfo && expr) srcInfo = expr->srcInfo;
        if (type->is<Type::Unknown>() && expr) type = expr->type; }
#line 3820 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
bool IR::Neg::operator==(IR::Neg const & a) const {
        return Operation_Unary::operator==(static_cast<const Operation_Unary &>(a));
    }
bool IR::Neg::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Unary::equiv(a_)) return false;
        return true;
    }
void IR::Neg::toJSON(JSONGenerator & json) const {
    Operation_Unary::toJSON(json);
}
IR::Neg::Neg(JSONLoader & json) : Operation_Unary(json) {
}
IR::Node * IR::Neg::fromJSON(JSONLoader & json) { return new Neg(json); }
IR::Neg::Neg(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(srcInfo, type, expr)
    { validate(); }
IR::Neg::Neg(const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(type, expr)
    { validate(); }
IR::Neg::Neg(Util::SourceInfo srcInfo, const IR::Expression* expr) :
    Operation_Unary(srcInfo, expr)
    { validate(); }
IR::Neg::Neg(const IR::Expression* expr) :
    Operation_Unary(expr)
    { validate(); }
bool IR::Cmpl::operator==(IR::Cmpl const & a) const {
        return Operation_Unary::operator==(static_cast<const Operation_Unary &>(a));
    }
bool IR::Cmpl::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Unary::equiv(a_)) return false;
        return true;
    }
void IR::Cmpl::toJSON(JSONGenerator & json) const {
    Operation_Unary::toJSON(json);
}
IR::Cmpl::Cmpl(JSONLoader & json) : Operation_Unary(json) {
}
IR::Node * IR::Cmpl::fromJSON(JSONLoader & json) { return new Cmpl(json); }
IR::Cmpl::Cmpl(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(srcInfo, type, expr)
    { validate(); }
IR::Cmpl::Cmpl(const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(type, expr)
    { validate(); }
IR::Cmpl::Cmpl(Util::SourceInfo srcInfo, const IR::Expression* expr) :
    Operation_Unary(srcInfo, expr)
    { validate(); }
IR::Cmpl::Cmpl(const IR::Expression* expr) :
    Operation_Unary(expr)
    { validate(); }
bool IR::LNot::operator==(IR::LNot const & a) const {
        return Operation_Unary::operator==(static_cast<const Operation_Unary &>(a));
    }
bool IR::LNot::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Unary::equiv(a_)) return false;
        return true;
    }
void IR::LNot::toJSON(JSONGenerator & json) const {
    Operation_Unary::toJSON(json);
}
IR::LNot::LNot(JSONLoader & json) : Operation_Unary(json) {
}
IR::Node * IR::LNot::fromJSON(JSONLoader & json) { return new LNot(json); }
IR::LNot::LNot(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(srcInfo, type, expr)
    { validate(); }
IR::LNot::LNot(const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(type, expr)
    { validate(); }
IR::LNot::LNot(Util::SourceInfo srcInfo, const IR::Expression* expr) :
    Operation_Unary(srcInfo, expr)
    { validate(); }
IR::LNot::LNot(const IR::Expression* expr) :
    Operation_Unary(expr)
    { validate(); }
bool IR::Operation_Binary::operator==(IR::Operation_Binary const & a) const {
        return Operation::operator==(static_cast<const Operation &>(a))
        && left == a.left
        && right == a.right;
    }
bool IR::Operation_Binary::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation::equiv(a_)) return false;
        auto &a = static_cast<const Operation_Binary &>(a_);
        return (left ? a.left ? left->equiv(*a.left) : false : a.left == nullptr)
        && (right ? a.right ? right->equiv(*a.right) : false : a.right == nullptr);
    }
void IR::Operation_Binary::visit_children(Visitor & v) {
    Operation::visit_children(v);
    v.visit(left, "left");
    v.visit(right, "right");
}
void IR::Operation_Binary::visit_children(Visitor & v) const {
    Operation::visit_children(v);
    v.visit(left, "left");
    v.visit(right, "right");
}
void IR::Operation_Binary::validate() const {
#line 3923 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(left);
        CHECK_NULL(right); }
void IR::Operation_Binary::toJSON(JSONGenerator & json) const {
    Operation::toJSON(json);
    json << "," << std::endl << json.indent << "\"left\" : " << this->left;
    json << "," << std::endl << json.indent << "\"right\" : " << this->right;
}
IR::Operation_Binary::Operation_Binary(JSONLoader & json) : Operation(json) {
    json.load("left", left);
    json.load("right", right);
}
IR::Operation_Binary::Operation_Binary(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation(srcInfo, type), left(left), right(right)
    {
#line 32 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        if (!srcInfo && left && right) srcInfo = left->srcInfo + right->srcInfo;
        if (type->is<Type::Unknown>() && left && right && left->type == right->type)
            type = left->type; }
#line 3944 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Operation_Binary::Operation_Binary(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation(type), left(left), right(right)
    {
#line 32 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        if (!srcInfo && left && right) srcInfo = left->srcInfo + right->srcInfo;
        if (type->is<Type::Unknown>() && left && right && left->type == right->type)
            type = left->type; }
#line 3954 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Operation_Binary::Operation_Binary(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation(srcInfo), left(left), right(right)
    {
#line 32 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        if (!srcInfo && left && right) srcInfo = left->srcInfo + right->srcInfo;
        if (type->is<Type::Unknown>() && left && right && left->type == right->type)
            type = left->type; }
#line 3964 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Operation_Binary::Operation_Binary(const IR::Expression* left, const IR::Expression* right) :
    left(left), right(right)
    {
#line 32 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        if (!srcInfo && left && right) srcInfo = left->srcInfo + right->srcInfo;
        if (type->is<Type::Unknown>() && left && right && left->type == right->type)
            type = left->type; }
#line 3974 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
bool IR::Operation_Ternary::operator==(IR::Operation_Ternary const & a) const {
        return Operation::operator==(static_cast<const Operation &>(a))
        && e0 == a.e0
        && e1 == a.e1
        && e2 == a.e2;
    }
bool IR::Operation_Ternary::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation::equiv(a_)) return false;
        auto &a = static_cast<const Operation_Ternary &>(a_);
        return (e0 ? a.e0 ? e0->equiv(*a.e0) : false : a.e0 == nullptr)
        && (e1 ? a.e1 ? e1->equiv(*a.e1) : false : a.e1 == nullptr)
        && (e2 ? a.e2 ? e2->equiv(*a.e2) : false : a.e2 == nullptr);
    }
void IR::Operation_Ternary::visit_children(Visitor & v) {
    Operation::visit_children(v);
    v.visit(e0, "e0");
    v.visit(e1, "e1");
    v.visit(e2, "e2");
}
void IR::Operation_Ternary::visit_children(Visitor & v) const {
    Operation::visit_children(v);
    v.visit(e0, "e0");
    v.visit(e1, "e1");
    v.visit(e2, "e2");
}
void IR::Operation_Ternary::validate() const {
#line 4003 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(e0);
        CHECK_NULL(e1);
        CHECK_NULL(e2); }
void IR::Operation_Ternary::toJSON(JSONGenerator & json) const {
    Operation::toJSON(json);
    json << "," << std::endl << json.indent << "\"e0\" : " << this->e0;
    json << "," << std::endl << json.indent << "\"e1\" : " << this->e1;
    json << "," << std::endl << json.indent << "\"e2\" : " << this->e2;
}
IR::Operation_Ternary::Operation_Ternary(JSONLoader & json) : Operation(json) {
    json.load("e0", e0);
    json.load("e1", e1);
    json.load("e2", e2);
}
IR::Operation_Ternary::Operation_Ternary(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation(srcInfo, type), e0(e0), e1(e1), e2(e2)
    {
#line 42 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (!srcInfo && e0 && e2) srcInfo = e0->srcInfo + e2->srcInfo; }
#line 4024 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Operation_Ternary::Operation_Ternary(const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation(type), e0(e0), e1(e1), e2(e2)
    {
#line 42 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (!srcInfo && e0 && e2) srcInfo = e0->srcInfo + e2->srcInfo; }
#line 4031 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Operation_Ternary::Operation_Ternary(Util::SourceInfo srcInfo, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation(srcInfo), e0(e0), e1(e1), e2(e2)
    {
#line 42 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (!srcInfo && e0 && e2) srcInfo = e0->srcInfo + e2->srcInfo; }
#line 4038 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Operation_Ternary::Operation_Ternary(const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    e0(e0), e1(e1), e2(e2)
    {
#line 42 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (!srcInfo && e0 && e2) srcInfo = e0->srcInfo + e2->srcInfo; }
#line 4045 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
bool IR::Operation_Relation::operator==(IR::Operation_Relation const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Operation_Relation::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Operation_Relation::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Operation_Relation::Operation_Relation(JSONLoader & json) : Operation_Binary(json) {
}
IR::Operation_Relation::Operation_Relation(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    {
#line 46 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ type = Type::Boolean::get(); }
#line 4065 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Operation_Relation::Operation_Relation(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    {
#line 46 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ type = Type::Boolean::get(); }
#line 4072 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Operation_Relation::Operation_Relation(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    {
#line 46 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ type = Type::Boolean::get(); }
#line 4079 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Operation_Relation::Operation_Relation(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    {
#line 46 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ type = Type::Boolean::get(); }
#line 4086 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
bool IR::Mul::operator==(IR::Mul const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Mul::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Mul::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Mul::Mul(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Mul::fromJSON(JSONLoader & json) { return new Mul(json); }
IR::Mul::Mul(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
IR::Mul::Mul(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
IR::Mul::Mul(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
IR::Mul::Mul(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
bool IR::Div::operator==(IR::Div const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Div::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Div::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Div::Div(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Div::fromJSON(JSONLoader & json) { return new Div(json); }
IR::Div::Div(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
IR::Div::Div(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
IR::Div::Div(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
IR::Div::Div(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
bool IR::Mod::operator==(IR::Mod const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Mod::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Mod::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Mod::Mod(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Mod::fromJSON(JSONLoader & json) { return new Mod(json); }
IR::Mod::Mod(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
IR::Mod::Mod(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
IR::Mod::Mod(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
IR::Mod::Mod(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
bool IR::Add::operator==(IR::Add const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Add::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Add::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Add::Add(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Add::fromJSON(JSONLoader & json) { return new Add(json); }
IR::Add::Add(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
IR::Add::Add(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
IR::Add::Add(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
IR::Add::Add(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
bool IR::Sub::operator==(IR::Sub const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Sub::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Sub::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Sub::Sub(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Sub::fromJSON(JSONLoader & json) { return new Sub(json); }
IR::Sub::Sub(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
IR::Sub::Sub(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
IR::Sub::Sub(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
IR::Sub::Sub(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
bool IR::AddSat::operator==(IR::AddSat const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::AddSat::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::AddSat::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::AddSat::AddSat(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::AddSat::fromJSON(JSONLoader & json) { return new AddSat(json); }
IR::AddSat::AddSat(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
IR::AddSat::AddSat(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
IR::AddSat::AddSat(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
IR::AddSat::AddSat(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
bool IR::SubSat::operator==(IR::SubSat const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::SubSat::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::SubSat::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::SubSat::SubSat(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::SubSat::fromJSON(JSONLoader & json) { return new SubSat(json); }
IR::SubSat::SubSat(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
IR::SubSat::SubSat(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
IR::SubSat::SubSat(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
IR::SubSat::SubSat(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
bool IR::Shl::operator==(IR::Shl const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Shl::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Shl::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Shl::Shl(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Shl::fromJSON(JSONLoader & json) { return new Shl(json); }
IR::Shl::Shl(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    {
#line 81 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (type->is<Type::Unknown>() && left) type = left->type; }
#line 4289 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Shl::Shl(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    {
#line 81 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (type->is<Type::Unknown>() && left) type = left->type; }
#line 4296 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Shl::Shl(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    {
#line 81 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (type->is<Type::Unknown>() && left) type = left->type; }
#line 4303 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Shl::Shl(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    {
#line 81 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (type->is<Type::Unknown>() && left) type = left->type; }
#line 4310 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
bool IR::Shr::operator==(IR::Shr const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Shr::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Shr::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Shr::Shr(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Shr::fromJSON(JSONLoader & json) { return new Shr(json); }
IR::Shr::Shr(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    {
#line 86 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (type->is<Type::Unknown>() && left) type = left->type; }
#line 4331 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Shr::Shr(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    {
#line 86 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (type->is<Type::Unknown>() && left) type = left->type; }
#line 4338 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Shr::Shr(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    {
#line 86 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (type->is<Type::Unknown>() && left) type = left->type; }
#line 4345 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Shr::Shr(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    {
#line 86 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (type->is<Type::Unknown>() && left) type = left->type; }
#line 4352 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
bool IR::Equ::operator==(IR::Equ const & a) const {
        return Operation_Relation::operator==(static_cast<const Operation_Relation &>(a));
    }
bool IR::Equ::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Relation::equiv(a_)) return false;
        return true;
    }
void IR::Equ::toJSON(JSONGenerator & json) const {
    Operation_Relation::toJSON(json);
}
IR::Equ::Equ(JSONLoader & json) : Operation_Relation(json) {
}
IR::Node * IR::Equ::fromJSON(JSONLoader & json) { return new Equ(json); }
IR::Equ::Equ(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, type, left, right)
    { validate(); }
IR::Equ::Equ(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(type, left, right)
    { validate(); }
IR::Equ::Equ(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, left, right)
    { validate(); }
IR::Equ::Equ(const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(left, right)
    { validate(); }
bool IR::Neq::operator==(IR::Neq const & a) const {
        return Operation_Relation::operator==(static_cast<const Operation_Relation &>(a));
    }
bool IR::Neq::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Relation::equiv(a_)) return false;
        return true;
    }
void IR::Neq::toJSON(JSONGenerator & json) const {
    Operation_Relation::toJSON(json);
}
IR::Neq::Neq(JSONLoader & json) : Operation_Relation(json) {
}
IR::Node * IR::Neq::fromJSON(JSONLoader & json) { return new Neq(json); }
IR::Neq::Neq(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, type, left, right)
    { validate(); }
IR::Neq::Neq(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(type, left, right)
    { validate(); }
IR::Neq::Neq(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, left, right)
    { validate(); }
IR::Neq::Neq(const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(left, right)
    { validate(); }
bool IR::Lss::operator==(IR::Lss const & a) const {
        return Operation_Relation::operator==(static_cast<const Operation_Relation &>(a));
    }
bool IR::Lss::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Relation::equiv(a_)) return false;
        return true;
    }
void IR::Lss::toJSON(JSONGenerator & json) const {
    Operation_Relation::toJSON(json);
}
IR::Lss::Lss(JSONLoader & json) : Operation_Relation(json) {
}
IR::Node * IR::Lss::fromJSON(JSONLoader & json) { return new Lss(json); }
IR::Lss::Lss(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, type, left, right)
    { validate(); }
IR::Lss::Lss(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(type, left, right)
    { validate(); }
IR::Lss::Lss(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, left, right)
    { validate(); }
IR::Lss::Lss(const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(left, right)
    { validate(); }
bool IR::Leq::operator==(IR::Leq const & a) const {
        return Operation_Relation::operator==(static_cast<const Operation_Relation &>(a));
    }
bool IR::Leq::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Relation::equiv(a_)) return false;
        return true;
    }
void IR::Leq::toJSON(JSONGenerator & json) const {
    Operation_Relation::toJSON(json);
}
IR::Leq::Leq(JSONLoader & json) : Operation_Relation(json) {
}
IR::Node * IR::Leq::fromJSON(JSONLoader & json) { return new Leq(json); }
IR::Leq::Leq(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, type, left, right)
    { validate(); }
IR::Leq::Leq(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(type, left, right)
    { validate(); }
IR::Leq::Leq(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, left, right)
    { validate(); }
IR::Leq::Leq(const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(left, right)
    { validate(); }
bool IR::Grt::operator==(IR::Grt const & a) const {
        return Operation_Relation::operator==(static_cast<const Operation_Relation &>(a));
    }
bool IR::Grt::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Relation::equiv(a_)) return false;
        return true;
    }
void IR::Grt::toJSON(JSONGenerator & json) const {
    Operation_Relation::toJSON(json);
}
IR::Grt::Grt(JSONLoader & json) : Operation_Relation(json) {
}
IR::Node * IR::Grt::fromJSON(JSONLoader & json) { return new Grt(json); }
IR::Grt::Grt(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, type, left, right)
    { validate(); }
IR::Grt::Grt(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(type, left, right)
    { validate(); }
IR::Grt::Grt(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, left, right)
    { validate(); }
IR::Grt::Grt(const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(left, right)
    { validate(); }
bool IR::Geq::operator==(IR::Geq const & a) const {
        return Operation_Relation::operator==(static_cast<const Operation_Relation &>(a));
    }
bool IR::Geq::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Relation::equiv(a_)) return false;
        return true;
    }
void IR::Geq::toJSON(JSONGenerator & json) const {
    Operation_Relation::toJSON(json);
}
IR::Geq::Geq(JSONLoader & json) : Operation_Relation(json) {
}
IR::Node * IR::Geq::fromJSON(JSONLoader & json) { return new Geq(json); }
IR::Geq::Geq(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, type, left, right)
    { validate(); }
IR::Geq::Geq(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(type, left, right)
    { validate(); }
IR::Geq::Geq(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, left, right)
    { validate(); }
IR::Geq::Geq(const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(left, right)
    { validate(); }
bool IR::BAnd::operator==(IR::BAnd const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::BAnd::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::BAnd::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::BAnd::BAnd(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::BAnd::fromJSON(JSONLoader & json) { return new BAnd(json); }
IR::BAnd::BAnd(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
IR::BAnd::BAnd(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
IR::BAnd::BAnd(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
IR::BAnd::BAnd(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
bool IR::BOr::operator==(IR::BOr const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::BOr::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::BOr::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::BOr::BOr(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::BOr::fromJSON(JSONLoader & json) { return new BOr(json); }
IR::BOr::BOr(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
IR::BOr::BOr(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
IR::BOr::BOr(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
IR::BOr::BOr(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
bool IR::BXor::operator==(IR::BXor const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::BXor::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::BXor::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::BXor::BXor(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::BXor::fromJSON(JSONLoader & json) { return new BXor(json); }
IR::BXor::BXor(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
IR::BXor::BXor(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
IR::BXor::BXor(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
IR::BXor::BXor(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
bool IR::LAnd::operator==(IR::LAnd const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::LAnd::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::LAnd::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::LAnd::LAnd(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::LAnd::fromJSON(JSONLoader & json) { return new LAnd(json); }
IR::LAnd::LAnd(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
IR::LAnd::LAnd(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
IR::LAnd::LAnd(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
IR::LAnd::LAnd(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
bool IR::LOr::operator==(IR::LOr const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::LOr::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::LOr::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::LOr::LOr(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::LOr::fromJSON(JSONLoader & json) { return new LOr(json); }
IR::LOr::LOr(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
IR::LOr::LOr(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
IR::LOr::LOr(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
IR::LOr::LOr(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
bool IR::Literal::operator==(IR::Literal const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a));
    }
bool IR::Literal::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        return true;
    }
void IR::Literal::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
}
IR::Literal::Literal(JSONLoader & json) : Expression(json) {
}
IR::Literal::Literal(Util::SourceInfo srcInfo, const IR::Type* type) :
    Expression(srcInfo, type)
    { validate(); }
IR::Literal::Literal(const IR::Type* type) :
    Expression(type)
    { validate(); }
IR::Literal::Literal(Util::SourceInfo srcInfo) :
    Expression(srcInfo)
    { validate(); }
IR::Literal::Literal() 
    { validate(); }
/// base used when reading/writing
/// if noWarning is true, no warning is emitted



#line 147 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
IR::Constant::Constant(int v, unsigned base) :
        Literal(new Type_InfInt()), value(v), base(base) {}
#line 4672 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 149 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
IR::Constant::Constant(unsigned v, unsigned base) :
        Literal(new Type_InfInt()), value(v), base(base) {}
#line 4676 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 164 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
IR::Constant::Constant(uint64_t v, unsigned base) :
        Literal(new Type_InfInt()), value(v), base(base) {}
#line 4680 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 166 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
IR::Constant::Constant(big_int v, unsigned base) :
        Literal(new Type_InfInt()), value(v), base(base) {}
#line 4684 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 168 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
IR::Constant::Constant(Util::SourceInfo si, big_int v, unsigned base) :
        Literal(si, new Type_InfInt()), value(v), base(base) {}
#line 4688 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 170 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
IR::Constant::Constant(IR::Type const * t, big_int v, unsigned base, bool noWarning) :
        Literal(t), value(v), base(base) { CHECK_NULL(t); handleOverflow(noWarning); }
#line 4692 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 172 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
IR::Constant::Constant(Util::SourceInfo si, IR::Type const * t, big_int v, unsigned base, bool noWarning) :
        Literal(si, t), value(v), base(base) { CHECK_NULL(t); handleOverflow(noWarning); }
#line 4696 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 178 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
bool IR::Constant::fitsInt() const { return value >= INT_MIN && value <= INT_MAX; }
#line 4699 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 179 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
bool IR::Constant::fitsLong() const { return value >= LONG_MIN && value <= LONG_MAX; }
#line 4702 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 180 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
bool IR::Constant::fitsUint() const { return value >= 0 && value <= UINT_MAX; }
#line 4705 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 181 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
bool IR::Constant::fitsUint64() const { return value >= 0 && value <= UINT64_MAX; }
#line 4708 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 182 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
bool IR::Constant::fitsInt64() const { return value >= INT64_MIN && value <= INT64_MAX; }
#line 4711 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 183 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
long IR::Constant::asLong() const {
        if (!fitsLong())
            ::error(ErrorType::ERR_OVERLIMIT, "%1$x: Value too large for long", this);
        return static_cast<long>(value); }
#line 4717 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 187 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
int IR::Constant::asInt() const {
        if (!fitsInt())
            ::error(ErrorType::ERR_OVERLIMIT, "%1$x: Value too large for int", this);
        return static_cast<int>(value); }
#line 4723 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 191 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
unsigned IR::Constant::asUnsigned() const {
        if (!fitsUint())
            ::error(ErrorType::ERR_OVERLIMIT, "%1$x: Value too large for unsigned int", this);
        return static_cast<unsigned>(value);
    }
#line 4730 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 196 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
uint64_t IR::Constant::asUint64() const {
        if (!fitsUint64())
            ::error(ErrorType::ERR_OVERLIMIT, "%1$x: Value too large for uint64", this);
        return static_cast<uint64_t>(value);
    }
#line 4737 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 201 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
int64_t IR::Constant::asInt64() const {
        if (!fitsInt64())
            ::error(ErrorType::ERR_OVERLIMIT, "%1$x: Value too large for int64", this);
        return static_cast<int64_t>(value);
    }
#line 4744 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"



#line 218 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
cstring IR::Constant::toString() const {
        const IR::Type_Bits* tb = dynamic_cast<const IR::Type_Bits*>(type);
        unsigned width;
        bool sign;
        if (tb == nullptr) {
            width = 0;
            sign = false;
        } else {
            width = tb->size;
            sign = tb->isSigned;
        }
        return Util::toString(value, width, sign, base);
    }
#line 4762 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 231 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
void IR::Constant::visit_children(Visitor & v) { v.visit(type, "type"); }
#line 231 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
void IR::Constant::visit_children(Visitor & v) const { v.visit(type, "type"); }
#line 4767 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Constant::operator==(IR::Constant const & a) const {
        return Literal::operator==(static_cast<const Literal &>(a))
        && value == a.value
        && base == a.base;
    }
bool IR::Constant::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Literal::equiv(a_)) return false;
        auto &a = static_cast<const Constant &>(a_);
        return value == a.value
        && base == a.base;
    }
void IR::Constant::dump_fields(std::ostream & out) const {
    Literal::dump_fields(out);
        out << " value=" << value;
        out << " base=" << base;
}
void IR::Constant::toJSON(JSONGenerator & json) const {
    Literal::toJSON(json);
    json << "," << std::endl << json.indent << "\"value\" : " << this->value;
    json << "," << std::endl << json.indent << "\"base\" : " << this->base;
}
IR::Constant::Constant(JSONLoader & json) : Literal(json) {
    json.load("value", value);
    json.load("base", base);
}
IR::Node * IR::Constant::fromJSON(JSONLoader & json) { return new Constant(json); }
#line 236 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
cstring IR::BoolLiteral::toString() const { return value ? "true" : "false"; }
#line 4797 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::BoolLiteral::operator==(IR::BoolLiteral const & a) const {
        return Literal::operator==(static_cast<const Literal &>(a))
        && value == a.value;
    }
bool IR::BoolLiteral::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Literal::equiv(a_)) return false;
        auto &a = static_cast<const BoolLiteral &>(a_);
        return value == a.value;
    }
void IR::BoolLiteral::dump_fields(std::ostream & out) const {
    Literal::dump_fields(out);
        out << " value=" << value;
}
void IR::BoolLiteral::toJSON(JSONGenerator & json) const {
    Literal::toJSON(json);
    json << "," << std::endl << json.indent << "\"value\" : " << this->value;
}
IR::BoolLiteral::BoolLiteral(JSONLoader & json) : Literal(json) {
    json.load("value", value);
}
IR::Node * IR::BoolLiteral::fromJSON(JSONLoader & json) { return new BoolLiteral(json); }
IR::BoolLiteral::BoolLiteral(Util::SourceInfo srcInfo, const IR::Type* type, bool value) :
    Literal(srcInfo, type), value(value)
    { validate(); }
IR::BoolLiteral::BoolLiteral(const IR::Type* type, bool value) :
    Literal(type), value(value)
    { validate(); }
IR::BoolLiteral::BoolLiteral(Util::SourceInfo srcInfo, bool value) :
    Literal(srcInfo), value(value)
    { validate(); }
IR::BoolLiteral::BoolLiteral(bool value) :
    value(value)
    { validate(); }
#line 241 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
void IR::StringLiteral::validate() const {
#line 4834 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

#line 241 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (value.isNull()) BUG("null StringLiteral"); } }
#line 4838 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 242 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
cstring IR::StringLiteral::toString() const { return cstring("\"") + value + "\""; }
#line 4841 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 243 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
IR::StringLiteral::StringLiteral(IR::ID v) : Literal(v.srcInfo), value(v.name) {}
#line 4844 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::StringLiteral::operator==(IR::StringLiteral const & a) const {
        return Literal::operator==(static_cast<const Literal &>(a))
        && value == a.value;
    }
bool IR::StringLiteral::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Literal::equiv(a_)) return false;
        auto &a = static_cast<const StringLiteral &>(a_);
        return value == a.value;
    }
void IR::StringLiteral::dump_fields(std::ostream & out) const {
    Literal::dump_fields(out);
        out << " value=" << value;
}
void IR::StringLiteral::toJSON(JSONGenerator & json) const {
    Literal::toJSON(json);
    json << "," << std::endl << json.indent << "\"value\" : " << this->value;
}
IR::StringLiteral::StringLiteral(JSONLoader & json) : Literal(json) {
    json.load("value", value);
}
IR::Node * IR::StringLiteral::fromJSON(JSONLoader & json) { return new StringLiteral(json); }
IR::StringLiteral::StringLiteral(Util::SourceInfo srcInfo, const IR::Type* type, cstring value) :
    Literal(srcInfo, type), value(value)
    { validate(); }
IR::StringLiteral::StringLiteral(const IR::Type* type, cstring value) :
    Literal(type), value(value)
    { validate(); }
IR::StringLiteral::StringLiteral(Util::SourceInfo srcInfo, cstring value) :
    Literal(srcInfo), value(value)
    { validate(); }
IR::StringLiteral::StringLiteral(cstring value) :
    value(value)
    { validate(); }
#line 252 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
IR::PathExpression::PathExpression(IR::ID id) : Expression(id.srcInfo), path(new IR::Path(id)) {}
#line 4881 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 253 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
cstring IR::PathExpression::toString() const { return path->toString(); }
#line 4884 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::PathExpression::operator==(IR::PathExpression const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && path == a.path;
    }
bool IR::PathExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const PathExpression &>(a_);
        return (path ? a.path ? path->equiv(*a.path) : false : a.path == nullptr);
    }
void IR::PathExpression::visit_children(Visitor & v) {
    Expression::visit_children(v);
    v.visit(path, "path");
}
void IR::PathExpression::visit_children(Visitor & v) const {
    Expression::visit_children(v);
    v.visit(path, "path");
}
void IR::PathExpression::validate() const {
#line 4904 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(path); }
void IR::PathExpression::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"path\" : " << this->path;
}
IR::PathExpression::PathExpression(JSONLoader & json) : Expression(json) {
    json.load("path", path);
}
IR::Node * IR::PathExpression::fromJSON(JSONLoader & json) { return new PathExpression(json); }
IR::PathExpression::PathExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Path* path) :
    Expression(srcInfo, type), path(path)
    {
#line 251 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (!srcInfo && path) srcInfo = path->srcInfo; }
#line 4920 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::PathExpression::PathExpression(const IR::Type* type, const IR::Path* path) :
    Expression(type), path(path)
    {
#line 251 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (!srcInfo && path) srcInfo = path->srcInfo; }
#line 4927 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::PathExpression::PathExpression(Util::SourceInfo srcInfo, const IR::Path* path) :
    Expression(srcInfo), path(path)
    {
#line 251 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (!srcInfo && path) srcInfo = path->srcInfo; }
#line 4934 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::PathExpression::PathExpression(const IR::Path* path) :
    path(path)
    {
#line 251 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (!srcInfo && path) srcInfo = path->srcInfo; }
#line 4941 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
#line 262 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
IR::TypeNameExpression::TypeNameExpression(IR::ID id) : Expression(id.srcInfo),
                                typeName(new IR::Type_Name(new IR::Path(id))) {}
#line 4946 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 264 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
void IR::TypeNameExpression::dbprint(std::ostream & out) const { out << typeName; }
#line 4949 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 265 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
cstring IR::TypeNameExpression::toString() const { return typeName->toString(); }
#line 4952 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::TypeNameExpression::operator==(IR::TypeNameExpression const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && typeName == a.typeName;
    }
bool IR::TypeNameExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const TypeNameExpression &>(a_);
        return (typeName ? a.typeName ? typeName->equiv(*a.typeName) : false : a.typeName == nullptr);
    }
void IR::TypeNameExpression::visit_children(Visitor & v) {
    Expression::visit_children(v);
    v.visit(typeName, "typeName");
}
void IR::TypeNameExpression::visit_children(Visitor & v) const {
    Expression::visit_children(v);
    v.visit(typeName, "typeName");
}
void IR::TypeNameExpression::validate() const {
#line 4972 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(typeName); }
void IR::TypeNameExpression::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"typeName\" : " << this->typeName;
}
IR::TypeNameExpression::TypeNameExpression(JSONLoader & json) : Expression(json) {
    json.load("typeName", typeName);
}
IR::Node * IR::TypeNameExpression::fromJSON(JSONLoader & json) { return new TypeNameExpression(json); }
IR::TypeNameExpression::TypeNameExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Type_Name* typeName) :
    Expression(srcInfo, type), typeName(typeName)
    {
#line 261 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (!srcInfo && typeName) srcInfo = typeName->srcInfo; }
#line 4988 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::TypeNameExpression::TypeNameExpression(const IR::Type* type, const IR::Type_Name* typeName) :
    Expression(type), typeName(typeName)
    {
#line 261 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (!srcInfo && typeName) srcInfo = typeName->srcInfo; }
#line 4995 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::TypeNameExpression::TypeNameExpression(Util::SourceInfo srcInfo, const IR::Type_Name* typeName) :
    Expression(srcInfo), typeName(typeName)
    {
#line 261 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (!srcInfo && typeName) srcInfo = typeName->srcInfo; }
#line 5002 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::TypeNameExpression::TypeNameExpression(const IR::Type_Name* typeName) :
    typeName(typeName)
    {
#line 261 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (!srcInfo && typeName) srcInfo = typeName->srcInfo; }
#line 5009 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
#line 271 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
cstring IR::Slice::toString() const { return e0->toString() + "[" + e1->toString() + ":" + e2->toString() + "]"; }
#line 5013 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

#line 273 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
unsigned IR::Slice::getH() const { return e1->to<IR::Constant>()->asUnsigned(); }
#line 5017 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 274 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
unsigned IR::Slice::getL() const { return e2->to<IR::Constant>()->asUnsigned(); }
#line 5020 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 275 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
IR::Slice::Slice(const IR::Expression* a, int hi, int lo) : Operation_Ternary(IR::Type::Bits::get(hi-lo+1), a, new Constant(hi), new Constant(lo)) {}
#line 5023 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 277 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
IR::Slice::Slice(Util::SourceInfo si, const IR::Expression* a, int hi, int lo) : Operation_Ternary(si, IR::Type::Bits::get(hi-lo+1), a, new Constant(hi), new Constant(lo)) {}
#line 5026 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

bool IR::Slice::operator==(IR::Slice const & a) const {
        return Operation_Ternary::operator==(static_cast<const Operation_Ternary &>(a));
    }
bool IR::Slice::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Ternary::equiv(a_)) return false;
        return true;
    }
void IR::Slice::toJSON(JSONGenerator & json) const {
    Operation_Ternary::toJSON(json);
}
IR::Slice::Slice(JSONLoader & json) : Operation_Ternary(json) {
}
IR::Node * IR::Slice::fromJSON(JSONLoader & json) { return new Slice(json); }
IR::Slice::Slice(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation_Ternary(srcInfo, type, e0, e1, e2)
    {
#line 279 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        if (type->is<Type::Unknown>() && e1 && e1->is<Constant>() && e2 && e2->is<Constant>())
            type = IR::Type::Bits::get(getH() - getL() + 1); }
#line 5049 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Slice::Slice(const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation_Ternary(type, e0, e1, e2)
    {
#line 279 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        if (type->is<Type::Unknown>() && e1 && e1->is<Constant>() && e2 && e2->is<Constant>())
            type = IR::Type::Bits::get(getH() - getL() + 1); }
#line 5058 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Slice::Slice(Util::SourceInfo srcInfo, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation_Ternary(srcInfo, e0, e1, e2)
    {
#line 279 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        if (type->is<Type::Unknown>() && e1 && e1->is<Constant>() && e2 && e2->is<Constant>())
            type = IR::Type::Bits::get(getH() - getL() + 1); }
#line 5067 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Slice::Slice(const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation_Ternary(e0, e1, e2)
    {
#line 279 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        if (type->is<Type::Unknown>() && e1 && e1->is<Constant>() && e2 && e2->is<Constant>())
            type = IR::Type::Bits::get(getH() - getL() + 1); }
#line 5076 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
#line 293 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
cstring IR::Member::toString() const { return expr->toString() + "." + member; }
#line 5080 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Member::operator==(IR::Member const & a) const {
        return Operation_Unary::operator==(static_cast<const Operation_Unary &>(a))
        && member == a.member;
    }
bool IR::Member::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Unary::equiv(a_)) return false;
        auto &a = static_cast<const Member &>(a_);
        return member == a.member;
    }
void IR::Member::dump_fields(std::ostream & out) const {
    Operation_Unary::dump_fields(out);
        out << " member=" << member;
}
void IR::Member::toJSON(JSONGenerator & json) const {
    Operation_Unary::toJSON(json);
    json << "," << std::endl << json.indent << "\"member\" : " << this->member;
}
IR::Member::Member(JSONLoader & json) : Operation_Unary(json) {
    json.load("member", member);
}
IR::Node * IR::Member::fromJSON(JSONLoader & json) { return new Member(json); }
IR::Member::Member(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr, IR::ID member) :
    Operation_Unary(srcInfo, type, expr), member(member)
    { validate(); }
IR::Member::Member(const IR::Type* type, const IR::Expression* expr, IR::ID member) :
    Operation_Unary(type, expr), member(member)
    { validate(); }
IR::Member::Member(Util::SourceInfo srcInfo, const IR::Expression* expr, IR::ID member) :
    Operation_Unary(srcInfo, expr), member(member)
    { validate(); }
IR::Member::Member(const IR::Expression* expr, IR::ID member) :
    Operation_Unary(expr), member(member)
    { validate(); }
bool IR::Concat::operator==(IR::Concat const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Concat::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Concat::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Concat::Concat(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Concat::fromJSON(JSONLoader & json) { return new Concat(json); }
IR::Concat::Concat(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    {
#line 299 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        if (left && right) {
            auto lt = left->type->to<IR::Type::Bits>();
            auto rt = right->type->to<IR::Type::Bits>();
            if (lt && rt)
                type = IR::Type::Bits::get(lt->size + rt->size, lt->isSigned); } }
#line 5139 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Concat::Concat(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    {
#line 299 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        if (left && right) {
            auto lt = left->type->to<IR::Type::Bits>();
            auto rt = right->type->to<IR::Type::Bits>();
            if (lt && rt)
                type = IR::Type::Bits::get(lt->size + rt->size, lt->isSigned); } }
#line 5151 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Concat::Concat(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    {
#line 299 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        if (left && right) {
            auto lt = left->type->to<IR::Type::Bits>();
            auto rt = right->type->to<IR::Type::Bits>();
            if (lt && rt)
                type = IR::Type::Bits::get(lt->size + rt->size, lt->isSigned); } }
#line 5163 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Concat::Concat(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    {
#line 299 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        if (left && right) {
            auto lt = left->type->to<IR::Type::Bits>();
            auto rt = right->type->to<IR::Type::Bits>();
            if (lt && rt)
                type = IR::Type::Bits::get(lt->size + rt->size, lt->isSigned); } }
#line 5175 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
#line 313 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
cstring IR::ArrayIndex::toString() const { return left->toString() + "[" + right->toString() + "]"; }
#line 5179 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::ArrayIndex::operator==(IR::ArrayIndex const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::ArrayIndex::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::ArrayIndex::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::ArrayIndex::ArrayIndex(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::ArrayIndex::fromJSON(JSONLoader & json) { return new ArrayIndex(json); }
IR::ArrayIndex::ArrayIndex(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    {
#line 310 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        if (auto st = left ? left->type->to<IR::Type_Stack>() : nullptr)
            type = st->elementType; }
#line 5201 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::ArrayIndex::ArrayIndex(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    {
#line 310 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        if (auto st = left ? left->type->to<IR::Type_Stack>() : nullptr)
            type = st->elementType; }
#line 5210 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::ArrayIndex::ArrayIndex(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    {
#line 310 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        if (auto st = left ? left->type->to<IR::Type_Stack>() : nullptr)
            type = st->elementType; }
#line 5219 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::ArrayIndex::ArrayIndex(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    {
#line 310 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        if (auto st = left ? left->type->to<IR::Type_Stack>() : nullptr)
            type = st->elementType; }
#line 5228 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
bool IR::Range::operator==(IR::Range const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Range::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Range::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Range::Range(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Range::fromJSON(JSONLoader & json) { return new Range(json); }
IR::Range::Range(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    {
#line 319 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (left && type == left->type && !left->type->is<Type::Unknown>())
                type = new Type_Set(left->type); }
#line 5250 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Range::Range(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    {
#line 319 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (left && type == left->type && !left->type->is<Type::Unknown>())
                type = new Type_Set(left->type); }
#line 5258 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Range::Range(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    {
#line 319 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (left && type == left->type && !left->type->is<Type::Unknown>())
                type = new Type_Set(left->type); }
#line 5266 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Range::Range(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    {
#line 319 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (left && type == left->type && !left->type->is<Type::Unknown>())
                type = new Type_Set(left->type); }
#line 5274 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
bool IR::Mask::operator==(IR::Mask const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Mask::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Mask::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Mask::Mask(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Mask::fromJSON(JSONLoader & json) { return new Mask(json); }
IR::Mask::Mask(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    {
#line 326 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (left && type == left->type && !left->type->is<Type::Unknown>())
                type = new Type_Set(left->type); }
#line 5296 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Mask::Mask(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    {
#line 326 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (left && type == left->type && !left->type->is<Type::Unknown>())
                type = new Type_Set(left->type); }
#line 5304 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Mask::Mask(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    {
#line 326 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (left && type == left->type && !left->type->is<Type::Unknown>())
                type = new Type_Set(left->type); }
#line 5312 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Mask::Mask(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    {
#line 326 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (left && type == left->type && !left->type->is<Type::Unknown>())
                type = new Type_Set(left->type); }
#line 5320 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
#line 333 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
void IR::Mux::visit_children(Visitor & v) {
        v.visit(e0, "e0");
        auto &clone(v.flow_clone());
        v.visit(e1, "e1");
        clone.visit(e2, "e2");
        v.flow_merge(clone); }
#line 333 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
void IR::Mux::visit_children(Visitor & v) const {
        v.visit(e0, "e0");
        auto &clone(v.flow_clone());
        v.visit(e1, "e1");
        clone.visit(e2, "e2");
        v.flow_merge(clone); }
#line 5336 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Mux::operator==(IR::Mux const & a) const {
        return Operation_Ternary::operator==(static_cast<const Operation_Ternary &>(a));
    }
bool IR::Mux::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Ternary::equiv(a_)) return false;
        return true;
    }
void IR::Mux::toJSON(JSONGenerator & json) const {
    Operation_Ternary::toJSON(json);
}
IR::Mux::Mux(JSONLoader & json) : Operation_Ternary(json) {
}
IR::Node * IR::Mux::fromJSON(JSONLoader & json) { return new Mux(json); }
IR::Mux::Mux(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation_Ternary(srcInfo, type, e0, e1, e2)
    {
#line 339 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (type->is<Type::Unknown>() && e1 && e2 && e1->type == e2->type) type = e1->type; }
#line 5356 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Mux::Mux(const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation_Ternary(type, e0, e1, e2)
    {
#line 339 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (type->is<Type::Unknown>() && e1 && e2 && e1->type == e2->type) type = e1->type; }
#line 5363 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Mux::Mux(Util::SourceInfo srcInfo, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation_Ternary(srcInfo, e0, e1, e2)
    {
#line 339 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (type->is<Type::Unknown>() && e1 && e2 && e1->type == e2->type) type = e1->type; }
#line 5370 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::Mux::Mux(const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation_Ternary(e0, e1, e2)
    {
#line 339 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ if (type->is<Type::Unknown>() && e1 && e2 && e1->type == e2->type) type = e1->type; }
#line 5377 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
bool IR::DefaultExpression::operator==(IR::DefaultExpression const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a));
    }
bool IR::DefaultExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        return true;
    }
void IR::DefaultExpression::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
}
IR::DefaultExpression::DefaultExpression(JSONLoader & json) : Expression(json) {
}
IR::Node * IR::DefaultExpression::fromJSON(JSONLoader & json) { return new DefaultExpression(json); }
IR::DefaultExpression::DefaultExpression(Util::SourceInfo srcInfo, const IR::Type* type) :
    Expression(srcInfo, type)
    { validate(); }
IR::DefaultExpression::DefaultExpression(const IR::Type* type) :
    Expression(type)
    { validate(); }
IR::DefaultExpression::DefaultExpression(Util::SourceInfo srcInfo) :
    Expression(srcInfo)
    { validate(); }
IR::DefaultExpression::DefaultExpression() 
    { validate(); }
bool IR::This::operator==(IR::This const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && id == a.id;
    }
bool IR::This::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const This &>(a_);
        return id == a.id;
    }
void IR::This::dump_fields(std::ostream & out) const {
    Expression::dump_fields(out);
        out << " id=" << id;
}
void IR::This::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"id\" : " << this->id;
}
IR::This::This(JSONLoader & json) : Expression(json) {
    json.load("id", id);
}
IR::Node * IR::This::fromJSON(JSONLoader & json) { return new This(json); }
IR::This::This(Util::SourceInfo srcInfo, const IR::Type* type) :
    Expression(srcInfo, type)
    { validate(); }
IR::This::This(const IR::Type* type) :
    Expression(type)
    { validate(); }
IR::This::This(Util::SourceInfo srcInfo) :
    Expression(srcInfo)
    { validate(); }
IR::This::This() 
    { validate(); }
/// These will generally always be the same, except when a cast to a type argument of
/// a generic occurs.  Then at some point, the 'destType' will be specialized to a concrete
/// type, and 'type' will only be updated later when type inferencing occurs
#line 359 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
cstring IR::Cast::toString() const { return "cast"; }
#line 5442 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 360 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
void IR::Cast::validate() const {
#line 5445 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(destType);
#line 360 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ BUG_CHECK(!destType->is<Type_Unknown>(), "%1%: Cannot cast to unknown type", this); } }
#line 5450 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Cast::operator==(IR::Cast const & a) const {
        return Operation_Unary::operator==(static_cast<const Operation_Unary &>(a))
        && destType == a.destType;
    }
bool IR::Cast::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Unary::equiv(a_)) return false;
        auto &a = static_cast<const Cast &>(a_);
        return (destType ? a.destType ? destType->equiv(*a.destType) : false : a.destType == nullptr);
    }
void IR::Cast::visit_children(Visitor & v) {
    Operation_Unary::visit_children(v);
    v.visit(destType, "destType");
}
void IR::Cast::visit_children(Visitor & v) const {
    Operation_Unary::visit_children(v);
    v.visit(destType, "destType");
}
void IR::Cast::toJSON(JSONGenerator & json) const {
    Operation_Unary::toJSON(json);
    json << "," << std::endl << json.indent << "\"destType\" : " << this->destType;
}
IR::Cast::Cast(JSONLoader & json) : Operation_Unary(json) {
    json.load("destType", destType);
}
IR::Node * IR::Cast::fromJSON(JSONLoader & json) { return new Cast(json); }
IR::Cast::Cast(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(srcInfo, type, expr)
    { validate(); }
IR::Cast::Cast(const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(type, expr)
    { validate(); }
IR::Cast::Cast(Util::SourceInfo srcInfo, const IR::Expression* expr) :
    Operation_Unary(srcInfo, expr)
    { validate(); }
IR::Cast::Cast(const IR::Expression* expr) :
    Operation_Unary(expr)
    { validate(); }
#line 366 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
void IR::SelectCase::dbprint(std::ostream & out) const { out << keyset << ": " << state; }
#line 5491 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::SelectCase::operator==(IR::SelectCase const & a) const {
        return typeid(*this) == typeid(a)
        && keyset == a.keyset
        && state == a.state;
    }
bool IR::SelectCase::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const SelectCase &>(a_);
        return (keyset ? a.keyset ? keyset->equiv(*a.keyset) : false : a.keyset == nullptr)
        && (state ? a.state ? state->equiv(*a.state) : false : a.state == nullptr);
    }
void IR::SelectCase::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(keyset, "keyset");
    v.visit(state, "state");
}
void IR::SelectCase::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(keyset, "keyset");
    v.visit(state, "state");
}
void IR::SelectCase::validate() const {
#line 5515 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(keyset);
        CHECK_NULL(state); }
void IR::SelectCase::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"keyset\" : " << this->keyset;
    json << "," << std::endl << json.indent << "\"state\" : " << this->state;
}
IR::SelectCase::SelectCase(JSONLoader & json) : Node(json) {
    json.load("keyset", keyset);
    json.load("state", state);
}
IR::Node * IR::SelectCase::fromJSON(JSONLoader & json) { return new SelectCase(json); }
IR::SelectCase::SelectCase(Util::SourceInfo srcInfo, const IR::Expression* keyset, const IR::PathExpression* state) :
    Node(srcInfo), keyset(keyset), state(state)
    { validate(); }
IR::SelectCase::SelectCase(const IR::Expression* keyset, const IR::PathExpression* state) :
    keyset(keyset), state(state)
    { validate(); }
#line 372 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
void IR::SelectExpression::visit_children(Visitor & v) {
        v.visit(select, "select");
        v.parallel_visit(selectCases, "selectCases"); }
#line 372 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
void IR::SelectExpression::visit_children(Visitor & v) const {
        v.visit(select, "select");
        v.parallel_visit(selectCases, "selectCases"); }
#line 5543 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::SelectExpression::operator==(IR::SelectExpression const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && select == a.select
        && selectCases == a.selectCases;
    }
bool IR::SelectExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const SelectExpression &>(a_);
        return (select ? a.select ? select->equiv(*a.select) : false : a.select == nullptr)
        && selectCases.equiv(a.selectCases);
    }
void IR::SelectExpression::validate() const {
#line 5557 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(select);
        selectCases.validate(); }
void IR::SelectExpression::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"select\" : " << this->select;
    json << "," << std::endl << json.indent << "\"selectCases\" : " << this->selectCases;
}
IR::SelectExpression::SelectExpression(JSONLoader & json) : Expression(json) {
    json.load("select", select);
    json.load("selectCases", selectCases);
}
IR::Node * IR::SelectExpression::fromJSON(JSONLoader & json) { return new SelectExpression(json); }
IR::SelectExpression::SelectExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::ListExpression* select, IR::Vector<IR::SelectCase> selectCases) :
    Expression(srcInfo, type), select(select), selectCases(selectCases)
    { validate(); }
IR::SelectExpression::SelectExpression(const IR::Type* type, const IR::ListExpression* select, IR::Vector<IR::SelectCase> selectCases) :
    Expression(type), select(select), selectCases(selectCases)
    { validate(); }
IR::SelectExpression::SelectExpression(Util::SourceInfo srcInfo, const IR::ListExpression* select, IR::Vector<IR::SelectCase> selectCases) :
    Expression(srcInfo), select(select), selectCases(selectCases)
    { validate(); }
IR::SelectExpression::SelectExpression(const IR::ListExpression* select, IR::Vector<IR::SelectCase> selectCases) :
    select(select), selectCases(selectCases)
    { validate(); }
#line 381 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
cstring IR::MethodCallExpression::toString() const { return method->toString(); }
#line 5585 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 382 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
void IR::MethodCallExpression::validate() const {
#line 5588 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(method);
        CHECK_NULL(typeArguments);
        CHECK_NULL(arguments);
#line 382 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ typeArguments->check_null(); arguments->check_null(); } }
#line 5595 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 383 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
IR::MethodCallExpression::MethodCallExpression(Util::SourceInfo si, IR::ID m, std::initializer_list<const IR::Argument *> const & a) : Expression(si), method(new PathExpression(m)), arguments(new Vector<Argument>(a)) {}
#line 5598 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 385 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
IR::MethodCallExpression::MethodCallExpression(Util::SourceInfo si, const IR::Expression* m, std::initializer_list<const IR::Argument *> const & a) : Expression(si), method(m), arguments(new Vector<Argument>(a)) {}
#line 5601 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 388 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
IR::MethodCallExpression::MethodCallExpression(const IR::Expression* m, std::initializer_list<IR::Expression const *> const & a) : method(m), arguments(nullptr)  {
        auto arguments = new Vector<Argument>;
        for (auto arg : a) arguments->push_back(new Argument(arg));
        this->arguments = arguments; }
#line 5607 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::MethodCallExpression::operator==(IR::MethodCallExpression const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && method == a.method
        && typeArguments == a.typeArguments
        && arguments == a.arguments;
    }
bool IR::MethodCallExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const MethodCallExpression &>(a_);
        return (method ? a.method ? method->equiv(*a.method) : false : a.method == nullptr)
        && (typeArguments ? a.typeArguments ? typeArguments->equiv(*a.typeArguments) : false : a.typeArguments == nullptr)
        && (arguments ? a.arguments ? arguments->equiv(*a.arguments) : false : a.arguments == nullptr);
    }
void IR::MethodCallExpression::visit_children(Visitor & v) {
    Expression::visit_children(v);
    v.visit(method, "method");
    v.visit(typeArguments, "typeArguments");
    v.visit(arguments, "arguments");
}
void IR::MethodCallExpression::visit_children(Visitor & v) const {
    Expression::visit_children(v);
    v.visit(method, "method");
    v.visit(typeArguments, "typeArguments");
    v.visit(arguments, "arguments");
}
void IR::MethodCallExpression::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"method\" : " << this->method;
    json << "," << std::endl << json.indent << "\"typeArguments\" : " << this->typeArguments;
    json << "," << std::endl << json.indent << "\"arguments\" : " << this->arguments;
}
IR::MethodCallExpression::MethodCallExpression(JSONLoader & json) : Expression(json) {
    json.load("method", method);
    json.load("typeArguments", typeArguments);
    json.load("arguments", arguments);
}
IR::Node * IR::MethodCallExpression::fromJSON(JSONLoader & json) { return new MethodCallExpression(json); }
IR::MethodCallExpression::MethodCallExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments) :
    Expression(srcInfo, type), method(method), typeArguments(typeArguments), arguments(arguments)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments) :
    Expression(type), method(method), typeArguments(typeArguments), arguments(arguments)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(Util::SourceInfo srcInfo, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments) :
    Expression(srcInfo), method(method), typeArguments(typeArguments), arguments(arguments)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments) :
    method(method), typeArguments(typeArguments), arguments(arguments)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Argument>* arguments) :
    Expression(srcInfo, type), method(method), arguments(arguments)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Argument>* arguments) :
    Expression(type), method(method), arguments(arguments)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(Util::SourceInfo srcInfo, const IR::Expression* method, const IR::Vector<IR::Argument>* arguments) :
    Expression(srcInfo), method(method), arguments(arguments)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(const IR::Expression* method, const IR::Vector<IR::Argument>* arguments) :
    method(method), arguments(arguments)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments) :
    Expression(srcInfo, type), method(method), typeArguments(typeArguments)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments) :
    Expression(type), method(method), typeArguments(typeArguments)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(Util::SourceInfo srcInfo, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments) :
    Expression(srcInfo), method(method), typeArguments(typeArguments)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments) :
    method(method), typeArguments(typeArguments)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method) :
    Expression(srcInfo, type), method(method)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(const IR::Type* type, const IR::Expression* method) :
    Expression(type), method(method)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(Util::SourceInfo srcInfo, const IR::Expression* method) :
    Expression(srcInfo), method(method)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(const IR::Expression* method) :
    method(method)
    { validate(); }

#line 398 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
cstring IR::ConstructorCallExpression::toString() const { return constructedType->toString(); }
#line 5697 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 399 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
void IR::ConstructorCallExpression::validate() const {
#line 5700 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(constructedType);
        CHECK_NULL(arguments);
#line 399 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ BUG_CHECK(constructedType->is<Type_Name>() ||
                        constructedType->is<Type_Specialized>(),
                        "%1%: unexpected type", constructedType);
        arguments->check_null(); } }
#line 5709 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::ConstructorCallExpression::operator==(IR::ConstructorCallExpression const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && constructedType == a.constructedType
        && arguments == a.arguments;
    }
bool IR::ConstructorCallExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const ConstructorCallExpression &>(a_);
        return (constructedType ? a.constructedType ? constructedType->equiv(*a.constructedType) : false : a.constructedType == nullptr)
        && (arguments ? a.arguments ? arguments->equiv(*a.arguments) : false : a.arguments == nullptr);
    }
void IR::ConstructorCallExpression::visit_children(Visitor & v) {
    Expression::visit_children(v);
    v.visit(constructedType, "constructedType");
    v.visit(arguments, "arguments");
}
void IR::ConstructorCallExpression::visit_children(Visitor & v) const {
    Expression::visit_children(v);
    v.visit(constructedType, "constructedType");
    v.visit(arguments, "arguments");
}
void IR::ConstructorCallExpression::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"constructedType\" : " << this->constructedType;
    json << "," << std::endl << json.indent << "\"arguments\" : " << this->arguments;
}
IR::ConstructorCallExpression::ConstructorCallExpression(JSONLoader & json) : Expression(json) {
    json.load("constructedType", constructedType);
    json.load("arguments", arguments);
}
IR::Node * IR::ConstructorCallExpression::fromJSON(JSONLoader & json) { return new ConstructorCallExpression(json); }
IR::ConstructorCallExpression::ConstructorCallExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Vector<IR::Argument>* arguments) :
    Expression(srcInfo, type), arguments(arguments)
    { validate(); }
IR::ConstructorCallExpression::ConstructorCallExpression(const IR::Type* type, const IR::Vector<IR::Argument>* arguments) :
    Expression(type), arguments(arguments)
    { validate(); }
IR::ConstructorCallExpression::ConstructorCallExpression(Util::SourceInfo srcInfo, const IR::Vector<IR::Argument>* arguments) :
    Expression(srcInfo), arguments(arguments)
    { validate(); }
IR::ConstructorCallExpression::ConstructorCallExpression(const IR::Vector<IR::Argument>* arguments) :
    arguments(arguments)
    { validate(); }
#line 415 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
void IR::ListExpression::validate() const {
#line 5756 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        components.validate();
#line 415 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{ components.check_null(); } }
#line 5761 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 416 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
size_t IR::ListExpression::size() const { return components.size(); }
#line 5764 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 417 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
void IR::ListExpression::push_back(const IR::Expression* e) { components.push_back(e); }
#line 5767 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::ListExpression::operator==(IR::ListExpression const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && components == a.components;
    }
bool IR::ListExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const ListExpression &>(a_);
        return components.equiv(a.components);
    }
void IR::ListExpression::visit_children(Visitor & v) {
    Expression::visit_children(v);
    components.visit_children(v);
}
void IR::ListExpression::visit_children(Visitor & v) const {
    Expression::visit_children(v);
    components.visit_children(v);
}
void IR::ListExpression::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"components\" : " << this->components;
}
IR::ListExpression::ListExpression(JSONLoader & json) : Expression(json) {
    json.load("components", components);
}
IR::Node * IR::ListExpression::fromJSON(JSONLoader & json) { return new ListExpression(json); }
IR::ListExpression::ListExpression(Util::SourceInfo srcInfo, const IR::Type* type, IR::Vector<IR::Expression> components) :
    Expression(srcInfo, type), components(components)
    {
#line 408 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        validate();
        if (type->is<Type::Unknown>()) {
            Vector<Type> tuple;
            for (auto e : components)
                tuple.push_back(e->type);
            type = new Type_List(tuple); } }
#line 5805 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::ListExpression::ListExpression(const IR::Type* type, IR::Vector<IR::Expression> components) :
    Expression(type), components(components)
    {
#line 408 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        validate();
        if (type->is<Type::Unknown>()) {
            Vector<Type> tuple;
            for (auto e : components)
                tuple.push_back(e->type);
            type = new Type_List(tuple); } }
#line 5818 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::ListExpression::ListExpression(Util::SourceInfo srcInfo, IR::Vector<IR::Expression> components) :
    Expression(srcInfo), components(components)
    {
#line 408 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        validate();
        if (type->is<Type::Unknown>()) {
            Vector<Type> tuple;
            for (auto e : components)
                tuple.push_back(e->type);
            type = new Type_List(tuple); } }
#line 5831 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::ListExpression::ListExpression(IR::Vector<IR::Expression> components) :
    components(components)
    {
#line 408 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        validate();
        if (type->is<Type::Unknown>()) {
            Vector<Type> tuple;
            for (auto e : components)
                tuple.push_back(e->type);
            type = new Type_List(tuple); } }
#line 5844 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
/// The struct or header type that is being intialized.
/// May only be known after type checking; so it can be nullptr.
#line 426 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
void IR::StructExpression::validate() const {
#line 5850 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        components.validate();
#line 426 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        components.check_null(); components.validate();
        BUG_CHECK(structType == nullptr || structType->is<IR::Type_Name>() ||
                  structType->is<IR::Type_Specialized>(),
                  "%1%: unexpected struct type", this);
    } }
#line 5860 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 432 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
size_t IR::StructExpression::size() const { return components.size(); }
#line 5863 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::StructExpression::operator==(IR::StructExpression const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && structType == a.structType
        && components == a.components;
    }
bool IR::StructExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const StructExpression &>(a_);
        return (structType ? a.structType ? structType->equiv(*a.structType) : false : a.structType == nullptr)
        && components.equiv(a.components);
    }
void IR::StructExpression::visit_children(Visitor & v) {
    Expression::visit_children(v);
    v.visit(structType, "structType");
    components.visit_children(v);
}
void IR::StructExpression::visit_children(Visitor & v) const {
    Expression::visit_children(v);
    v.visit(structType, "structType");
    components.visit_children(v);
}
void IR::StructExpression::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    if (structType != nullptr)     json << "," << std::endl << json.indent << "\"structType\" : " << this->structType;
    json << "," << std::endl << json.indent << "\"components\" : " << this->components;
}
IR::StructExpression::StructExpression(JSONLoader & json) : Expression(json) {
    json.load("structType", structType);
    json.load("components", components);
}
IR::Node * IR::StructExpression::fromJSON(JSONLoader & json) { return new StructExpression(json); }
IR::StructExpression::StructExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Type* structType, IR::IndexedVector<IR::NamedExpression> components) :
    Expression(srcInfo, type), structType(structType), components(components)
    { validate(); }
IR::StructExpression::StructExpression(const IR::Type* type, const IR::Type* structType, IR::IndexedVector<IR::NamedExpression> components) :
    Expression(type), structType(structType), components(components)
    { validate(); }
IR::StructExpression::StructExpression(Util::SourceInfo srcInfo, const IR::Type* structType, IR::IndexedVector<IR::NamedExpression> components) :
    Expression(srcInfo), structType(structType), components(components)
    { validate(); }
IR::StructExpression::StructExpression(const IR::Type* structType, IR::IndexedVector<IR::NamedExpression> components) :
    structType(structType), components(components)
    { validate(); }
#line 439 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
void IR::ListCompileTimeValue::validate() const {
#line 5910 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        components.validate();
#line 439 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        for (auto v : components)
            BUG_CHECK(v->is<CompileTimeValue>(), "%1%: not a compile-time value", v); } }
#line 5917 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::ListCompileTimeValue::operator==(IR::ListCompileTimeValue const & a) const {
        return typeid(*this) == typeid(a)
        && components == a.components;
    }
bool IR::ListCompileTimeValue::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const ListCompileTimeValue &>(a_);
        return components.equiv(a.components);
    }
void IR::ListCompileTimeValue::visit_children(Visitor & v) {
    Node::visit_children(v);
    components.visit_children(v);
}
void IR::ListCompileTimeValue::visit_children(Visitor & v) const {
    Node::visit_children(v);
    components.visit_children(v);
}
void IR::ListCompileTimeValue::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"components\" : " << this->components;
}
IR::ListCompileTimeValue::ListCompileTimeValue(JSONLoader & json) : Node(json) {
    json.load("components", components);
}
IR::Node * IR::ListCompileTimeValue::fromJSON(JSONLoader & json) { return new ListCompileTimeValue(json); }
IR::ListCompileTimeValue::ListCompileTimeValue(Util::SourceInfo srcInfo, IR::Vector<IR::Node> components) :
    Node(srcInfo), components(components)
    { validate(); }
IR::ListCompileTimeValue::ListCompileTimeValue(IR::Vector<IR::Node> components) :
    components(components)
    { validate(); }
#line 448 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
IR::CompileTimeMethodCall::CompileTimeMethodCall(const IR::MethodCallExpression* e) : MethodCallExpression(*e) {}
#line 5952 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 449 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
void IR::CompileTimeMethodCall::validate() const {
#line 5955 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

#line 449 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/expression.def"
{
        for (auto v : *arguments)
            BUG_CHECK(v->is<CompileTimeValue>(), "%1%: not a compile-time value", v); } }
#line 5961 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::CompileTimeMethodCall::operator==(IR::CompileTimeMethodCall const & a) const {
        return MethodCallExpression::operator==(static_cast<const MethodCallExpression &>(a));
    }
bool IR::CompileTimeMethodCall::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!MethodCallExpression::equiv(a_)) return false;
        return true;
    }
void IR::CompileTimeMethodCall::toJSON(JSONGenerator & json) const {
    MethodCallExpression::toJSON(json);
}
IR::CompileTimeMethodCall::CompileTimeMethodCall(JSONLoader & json) : MethodCallExpression(json) {
}
IR::Node * IR::CompileTimeMethodCall::fromJSON(JSONLoader & json) { return new CompileTimeMethodCall(json); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments) :
    MethodCallExpression(srcInfo, type, method, typeArguments, arguments)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments) :
    MethodCallExpression(type, method, typeArguments, arguments)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments) :
    MethodCallExpression(srcInfo, method, typeArguments, arguments)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments) :
    MethodCallExpression(method, typeArguments, arguments)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Argument>* arguments) :
    MethodCallExpression(srcInfo, type, method, arguments)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Argument>* arguments) :
    MethodCallExpression(type, method, arguments)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Expression* method, const IR::Vector<IR::Argument>* arguments) :
    MethodCallExpression(srcInfo, method, arguments)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(const IR::Expression* method, const IR::Vector<IR::Argument>* arguments) :
    MethodCallExpression(method, arguments)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments) :
    MethodCallExpression(srcInfo, type, method, typeArguments)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments) :
    MethodCallExpression(type, method, typeArguments)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments) :
    MethodCallExpression(srcInfo, method, typeArguments)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments) :
    MethodCallExpression(method, typeArguments)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method) :
    MethodCallExpression(srcInfo, type, method)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(const IR::Type* type, const IR::Expression* method) :
    MethodCallExpression(type, method)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Expression* method) :
    MethodCallExpression(srcInfo, method)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(const IR::Expression* method) :
    MethodCallExpression(method)
    { validate(); }

#line 64 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::Annotations *IR::ParserState::getAnnotations() const { return annotations; }
#line 6027 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 65 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::ParserState::getDeclarations() const {
        return components.getDeclarations(); }
#line 6031 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 67 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
IR::IDeclaration const * IR::ParserState::getDeclByName(cstring name) const {
        return components.getDeclaration(name); }
#line 6035 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 74 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
bool IR::ParserState::isBuiltin() const { return name == ParserState::accept || name == ParserState::reject; }
#line 6038 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 75 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::ParserState::validate() const {
#line 6041 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        components.validate();
#line 75 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
{
        if (selectExpression != nullptr)
            BUG_CHECK(selectExpression->is<IR::PathExpression>() ||
                      selectExpression->is<IR::SelectExpression>(),
                      "%1%: unexpected select expression", selectExpression);
    } }
#line 6052 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::ParserState::operator==(IR::ParserState const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && components == a.components
        && selectExpression == a.selectExpression;
    }
bool IR::ParserState::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const ParserState &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && components.equiv(a.components)
        && (selectExpression ? a.selectExpression ? selectExpression->equiv(*a.selectExpression) : false : a.selectExpression == nullptr);
    }
void IR::ParserState::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    components.visit_children(v);
    v.visit(selectExpression, "selectExpression");
}
void IR::ParserState::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    components.visit_children(v);
    v.visit(selectExpression, "selectExpression");
}
void IR::ParserState::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"components\" : " << this->components;
    if (selectExpression != nullptr)     json << "," << std::endl << json.indent << "\"selectExpression\" : " << this->selectExpression;
}
IR::ParserState::ParserState(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("components", components);
    json.load("selectExpression", selectExpression);
}
IR::Node * IR::ParserState::fromJSON(JSONLoader & json) { return new ParserState(json); }
IR::ParserState::ParserState(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StatOrDecl> components, const IR::Expression* selectExpression) :
    Declaration(srcInfo, name), annotations(annotations), components(components), selectExpression(selectExpression)
    { validate(); }
IR::ParserState::ParserState(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StatOrDecl> components, const IR::Expression* selectExpression) :
    Declaration(name), annotations(annotations), components(components), selectExpression(selectExpression)
    { validate(); }
IR::ParserState::ParserState(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StatOrDecl> components, const IR::Expression* selectExpression) :
    Declaration(srcInfo, name), components(components), selectExpression(selectExpression)
    { validate(); }
IR::ParserState::ParserState(IR::ID name, IR::IndexedVector<IR::StatOrDecl> components, const IR::Expression* selectExpression) :
    Declaration(name), components(components), selectExpression(selectExpression)
    { validate(); }
IR::ParserState::ParserState(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Expression* selectExpression) :
    Declaration(srcInfo, name), annotations(annotations), selectExpression(selectExpression)
    { validate(); }
IR::ParserState::ParserState(IR::ID name, const IR::Annotations* annotations, const IR::Expression* selectExpression) :
    Declaration(name), annotations(annotations), selectExpression(selectExpression)
    { validate(); }
IR::ParserState::ParserState(Util::SourceInfo srcInfo, IR::ID name, const IR::Expression* selectExpression) :
    Declaration(srcInfo, name), selectExpression(selectExpression)
    { validate(); }
IR::ParserState::ParserState(IR::ID name, const IR::Expression* selectExpression) :
    Declaration(name), selectExpression(selectExpression)
    { validate(); }
#line 90 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::TypeParameters *IR::P4Parser::getTypeParameters() const { return type->getTypeParameters(); }
#line 6117 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 91 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
std::vector<const IR::INamespace *> IR::P4Parser::getNestedNamespaces() const {
        return { type->typeParameters, type->applyParams, constructorParams }; }
#line 6121 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 93 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::P4Parser::getDeclarations() const {
        return parserLocals.getDeclarations()->concat(states.getDeclarations()); }
#line 6125 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 95 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::IDeclaration *IR::P4Parser::getDeclByName(cstring name) const {
        auto decl = parserLocals.getDeclaration(name);
        if (!decl) decl = states.getDeclaration(name);
        return decl; }
#line 6131 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 99 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::Type_Method *IR::P4Parser::getApplyMethodType() const { return type->getApplyMethodType(); }
#line 6134 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 100 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::ParameterList *IR::P4Parser::getApplyParameters() const { return type->getApplyParameters(); }
#line 6137 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 102 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::ParameterList *IR::P4Parser::getConstructorParameters() const { return constructorParams; }
#line 6140 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
IRNODE_DEFINE_APPLY_OVERLOAD(P4Parser, , )
#line 105 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::P4Parser::validate() const {
#line 6144 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(type);
        CHECK_NULL(constructorParams);
        parserLocals.validate();
        states.validate();
#line 105 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
{
        if (!(name == type->name))
            BUG("Name mismatch for %1%: %2% != %3%", this, name, type->name);
        parserLocals.check_null();
        states.check_null();
        checkDuplicates();
    } }
#line 6158 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 112 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
cstring IR::P4Parser::toString() const { return cstring("parser ") + externalName(); }
#line 6161 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::P4Parser::operator==(IR::P4Parser const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && type == a.type
        && constructorParams == a.constructorParams
        && parserLocals == a.parserLocals
        && states == a.states;
    }
bool IR::P4Parser::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const P4Parser &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (constructorParams ? a.constructorParams ? constructorParams->equiv(*a.constructorParams) : false : a.constructorParams == nullptr)
        && parserLocals.equiv(a.parserLocals)
        && states.equiv(a.states);
    }
void IR::P4Parser::visit_children(Visitor & v) {
    Type_Declaration::visit_children(v);
    v.visit(type, "type");
    v.visit(constructorParams, "constructorParams");
    parserLocals.visit_children(v);
    states.visit_children(v);
}
void IR::P4Parser::visit_children(Visitor & v) const {
    Type_Declaration::visit_children(v);
    v.visit(type, "type");
    v.visit(constructorParams, "constructorParams");
    parserLocals.visit_children(v);
    states.visit_children(v);
}
void IR::P4Parser::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
    json << "," << std::endl << json.indent << "\"constructorParams\" : " << this->constructorParams;
    json << "," << std::endl << json.indent << "\"parserLocals\" : " << this->parserLocals;
    json << "," << std::endl << json.indent << "\"states\" : " << this->states;
}
IR::P4Parser::P4Parser(JSONLoader & json) : Type_Declaration(json) {
    json.load("type", type);
    json.load("constructorParams", constructorParams);
    json.load("parserLocals", parserLocals);
    json.load("states", states);
}
IR::Node * IR::P4Parser::fromJSON(JSONLoader & json) { return new P4Parser(json); }
IR::P4Parser::P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::Declaration> parserLocals, IR::IndexedVector<IR::ParserState> states) :
    Type_Declaration(srcInfo, name), type(type), constructorParams(constructorParams), parserLocals(parserLocals), states(states)
    { validate(); }
IR::P4Parser::P4Parser(IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::Declaration> parserLocals, IR::IndexedVector<IR::ParserState> states) :
    Type_Declaration(name), type(type), constructorParams(constructorParams), parserLocals(parserLocals), states(states)
    { validate(); }
IR::P4Parser::P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, IR::IndexedVector<IR::Declaration> parserLocals, IR::IndexedVector<IR::ParserState> states) :
    Type_Declaration(srcInfo, name), type(type), parserLocals(parserLocals), states(states)
    { validate(); }
IR::P4Parser::P4Parser(IR::ID name, const IR::Type_Parser* type, IR::IndexedVector<IR::Declaration> parserLocals, IR::IndexedVector<IR::ParserState> states) :
    Type_Declaration(name), type(type), parserLocals(parserLocals), states(states)
    { validate(); }
IR::P4Parser::P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::ParserState> states) :
    Type_Declaration(srcInfo, name), type(type), constructorParams(constructorParams), states(states)
    { validate(); }
IR::P4Parser::P4Parser(IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::ParserState> states) :
    Type_Declaration(name), type(type), constructorParams(constructorParams), states(states)
    { validate(); }
IR::P4Parser::P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, IR::IndexedVector<IR::ParserState> states) :
    Type_Declaration(srcInfo, name), type(type), states(states)
    { validate(); }
IR::P4Parser::P4Parser(IR::ID name, const IR::Type_Parser* type, IR::IndexedVector<IR::ParserState> states) :
    Type_Declaration(name), type(type), states(states)
    { validate(); }
IR::P4Parser::P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::Declaration> parserLocals) :
    Type_Declaration(srcInfo, name), type(type), constructorParams(constructorParams), parserLocals(parserLocals)
    { validate(); }
IR::P4Parser::P4Parser(IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::Declaration> parserLocals) :
    Type_Declaration(name), type(type), constructorParams(constructorParams), parserLocals(parserLocals)
    { validate(); }
IR::P4Parser::P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, IR::IndexedVector<IR::Declaration> parserLocals) :
    Type_Declaration(srcInfo, name), type(type), parserLocals(parserLocals)
    { validate(); }
IR::P4Parser::P4Parser(IR::ID name, const IR::Type_Parser* type, IR::IndexedVector<IR::Declaration> parserLocals) :
    Type_Declaration(name), type(type), parserLocals(parserLocals)
    { validate(); }
IR::P4Parser::P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams) :
    Type_Declaration(srcInfo, name), type(type), constructorParams(constructorParams)
    { validate(); }
IR::P4Parser::P4Parser(IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams) :
    Type_Declaration(name), type(type), constructorParams(constructorParams)
    { validate(); }
IR::P4Parser::P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type) :
    Type_Declaration(srcInfo, name), type(type)
    { validate(); }
IR::P4Parser::P4Parser(IR::ID name, const IR::Type_Parser* type) :
    Type_Declaration(name), type(type)
    { validate(); }
#line 121 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::TypeParameters *IR::P4Control::getTypeParameters() const { return type->getTypeParameters(); }
#line 6256 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 122 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
std::vector<const IR::INamespace *> IR::P4Control::getNestedNamespaces() const {
        return { type->typeParameters, type->applyParams, constructorParams }; }
#line 6260 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 124 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::P4Control::getDeclarations() const {
        return controlLocals.getDeclarations(); }
#line 6264 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 126 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::Type_Method *IR::P4Control::getApplyMethodType() const { return type->getApplyMethodType(); }
#line 6267 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 127 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::ParameterList *IR::P4Control::getApplyParameters() const { return type->getApplyParameters(); }
#line 6270 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 129 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::IDeclaration *IR::P4Control::getDeclByName(cstring name) const {
        return controlLocals.getDeclaration(name); }
#line 6274 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 131 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::ParameterList *IR::P4Control::getConstructorParameters() const { return constructorParams; }
#line 6277 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
IRNODE_DEFINE_APPLY_OVERLOAD(P4Control, , )
#line 133 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::P4Control::validate() const {
#line 6281 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(type);
        CHECK_NULL(constructorParams);
        controlLocals.validate();
        CHECK_NULL(body);
#line 133 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
{
        if (!(name == type->name))
            BUG("Name mismatch for %1%: %2% != %3%", this, name, type->name);
        controlLocals.check_null();
    } }
#line 6293 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 138 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
cstring IR::P4Control::toString() const { return cstring("control ") + externalName(); }
#line 6296 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::P4Control::operator==(IR::P4Control const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && type == a.type
        && constructorParams == a.constructorParams
        && controlLocals == a.controlLocals
        && body == a.body;
    }
bool IR::P4Control::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const P4Control &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (constructorParams ? a.constructorParams ? constructorParams->equiv(*a.constructorParams) : false : a.constructorParams == nullptr)
        && controlLocals.equiv(a.controlLocals)
        && (body ? a.body ? body->equiv(*a.body) : false : a.body == nullptr);
    }
void IR::P4Control::visit_children(Visitor & v) {
    Type_Declaration::visit_children(v);
    v.visit(type, "type");
    v.visit(constructorParams, "constructorParams");
    controlLocals.visit_children(v);
    v.visit(body, "body");
}
void IR::P4Control::visit_children(Visitor & v) const {
    Type_Declaration::visit_children(v);
    v.visit(type, "type");
    v.visit(constructorParams, "constructorParams");
    controlLocals.visit_children(v);
    v.visit(body, "body");
}
void IR::P4Control::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
    json << "," << std::endl << json.indent << "\"constructorParams\" : " << this->constructorParams;
    json << "," << std::endl << json.indent << "\"controlLocals\" : " << this->controlLocals;
    json << "," << std::endl << json.indent << "\"body\" : " << this->body;
}
IR::P4Control::P4Control(JSONLoader & json) : Type_Declaration(json) {
    json.load("type", type);
    json.load("constructorParams", constructorParams);
    json.load("controlLocals", controlLocals);
    json.load("body", body);
}
IR::Node * IR::P4Control::fromJSON(JSONLoader & json) { return new P4Control(json); }
IR::P4Control::P4Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Control* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::Declaration> controlLocals, const IR::BlockStatement* body) :
    Type_Declaration(srcInfo, name), type(type), constructorParams(constructorParams), controlLocals(controlLocals), body(body)
    { validate(); }
IR::P4Control::P4Control(IR::ID name, const IR::Type_Control* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::Declaration> controlLocals, const IR::BlockStatement* body) :
    Type_Declaration(name), type(type), constructorParams(constructorParams), controlLocals(controlLocals), body(body)
    { validate(); }
IR::P4Control::P4Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Control* type, IR::IndexedVector<IR::Declaration> controlLocals, const IR::BlockStatement* body) :
    Type_Declaration(srcInfo, name), type(type), controlLocals(controlLocals), body(body)
    { validate(); }
IR::P4Control::P4Control(IR::ID name, const IR::Type_Control* type, IR::IndexedVector<IR::Declaration> controlLocals, const IR::BlockStatement* body) :
    Type_Declaration(name), type(type), controlLocals(controlLocals), body(body)
    { validate(); }
IR::P4Control::P4Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Control* type, const IR::ParameterList* constructorParams, const IR::BlockStatement* body) :
    Type_Declaration(srcInfo, name), type(type), constructorParams(constructorParams), body(body)
    { validate(); }
IR::P4Control::P4Control(IR::ID name, const IR::Type_Control* type, const IR::ParameterList* constructorParams, const IR::BlockStatement* body) :
    Type_Declaration(name), type(type), constructorParams(constructorParams), body(body)
    { validate(); }
IR::P4Control::P4Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Control* type, const IR::BlockStatement* body) :
    Type_Declaration(srcInfo, name), type(type), body(body)
    { validate(); }
IR::P4Control::P4Control(IR::ID name, const IR::Type_Control* type, const IR::BlockStatement* body) :
    Type_Declaration(name), type(type), body(body)
    { validate(); }
#line 146 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::P4Action::getDeclarations() const {
        return parameters->getDeclarations(); }
#line 6368 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 148 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::IDeclaration *IR::P4Action::getDeclByName(cstring name) const {
        return parameters->getDeclByName(name); }
#line 6372 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 150 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::Annotations *IR::P4Action::getAnnotations() const { return annotations; }
#line 6375 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 151 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::ParameterList *IR::P4Action::getParameters() const { return parameters; }
#line 6378 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::P4Action::operator==(IR::P4Action const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && parameters == a.parameters
        && body == a.body;
    }
bool IR::P4Action::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const P4Action &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (parameters ? a.parameters ? parameters->equiv(*a.parameters) : false : a.parameters == nullptr)
        && (body ? a.body ? body->equiv(*a.body) : false : a.body == nullptr);
    }
void IR::P4Action::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(parameters, "parameters");
    v.visit(body, "body");
}
void IR::P4Action::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(parameters, "parameters");
    v.visit(body, "body");
}
void IR::P4Action::validate() const {
#line 6406 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(parameters);
        CHECK_NULL(body); }
void IR::P4Action::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"parameters\" : " << this->parameters;
    json << "," << std::endl << json.indent << "\"body\" : " << this->body;
}
IR::P4Action::P4Action(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("parameters", parameters);
    json.load("body", body);
}
IR::Node * IR::P4Action::fromJSON(JSONLoader & json) { return new P4Action(json); }
IR::P4Action::P4Action(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::ParameterList* parameters, const IR::BlockStatement* body) :
    Declaration(srcInfo, name), annotations(annotations), parameters(parameters), body(body)
    { validate(); }
IR::P4Action::P4Action(IR::ID name, const IR::Annotations* annotations, const IR::ParameterList* parameters, const IR::BlockStatement* body) :
    Declaration(name), annotations(annotations), parameters(parameters), body(body)
    { validate(); }
IR::P4Action::P4Action(Util::SourceInfo srcInfo, IR::ID name, const IR::ParameterList* parameters, const IR::BlockStatement* body) :
    Declaration(srcInfo, name), parameters(parameters), body(body)
    { validate(); }
IR::P4Action::P4Action(IR::ID name, const IR::ParameterList* parameters, const IR::BlockStatement* body) :
    Declaration(name), parameters(parameters), body(body)
    { validate(); }
#line 157 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Type_Error::getDeclarations() const {
        return members.getDeclarations(); }
#line 6438 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 159 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::IDeclaration *IR::Type_Error::getDeclByName(cstring name) const {
        return members.getDeclaration(name); }
#line 6442 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 161 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::Type_Error::validate() const {
#line 6445 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        members.validate();
#line 161 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
{ members.check_null(); } }
#line 6450 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Error::operator==(IR::Type_Error const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && members == a.members;
    }
bool IR::Type_Error::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Type_Error &>(a_);
        return members.equiv(a.members);
    }
void IR::Type_Error::visit_children(Visitor & v) {
    Type_Declaration::visit_children(v);
    members.visit_children(v);
}
void IR::Type_Error::visit_children(Visitor & v) const {
    Type_Declaration::visit_children(v);
    members.visit_children(v);
}
void IR::Type_Error::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"members\" : " << this->members;
}
IR::Type_Error::Type_Error(JSONLoader & json) : Type_Declaration(json) {
    json.load("members", members);
}
IR::Node * IR::Type_Error::fromJSON(JSONLoader & json) { return new Type_Error(json); }
IR::Type_Error::Type_Error(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::Declaration_ID> members) :
    Type_Declaration(srcInfo, name), members(members)
    { validate(); }
IR::Type_Error::Type_Error(IR::ID name, IR::IndexedVector<IR::Declaration_ID> members) :
    Type_Declaration(name), members(members)
    { validate(); }
IR::Type_Error::Type_Error(Util::SourceInfo srcInfo, IR::ID name) :
    Type_Declaration(srcInfo, name)
    { validate(); }
IR::Type_Error::Type_Error(IR::ID name) :
    Type_Declaration(name)
    { validate(); }
#line 167 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Declaration_MatchKind::getDeclarations() const {
        return members.getDeclarations(); }
#line 6492 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 169 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::IDeclaration *IR::Declaration_MatchKind::getDeclByName(cstring name) const {
        return members.getDeclaration(name); }
#line 6496 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 171 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::Declaration_MatchKind::validate() const {
#line 6499 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        members.validate();
#line 171 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
{ members.check_null(); } }
#line 6504 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Declaration_MatchKind::operator==(IR::Declaration_MatchKind const & a) const {
        return typeid(*this) == typeid(a)
        && members == a.members;
    }
bool IR::Declaration_MatchKind::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const Declaration_MatchKind &>(a_);
        return members.equiv(a.members);
    }
void IR::Declaration_MatchKind::visit_children(Visitor & v) {
    Node::visit_children(v);
    members.visit_children(v);
}
void IR::Declaration_MatchKind::visit_children(Visitor & v) const {
    Node::visit_children(v);
    members.visit_children(v);
}
void IR::Declaration_MatchKind::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"members\" : " << this->members;
}
IR::Declaration_MatchKind::Declaration_MatchKind(JSONLoader & json) : Node(json) {
    json.load("members", members);
}
IR::Node * IR::Declaration_MatchKind::fromJSON(JSONLoader & json) { return new Declaration_MatchKind(json); }
IR::Declaration_MatchKind::Declaration_MatchKind(Util::SourceInfo srcInfo, IR::IndexedVector<IR::Declaration_ID> members) :
    Node(srcInfo), members(members)
    { validate(); }
IR::Declaration_MatchKind::Declaration_MatchKind(IR::IndexedVector<IR::Declaration_ID> members) :
    members(members)
    { validate(); }
IR::Declaration_MatchKind::Declaration_MatchKind(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::Declaration_MatchKind::Declaration_MatchKind() 
    { validate(); }
bool IR::PropertyValue::operator==(IR::PropertyValue const & a) const {
        return typeid(*this) == typeid(a);
    }
bool IR::PropertyValue::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        return true;
    }
void IR::PropertyValue::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
}
IR::PropertyValue::PropertyValue(JSONLoader & json) : Node(json) {
}
IR::PropertyValue::PropertyValue(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::PropertyValue::PropertyValue() 
    { validate(); }
#line 180 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::ExpressionValue::dbprint(std::ostream & out) const { out << expression; }
#line 6562 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::ExpressionValue::operator==(IR::ExpressionValue const & a) const {
        return PropertyValue::operator==(static_cast<const PropertyValue &>(a))
        && expression == a.expression;
    }
bool IR::ExpressionValue::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!PropertyValue::equiv(a_)) return false;
        auto &a = static_cast<const ExpressionValue &>(a_);
        return (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr);
    }
void IR::ExpressionValue::visit_children(Visitor & v) {
    PropertyValue::visit_children(v);
    v.visit(expression, "expression");
}
void IR::ExpressionValue::visit_children(Visitor & v) const {
    PropertyValue::visit_children(v);
    v.visit(expression, "expression");
}
void IR::ExpressionValue::validate() const {
#line 6582 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(expression); }
void IR::ExpressionValue::toJSON(JSONGenerator & json) const {
    PropertyValue::toJSON(json);
    json << "," << std::endl << json.indent << "\"expression\" : " << this->expression;
}
IR::ExpressionValue::ExpressionValue(JSONLoader & json) : PropertyValue(json) {
    json.load("expression", expression);
}
IR::Node * IR::ExpressionValue::fromJSON(JSONLoader & json) { return new ExpressionValue(json); }
IR::ExpressionValue::ExpressionValue(Util::SourceInfo srcInfo, const IR::Expression* expression) :
    PropertyValue(srcInfo), expression(expression)
    { validate(); }
IR::ExpressionValue::ExpressionValue(const IR::Expression* expression) :
    expression(expression)
    { validate(); }
#line 185 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::ExpressionListValue::dbprint(std::ostream & out) const { out << expressions; }
#line 6601 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::ExpressionListValue::operator==(IR::ExpressionListValue const & a) const {
        return PropertyValue::operator==(static_cast<const PropertyValue &>(a))
        && expressions == a.expressions;
    }
bool IR::ExpressionListValue::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!PropertyValue::equiv(a_)) return false;
        auto &a = static_cast<const ExpressionListValue &>(a_);
        return expressions.equiv(a.expressions);
    }
void IR::ExpressionListValue::visit_children(Visitor & v) {
    PropertyValue::visit_children(v);
    expressions.visit_children(v);
}
void IR::ExpressionListValue::visit_children(Visitor & v) const {
    PropertyValue::visit_children(v);
    expressions.visit_children(v);
}
void IR::ExpressionListValue::validate() const {
#line 6621 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        expressions.validate(); }
void IR::ExpressionListValue::toJSON(JSONGenerator & json) const {
    PropertyValue::toJSON(json);
    json << "," << std::endl << json.indent << "\"expressions\" : " << this->expressions;
}
IR::ExpressionListValue::ExpressionListValue(JSONLoader & json) : PropertyValue(json) {
    json.load("expressions", expressions);
}
IR::Node * IR::ExpressionListValue::fromJSON(JSONLoader & json) { return new ExpressionListValue(json); }
IR::ExpressionListValue::ExpressionListValue(Util::SourceInfo srcInfo, IR::Vector<IR::Expression> expressions) :
    PropertyValue(srcInfo), expressions(expressions)
    { validate(); }
IR::ExpressionListValue::ExpressionListValue(IR::Vector<IR::Expression> expressions) :
    expressions(expressions)
    { validate(); }

#line 192 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::ActionListElement::dbprint(std::ostream & out) const { out << annotations << expression; }
#line 6641 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 193 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
IR::ID IR::ActionListElement::getName() const { return getPath()->name; }
#line 6644 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 195 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::Annotations *IR::ActionListElement::getAnnotations() const { return annotations; }
#line 6647 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 196 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::ActionListElement::validate() const {
#line 6650 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(expression);
#line 196 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
{
        BUG_CHECK(expression->is<IR::PathExpression>() ||
                  expression->is<IR::MethodCallExpression>(),
                  "%1%: unexpected expression", expression);
    } }
#line 6660 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 201 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
cstring IR::ActionListElement::toString() const { return getName().toString(); }
#line 6663 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::ActionListElement::operator==(IR::ActionListElement const & a) const {
        return typeid(*this) == typeid(a)
        && annotations == a.annotations
        && expression == a.expression;
    }
bool IR::ActionListElement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const ActionListElement &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr);
    }
void IR::ActionListElement::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(expression, "expression");
}
void IR::ActionListElement::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(expression, "expression");
}
void IR::ActionListElement::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"expression\" : " << this->expression;
}
IR::ActionListElement::ActionListElement(JSONLoader & json) : Node(json) {
    json.load("annotations", annotations);
    json.load("expression", expression);
}
IR::Node * IR::ActionListElement::fromJSON(JSONLoader & json) { return new ActionListElement(json); }
IR::ActionListElement::ActionListElement(Util::SourceInfo srcInfo, const IR::Annotations* annotations, const IR::Expression* expression) :
    Node(srcInfo), annotations(annotations), expression(expression)
    { validate(); }
IR::ActionListElement::ActionListElement(const IR::Annotations* annotations, const IR::Expression* expression) :
    annotations(annotations), expression(expression)
    { validate(); }
IR::ActionListElement::ActionListElement(Util::SourceInfo srcInfo, const IR::Expression* expression) :
    Node(srcInfo), expression(expression)
    { validate(); }
IR::ActionListElement::ActionListElement(const IR::Expression* expression) :
    expression(expression)
    { validate(); }
#line 207 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::ActionList::validate() const {
#line 6710 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        actionList.validate();
#line 207 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
{ actionList.check_null(); } }
#line 6715 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 208 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
size_t IR::ActionList::size() const { return actionList.size(); }
#line 6718 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 209 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::ActionList::push_back(const IR::ActionListElement* e) { actionList.push_back(e); }
#line 6721 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 210 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::ActionListElement *IR::ActionList::getDeclaration(cstring n) const {
        return actionList.getDeclaration<ActionListElement>(n); }
#line 6725 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::ActionList::operator==(IR::ActionList const & a) const {
        return PropertyValue::operator==(static_cast<const PropertyValue &>(a))
        && actionList == a.actionList;
    }
bool IR::ActionList::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!PropertyValue::equiv(a_)) return false;
        auto &a = static_cast<const ActionList &>(a_);
        return actionList.equiv(a.actionList);
    }
void IR::ActionList::visit_children(Visitor & v) {
    PropertyValue::visit_children(v);
    actionList.visit_children(v);
}
void IR::ActionList::visit_children(Visitor & v) const {
    PropertyValue::visit_children(v);
    actionList.visit_children(v);
}
void IR::ActionList::toJSON(JSONGenerator & json) const {
    PropertyValue::toJSON(json);
    json << "," << std::endl << json.indent << "\"actionList\" : " << this->actionList;
}
IR::ActionList::ActionList(JSONLoader & json) : PropertyValue(json) {
    json.load("actionList", actionList);
}
IR::Node * IR::ActionList::fromJSON(JSONLoader & json) { return new ActionList(json); }
IR::ActionList::ActionList(Util::SourceInfo srcInfo, IR::IndexedVector<IR::ActionListElement> actionList) :
    PropertyValue(srcInfo), actionList(actionList)
    { validate(); }
IR::ActionList::ActionList(IR::IndexedVector<IR::ActionListElement> actionList) :
    actionList(actionList)
    { validate(); }
#line 219 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::Annotations *IR::KeyElement::getAnnotations() const { return annotations; }
#line 6760 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 220 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
IR::Node const * IR::KeyElement::transform_visit(Transform & v) {
        // call this from Transform::preorder(KeyElement) if the transform might split
        // the expression into a Vector<Expression>
        v.visit(annotations, "annotations");
        auto exp = v.apply_visitor(expression, "expression");
        v.visit(matchType, "matchType");
        v.prune();
        if (exp == expression) {
        } else if (auto vec = exp->to<Vector<Expression>>()) {
            auto *rv = new Vector<KeyElement>();
            for (auto el : *vec) {
                auto *kel = clone();
                kel->expression = el;
                rv->push_back(kel); }
            return rv;
        } else {
            expression = exp->to<IR::Expression>(); }
        return this; }
#line 6780 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::KeyElement::operator==(IR::KeyElement const & a) const {
        return typeid(*this) == typeid(a)
        && annotations == a.annotations
        && expression == a.expression
        && matchType == a.matchType;
    }
bool IR::KeyElement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const KeyElement &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr)
        && (matchType ? a.matchType ? matchType->equiv(*a.matchType) : false : a.matchType == nullptr);
    }
void IR::KeyElement::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(expression, "expression");
    v.visit(matchType, "matchType");
}
void IR::KeyElement::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(expression, "expression");
    v.visit(matchType, "matchType");
}
void IR::KeyElement::validate() const {
#line 6808 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(expression);
        CHECK_NULL(matchType); }
void IR::KeyElement::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"expression\" : " << this->expression;
    json << "," << std::endl << json.indent << "\"matchType\" : " << this->matchType;
}
IR::KeyElement::KeyElement(JSONLoader & json) : Node(json) {
    json.load("annotations", annotations);
    json.load("expression", expression);
    json.load("matchType", matchType);
}
IR::Node * IR::KeyElement::fromJSON(JSONLoader & json) { return new KeyElement(json); }
IR::KeyElement::KeyElement(Util::SourceInfo srcInfo, const IR::Annotations* annotations, const IR::Expression* expression, const IR::PathExpression* matchType) :
    Node(srcInfo), annotations(annotations), expression(expression), matchType(matchType)
    { validate(); }
IR::KeyElement::KeyElement(const IR::Annotations* annotations, const IR::Expression* expression, const IR::PathExpression* matchType) :
    annotations(annotations), expression(expression), matchType(matchType)
    { validate(); }
IR::KeyElement::KeyElement(Util::SourceInfo srcInfo, const IR::Expression* expression, const IR::PathExpression* matchType) :
    Node(srcInfo), expression(expression), matchType(matchType)
    { validate(); }
IR::KeyElement::KeyElement(const IR::Expression* expression, const IR::PathExpression* matchType) :
    expression(expression), matchType(matchType)
    { validate(); }
#line 243 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::Key::validate() const {
#line 6839 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        keyElements.validate();
#line 243 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
{ keyElements.check_null(); } }
#line 6844 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 244 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::Key::push_back(const IR::KeyElement* ke) { keyElements.push_back(ke); }
#line 6847 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Key::operator==(IR::Key const & a) const {
        return PropertyValue::operator==(static_cast<const PropertyValue &>(a))
        && keyElements == a.keyElements;
    }
bool IR::Key::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!PropertyValue::equiv(a_)) return false;
        auto &a = static_cast<const Key &>(a_);
        return keyElements.equiv(a.keyElements);
    }
void IR::Key::visit_children(Visitor & v) {
    PropertyValue::visit_children(v);
    keyElements.visit_children(v);
}
void IR::Key::visit_children(Visitor & v) const {
    PropertyValue::visit_children(v);
    keyElements.visit_children(v);
}
void IR::Key::toJSON(JSONGenerator & json) const {
    PropertyValue::toJSON(json);
    json << "," << std::endl << json.indent << "\"keyElements\" : " << this->keyElements;
}
IR::Key::Key(JSONLoader & json) : PropertyValue(json) {
    json.load("keyElements", keyElements);
}
IR::Node * IR::Key::fromJSON(JSONLoader & json) { return new Key(json); }
IR::Key::Key(Util::SourceInfo srcInfo, IR::Vector<IR::KeyElement> keyElements) :
    PropertyValue(srcInfo), keyElements(keyElements)
    { validate(); }
IR::Key::Key(IR::Vector<IR::KeyElement> keyElements) :
    keyElements(keyElements)
    { validate(); }
/// annotations are optional (supported annotations: @priority(value))
/// must be a tuple expression
/// typically a MethodCallExpression.
/// The action must be defined in action list
#line 255 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::Annotations *IR::Entry::getAnnotations() const { return annotations; }
#line 6886 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 256 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::ListExpression *IR::Entry::getKeys() const { return keys; }
#line 6889 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 257 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::Expression *IR::Entry::getAction() const { return action; }
#line 6892 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 258 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::Entry::dbprint(std::ostream & out) const { out << annotations << keys << action; }
#line 6895 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Entry::operator==(IR::Entry const & a) const {
        return typeid(*this) == typeid(a)
        && annotations == a.annotations
        && keys == a.keys
        && action == a.action;
    }
bool IR::Entry::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const Entry &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (keys ? a.keys ? keys->equiv(*a.keys) : false : a.keys == nullptr)
        && (action ? a.action ? action->equiv(*a.action) : false : a.action == nullptr);
    }
void IR::Entry::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(keys, "keys");
    v.visit(action, "action");
}
void IR::Entry::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(keys, "keys");
    v.visit(action, "action");
}
void IR::Entry::validate() const {
#line 6923 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(keys);
        CHECK_NULL(action); }
void IR::Entry::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"keys\" : " << this->keys;
    json << "," << std::endl << json.indent << "\"action\" : " << this->action;
}
IR::Entry::Entry(JSONLoader & json) : Node(json) {
    json.load("annotations", annotations);
    json.load("keys", keys);
    json.load("action", action);
}
IR::Node * IR::Entry::fromJSON(JSONLoader & json) { return new Entry(json); }
IR::Entry::Entry(Util::SourceInfo srcInfo, const IR::Annotations* annotations, const IR::ListExpression* keys, const IR::Expression* action) :
    Node(srcInfo), annotations(annotations), keys(keys), action(action)
    { validate(); }
IR::Entry::Entry(const IR::Annotations* annotations, const IR::ListExpression* keys, const IR::Expression* action) :
    annotations(annotations), keys(keys), action(action)
    { validate(); }
IR::Entry::Entry(Util::SourceInfo srcInfo, const IR::ListExpression* keys, const IR::Expression* action) :
    Node(srcInfo), keys(keys), action(action)
    { validate(); }
IR::Entry::Entry(const IR::ListExpression* keys, const IR::Expression* action) :
    keys(keys), action(action)
    { validate(); }
#line 264 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
size_t IR::EntriesList::size() const { return entries.size(); }
#line 6954 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 265 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::EntriesList::dbprint(std::ostream & out) const { out << "{ " << entries << "}"; }
#line 6957 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::EntriesList::operator==(IR::EntriesList const & a) const {
        return PropertyValue::operator==(static_cast<const PropertyValue &>(a))
        && entries == a.entries;
    }
bool IR::EntriesList::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!PropertyValue::equiv(a_)) return false;
        auto &a = static_cast<const EntriesList &>(a_);
        return entries.equiv(a.entries);
    }
void IR::EntriesList::visit_children(Visitor & v) {
    PropertyValue::visit_children(v);
    entries.visit_children(v);
}
void IR::EntriesList::visit_children(Visitor & v) const {
    PropertyValue::visit_children(v);
    entries.visit_children(v);
}
void IR::EntriesList::validate() const {
#line 6977 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        entries.validate(); }
void IR::EntriesList::toJSON(JSONGenerator & json) const {
    PropertyValue::toJSON(json);
    json << "," << std::endl << json.indent << "\"entries\" : " << this->entries;
}
IR::EntriesList::EntriesList(JSONLoader & json) : PropertyValue(json) {
    json.load("entries", entries);
}
IR::Node * IR::EntriesList::fromJSON(JSONLoader & json) { return new EntriesList(json); }
IR::EntriesList::EntriesList(Util::SourceInfo srcInfo, IR::Vector<IR::Entry> entries) :
    PropertyValue(srcInfo), entries(entries)
    { validate(); }
IR::EntriesList::EntriesList(IR::Vector<IR::Entry> entries) :
    entries(entries)
    { validate(); }
#line 272 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::Annotations *IR::Property::getAnnotations() const { return annotations; }
#line 6996 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 273 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::Property::dbprint(std::ostream & out) const { out << annotations << (isConstant ? "const " : "") << name << " = " << value; }
#line 6999 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Property::operator==(IR::Property const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && value == a.value
        && isConstant == a.isConstant;
    }
bool IR::Property::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Property &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (value ? a.value ? value->equiv(*a.value) : false : a.value == nullptr)
        && isConstant == a.isConstant;
    }
void IR::Property::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(value, "value");
}
void IR::Property::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(value, "value");
}
void IR::Property::validate() const {
#line 7025 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(value); }
void IR::Property::dump_fields(std::ostream & out) const {
    Declaration::dump_fields(out);
        out << " isConstant=" << isConstant;
}
void IR::Property::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"value\" : " << this->value;
    json << "," << std::endl << json.indent << "\"isConstant\" : " << this->isConstant;
}
IR::Property::Property(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("value", value);
    json.load("isConstant", isConstant);
}
IR::Node * IR::Property::fromJSON(JSONLoader & json) { return new Property(json); }
IR::Property::Property(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::PropertyValue* value, bool isConstant) :
    Declaration(srcInfo, name), annotations(annotations), value(value), isConstant(isConstant)
    { validate(); }
IR::Property::Property(IR::ID name, const IR::Annotations* annotations, const IR::PropertyValue* value, bool isConstant) :
    Declaration(name), annotations(annotations), value(value), isConstant(isConstant)
    { validate(); }
IR::Property::Property(Util::SourceInfo srcInfo, IR::ID name, const IR::PropertyValue* value, bool isConstant) :
    Declaration(srcInfo, name), value(value), isConstant(isConstant)
    { validate(); }
IR::Property::Property(IR::ID name, const IR::PropertyValue* value, bool isConstant) :
    Declaration(name), value(value), isConstant(isConstant)
    { validate(); }
#line 278 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
cstring IR::TableProperties::toString() const { return "TableProperties(" + Util::toString(properties.size()) + ")"; }
#line 7059 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 279 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::TableProperties::getDeclarations() const {
        return properties.getDeclarations(); }
#line 7063 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 281 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::Property *IR::TableProperties::getProperty(cstring name) const {
        return properties.getDeclaration<Property>(name); }
#line 7067 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 283 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::IDeclaration *IR::TableProperties::getDeclByName(cstring name) const {
        return properties.getDeclaration(name); }
#line 7071 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 285 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::TableProperties::push_back(const IR::Property* prop) { properties.push_back(prop); }
#line 7074 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 293 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::TableProperties::validate() const {
#line 7077 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        properties.validate();
#line 293 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
{ properties.check_null(); properties.validate(); } }
#line 7082 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::TableProperties::operator==(IR::TableProperties const & a) const {
        return typeid(*this) == typeid(a)
        && properties == a.properties;
    }
bool IR::TableProperties::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const TableProperties &>(a_);
        return properties.equiv(a.properties);
    }
void IR::TableProperties::visit_children(Visitor & v) {
    Node::visit_children(v);
    properties.visit_children(v);
}
void IR::TableProperties::visit_children(Visitor & v) const {
    Node::visit_children(v);
    properties.visit_children(v);
}
void IR::TableProperties::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"properties\" : " << this->properties;
}
IR::TableProperties::TableProperties(JSONLoader & json) : Node(json) {
    json.load("properties", properties);
}
IR::Node * IR::TableProperties::fromJSON(JSONLoader & json) { return new TableProperties(json); }
IR::TableProperties::TableProperties(Util::SourceInfo srcInfo, IR::IndexedVector<IR::Property> properties) :
    Node(srcInfo), properties(properties)
    { validate(); }
IR::TableProperties::TableProperties(IR::IndexedVector<IR::Property> properties) :
    properties(properties)
    { validate(); }
IR::TableProperties::TableProperties(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::TableProperties::TableProperties() 
    { validate(); }
#line 300 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::Annotations *IR::P4Table::getAnnotations() const { return annotations; }
#line 7122 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 302 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::ParameterList *IR::P4Table::getApplyParameters() const { return new ParameterList(); }
#line 7125 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 303 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::ActionList *IR::P4Table::getActionList() const {
        auto ap = properties->getProperty(TableProperties::actionsPropertyName);
        if (ap == nullptr)
            return nullptr;
        if (!ap->value->is<IR::ActionList>()) {
            ::error(ErrorType::ERR_INVALID, "%1%: must be an action list", ap);
            return nullptr; }
        return ap->value->to<IR::ActionList>(); }
#line 7135 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 311 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::Key *IR::P4Table::getKey() const {
        auto kp = properties->getProperty(TableProperties::keyPropertyName);
        if (kp == nullptr)
            return nullptr;
        if (!kp->value->is<IR::Key>()) {
            ::error(ErrorType::ERR_INVALID, "%1%: must be a key", kp);
            return nullptr; }
        return kp->value->to<IR::Key>(); }
#line 7145 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 319 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::Expression *IR::P4Table::getDefaultAction() const {
        auto d = properties->getProperty(TableProperties::defaultActionPropertyName);
        if (d == nullptr)
            return nullptr;
        if (!d->value->is<IR::ExpressionValue>()) {
            ::error(ErrorType::ERR_INVALID, "%1%: must be an expression", d);
            return nullptr; }
        return d->value->to<IR::ExpressionValue>()->expression; }
#line 7155 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 327 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::Constant *IR::P4Table::getConstantProperty(cstring name) const {
        if (auto d = properties->getProperty(name)) {
            if (auto ev = d->value->to<IR::ExpressionValue>()) {
                if (auto k = ev->expression->to<IR::Constant>()) {
                    return k; } }
            error(ErrorType::ERR_INVALID, "%1% must be a constant numeric expression", d); }
        return nullptr; }
#line 7164 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 334 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::Constant *IR::P4Table::getSizeProperty() const {
        return getConstantProperty(TableProperties::sizePropertyName);
    }
#line 7169 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 337 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::EntriesList *IR::P4Table::getEntries() const {
        auto ep = properties->getProperty(TableProperties::entriesPropertyName);
        if (ep == nullptr)
            return nullptr;
        if (!ep->value->is<IR::EntriesList>()) {
            ::error(ErrorType::ERR_INVALID, "%1%: must be a list of entries", ep);
            return nullptr;
        }
        return ep->value->to<IR::EntriesList>();
    }
#line 7181 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::P4Table::operator==(IR::P4Table const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && properties == a.properties;
    }
bool IR::P4Table::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const P4Table &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (properties ? a.properties ? properties->equiv(*a.properties) : false : a.properties == nullptr);
    }
void IR::P4Table::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(properties, "properties");
}
void IR::P4Table::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(properties, "properties");
}
void IR::P4Table::validate() const {
#line 7205 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(properties); }
void IR::P4Table::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"properties\" : " << this->properties;
}
IR::P4Table::P4Table(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("properties", properties);
}
IR::Node * IR::P4Table::fromJSON(JSONLoader & json) { return new P4Table(json); }
IR::P4Table::P4Table(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TableProperties* properties) :
    Declaration(srcInfo, name), annotations(annotations), properties(properties)
    { validate(); }
IR::P4Table::P4Table(IR::ID name, const IR::Annotations* annotations, const IR::TableProperties* properties) :
    Declaration(name), annotations(annotations), properties(properties)
    { validate(); }
IR::P4Table::P4Table(Util::SourceInfo srcInfo, IR::ID name, const IR::TableProperties* properties) :
    Declaration(srcInfo, name), properties(properties)
    { validate(); }
IR::P4Table::P4Table(IR::ID name, const IR::TableProperties* properties) :
    Declaration(name), properties(properties)
    { validate(); }

#line 353 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::Annotations *IR::P4ValueSet::getAnnotations() const { return annotations; }
#line 7234 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::P4ValueSet::operator==(IR::P4ValueSet const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && elementType == a.elementType
        && size == a.size;
    }
bool IR::P4ValueSet::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const P4ValueSet &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (elementType ? a.elementType ? elementType->equiv(*a.elementType) : false : a.elementType == nullptr)
        && (size ? a.size ? size->equiv(*a.size) : false : a.size == nullptr);
    }
void IR::P4ValueSet::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(elementType, "elementType");
    v.visit(size, "size");
}
void IR::P4ValueSet::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(elementType, "elementType");
    v.visit(size, "size");
}
void IR::P4ValueSet::validate() const {
#line 7262 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(elementType);
        CHECK_NULL(size); }
void IR::P4ValueSet::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"elementType\" : " << this->elementType;
    json << "," << std::endl << json.indent << "\"size\" : " << this->size;
}
IR::P4ValueSet::P4ValueSet(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("elementType", elementType);
    json.load("size", size);
}
IR::Node * IR::P4ValueSet::fromJSON(JSONLoader & json) { return new P4ValueSet(json); }
IR::P4ValueSet::P4ValueSet(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* elementType, const IR::Expression* size) :
    Declaration(srcInfo, name), annotations(annotations), elementType(elementType), size(size)
    { validate(); }
IR::P4ValueSet::P4ValueSet(IR::ID name, const IR::Annotations* annotations, const IR::Type* elementType, const IR::Expression* size) :
    Declaration(name), annotations(annotations), elementType(elementType), size(size)
    { validate(); }
IR::P4ValueSet::P4ValueSet(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* elementType, const IR::Expression* size) :
    Declaration(srcInfo, name), elementType(elementType), size(size)
    { validate(); }
IR::P4ValueSet::P4ValueSet(IR::ID name, const IR::Type* elementType, const IR::Expression* size) :
    Declaration(name), elementType(elementType), size(size)
    { validate(); }
#line 361 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::Annotations *IR::Declaration_Variable::getAnnotations() const { return annotations; }
#line 7293 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 362 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::Declaration_Variable::dbprint(std::ostream & out) const {
        out << annotations << type << ' ' << name;
        if (initializer) out << " = " << *initializer; }
#line 7298 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Declaration_Variable::operator==(IR::Declaration_Variable const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && type == a.type
        && initializer == a.initializer;
    }
bool IR::Declaration_Variable::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Declaration_Variable &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (initializer ? a.initializer ? initializer->equiv(*a.initializer) : false : a.initializer == nullptr);
    }
void IR::Declaration_Variable::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
    v.visit(initializer, "initializer");
}
void IR::Declaration_Variable::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
    v.visit(initializer, "initializer");
}
void IR::Declaration_Variable::validate() const {
#line 7326 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(type); }
void IR::Declaration_Variable::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
    if (initializer != nullptr)     json << "," << std::endl << json.indent << "\"initializer\" : " << this->initializer;
}
IR::Declaration_Variable::Declaration_Variable(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("type", type);
    json.load("initializer", initializer);
}
IR::Node * IR::Declaration_Variable::fromJSON(JSONLoader & json) { return new Declaration_Variable(json); }
IR::Declaration_Variable::Declaration_Variable(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Expression* initializer) :
    Declaration(srcInfo, name), annotations(annotations), type(type), initializer(initializer)
    { validate(); }
IR::Declaration_Variable::Declaration_Variable(IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Expression* initializer) :
    Declaration(name), annotations(annotations), type(type), initializer(initializer)
    { validate(); }
IR::Declaration_Variable::Declaration_Variable(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type, const IR::Expression* initializer) :
    Declaration(srcInfo, name), type(type), initializer(initializer)
    { validate(); }
IR::Declaration_Variable::Declaration_Variable(IR::ID name, const IR::Type* type, const IR::Expression* initializer) :
    Declaration(name), type(type), initializer(initializer)
    { validate(); }
IR::Declaration_Variable::Declaration_Variable(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type) :
    Declaration(srcInfo, name), annotations(annotations), type(type)
    { validate(); }
IR::Declaration_Variable::Declaration_Variable(IR::ID name, const IR::Annotations* annotations, const IR::Type* type) :
    Declaration(name), annotations(annotations), type(type)
    { validate(); }
IR::Declaration_Variable::Declaration_Variable(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type) :
    Declaration(srcInfo, name), type(type)
    { validate(); }
IR::Declaration_Variable::Declaration_Variable(IR::ID name, const IR::Type* type) :
    Declaration(name), type(type)
    { validate(); }
#line 372 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::Annotations *IR::Declaration_Constant::getAnnotations() const { return annotations; }
#line 7368 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 373 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
cstring IR::Declaration_Constant::toString() const { return Declaration::toString(); }
#line 7371 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 374 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::Declaration_Constant::dbprint(std::ostream & out) const { out << annotations << type << ' ' << name << " = " << *initializer; }
#line 7374 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Declaration_Constant::operator==(IR::Declaration_Constant const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && type == a.type
        && initializer == a.initializer;
    }
bool IR::Declaration_Constant::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Declaration_Constant &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (initializer ? a.initializer ? initializer->equiv(*a.initializer) : false : a.initializer == nullptr);
    }
void IR::Declaration_Constant::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
    v.visit(initializer, "initializer");
}
void IR::Declaration_Constant::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
    v.visit(initializer, "initializer");
}
void IR::Declaration_Constant::validate() const {
#line 7402 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(type);
        CHECK_NULL(initializer); }
void IR::Declaration_Constant::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
    json << "," << std::endl << json.indent << "\"initializer\" : " << this->initializer;
}
IR::Declaration_Constant::Declaration_Constant(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("type", type);
    json.load("initializer", initializer);
}
IR::Node * IR::Declaration_Constant::fromJSON(JSONLoader & json) { return new Declaration_Constant(json); }
IR::Declaration_Constant::Declaration_Constant(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Expression* initializer) :
    Declaration(srcInfo, name), annotations(annotations), type(type), initializer(initializer)
    { validate(); }
IR::Declaration_Constant::Declaration_Constant(IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Expression* initializer) :
    Declaration(name), annotations(annotations), type(type), initializer(initializer)
    { validate(); }
IR::Declaration_Constant::Declaration_Constant(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type, const IR::Expression* initializer) :
    Declaration(srcInfo, name), type(type), initializer(initializer)
    { validate(); }
IR::Declaration_Constant::Declaration_Constant(IR::ID name, const IR::Type* type, const IR::Expression* initializer) :
    Declaration(name), type(type), initializer(initializer)
    { validate(); }



#line 389 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::Annotations *IR::Declaration_Instance::getAnnotations() const { return annotations; }
#line 7436 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 390 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::Type *IR::Declaration_Instance::getType() const { return type; }
#line 7439 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 391 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
cstring IR::Declaration_Instance::Name() const { return name; }
#line 7442 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 392 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::Declaration_Instance::validate() const {
#line 7445 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(type);
        CHECK_NULL(arguments);
        properties.validate();
#line 392 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
{ BUG_CHECK(type->is<Type_Name>() ||
                        type->is<Type_Specialized>() ||
                        type->is<Type_Extern>(),        // P4_14 only?
                        "%1%: unexpected type", type);
        arguments->check_null(); } }
#line 7457 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Declaration_Instance::operator==(IR::Declaration_Instance const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && type == a.type
        && arguments == a.arguments
        && properties == a.properties
        && initializer == a.initializer;
    }
bool IR::Declaration_Instance::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Declaration_Instance &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (arguments ? a.arguments ? arguments->equiv(*a.arguments) : false : a.arguments == nullptr)
        && properties.equiv(a.properties)
        && (initializer ? a.initializer ? initializer->equiv(*a.initializer) : false : a.initializer == nullptr);
    }
void IR::Declaration_Instance::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
    v.visit(arguments, "arguments");
    properties.visit_children(v);
    v.visit(initializer, "initializer");
}
void IR::Declaration_Instance::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
    v.visit(arguments, "arguments");
    properties.visit_children(v);
    v.visit(initializer, "initializer");
}
void IR::Declaration_Instance::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
    json << "," << std::endl << json.indent << "\"arguments\" : " << this->arguments;
    json << "," << std::endl << json.indent << "\"properties\" : " << this->properties;
    if (initializer != nullptr)     json << "," << std::endl << json.indent << "\"initializer\" : " << this->initializer;
}
IR::Declaration_Instance::Declaration_Instance(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("type", type);
    json.load("arguments", arguments);
    json.load("properties", properties);
    json.load("initializer", initializer);
}
IR::Node * IR::Declaration_Instance::fromJSON(JSONLoader & json) { return new Declaration_Instance(json); }
IR::Declaration_Instance::Declaration_Instance(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer) :
    Declaration(srcInfo, name), annotations(annotations), type(type), arguments(arguments), initializer(initializer)
    { validate(); }
IR::Declaration_Instance::Declaration_Instance(IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer) :
    Declaration(name), annotations(annotations), type(type), arguments(arguments), initializer(initializer)
    { validate(); }
IR::Declaration_Instance::Declaration_Instance(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer) :
    Declaration(srcInfo, name), type(type), arguments(arguments), initializer(initializer)
    { validate(); }
IR::Declaration_Instance::Declaration_Instance(IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer) :
    Declaration(name), type(type), arguments(arguments), initializer(initializer)
    { validate(); }
IR::Declaration_Instance::Declaration_Instance(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments) :
    Declaration(srcInfo, name), annotations(annotations), type(type), arguments(arguments)
    { validate(); }
IR::Declaration_Instance::Declaration_Instance(IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments) :
    Declaration(name), annotations(annotations), type(type), arguments(arguments)
    { validate(); }
IR::Declaration_Instance::Declaration_Instance(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments) :
    Declaration(srcInfo, name), type(type), arguments(arguments)
    { validate(); }
IR::Declaration_Instance::Declaration_Instance(IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments) :
    Declaration(name), type(type), arguments(arguments)
    { validate(); }
/// Top-level program objects.
/// This is not an IndexedVector because:
/// - we allow overloaded function-like objects.
/// - not all objects in a P4Program are declarations (e.g., match_kind is not).
#line 407 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::P4Program::validate() const {
#line 7538 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        objects.validate();
#line 407 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
{ objects.check_null(); } }
#line 7543 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
IRNODE_DEFINE_APPLY_OVERLOAD(P4Program, , )
bool IR::P4Program::operator==(IR::P4Program const & a) const {
        return typeid(*this) == typeid(a)
        && objects == a.objects;
    }
bool IR::P4Program::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const P4Program &>(a_);
        return objects.equiv(a.objects);
    }
void IR::P4Program::visit_children(Visitor & v) {
    Node::visit_children(v);
    objects.visit_children(v);
}
void IR::P4Program::visit_children(Visitor & v) const {
    Node::visit_children(v);
    objects.visit_children(v);
}
void IR::P4Program::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"objects\" : " << this->objects;
}
IR::P4Program::P4Program(JSONLoader & json) : Node(json) {
    json.load("objects", objects);
}
IR::Node * IR::P4Program::fromJSON(JSONLoader & json) { return new P4Program(json); }
IR::P4Program::P4Program(Util::SourceInfo srcInfo, IR::Vector<IR::Node> objects) :
    Node(srcInfo), objects(objects)
    { validate(); }
IR::P4Program::P4Program(IR::Vector<IR::Node> objects) :
    objects(objects)
    { validate(); }
IR::P4Program::P4Program(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::P4Program::P4Program() 
    { validate(); }
bool IR::Statement::operator==(IR::Statement const & a) const {
        return StatOrDecl::operator==(static_cast<const StatOrDecl &>(a));
    }
bool IR::Statement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!StatOrDecl::equiv(a_)) return false;
        return true;
    }
void IR::Statement::toJSON(JSONGenerator & json) const {
    StatOrDecl::toJSON(json);
}
IR::Statement::Statement(JSONLoader & json) : StatOrDecl(json) {
}
IR::Statement::Statement(Util::SourceInfo srcInfo) :
    StatOrDecl(srcInfo)
    { validate(); }
IR::Statement::Statement() 
    { validate(); }
#line 417 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
cstring IR::ExitStatement::toString() const { return "exit"; }
#line 7602 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 418 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::ExitStatement::dbprint(std::ostream & out) const { out << "exit"; }
#line 7605 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::ExitStatement::operator==(IR::ExitStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a));
    }
bool IR::ExitStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        return true;
    }
void IR::ExitStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
}
IR::ExitStatement::ExitStatement(JSONLoader & json) : Statement(json) {
}
IR::Node * IR::ExitStatement::fromJSON(JSONLoader & json) { return new ExitStatement(json); }
IR::ExitStatement::ExitStatement(Util::SourceInfo srcInfo) :
    Statement(srcInfo)
    { validate(); }
IR::ExitStatement::ExitStatement() 
    { validate(); }
#line 423 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
cstring IR::ReturnStatement::toString() const { return cstring("return ") +
                (expression != nullptr ? expression->toString() : cstring("")); }
#line 7628 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::ReturnStatement::operator==(IR::ReturnStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a))
        && expression == a.expression;
    }
bool IR::ReturnStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        auto &a = static_cast<const ReturnStatement &>(a_);
        return (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr);
    }
void IR::ReturnStatement::visit_children(Visitor & v) {
    Statement::visit_children(v);
    v.visit(expression, "expression");
}
void IR::ReturnStatement::visit_children(Visitor & v) const {
    Statement::visit_children(v);
    v.visit(expression, "expression");
}
void IR::ReturnStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
    if (expression != nullptr)     json << "," << std::endl << json.indent << "\"expression\" : " << this->expression;
}
IR::ReturnStatement::ReturnStatement(JSONLoader & json) : Statement(json) {
    json.load("expression", expression);
}
IR::Node * IR::ReturnStatement::fromJSON(JSONLoader & json) { return new ReturnStatement(json); }
IR::ReturnStatement::ReturnStatement(Util::SourceInfo srcInfo, const IR::Expression* expression) :
    Statement(srcInfo), expression(expression)
    { validate(); }
IR::ReturnStatement::ReturnStatement(const IR::Expression* expression) :
    expression(expression)
    { validate(); }
#line 428 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::EmptyStatement::dbprint(std::ostream & out) const { out << ""; }
#line 7663 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::EmptyStatement::operator==(IR::EmptyStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a));
    }
bool IR::EmptyStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        return true;
    }
void IR::EmptyStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
}
IR::EmptyStatement::EmptyStatement(JSONLoader & json) : Statement(json) {
}
IR::Node * IR::EmptyStatement::fromJSON(JSONLoader & json) { return new EmptyStatement(json); }
IR::EmptyStatement::EmptyStatement(Util::SourceInfo srcInfo) :
    Statement(srcInfo)
    { validate(); }
IR::EmptyStatement::EmptyStatement() 
    { validate(); }
bool IR::AssignmentStatement::operator==(IR::AssignmentStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a))
        && left == a.left
        && right == a.right;
    }
bool IR::AssignmentStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        auto &a = static_cast<const AssignmentStatement &>(a_);
        return (left ? a.left ? left->equiv(*a.left) : false : a.left == nullptr)
        && (right ? a.right ? right->equiv(*a.right) : false : a.right == nullptr);
    }
void IR::AssignmentStatement::visit_children(Visitor & v) {
    Statement::visit_children(v);
    v.visit(left, "left");
    v.visit(right, "right");
}
void IR::AssignmentStatement::visit_children(Visitor & v) const {
    Statement::visit_children(v);
    v.visit(left, "left");
    v.visit(right, "right");
}
void IR::AssignmentStatement::validate() const {
#line 7706 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(left);
        CHECK_NULL(right); }
void IR::AssignmentStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
    json << "," << std::endl << json.indent << "\"left\" : " << this->left;
    json << "," << std::endl << json.indent << "\"right\" : " << this->right;
}
IR::AssignmentStatement::AssignmentStatement(JSONLoader & json) : Statement(json) {
    json.load("left", left);
    json.load("right", right);
}
IR::Node * IR::AssignmentStatement::fromJSON(JSONLoader & json) { return new AssignmentStatement(json); }
IR::AssignmentStatement::AssignmentStatement(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Statement(srcInfo), left(left), right(right)
    { validate(); }
IR::AssignmentStatement::AssignmentStatement(const IR::Expression* left, const IR::Expression* right) :
    left(left), right(right)
    { validate(); }
#line 440 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::IfStatement::visit_children(Visitor & v) {
        v.visit(condition, "condition");
        auto &clone(v.flow_clone());
        v.visit(ifTrue, "ifTrue");
        clone.visit(ifFalse, "ifFalse");
        v.flow_merge(clone);
    }
#line 440 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::IfStatement::visit_children(Visitor & v) const {
        v.visit(condition, "condition");
        auto &clone(v.flow_clone());
        v.visit(ifTrue, "ifTrue");
        clone.visit(ifFalse, "ifFalse");
        v.flow_merge(clone);
    }
#line 7742 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 447 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::IfStatement::validate() const {
#line 7745 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(condition);
        CHECK_NULL(ifTrue);
#line 447 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
{ CHECK_NULL(ifTrue); } }
#line 7751 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::IfStatement::operator==(IR::IfStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a))
        && condition == a.condition
        && ifTrue == a.ifTrue
        && ifFalse == a.ifFalse;
    }
bool IR::IfStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        auto &a = static_cast<const IfStatement &>(a_);
        return (condition ? a.condition ? condition->equiv(*a.condition) : false : a.condition == nullptr)
        && (ifTrue ? a.ifTrue ? ifTrue->equiv(*a.ifTrue) : false : a.ifTrue == nullptr)
        && (ifFalse ? a.ifFalse ? ifFalse->equiv(*a.ifFalse) : false : a.ifFalse == nullptr);
    }
void IR::IfStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
    json << "," << std::endl << json.indent << "\"condition\" : " << this->condition;
    json << "," << std::endl << json.indent << "\"ifTrue\" : " << this->ifTrue;
    if (ifFalse != nullptr)     json << "," << std::endl << json.indent << "\"ifFalse\" : " << this->ifFalse;
}
IR::IfStatement::IfStatement(JSONLoader & json) : Statement(json) {
    json.load("condition", condition);
    json.load("ifTrue", ifTrue);
    json.load("ifFalse", ifFalse);
}
IR::Node * IR::IfStatement::fromJSON(JSONLoader & json) { return new IfStatement(json); }
IR::IfStatement::IfStatement(Util::SourceInfo srcInfo, const IR::Expression* condition, const IR::Statement* ifTrue, const IR::Statement* ifFalse) :
    Statement(srcInfo), condition(condition), ifTrue(ifTrue), ifFalse(ifFalse)
    { validate(); }
IR::IfStatement::IfStatement(const IR::Expression* condition, const IR::Statement* ifTrue, const IR::Statement* ifFalse) :
    condition(condition), ifTrue(ifTrue), ifFalse(ifFalse)
    { validate(); }
#line 453 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::IDeclaration *IR::BlockStatement::getDeclByName(cstring name) const {
        return components.getDeclaration(name); }
#line 7787 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 455 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::BlockStatement::getDeclarations() const {
        return components.getDeclarations(); }
#line 7791 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 457 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::BlockStatement::push_back(const IR::StatOrDecl* st) { components.push_back(st); }
#line 7794 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 458 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::Annotations *IR::BlockStatement::getAnnotations() const { return annotations; }
#line 7797 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::BlockStatement::operator==(IR::BlockStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a))
        && annotations == a.annotations
        && components == a.components;
    }
bool IR::BlockStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        auto &a = static_cast<const BlockStatement &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && components.equiv(a.components);
    }
void IR::BlockStatement::visit_children(Visitor & v) {
    Statement::visit_children(v);
    v.visit(annotations, "annotations");
    components.visit_children(v);
}
void IR::BlockStatement::visit_children(Visitor & v) const {
    Statement::visit_children(v);
    v.visit(annotations, "annotations");
    components.visit_children(v);
}
void IR::BlockStatement::validate() const {
#line 7821 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        components.validate(); }
void IR::BlockStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"components\" : " << this->components;
}
IR::BlockStatement::BlockStatement(JSONLoader & json) : Statement(json) {
    json.load("annotations", annotations);
    json.load("components", components);
}
IR::Node * IR::BlockStatement::fromJSON(JSONLoader & json) { return new BlockStatement(json); }
IR::BlockStatement::BlockStatement(Util::SourceInfo srcInfo, const IR::Annotations* annotations, IR::IndexedVector<IR::StatOrDecl> components) :
    Statement(srcInfo), annotations(annotations), components(components)
    { validate(); }
IR::BlockStatement::BlockStatement(const IR::Annotations* annotations, IR::IndexedVector<IR::StatOrDecl> components) :
    annotations(annotations), components(components)
    { validate(); }
IR::BlockStatement::BlockStatement(Util::SourceInfo srcInfo, IR::IndexedVector<IR::StatOrDecl> components) :
    Statement(srcInfo), components(components)
    { validate(); }
IR::BlockStatement::BlockStatement(IR::IndexedVector<IR::StatOrDecl> components) :
    components(components)
    { validate(); }
IR::BlockStatement::BlockStatement(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    Statement(srcInfo), annotations(annotations)
    { validate(); }
IR::BlockStatement::BlockStatement(const IR::Annotations* annotations) :
    annotations(annotations)
    { validate(); }
IR::BlockStatement::BlockStatement(Util::SourceInfo srcInfo) :
    Statement(srcInfo)
    { validate(); }
IR::BlockStatement::BlockStatement() 
    { validate(); }
#line 464 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
IR::MethodCallStatement::MethodCallStatement(Util::SourceInfo si, IR::ID m, std::initializer_list<const IR::Argument *> const & a) : Statement(si), methodCall(new MethodCallExpression(si, m, a)) {}
#line 7860 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 466 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
IR::MethodCallStatement::MethodCallStatement(Util::SourceInfo si, const IR::Expression* m, std::initializer_list<const IR::Argument *> const & a) : Statement(si), methodCall(new MethodCallExpression(si, m, a)) {}
#line 7863 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 469 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
cstring IR::MethodCallStatement::toString() const { return methodCall->toString(); }
#line 7866 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::MethodCallStatement::operator==(IR::MethodCallStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a))
        && methodCall == a.methodCall;
    }
bool IR::MethodCallStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        auto &a = static_cast<const MethodCallStatement &>(a_);
        return (methodCall ? a.methodCall ? methodCall->equiv(*a.methodCall) : false : a.methodCall == nullptr);
    }
void IR::MethodCallStatement::visit_children(Visitor & v) {
    Statement::visit_children(v);
    v.visit(methodCall, "methodCall");
}
void IR::MethodCallStatement::visit_children(Visitor & v) const {
    Statement::visit_children(v);
    v.visit(methodCall, "methodCall");
}
void IR::MethodCallStatement::validate() const {
#line 7886 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(methodCall); }
void IR::MethodCallStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
    json << "," << std::endl << json.indent << "\"methodCall\" : " << this->methodCall;
}
IR::MethodCallStatement::MethodCallStatement(JSONLoader & json) : Statement(json) {
    json.load("methodCall", methodCall);
}
IR::Node * IR::MethodCallStatement::fromJSON(JSONLoader & json) { return new MethodCallStatement(json); }
IR::MethodCallStatement::MethodCallStatement(Util::SourceInfo srcInfo, const IR::MethodCallExpression* methodCall) :
    Statement(srcInfo), methodCall(methodCall)
    {
#line 463 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
{ if (!srcInfo) srcInfo = methodCall->srcInfo; }
#line 7902 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::MethodCallStatement::MethodCallStatement(const IR::MethodCallExpression* methodCall) :
    methodCall(methodCall)
    {
#line 463 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
{ if (!srcInfo) srcInfo = methodCall->srcInfo; }
#line 7909 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }


#line 476 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::SwitchCase::validate() const {
#line 7915 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(label);
#line 476 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
{
#if 0
        if (!(label->is<IR::DefaultExpression>() || label->is<IR::PathExpression>()))
            ::error(ErrorType::ERR_EXPRESSION,
                    "%1%: Unexpected expression for switch case", *this);
#endif
        BUG_CHECK(statement == nullptr || statement->is<IR::BlockStatement>(),
                  "%1%: Expected a block statement",
                  statement);
    } }
#line 7929 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::SwitchCase::operator==(IR::SwitchCase const & a) const {
        return typeid(*this) == typeid(a)
        && label == a.label
        && statement == a.statement;
    }
bool IR::SwitchCase::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const SwitchCase &>(a_);
        return (label ? a.label ? label->equiv(*a.label) : false : a.label == nullptr)
        && (statement ? a.statement ? statement->equiv(*a.statement) : false : a.statement == nullptr);
    }
void IR::SwitchCase::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(label, "label");
    v.visit(statement, "statement");
}
void IR::SwitchCase::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(label, "label");
    v.visit(statement, "statement");
}
void IR::SwitchCase::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"label\" : " << this->label;
    if (statement != nullptr)     json << "," << std::endl << json.indent << "\"statement\" : " << this->statement;
}
IR::SwitchCase::SwitchCase(JSONLoader & json) : Node(json) {
    json.load("label", label);
    json.load("statement", statement);
}
IR::Node * IR::SwitchCase::fromJSON(JSONLoader & json) { return new SwitchCase(json); }
IR::SwitchCase::SwitchCase(Util::SourceInfo srcInfo, const IR::Expression* label, const IR::Statement* statement) :
    Node(srcInfo), label(label), statement(statement)
    { validate(); }
IR::SwitchCase::SwitchCase(const IR::Expression* label, const IR::Statement* statement) :
    label(label), statement(statement)
    { validate(); }
#line 493 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::SwitchStatement::visit_children(Visitor & v) {
        v.visit(expression, "expression");
        v.parallel_visit(cases, "cases"); }
#line 493 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::SwitchStatement::visit_children(Visitor & v) const {
        v.visit(expression, "expression");
        v.parallel_visit(cases, "cases"); }
#line 7976 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::SwitchStatement::operator==(IR::SwitchStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a))
        && expression == a.expression
        && cases == a.cases;
    }
bool IR::SwitchStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        auto &a = static_cast<const SwitchStatement &>(a_);
        return (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr)
        && cases.equiv(a.cases);
    }
void IR::SwitchStatement::validate() const {
#line 7990 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(expression);
        cases.validate(); }
void IR::SwitchStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
    json << "," << std::endl << json.indent << "\"expression\" : " << this->expression;
    json << "," << std::endl << json.indent << "\"cases\" : " << this->cases;
}
IR::SwitchStatement::SwitchStatement(JSONLoader & json) : Statement(json) {
    json.load("expression", expression);
    json.load("cases", cases);
}
IR::Node * IR::SwitchStatement::fromJSON(JSONLoader & json) { return new SwitchStatement(json); }
IR::SwitchStatement::SwitchStatement(Util::SourceInfo srcInfo, const IR::Expression* expression, IR::Vector<IR::SwitchCase> cases) :
    Statement(srcInfo), expression(expression), cases(cases)
    { validate(); }
IR::SwitchStatement::SwitchStatement(const IR::Expression* expression, IR::Vector<IR::SwitchCase> cases) :
    expression(expression), cases(cases)
    { validate(); }
#line 501 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::ParameterList *IR::Function::getParameters() const {
        return type->parameters;
    }
#line 8014 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 504 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Function::getDeclarations() const {
        return type->parameters->getDeclarations(); }
#line 8018 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 506 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::IDeclaration *IR::Function::getDeclByName(cstring name) const {
        return type->parameters->getDeclByName(name); }
#line 8022 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 508 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
std::vector<const IR::INamespace *> IR::Function::getNestedNamespaces() const {
        return { type->typeParameters }; }
#line 8026 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Function::operator==(IR::Function const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && type == a.type
        && body == a.body;
    }
bool IR::Function::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Function &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (body ? a.body ? body->equiv(*a.body) : false : a.body == nullptr);
    }
void IR::Function::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(type, "type");
    v.visit(body, "body");
}
void IR::Function::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(type, "type");
    v.visit(body, "body");
}
void IR::Function::validate() const {
#line 8050 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(type);
        CHECK_NULL(body); }
void IR::Function::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
    json << "," << std::endl << json.indent << "\"body\" : " << this->body;
}
IR::Function::Function(JSONLoader & json) : Declaration(json) {
    json.load("type", type);
    json.load("body", body);
}
IR::Node * IR::Function::fromJSON(JSONLoader & json) { return new Function(json); }
IR::Function::Function(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Method* type, const IR::BlockStatement* body) :
    Declaration(srcInfo, name), type(type), body(body)
    { validate(); }
IR::Function::Function(IR::ID name, const IR::Type_Method* type, const IR::BlockStatement* body) :
    Declaration(name), type(type), body(body)
    { validate(); }
/// Node that evaluates to this block.
/// This is either a Declaration_Instance or a ConstructorCallExpression.
/// One value for each Node inside that evaluates to a compile-time constant.
/// This includes all constructor parameters, and all inner nested blocks.
/// value can be null for parameters which are optional
#line 533 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
bool IR::Block::hasValue(const IR::Node* node) const {
        return constantValue.find(node) != constantValue.end();
    }
#line 8079 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 536 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::CompileTimeValue *IR::Block::getValue(const IR::Node* node) const {
        CHECK_NULL(node);
        auto it = constantValue.find(node);
        BUG_CHECK(it != constantValue.end(), "%1%: No such node %2%", this, node);
        return it->second; }
#line 8086 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 541 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::Block::visit_children(Visitor & v) { (void)v; }
#line 541 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::Block::visit_children(Visitor & v) const { (void)v; }
#line 8091 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 542 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
IR::IDeclaration const * IR::Block::getContainer() const { return nullptr; }
#line 8094 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Block::operator==(IR::Block const & a) const {
        return typeid(*this) == typeid(a)
        && node == a.node
        && constantValue == a.constantValue;
    }
bool IR::Block::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const Block &>(a_);
        return (node ? a.node ? node->equiv(*a.node) : false : a.node == nullptr)
        && constantValue == a.constantValue;
    }
void IR::Block::validate() const {
#line 8108 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(node); }
void IR::Block::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"node\" : " << this->node;
    json << "," << std::endl << json.indent << "\"constantValue\" : " << this->constantValue;
}
IR::Block::Block(JSONLoader & json) : Node(json) {
    json.load("node", node);
    json.load("constantValue", constantValue);
}
IR::Block::Block(Util::SourceInfo srcInfo, const IR::Node* node) :
    Node(srcInfo), node(node)
    { validate(); }
IR::Block::Block(const IR::Node* node) :
    node(node)
    { validate(); }
#line 547 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
IR::IDeclaration const * IR::TableBlock::getContainer() const { return container; }
#line 8128 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::TableBlock::operator==(IR::TableBlock const & a) const {
        return Block::operator==(static_cast<const Block &>(a))
        && container == a.container;
    }
bool IR::TableBlock::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Block::equiv(a_)) return false;
        auto &a = static_cast<const TableBlock &>(a_);
        return (container ? a.container ? container->equiv(*a.container) : false : a.container == nullptr);
    }
void IR::TableBlock::visit_children(Visitor & v) {
    Block::visit_children(v);
    v.visit(container, "container");
}
void IR::TableBlock::visit_children(Visitor & v) const {
    Block::visit_children(v);
    v.visit(container, "container");
}
void IR::TableBlock::validate() const {
#line 8148 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(container); }
void IR::TableBlock::toJSON(JSONGenerator & json) const {
    Block::toJSON(json);
    json << "," << std::endl << json.indent << "\"container\" : " << this->container;
}
IR::TableBlock::TableBlock(JSONLoader & json) : Block(json) {
    json.load("container", container);
}
IR::Node * IR::TableBlock::fromJSON(JSONLoader & json) { return new TableBlock(json); }
IR::TableBlock::TableBlock(Util::SourceInfo srcInfo, const IR::Node* node, const IR::P4Table* container) :
    Block(srcInfo, node), container(container)
    { validate(); }
IR::TableBlock::TableBlock(const IR::Node* node, const IR::P4Table* container) :
    Block(node), container(container)
    { validate(); }

/// @return the argument that the given parameter was instantiated with.
/// It's a fatal error if no such parameter exists.
/// @return the argument that the given parameter was instantiated with, or
/// null if no such parameter exists.
bool IR::InstantiatedBlock::operator==(IR::InstantiatedBlock const & a) const {
        return Block::operator==(static_cast<const Block &>(a))
        && instanceType == a.instanceType;
    }
bool IR::InstantiatedBlock::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Block::equiv(a_)) return false;
        auto &a = static_cast<const InstantiatedBlock &>(a_);
        return (instanceType ? a.instanceType ? instanceType->equiv(*a.instanceType) : false : a.instanceType == nullptr);
    }
void IR::InstantiatedBlock::visit_children(Visitor & v) {
    Block::visit_children(v);
    v.visit(instanceType, "instanceType");
}
void IR::InstantiatedBlock::visit_children(Visitor & v) const {
    Block::visit_children(v);
    v.visit(instanceType, "instanceType");
}
void IR::InstantiatedBlock::validate() const {
#line 8189 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(instanceType); }
void IR::InstantiatedBlock::toJSON(JSONGenerator & json) const {
    Block::toJSON(json);
    json << "," << std::endl << json.indent << "\"instanceType\" : " << this->instanceType;
}
IR::InstantiatedBlock::InstantiatedBlock(JSONLoader & json) : Block(json) {
    json.load("instanceType", instanceType);
}
IR::InstantiatedBlock::InstantiatedBlock(Util::SourceInfo srcInfo, const IR::Node* node, const IR::Type* instanceType) :
    Block(srcInfo, node), instanceType(instanceType)
    { validate(); }
IR::InstantiatedBlock::InstantiatedBlock(const IR::Node* node, const IR::Type* instanceType) :
    Block(node), instanceType(instanceType)
    { validate(); }
#line 571 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::ParameterList *IR::ParserBlock::getConstructorParameters() const {
        return container->constructorParams; }
#line 8208 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 573 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
cstring IR::ParserBlock::toString() const { return container->toString(); }
#line 8211 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 574 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
IR::ID IR::ParserBlock::getName() const { return container->getName(); }
#line 8214 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 575 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
IR::IDeclaration const * IR::ParserBlock::getContainer() const { return container; }
#line 8217 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::ParserBlock::operator==(IR::ParserBlock const & a) const {
        return InstantiatedBlock::operator==(static_cast<const InstantiatedBlock &>(a))
        && container == a.container;
    }
bool IR::ParserBlock::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!InstantiatedBlock::equiv(a_)) return false;
        auto &a = static_cast<const ParserBlock &>(a_);
        return (container ? a.container ? container->equiv(*a.container) : false : a.container == nullptr);
    }
void IR::ParserBlock::visit_children(Visitor & v) {
    InstantiatedBlock::visit_children(v);
    v.visit(container, "container");
}
void IR::ParserBlock::visit_children(Visitor & v) const {
    InstantiatedBlock::visit_children(v);
    v.visit(container, "container");
}
void IR::ParserBlock::validate() const {
#line 8237 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(container); }
void IR::ParserBlock::toJSON(JSONGenerator & json) const {
    InstantiatedBlock::toJSON(json);
    json << "," << std::endl << json.indent << "\"container\" : " << this->container;
}
IR::ParserBlock::ParserBlock(JSONLoader & json) : InstantiatedBlock(json) {
    json.load("container", container);
}
IR::Node * IR::ParserBlock::fromJSON(JSONLoader & json) { return new ParserBlock(json); }
IR::ParserBlock::ParserBlock(Util::SourceInfo srcInfo, const IR::Node* node, const IR::Type* instanceType, const IR::P4Parser* container) :
    InstantiatedBlock(srcInfo, node, instanceType), container(container)
    { validate(); }
IR::ParserBlock::ParserBlock(const IR::Node* node, const IR::Type* instanceType, const IR::P4Parser* container) :
    InstantiatedBlock(node, instanceType), container(container)
    { validate(); }
#line 581 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::ParameterList *IR::ControlBlock::getConstructorParameters() const {
        return container->constructorParams; }
#line 8257 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 583 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
cstring IR::ControlBlock::toString() const { return container->toString(); }
#line 8260 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 584 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
IR::ID IR::ControlBlock::getName() const { return container->getName(); }
#line 8263 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 585 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
IR::IDeclaration const * IR::ControlBlock::getContainer() const { return container; }
#line 8266 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::ControlBlock::operator==(IR::ControlBlock const & a) const {
        return InstantiatedBlock::operator==(static_cast<const InstantiatedBlock &>(a))
        && container == a.container;
    }
bool IR::ControlBlock::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!InstantiatedBlock::equiv(a_)) return false;
        auto &a = static_cast<const ControlBlock &>(a_);
        return (container ? a.container ? container->equiv(*a.container) : false : a.container == nullptr);
    }
void IR::ControlBlock::visit_children(Visitor & v) {
    InstantiatedBlock::visit_children(v);
    v.visit(container, "container");
}
void IR::ControlBlock::visit_children(Visitor & v) const {
    InstantiatedBlock::visit_children(v);
    v.visit(container, "container");
}
void IR::ControlBlock::validate() const {
#line 8286 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(container); }
void IR::ControlBlock::toJSON(JSONGenerator & json) const {
    InstantiatedBlock::toJSON(json);
    json << "," << std::endl << json.indent << "\"container\" : " << this->container;
}
IR::ControlBlock::ControlBlock(JSONLoader & json) : InstantiatedBlock(json) {
    json.load("container", container);
}
IR::Node * IR::ControlBlock::fromJSON(JSONLoader & json) { return new ControlBlock(json); }
IR::ControlBlock::ControlBlock(Util::SourceInfo srcInfo, const IR::Node* node, const IR::Type* instanceType, const IR::P4Control* container) :
    InstantiatedBlock(srcInfo, node, instanceType), container(container)
    { validate(); }
IR::ControlBlock::ControlBlock(const IR::Node* node, const IR::Type* instanceType, const IR::P4Control* container) :
    InstantiatedBlock(node, instanceType), container(container)
    { validate(); }
#line 591 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::ParameterList *IR::PackageBlock::getConstructorParameters() const { return type->constructorParams; }
#line 8305 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 592 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
cstring IR::PackageBlock::toString() const { return type->toString(); }
#line 8308 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 593 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
IR::ID IR::PackageBlock::getName() const { return type->getName(); }
#line 8311 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::PackageBlock::operator==(IR::PackageBlock const & a) const {
        return InstantiatedBlock::operator==(static_cast<const InstantiatedBlock &>(a))
        && type == a.type;
    }
bool IR::PackageBlock::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!InstantiatedBlock::equiv(a_)) return false;
        auto &a = static_cast<const PackageBlock &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr);
    }
void IR::PackageBlock::visit_children(Visitor & v) {
    InstantiatedBlock::visit_children(v);
    v.visit(type, "type");
}
void IR::PackageBlock::visit_children(Visitor & v) const {
    InstantiatedBlock::visit_children(v);
    v.visit(type, "type");
}
void IR::PackageBlock::validate() const {
#line 8331 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(type); }
void IR::PackageBlock::toJSON(JSONGenerator & json) const {
    InstantiatedBlock::toJSON(json);
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
}
IR::PackageBlock::PackageBlock(JSONLoader & json) : InstantiatedBlock(json) {
    json.load("type", type);
}
IR::Node * IR::PackageBlock::fromJSON(JSONLoader & json) { return new PackageBlock(json); }
IR::PackageBlock::PackageBlock(Util::SourceInfo srcInfo, const IR::Node* node, const IR::Type* instanceType, const IR::Type_Package* type) :
    InstantiatedBlock(srcInfo, node, instanceType), type(type)
    { validate(); }
IR::PackageBlock::PackageBlock(const IR::Node* node, const IR::Type* instanceType, const IR::Type_Package* type) :
    InstantiatedBlock(node, instanceType), type(type)
    { validate(); }

#line 600 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::ParameterList *IR::ExternBlock::getConstructorParameters() const {
        return constructor->type->parameters; }
#line 8352 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 602 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
cstring IR::ExternBlock::toString() const { return type->toString(); }
#line 8355 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 603 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
IR::ID IR::ExternBlock::getName() const { return type->getName(); }
#line 8358 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::ExternBlock::operator==(IR::ExternBlock const & a) const {
        return InstantiatedBlock::operator==(static_cast<const InstantiatedBlock &>(a))
        && type == a.type
        && constructor == a.constructor;
    }
bool IR::ExternBlock::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!InstantiatedBlock::equiv(a_)) return false;
        auto &a = static_cast<const ExternBlock &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (constructor ? a.constructor ? constructor->equiv(*a.constructor) : false : a.constructor == nullptr);
    }
void IR::ExternBlock::visit_children(Visitor & v) {
    InstantiatedBlock::visit_children(v);
    v.visit(type, "type");
    v.visit(constructor, "constructor");
}
void IR::ExternBlock::visit_children(Visitor & v) const {
    InstantiatedBlock::visit_children(v);
    v.visit(type, "type");
    v.visit(constructor, "constructor");
}
void IR::ExternBlock::validate() const {
#line 8382 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(type);
        CHECK_NULL(constructor); }
void IR::ExternBlock::toJSON(JSONGenerator & json) const {
    InstantiatedBlock::toJSON(json);
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
    json << "," << std::endl << json.indent << "\"constructor\" : " << this->constructor;
}
IR::ExternBlock::ExternBlock(JSONLoader & json) : InstantiatedBlock(json) {
    json.load("type", type);
    json.load("constructor", constructor);
}
IR::Node * IR::ExternBlock::fromJSON(JSONLoader & json) { return new ExternBlock(json); }
IR::ExternBlock::ExternBlock(Util::SourceInfo srcInfo, const IR::Node* node, const IR::Type* instanceType, const IR::Type_Extern* type, const IR::Method* constructor) :
    InstantiatedBlock(srcInfo, node, instanceType), type(type), constructor(constructor)
    { validate(); }
IR::ExternBlock::ExternBlock(const IR::Node* node, const IR::Type* instanceType, const IR::Type_Extern* type, const IR::Method* constructor) :
    InstantiatedBlock(node, instanceType), type(type), constructor(constructor)
    { validate(); }
#line 609 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
const IR::P4Program *IR::ToplevelBlock::getProgram() const { return node->to<IR::P4Program>(); }
#line 8404 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 611 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
IR::ID IR::ToplevelBlock::getName() const { return "main"; }
#line 8407 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 613 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
void IR::ToplevelBlock::validate() const {
#line 8410 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

#line 613 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/ir.def"
{ BUG_CHECK(node->is<IR::P4Program>(), "%1%: expected a P4Program", node); } }
#line 8414 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::ToplevelBlock::operator==(IR::ToplevelBlock const & a) const {
        return Block::operator==(static_cast<const Block &>(a));
    }
bool IR::ToplevelBlock::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Block::equiv(a_)) return false;
        return true;
    }
void IR::ToplevelBlock::toJSON(JSONGenerator & json) const {
    Block::toJSON(json);
}
IR::ToplevelBlock::ToplevelBlock(JSONLoader & json) : Block(json) {
}
IR::Node * IR::ToplevelBlock::fromJSON(JSONLoader & json) { return new ToplevelBlock(json); }
IR::ToplevelBlock::ToplevelBlock(Util::SourceInfo srcInfo, const IR::Node* node) :
    Block(srcInfo, node)
    { validate(); }
IR::ToplevelBlock::ToplevelBlock(const IR::Node* node) :
    Block(node)
    { validate(); }
/** @} */
/* end group irdefs */
/* -*-C++-*- */
/*
  This file contains IR classes needed just for the P4 v1.0/v1.1 front-end.
*/
/** \addtogroup irdefs
  * @{
  */
#line 46 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
cstring IR::Type_Block::toString() const { return "block"; }
#line 8446 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 48 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::Type_Block::dbprint(std::ostream & out) const { out << "block"; }
#line 8449 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Block::operator==(IR::Type_Block const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Block::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Block::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Block::Type_Block(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Block::fromJSON(JSONLoader & json) { return new Type_Block(json); }
IR::Type_Block::Type_Block(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_Block::Type_Block() 
    { validate(); }
#line 51 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
cstring IR::Type_Counter::toString() const { return "counter"; }
#line 8471 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 53 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::Type_Counter::dbprint(std::ostream & out) const { out << "counter"; }
#line 8474 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Counter::operator==(IR::Type_Counter const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Counter::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Counter::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Counter::Type_Counter(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Counter::fromJSON(JSONLoader & json) { return new Type_Counter(json); }
IR::Type_Counter::Type_Counter(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_Counter::Type_Counter() 
    { validate(); }
#line 56 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
cstring IR::Type_Expression::toString() const { return "expression"; }
#line 8496 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 58 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::Type_Expression::dbprint(std::ostream & out) const { out << "expression"; }
#line 8499 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Expression::operator==(IR::Type_Expression const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Expression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Expression::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Expression::Type_Expression(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Expression::fromJSON(JSONLoader & json) { return new Type_Expression(json); }
IR::Type_Expression::Type_Expression(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_Expression::Type_Expression() 
    { validate(); }
#line 61 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
cstring IR::Type_FieldListCalculation::toString() const { return "field_list_calculation"; }
#line 8521 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 63 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::Type_FieldListCalculation::dbprint(std::ostream & out) const { out << "field_list_calculation"; }
#line 8524 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_FieldListCalculation::operator==(IR::Type_FieldListCalculation const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_FieldListCalculation::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_FieldListCalculation::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_FieldListCalculation::Type_FieldListCalculation(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_FieldListCalculation::fromJSON(JSONLoader & json) { return new Type_FieldListCalculation(json); }
IR::Type_FieldListCalculation::Type_FieldListCalculation(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_FieldListCalculation::Type_FieldListCalculation() 
    { validate(); }
#line 66 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
cstring IR::Type_Meter::toString() const { return "meter"; }
#line 8546 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 68 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::Type_Meter::dbprint(std::ostream & out) const { out << "meter"; }
#line 8549 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Meter::operator==(IR::Type_Meter const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Meter::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Meter::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Meter::Type_Meter(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Meter::fromJSON(JSONLoader & json) { return new Type_Meter(json); }
IR::Type_Meter::Type_Meter(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_Meter::Type_Meter() 
    { validate(); }
#line 71 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
cstring IR::Type_Register::toString() const { return "register"; }
#line 8571 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 73 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::Type_Register::dbprint(std::ostream & out) const { out << "register"; }
#line 8574 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_Register::operator==(IR::Type_Register const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Register::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Register::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Register::Type_Register(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Register::fromJSON(JSONLoader & json) { return new Type_Register(json); }
IR::Type_Register::Type_Register(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_Register::Type_Register() 
    { validate(); }
#line 76 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
cstring IR::Type_AnyTable::toString() const { return "table"; }
#line 8596 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 78 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::Type_AnyTable::dbprint(std::ostream & out) const { out << "table"; }
#line 8599 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Type_AnyTable::operator==(IR::Type_AnyTable const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_AnyTable::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_AnyTable::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_AnyTable::Type_AnyTable(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_AnyTable::fromJSON(JSONLoader & json) { return new Type_AnyTable(json); }
IR::Type_AnyTable::Type_AnyTable(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_AnyTable::Type_AnyTable() 
    { validate(); }
#line 87 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
const IR::Annotations *IR::HeaderOrMetadata::getAnnotations() const { return annotations; }
#line 8621 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 88 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
IR::HeaderOrMetadata::HeaderOrMetadata(IR::ID n, const IR::Type_StructLike* t) : type_name(t->name), name(n), annotations(Annotations::empty), type(t) {}
#line 8624 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 90 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::HeaderOrMetadata::dbprint(std::ostream & out) const { out << type_name << ' ' << name; }
#line 8627 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::HeaderOrMetadata::operator==(IR::HeaderOrMetadata const & a) const {
        return typeid(*this) == typeid(a)
        && type_name == a.type_name
        && name == a.name
        && annotations == a.annotations
        && type == a.type;
    }
bool IR::HeaderOrMetadata::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const HeaderOrMetadata &>(a_);
        return type_name == a.type_name
        && name == a.name
        && (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr);
    }
void IR::HeaderOrMetadata::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
}
void IR::HeaderOrMetadata::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
}
void IR::HeaderOrMetadata::validate() const {
#line 8655 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations); }
void IR::HeaderOrMetadata::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " type_name=" << type_name;
        out << " name=" << name;
}
void IR::HeaderOrMetadata::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"type_name\" : " << this->type_name;
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    if (type != nullptr)     json << "," << std::endl << json.indent << "\"type\" : " << this->type;
}
IR::HeaderOrMetadata::HeaderOrMetadata(JSONLoader & json) : Node(json) {
    json.load("type_name", type_name);
    json.load("name", name);
    json.load("annotations", annotations);
    json.load("type", type);
}
IR::HeaderOrMetadata::HeaderOrMetadata(Util::SourceInfo srcInfo, IR::ID type_name, IR::ID name, const IR::Annotations* annotations) :
    Node(srcInfo), type_name(type_name), name(name), annotations(annotations)
    { validate(); }
IR::HeaderOrMetadata::HeaderOrMetadata(IR::ID type_name, IR::ID name, const IR::Annotations* annotations) :
    type_name(type_name), name(name), annotations(annotations)
    { validate(); }
#line 94 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
IR::Header::Header(IR::ID n, const IR::Type_Header* t) : HeaderOrMetadata(n, t) {}
#line 8684 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Header::operator==(IR::Header const & a) const {
        return HeaderOrMetadata::operator==(static_cast<const HeaderOrMetadata &>(a));
    }
bool IR::Header::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!HeaderOrMetadata::equiv(a_)) return false;
        return true;
    }
void IR::Header::toJSON(JSONGenerator & json) const {
    HeaderOrMetadata::toJSON(json);
}
IR::Header::Header(JSONLoader & json) : HeaderOrMetadata(json) {
}
IR::Node * IR::Header::fromJSON(JSONLoader & json) { return new Header(json); }
IR::Header::Header(Util::SourceInfo srcInfo, IR::ID type_name, IR::ID name, const IR::Annotations* annotations) :
    HeaderOrMetadata(srcInfo, type_name, name, annotations)
    { validate(); }
IR::Header::Header(IR::ID type_name, IR::ID name, const IR::Annotations* annotations) :
    HeaderOrMetadata(type_name, name, annotations)
    { validate(); }
#line 100 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
IR::HeaderStack::HeaderStack(IR::ID n, const IR::Type_Header* t, int sz) : HeaderOrMetadata(n, t), size(sz) {}
#line 8707 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::HeaderStack::operator==(IR::HeaderStack const & a) const {
        return HeaderOrMetadata::operator==(static_cast<const HeaderOrMetadata &>(a))
        && size == a.size;
    }
bool IR::HeaderStack::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!HeaderOrMetadata::equiv(a_)) return false;
        auto &a = static_cast<const HeaderStack &>(a_);
        return size == a.size;
    }
void IR::HeaderStack::dump_fields(std::ostream & out) const {
    HeaderOrMetadata::dump_fields(out);
        out << " size=" << size;
}
void IR::HeaderStack::toJSON(JSONGenerator & json) const {
    HeaderOrMetadata::toJSON(json);
    json << "," << std::endl << json.indent << "\"size\" : " << this->size;
}
IR::HeaderStack::HeaderStack(JSONLoader & json) : HeaderOrMetadata(json) {
    json.load("size", size);
}
IR::Node * IR::HeaderStack::fromJSON(JSONLoader & json) { return new HeaderStack(json); }
IR::HeaderStack::HeaderStack(Util::SourceInfo srcInfo, IR::ID type_name, IR::ID name, const IR::Annotations* annotations, int size) :
    HeaderOrMetadata(srcInfo, type_name, name, annotations), size(size)
    { validate(); }
IR::HeaderStack::HeaderStack(IR::ID type_name, IR::ID name, const IR::Annotations* annotations, int size) :
    HeaderOrMetadata(type_name, name, annotations), size(size)
    { validate(); }
#line 105 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
IR::Metadata::Metadata(IR::ID n, const IR::Type_StructLike* t) : HeaderOrMetadata(n, t) {}
#line 8738 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Metadata::operator==(IR::Metadata const & a) const {
        return HeaderOrMetadata::operator==(static_cast<const HeaderOrMetadata &>(a));
    }
bool IR::Metadata::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!HeaderOrMetadata::equiv(a_)) return false;
        return true;
    }
void IR::Metadata::toJSON(JSONGenerator & json) const {
    HeaderOrMetadata::toJSON(json);
}
IR::Metadata::Metadata(JSONLoader & json) : HeaderOrMetadata(json) {
}
IR::Node * IR::Metadata::fromJSON(JSONLoader & json) { return new Metadata(json); }
IR::Metadata::Metadata(Util::SourceInfo srcInfo, IR::ID type_name, IR::ID name, const IR::Annotations* annotations) :
    HeaderOrMetadata(srcInfo, type_name, name, annotations)
    { validate(); }
IR::Metadata::Metadata(IR::ID type_name, IR::ID name, const IR::Annotations* annotations) :
    HeaderOrMetadata(type_name, name, annotations)
    { validate(); }
bool IR::HeaderRef::operator==(IR::HeaderRef const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a));
    }
bool IR::HeaderRef::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        return true;
    }
void IR::HeaderRef::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
}
IR::HeaderRef::HeaderRef(JSONLoader & json) : Expression(json) {
}
IR::HeaderRef::HeaderRef(Util::SourceInfo srcInfo, const IR::Type* type) :
    Expression(srcInfo, type)
    { validate(); }
IR::HeaderRef::HeaderRef(const IR::Type* type) :
    Expression(type)
    { validate(); }
IR::HeaderRef::HeaderRef(Util::SourceInfo srcInfo) :
    Expression(srcInfo)
    { validate(); }
IR::HeaderRef::HeaderRef() 
    { validate(); }
#line 116 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
const IR::HeaderOrMetadata *IR::ConcreteHeaderRef::baseRef() const { return ref; }
#line 8785 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 117 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
cstring IR::ConcreteHeaderRef::toString() const { return ref->name; }
#line 8788 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 118 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::ConcreteHeaderRef::dbprint(std::ostream & out) const { out << ref->name; }
#line 8791 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::ConcreteHeaderRef::operator==(IR::ConcreteHeaderRef const & a) const {
        return HeaderRef::operator==(static_cast<const HeaderRef &>(a))
        && ref == a.ref;
    }
bool IR::ConcreteHeaderRef::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!HeaderRef::equiv(a_)) return false;
        auto &a = static_cast<const ConcreteHeaderRef &>(a_);
        return (ref ? a.ref ? ref->equiv(*a.ref) : false : a.ref == nullptr);
    }
void IR::ConcreteHeaderRef::visit_children(Visitor & v) {
    HeaderRef::visit_children(v);
    v.visit(ref, "ref");
}
void IR::ConcreteHeaderRef::visit_children(Visitor & v) const {
    HeaderRef::visit_children(v);
    v.visit(ref, "ref");
}
void IR::ConcreteHeaderRef::validate() const {
#line 8811 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(ref); }
void IR::ConcreteHeaderRef::toJSON(JSONGenerator & json) const {
    HeaderRef::toJSON(json);
    json << "," << std::endl << json.indent << "\"ref\" : " << this->ref;
}
IR::ConcreteHeaderRef::ConcreteHeaderRef(JSONLoader & json) : HeaderRef(json) {
    json.load("ref", ref);
}
IR::Node * IR::ConcreteHeaderRef::fromJSON(JSONLoader & json) { return new ConcreteHeaderRef(json); }
IR::ConcreteHeaderRef::ConcreteHeaderRef(Util::SourceInfo srcInfo, const IR::Type* type, const IR::HeaderOrMetadata* ref) :
    HeaderRef(srcInfo, type), ref(ref)
    {
#line 115 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
{ if (type->is<Type::Unknown>() && ref) type = ref->type; }
#line 8827 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::ConcreteHeaderRef::ConcreteHeaderRef(const IR::Type* type, const IR::HeaderOrMetadata* ref) :
    HeaderRef(type), ref(ref)
    {
#line 115 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
{ if (type->is<Type::Unknown>() && ref) type = ref->type; }
#line 8834 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::ConcreteHeaderRef::ConcreteHeaderRef(Util::SourceInfo srcInfo, const IR::HeaderOrMetadata* ref) :
    HeaderRef(srcInfo), ref(ref)
    {
#line 115 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
{ if (type->is<Type::Unknown>() && ref) type = ref->type; }
#line 8841 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::ConcreteHeaderRef::ConcreteHeaderRef(const IR::HeaderOrMetadata* ref) :
    ref(ref)
    {
#line 115 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
{ if (type->is<Type::Unknown>() && ref) type = ref->type; }
#line 8848 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
#line 128 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
const IR::Expression *IR::HeaderStackItemRef::base() const { return base_; }
#line 8852 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 129 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
const IR::HeaderOrMetadata *IR::HeaderStackItemRef::baseRef() const { return base_->to<HeaderRef>()->baseRef(); }
#line 8855 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 130 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
const IR::Expression *IR::HeaderStackItemRef::index() const { return index_; }
#line 8858 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 131 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::HeaderStackItemRef::set_base(const IR::Expression* b) { base_ = b; }
#line 8861 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 132 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
cstring IR::HeaderStackItemRef::toString() const { return base_->toString() + "[" + index_->toString() + "]"; }
#line 8864 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::HeaderStackItemRef::operator==(IR::HeaderStackItemRef const & a) const {
        return HeaderRef::operator==(static_cast<const HeaderRef &>(a))
        && base_ == a.base_
        && index_ == a.index_;
    }
bool IR::HeaderStackItemRef::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!HeaderRef::equiv(a_)) return false;
        auto &a = static_cast<const HeaderStackItemRef &>(a_);
        return (base_ ? a.base_ ? base_->equiv(*a.base_) : false : a.base_ == nullptr)
        && (index_ ? a.index_ ? index_->equiv(*a.index_) : false : a.index_ == nullptr);
    }
void IR::HeaderStackItemRef::visit_children(Visitor & v) {
    HeaderRef::visit_children(v);
    v.visit(base_, "base_");
    v.visit(index_, "index_");
}
void IR::HeaderStackItemRef::visit_children(Visitor & v) const {
    HeaderRef::visit_children(v);
    v.visit(base_, "base_");
    v.visit(index_, "index_");
}
void IR::HeaderStackItemRef::validate() const {
#line 8888 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(base_);
        CHECK_NULL(index_); }
void IR::HeaderStackItemRef::toJSON(JSONGenerator & json) const {
    HeaderRef::toJSON(json);
    json << "," << std::endl << json.indent << "\"base_\" : " << this->base_;
    json << "," << std::endl << json.indent << "\"index_\" : " << this->index_;
}
IR::HeaderStackItemRef::HeaderStackItemRef(JSONLoader & json) : HeaderRef(json) {
    json.load("base_", base_);
    json.load("index_", index_);
}
IR::Node * IR::HeaderStackItemRef::fromJSON(JSONLoader & json) { return new HeaderStackItemRef(json); }
IR::HeaderStackItemRef::HeaderStackItemRef(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* base_, const IR::Expression* index_) :
    HeaderRef(srcInfo, type), base_(base_), index_(index_)
    {
#line 124 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
{
        if (type->is<Type::Unknown>() && base_)
            if (auto *hr = base_->to<HeaderRef>())
                type = hr->baseRef()->type; }
#line 8910 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::HeaderStackItemRef::HeaderStackItemRef(const IR::Type* type, const IR::Expression* base_, const IR::Expression* index_) :
    HeaderRef(type), base_(base_), index_(index_)
    {
#line 124 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
{
        if (type->is<Type::Unknown>() && base_)
            if (auto *hr = base_->to<HeaderRef>())
                type = hr->baseRef()->type; }
#line 8920 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::HeaderStackItemRef::HeaderStackItemRef(Util::SourceInfo srcInfo, const IR::Expression* base_, const IR::Expression* index_) :
    HeaderRef(srcInfo), base_(base_), index_(index_)
    {
#line 124 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
{
        if (type->is<Type::Unknown>() && base_)
            if (auto *hr = base_->to<HeaderRef>())
                type = hr->baseRef()->type; }
#line 8930 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::HeaderStackItemRef::HeaderStackItemRef(const IR::Expression* base_, const IR::Expression* index_) :
    base_(base_), index_(index_)
    {
#line 124 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
{
        if (type->is<Type::Unknown>() && base_)
            if (auto *hr = base_->to<HeaderRef>())
                type = hr->baseRef()->type; }
#line 8940 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
#line 139 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::If::visit_children(Visitor & v) {
        v.visit(pred, "pred");
        auto &clone(v.flow_clone());
        v.visit(ifTrue, "ifTrue");
        clone.visit(ifFalse, "ifFalse");
        v.flow_merge(clone);
        Expression::visit_children(v);
    }
#line 139 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::If::visit_children(Visitor & v) const {
        v.visit(pred, "pred");
        auto &clone(v.flow_clone());
        v.visit(ifTrue, "ifTrue");
        clone.visit(ifFalse, "ifFalse");
        v.flow_merge(clone);
        Expression::visit_children(v);
    }
#line 8960 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::If::operator==(IR::If const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && pred == a.pred
        && ifTrue == a.ifTrue
        && ifFalse == a.ifFalse;
    }
bool IR::If::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const If &>(a_);
        return (pred ? a.pred ? pred->equiv(*a.pred) : false : a.pred == nullptr)
        && (ifTrue ? a.ifTrue ? ifTrue->equiv(*a.ifTrue) : false : a.ifTrue == nullptr)
        && (ifFalse ? a.ifFalse ? ifFalse->equiv(*a.ifFalse) : false : a.ifFalse == nullptr);
    }
void IR::If::validate() const {
#line 8976 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(pred); }
void IR::If::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"pred\" : " << this->pred;
    if (ifTrue != nullptr)     json << "," << std::endl << json.indent << "\"ifTrue\" : " << this->ifTrue;
    if (ifFalse != nullptr)     json << "," << std::endl << json.indent << "\"ifFalse\" : " << this->ifFalse;
}
IR::If::If(JSONLoader & json) : Expression(json) {
    json.load("pred", pred);
    json.load("ifTrue", ifTrue);
    json.load("ifFalse", ifFalse);
}
IR::Node * IR::If::fromJSON(JSONLoader & json) { return new If(json); }
IR::If::If(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* pred, const IR::Vector<IR::Expression>* ifTrue, const IR::Vector<IR::Expression>* ifFalse) :
    Expression(srcInfo, type), pred(pred), ifTrue(ifTrue), ifFalse(ifFalse)
    { validate(); }
IR::If::If(const IR::Type* type, const IR::Expression* pred, const IR::Vector<IR::Expression>* ifTrue, const IR::Vector<IR::Expression>* ifFalse) :
    Expression(type), pred(pred), ifTrue(ifTrue), ifFalse(ifFalse)
    { validate(); }
IR::If::If(Util::SourceInfo srcInfo, const IR::Expression* pred, const IR::Vector<IR::Expression>* ifTrue, const IR::Vector<IR::Expression>* ifFalse) :
    Expression(srcInfo), pred(pred), ifTrue(ifTrue), ifFalse(ifFalse)
    { validate(); }
IR::If::If(const IR::Expression* pred, const IR::Vector<IR::Expression>* ifTrue, const IR::Vector<IR::Expression>* ifFalse) :
    pred(pred), ifTrue(ifTrue), ifFalse(ifFalse)
    { validate(); }
#line 154 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
IR::NamedCond::NamedCond(IR::If const & i) : If(i), name(unique_name()) {}
#line 9005 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 155 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
bool IR::NamedCond::operator==(IR::NamedCond const & a) const { return If::operator==(static_cast<const If &>(a)); }
#line 9008 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::NamedCond::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!If::equiv(a_)) return false;
        auto &a = static_cast<const NamedCond &>(a_);
        return name == a.name;
    }
void IR::NamedCond::dump_fields(std::ostream & out) const {
    If::dump_fields(out);
        out << " name=" << name;
}
void IR::NamedCond::toJSON(JSONGenerator & json) const {
    If::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
}
IR::NamedCond::NamedCond(JSONLoader & json) : If(json) {
    json.load("name", name);
}
IR::Node * IR::NamedCond::fromJSON(JSONLoader & json) { return new NamedCond(json); }
#line 163 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::Apply::visit_children(Visitor & v) {
        auto &clone(v.flow_clone());
        // HACK -- temp sort actions into program (source) order, so that condition names are
        // generated in the same order as p4-hlir
        typedef std::remove_reference<decltype(actions.at("any"))>::type action_t;
        safe_vector<action_t *> sort_actions;
        for (auto &p : Values(actions)) sort_actions.push_back(&p);
        std::sort(sort_actions.begin(), sort_actions.end(),
            [](action_t *a, action_t *b) {
                return (*a)->srcInfo.getStart() < (*b)->srcInfo.getStart(); });
        for (auto p : sort_actions) {
            auto &clone2(clone.flow_clone());
            clone2.visit(*p);
            v.flow_merge(clone2); }
        Expression::visit_children(v);
    }
#line 163 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::Apply::visit_children(Visitor & v) const {
        auto &clone(v.flow_clone());
        // HACK -- temp sort actions into program (source) order, so that condition names are
        // generated in the same order as p4-hlir
        typedef std::remove_reference<decltype(actions.at("any"))>::type action_t;
        safe_vector<action_t *> sort_actions;
        for (auto &p : Values(actions)) sort_actions.push_back(&p);
        std::sort(sort_actions.begin(), sort_actions.end(),
            [](action_t *a, action_t *b) {
                return (*a)->srcInfo.getStart() < (*b)->srcInfo.getStart(); });
        for (auto p : sort_actions) {
            auto &clone2(clone.flow_clone());
            clone2.visit(*p);
            v.flow_merge(clone2); }
        Expression::visit_children(v);
    }
#line 9061 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Apply::operator==(IR::Apply const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && name == a.name
        && actions == a.actions;
    }
bool IR::Apply::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const Apply &>(a_);
        return name == a.name
        && actions.equiv(a.actions);
    }
void IR::Apply::validate() const {
#line 9075 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        actions.validate(); }
void IR::Apply::dump_fields(std::ostream & out) const {
    Expression::dump_fields(out);
        out << " name=" << name;
}
void IR::Apply::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"actions\" : " << this->actions;
}
IR::Apply::Apply(JSONLoader & json) : Expression(json) {
    json.load("name", name);
    json.load("actions", actions);
}
IR::Node * IR::Apply::fromJSON(JSONLoader & json) { return new Apply(json); }
IR::Apply::Apply(Util::SourceInfo srcInfo, const IR::Type* type, IR::ID name) :
    Expression(srcInfo, type), name(name)
    { validate(); }
IR::Apply::Apply(const IR::Type* type, IR::ID name) :
    Expression(type), name(name)
    { validate(); }
IR::Apply::Apply(Util::SourceInfo srcInfo, IR::ID name) :
    Expression(srcInfo), name(name)
    { validate(); }
IR::Apply::Apply(IR::ID name) :
    name(name)
    { validate(); }
IR::Apply::Apply(Util::SourceInfo srcInfo, const IR::Type* type) :
    Expression(srcInfo, type)
    { validate(); }
IR::Apply::Apply(const IR::Type* type) :
    Expression(type)
    { validate(); }
IR::Apply::Apply(Util::SourceInfo srcInfo) :
    Expression(srcInfo)
    { validate(); }
IR::Apply::Apply() 
    { validate(); }
#line 185 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
IR::Primitive::Primitive(cstring n, const IR::Vector<IR::Expression>* l) : name(n) {
        if (l) for (auto e : *l) operands.push_back(e); }
#line 9118 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 187 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
IR::Primitive::Primitive(Util::SourceInfo si, cstring n, const IR::Vector<IR::Expression>* l) : Operation(si), name(n) {
        if (l) for (auto e : *l) operands.push_back(e); }
#line 9122 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 189 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
IR::Primitive::Primitive(cstring n, const IR::Expression* a1) : name(n) {
        operands.push_back(a1); }
#line 9126 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 191 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
IR::Primitive::Primitive(Util::SourceInfo si, cstring n, const IR::Expression* a1) : Operation(si), name(n) {
        operands.push_back(a1); }
#line 9130 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 193 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
IR::Primitive::Primitive(cstring n, const IR::Expression* a1, const IR::Expression* a2) : name(n) {
        operands.push_back(a1); operands.push_back(a2); }
#line 9134 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 195 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
IR::Primitive::Primitive(Util::SourceInfo si, cstring n, const IR::Expression* a1, const IR::Expression* a2) : Operation(si), name(n) {
        operands.push_back(a1); operands.push_back(a2); }
#line 9138 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 198 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
IR::Primitive::Primitive(cstring n, const IR::Expression* a1, const IR::Vector<IR::Expression>* a2) : name(n) {
        operands.push_back(a1);
        if (a2) for (auto e : *a2) operands.push_back(e); }
#line 9143 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 201 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
IR::Primitive::Primitive(Util::SourceInfo si, cstring n, const IR::Expression* a1, const IR::Vector<IR::Expression>* a2) : Operation(si), name(n) {
        operands.push_back(a1);
        if (a2) for (auto e : *a2) operands.push_back(e); }
#line 9148 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 205 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
IR::Primitive::Primitive(cstring n, const IR::Expression* a1, const IR::Expression* a2, const IR::Expression* a3) : name(n) {
        operands.push_back(a1); operands.push_back(a2); operands.push_back(a3); }
#line 9152 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 207 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
IR::Primitive::Primitive(Util::SourceInfo si, cstring n, const IR::Expression* a1, const IR::Expression* a2, const IR::Expression* a3) : Operation(si), name(n) {
        operands.push_back(a1); operands.push_back(a2); operands.push_back(a3); }
#line 9156 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
IRNODE_DEFINE_APPLY_OVERLOAD(Primitive, , )
bool IR::Primitive::operator==(IR::Primitive const & a) const {
        return Operation::operator==(static_cast<const Operation &>(a))
        && name == a.name
        && operands == a.operands;
    }
bool IR::Primitive::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation::equiv(a_)) return false;
        auto &a = static_cast<const Primitive &>(a_);
        return name == a.name
        && operands.equiv(a.operands);
    }
void IR::Primitive::visit_children(Visitor & v) {
    Operation::visit_children(v);
    operands.visit_children(v);
}
void IR::Primitive::visit_children(Visitor & v) const {
    Operation::visit_children(v);
    operands.visit_children(v);
}
void IR::Primitive::validate() const {
#line 9179 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        operands.validate(); }
void IR::Primitive::dump_fields(std::ostream & out) const {
    Operation::dump_fields(out);
        out << " name=" << name;
}
void IR::Primitive::toJSON(JSONGenerator & json) const {
    Operation::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"operands\" : " << this->operands;
}
IR::Primitive::Primitive(JSONLoader & json) : Operation(json) {
    json.load("name", name);
    json.load("operands", operands);
}
IR::Node * IR::Primitive::fromJSON(JSONLoader & json) { return new Primitive(json); }
IR::Primitive::Primitive(Util::SourceInfo srcInfo, const IR::Type* type, cstring name) :
    Operation(srcInfo, type), name(name)
    { validate(); }
IR::Primitive::Primitive(const IR::Type* type, cstring name) :
    Operation(type), name(name)
    { validate(); }
IR::Primitive::Primitive(Util::SourceInfo srcInfo, cstring name) :
    Operation(srcInfo), name(name)
    { validate(); }
IR::Primitive::Primitive(cstring name) :
    name(name)
    { validate(); }
#line 224 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
const IR::Annotations *IR::FieldList::getAnnotations() const { return annotations; }
#line 9210 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::FieldList::operator==(IR::FieldList const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && payload == a.payload
        && annotations == a.annotations
        && fields == a.fields;
    }
bool IR::FieldList::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const FieldList &>(a_);
        return name == a.name
        && payload == a.payload
        && (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && fields.equiv(a.fields);
    }
void IR::FieldList::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
    fields.visit_children(v);
}
void IR::FieldList::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
    fields.visit_children(v);
}
void IR::FieldList::validate() const {
#line 9238 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        fields.validate(); }
void IR::FieldList::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
        out << " payload=" << payload;
}
void IR::FieldList::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"payload\" : " << this->payload;
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"fields\" : " << this->fields;
}
IR::FieldList::FieldList(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("payload", payload);
    json.load("annotations", annotations);
    json.load("fields", fields);
}
IR::Node * IR::FieldList::fromJSON(JSONLoader & json) { return new FieldList(json); }
IR::FieldList::FieldList(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Node(srcInfo), name(name), annotations(annotations)
    { validate(); }
IR::FieldList::FieldList(IR::ID name, const IR::Annotations* annotations) :
    name(name), annotations(annotations)
    { validate(); }
IR::FieldList::FieldList(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    Node(srcInfo), annotations(annotations)
    { validate(); }
IR::FieldList::FieldList(const IR::Annotations* annotations) :
    annotations(annotations)
    { validate(); }
IR::FieldList::FieldList(Util::SourceInfo srcInfo, IR::ID name) :
    Node(srcInfo), name(name)
    { validate(); }
IR::FieldList::FieldList(IR::ID name) :
    name(name)
    { validate(); }
IR::FieldList::FieldList(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::FieldList::FieldList() 
    { validate(); }
#line 234 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
const IR::Annotations *IR::FieldListCalculation::getAnnotations() const { return annotations; }
#line 9286 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::FieldListCalculation::operator==(IR::FieldListCalculation const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && input == a.input
        && input_fields == a.input_fields
        && algorithm == a.algorithm
        && output_width == a.output_width
        && annotations == a.annotations;
    }
bool IR::FieldListCalculation::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const FieldListCalculation &>(a_);
        return name == a.name
        && (input ? a.input ? input->equiv(*a.input) : false : a.input == nullptr)
        && (input_fields ? a.input_fields ? input_fields->equiv(*a.input_fields) : false : a.input_fields == nullptr)
        && (algorithm ? a.algorithm ? algorithm->equiv(*a.algorithm) : false : a.algorithm == nullptr)
        && output_width == a.output_width
        && (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr);
    }
void IR::FieldListCalculation::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(input, "input");
    v.visit(input_fields, "input_fields");
    v.visit(algorithm, "algorithm");
    v.visit(annotations, "annotations");
}
void IR::FieldListCalculation::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(input, "input");
    v.visit(input_fields, "input_fields");
    v.visit(algorithm, "algorithm");
    v.visit(annotations, "annotations");
}
void IR::FieldListCalculation::validate() const {
#line 9322 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations); }
void IR::FieldListCalculation::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
        out << " output_width=" << output_width;
}
void IR::FieldListCalculation::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    if (input != nullptr)     json << "," << std::endl << json.indent << "\"input\" : " << this->input;
    if (input_fields != nullptr)     json << "," << std::endl << json.indent << "\"input_fields\" : " << this->input_fields;
    if (algorithm != nullptr)     json << "," << std::endl << json.indent << "\"algorithm\" : " << this->algorithm;
    json << "," << std::endl << json.indent << "\"output_width\" : " << this->output_width;
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
}
IR::FieldListCalculation::FieldListCalculation(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("input", input);
    json.load("input_fields", input_fields);
    json.load("algorithm", algorithm);
    json.load("output_width", output_width);
    json.load("annotations", annotations);
}
IR::Node * IR::FieldListCalculation::fromJSON(JSONLoader & json) { return new FieldListCalculation(json); }
IR::FieldListCalculation::FieldListCalculation(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Node(srcInfo), name(name), annotations(annotations)
    { validate(); }
IR::FieldListCalculation::FieldListCalculation(IR::ID name, const IR::Annotations* annotations) :
    name(name), annotations(annotations)
    { validate(); }
IR::FieldListCalculation::FieldListCalculation(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    Node(srcInfo), annotations(annotations)
    { validate(); }
IR::FieldListCalculation::FieldListCalculation(const IR::Annotations* annotations) :
    annotations(annotations)
    { validate(); }
IR::FieldListCalculation::FieldListCalculation(Util::SourceInfo srcInfo, IR::ID name) :
    Node(srcInfo), name(name)
    { validate(); }
IR::FieldListCalculation::FieldListCalculation(IR::ID name) :
    name(name)
    { validate(); }
IR::FieldListCalculation::FieldListCalculation(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::FieldListCalculation::FieldListCalculation() 
    { validate(); }
#line 244 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
IR::CalculatedField::update_or_verify::update_or_verify() {}
#line 9373 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

bool IR::CalculatedField::update_or_verify::operator==(IR::CalculatedField::update_or_verify const & a) const {
        return update == a.update
        && name == a.name
        && cond == a.cond;
    }
void IR::CalculatedField::update_or_verify::toJSON(JSONGenerator & json) const {
    json << "," << std::endl << json.indent << "\"update\" : " << this->update;
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"cond\" : " << this->cond;
}
IR::CalculatedField::update_or_verify::update_or_verify(JSONLoader & json)  {
    json.load("update", update);
    json.load("name", name);
    json.load("cond", cond);
}
IR::CalculatedField::update_or_verify * IR::CalculatedField::update_or_verify::fromJSON(JSONLoader & json) { return new update_or_verify(json); }
IR::CalculatedField::update_or_verify::update_or_verify(Util::SourceInfo srcInfo, bool update, IR::ID name, const IR::Expression* cond) :
    srcInfo(srcInfo), update(update), name(name), cond(cond)
    {}
#line 248 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
const IR::Annotations *IR::CalculatedField::getAnnotations() const { return annotations; }
#line 9396 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 249 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::CalculatedField::visit_children(Visitor & v) {
        v.visit(field, "field");
        for (auto &s : specs) v.visit(s.cond, s.name.name);
        v.visit(annotations, "annotations"); }
#line 249 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::CalculatedField::visit_children(Visitor & v) const {
        v.visit(field, "field");
        for (auto &s : specs) v.visit(s.cond, s.name.name);
        v.visit(annotations, "annotations"); }
#line 9407 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::CalculatedField::operator==(IR::CalculatedField const & a) const {
        return typeid(*this) == typeid(a)
        && field == a.field
        && specs == a.specs
        && annotations == a.annotations;
    }
bool IR::CalculatedField::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const CalculatedField &>(a_);
        return (field ? a.field ? field->equiv(*a.field) : false : a.field == nullptr)
        && specs == a.specs
        && (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr);
    }
void IR::CalculatedField::validate() const {
#line 9423 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations); }
void IR::CalculatedField::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    if (field != nullptr)     json << "," << std::endl << json.indent << "\"field\" : " << this->field;
    json << "," << std::endl << json.indent << "\"specs\" : " << this->specs;
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
}
IR::CalculatedField::CalculatedField(JSONLoader & json) : Node(json) {
    json.load("field", field);
    json.load("specs", specs);
    json.load("annotations", annotations);
}
IR::Node * IR::CalculatedField::fromJSON(JSONLoader & json) { return new CalculatedField(json); }
IR::CalculatedField::CalculatedField(Util::SourceInfo srcInfo, const IR::Expression* field, const IR::Annotations* annotations) :
    Node(srcInfo), field(field), annotations(annotations)
    { validate(); }
IR::CalculatedField::CalculatedField(const IR::Expression* field, const IR::Annotations* annotations) :
    field(field), annotations(annotations)
    { validate(); }
IR::CalculatedField::CalculatedField(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    Node(srcInfo), annotations(annotations)
    { validate(); }
IR::CalculatedField::CalculatedField(const IR::Annotations* annotations) :
    annotations(annotations)
    { validate(); }
#line 258 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
const IR::Annotations *IR::ParserValueSet::getAnnotations() const { return annotations; }
#line 9452 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 259 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::ParserValueSet::dbprint(std::ostream & out) const { out << node_type_name() << " " << name; }
#line 9455 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 260 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
cstring IR::ParserValueSet::toString() const { return node_type_name() + " " + name; }
#line 9458 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::ParserValueSet::operator==(IR::ParserValueSet const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && annotations == a.annotations;
    }
bool IR::ParserValueSet::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const ParserValueSet &>(a_);
        return name == a.name
        && (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr);
    }
void IR::ParserValueSet::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
}
void IR::ParserValueSet::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
}
void IR::ParserValueSet::validate() const {
#line 9480 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations); }
void IR::ParserValueSet::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
}
void IR::ParserValueSet::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
}
IR::ParserValueSet::ParserValueSet(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("annotations", annotations);
}
IR::Node * IR::ParserValueSet::fromJSON(JSONLoader & json) { return new ParserValueSet(json); }
IR::ParserValueSet::ParserValueSet(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Node(srcInfo), name(name), annotations(annotations)
    { validate(); }
IR::ParserValueSet::ParserValueSet(IR::ID name, const IR::Annotations* annotations) :
    name(name), annotations(annotations)
    { validate(); }
IR::ParserValueSet::ParserValueSet(Util::SourceInfo srcInfo, IR::ID name) :
    Node(srcInfo), name(name)
    { validate(); }
IR::ParserValueSet::ParserValueSet(IR::ID name) :
    name(name)
    { validate(); }
bool IR::CaseEntry::operator==(IR::CaseEntry const & a) const {
        return typeid(*this) == typeid(a)
        && values == a.values
        && action == a.action;
    }
bool IR::CaseEntry::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const CaseEntry &>(a_);
        return values == a.values
        && action == a.action;
    }
void IR::CaseEntry::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " action=" << action;
}
void IR::CaseEntry::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"values\" : " << this->values;
    json << "," << std::endl << json.indent << "\"action\" : " << this->action;
}
IR::CaseEntry::CaseEntry(JSONLoader & json) : Node(json) {
    json.load("values", values);
    json.load("action", action);
}
IR::Node * IR::CaseEntry::fromJSON(JSONLoader & json) { return new CaseEntry(json); }
IR::CaseEntry::CaseEntry(Util::SourceInfo srcInfo, IR::ID action) :
    Node(srcInfo), action(action)
    { validate(); }
IR::CaseEntry::CaseEntry(IR::ID action) :
    action(action)
    { validate(); }
IR::CaseEntry::CaseEntry(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::CaseEntry::CaseEntry() 
    { validate(); }
#line 277 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
const IR::Annotations *IR::V1Parser::getAnnotations() const { return annotations; }
#line 9548 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 278 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
cstring IR::V1Parser::toString() const { return node_type_name() + " " + name; }
#line 9551 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::V1Parser::operator==(IR::V1Parser const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && stmts == a.stmts
        && select == a.select
        && cases == a.cases
        && default_return == a.default_return
        && parse_error == a.parse_error
        && drop == a.drop
        && annotations == a.annotations;
    }
bool IR::V1Parser::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const V1Parser &>(a_);
        return name == a.name
        && stmts.equiv(a.stmts)
        && (select ? a.select ? select->equiv(*a.select) : false : a.select == nullptr)
        && (cases ? a.cases ? cases->equiv(*a.cases) : false : a.cases == nullptr)
        && default_return == a.default_return
        && parse_error == a.parse_error
        && drop == a.drop
        && (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr);
    }
void IR::V1Parser::visit_children(Visitor & v) {
    Node::visit_children(v);
    stmts.visit_children(v);
    v.visit(select, "select");
    v.visit(cases, "cases");
    v.visit(annotations, "annotations");
}
void IR::V1Parser::visit_children(Visitor & v) const {
    Node::visit_children(v);
    stmts.visit_children(v);
    v.visit(select, "select");
    v.visit(cases, "cases");
    v.visit(annotations, "annotations");
}
void IR::V1Parser::validate() const {
#line 9591 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        stmts.validate();
        CHECK_NULL(annotations); }
void IR::V1Parser::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
        out << " default_return=" << default_return;
        out << " parse_error=" << parse_error;
        out << " drop=" << drop;
}
void IR::V1Parser::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"stmts\" : " << this->stmts;
    if (select != nullptr)     json << "," << std::endl << json.indent << "\"select\" : " << this->select;
    if (cases != nullptr)     json << "," << std::endl << json.indent << "\"cases\" : " << this->cases;
    json << "," << std::endl << json.indent << "\"default_return\" : " << this->default_return;
    json << "," << std::endl << json.indent << "\"parse_error\" : " << this->parse_error;
    json << "," << std::endl << json.indent << "\"drop\" : " << this->drop;
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
}
IR::V1Parser::V1Parser(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("stmts", stmts);
    json.load("select", select);
    json.load("cases", cases);
    json.load("default_return", default_return);
    json.load("parse_error", parse_error);
    json.load("drop", drop);
    json.load("annotations", annotations);
}
IR::Node * IR::V1Parser::fromJSON(JSONLoader & json) { return new V1Parser(json); }
IR::V1Parser::V1Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Node(srcInfo), name(name), annotations(annotations)
    { validate(); }
IR::V1Parser::V1Parser(IR::ID name, const IR::Annotations* annotations) :
    name(name), annotations(annotations)
    { validate(); }
IR::V1Parser::V1Parser(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    Node(srcInfo), annotations(annotations)
    { validate(); }
IR::V1Parser::V1Parser(const IR::Annotations* annotations) :
    annotations(annotations)
    { validate(); }
bool IR::ParserException::operator==(IR::ParserException const & a) const {
        return typeid(*this) == typeid(a);
    }
bool IR::ParserException::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        return true;
    }
void IR::ParserException::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
}
IR::ParserException::ParserException(JSONLoader & json) : Node(json) {
}
IR::Node * IR::ParserException::fromJSON(JSONLoader & json) { return new ParserException(json); }
IR::ParserException::ParserException(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::ParserException::ParserException() 
    { validate(); }
#line 286 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
cstring IR::Attached::Name() const { return name; }
#line 9657 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 288 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
const IR::Type *IR::Attached::getType() const { return Type_Unknown::get(); }
#line 9660 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 289 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
const IR::Annotations *IR::Attached::getAnnotations() const { return annotations; }
#line 9663 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 290 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
bool IR::Attached::indexed() const { return false; }
#line 9666 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 291 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
IR::Attached * IR::Attached::clone_rename(char const * ext) const {
        Attached *rv = clone();
        rv->name = ID(Util::SourceInfo(), rv->name.name + ext);
        return rv; }
#line 9672 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 295 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::Attached::dbprint(std::ostream & out) const { out << node_type_name() << " " << name; }
#line 9675 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 296 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
cstring IR::Attached::toString() const { return node_type_name() + " " + name; }
#line 9678 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Attached::operator==(IR::Attached const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && annotations == a.annotations;
    }
bool IR::Attached::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const Attached &>(a_);
        return name == a.name
        && (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr);
    }
void IR::Attached::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
}
void IR::Attached::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
}
void IR::Attached::validate() const {
#line 9700 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations); }
void IR::Attached::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
}
void IR::Attached::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
}
IR::Attached::Attached(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("annotations", annotations);
}
IR::Attached::Attached(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Node(srcInfo), name(name), annotations(annotations)
    { validate(); }
IR::Attached::Attached(IR::ID name, const IR::Annotations* annotations) :
    name(name), annotations(annotations)
    { validate(); }
IR::Attached::Attached(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    Node(srcInfo), annotations(annotations)
    { validate(); }
IR::Attached::Attached(const IR::Annotations* annotations) :
    annotations(annotations)
    { validate(); }
IR::Attached::Attached(Util::SourceInfo srcInfo, IR::ID name) :
    Node(srcInfo), name(name)
    { validate(); }
IR::Attached::Attached(IR::ID name) :
    name(name)
    { validate(); }
IR::Attached::Attached(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::Attached::Attached() 
    { validate(); }
#line 304 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
bool IR::Stateful::indexed() const { return !direct; }
#line 9741 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

bool IR::Stateful::operator==(IR::Stateful const & a) const {
        return Attached::operator==(static_cast<const Attached &>(a))
        && table == a.table
        && direct == a.direct
        && saturating == a.saturating
        && instance_count == a.instance_count;
    }
bool IR::Stateful::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Attached::equiv(a_)) return false;
        auto &a = static_cast<const Stateful &>(a_);
        return table == a.table
        && direct == a.direct
        && saturating == a.saturating
        && instance_count == a.instance_count;
    }
void IR::Stateful::dump_fields(std::ostream & out) const {
    Attached::dump_fields(out);
        out << " table=" << table;
        out << " direct=" << direct;
        out << " saturating=" << saturating;
        out << " instance_count=" << instance_count;
}
void IR::Stateful::toJSON(JSONGenerator & json) const {
    Attached::toJSON(json);
    json << "," << std::endl << json.indent << "\"table\" : " << this->table;
    json << "," << std::endl << json.indent << "\"direct\" : " << this->direct;
    json << "," << std::endl << json.indent << "\"saturating\" : " << this->saturating;
    json << "," << std::endl << json.indent << "\"instance_count\" : " << this->instance_count;
}
IR::Stateful::Stateful(JSONLoader & json) : Attached(json) {
    json.load("table", table);
    json.load("direct", direct);
    json.load("saturating", saturating);
    json.load("instance_count", instance_count);
}
IR::Stateful::Stateful(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Attached(srcInfo, name, annotations)
    { validate(); }
IR::Stateful::Stateful(IR::ID name, const IR::Annotations* annotations) :
    Attached(name, annotations)
    { validate(); }
IR::Stateful::Stateful(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    Attached(srcInfo, annotations)
    { validate(); }
IR::Stateful::Stateful(const IR::Annotations* annotations) :
    Attached(annotations)
    { validate(); }
IR::Stateful::Stateful(Util::SourceInfo srcInfo, IR::ID name) :
    Attached(srcInfo, name)
    { validate(); }
IR::Stateful::Stateful(IR::ID name) :
    Attached(name)
    { validate(); }
IR::Stateful::Stateful(Util::SourceInfo srcInfo) :
    Attached(srcInfo)
    { validate(); }
IR::Stateful::Stateful() 
    { validate(); }
#line 310 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::CounterOrMeter::settype(cstring t) {
        if (strcasecmp(t.c_str(), "packets") == 0) type = CounterType::PACKETS;
        else if (strcasecmp(t.c_str(), "bytes") == 0) type = CounterType::BYTES;
        else if (strcasecmp(t.c_str(), "packets_and_bytes") == 0 ||
                 strcasecmp(t.c_str(), "PacketAndBytes") == 0) type = CounterType::BOTH;
        else error(ErrorType::ERR_UNKNOWN, "%s: Unknown type %s", srcInfo, t); }
#line 9809 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

bool IR::CounterOrMeter::operator==(IR::CounterOrMeter const & a) const {
        return Stateful::operator==(static_cast<const Stateful &>(a))
        && type == a.type;
    }
bool IR::CounterOrMeter::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Stateful::equiv(a_)) return false;
        auto &a = static_cast<const CounterOrMeter &>(a_);
        return type == a.type;
    }
void IR::CounterOrMeter::dump_fields(std::ostream & out) const {
    Stateful::dump_fields(out);
        out << " type=" << type;
}
void IR::CounterOrMeter::toJSON(JSONGenerator & json) const {
    Stateful::toJSON(json);
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
}
IR::CounterOrMeter::CounterOrMeter(JSONLoader & json) : Stateful(json) {
    json.load("type", type);
}
IR::CounterOrMeter::CounterOrMeter(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Stateful(srcInfo, name, annotations)
    { validate(); }
IR::CounterOrMeter::CounterOrMeter(IR::ID name, const IR::Annotations* annotations) :
    Stateful(name, annotations)
    { validate(); }
IR::CounterOrMeter::CounterOrMeter(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    Stateful(srcInfo, annotations)
    { validate(); }
IR::CounterOrMeter::CounterOrMeter(const IR::Annotations* annotations) :
    Stateful(annotations)
    { validate(); }
IR::CounterOrMeter::CounterOrMeter(Util::SourceInfo srcInfo, IR::ID name) :
    Stateful(srcInfo, name)
    { validate(); }
IR::CounterOrMeter::CounterOrMeter(IR::ID name) :
    Stateful(name)
    { validate(); }
IR::CounterOrMeter::CounterOrMeter(Util::SourceInfo srcInfo) :
    Stateful(srcInfo)
    { validate(); }
IR::CounterOrMeter::CounterOrMeter() 
    { validate(); }
#line 321 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
char const * IR::Counter::kind() const { return "stats"; }
#line 9857 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 322 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
IR::Type const * IR::Counter::getType() const { return Type_Counter::get(); }
#line 9860 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Counter::operator==(IR::Counter const & a) const {
        return CounterOrMeter::operator==(static_cast<const CounterOrMeter &>(a))
        && max_width == a.max_width
        && min_width == a.min_width;
    }
bool IR::Counter::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!CounterOrMeter::equiv(a_)) return false;
        auto &a = static_cast<const Counter &>(a_);
        return max_width == a.max_width
        && min_width == a.min_width;
    }
void IR::Counter::dump_fields(std::ostream & out) const {
    CounterOrMeter::dump_fields(out);
        out << " max_width=" << max_width;
        out << " min_width=" << min_width;
}
void IR::Counter::toJSON(JSONGenerator & json) const {
    CounterOrMeter::toJSON(json);
    json << "," << std::endl << json.indent << "\"max_width\" : " << this->max_width;
    json << "," << std::endl << json.indent << "\"min_width\" : " << this->min_width;
}
IR::Counter::Counter(JSONLoader & json) : CounterOrMeter(json) {
    json.load("max_width", max_width);
    json.load("min_width", min_width);
}
IR::Node * IR::Counter::fromJSON(JSONLoader & json) { return new Counter(json); }
IR::Counter::Counter(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    CounterOrMeter(srcInfo, name, annotations)
    { validate(); }
IR::Counter::Counter(IR::ID name, const IR::Annotations* annotations) :
    CounterOrMeter(name, annotations)
    { validate(); }
IR::Counter::Counter(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    CounterOrMeter(srcInfo, annotations)
    { validate(); }
IR::Counter::Counter(const IR::Annotations* annotations) :
    CounterOrMeter(annotations)
    { validate(); }
IR::Counter::Counter(Util::SourceInfo srcInfo, IR::ID name) :
    CounterOrMeter(srcInfo, name)
    { validate(); }
IR::Counter::Counter(IR::ID name) :
    CounterOrMeter(name)
    { validate(); }
IR::Counter::Counter(Util::SourceInfo srcInfo) :
    CounterOrMeter(srcInfo)
    { validate(); }
IR::Counter::Counter() 
    { validate(); }
#line 329 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
char const * IR::Meter::kind() const { return "meter"; }
#line 9913 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 330 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
const IR::Type *IR::Meter::getType() const { return Type_Meter::get(); }
#line 9916 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Meter::operator==(IR::Meter const & a) const {
        return CounterOrMeter::operator==(static_cast<const CounterOrMeter &>(a))
        && result == a.result
        && pre_color == a.pre_color
        && implementation == a.implementation;
    }
bool IR::Meter::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!CounterOrMeter::equiv(a_)) return false;
        auto &a = static_cast<const Meter &>(a_);
        return (result ? a.result ? result->equiv(*a.result) : false : a.result == nullptr)
        && (pre_color ? a.pre_color ? pre_color->equiv(*a.pre_color) : false : a.pre_color == nullptr)
        && implementation == a.implementation;
    }
void IR::Meter::visit_children(Visitor & v) {
    CounterOrMeter::visit_children(v);
    v.visit(result, "result");
    v.visit(pre_color, "pre_color");
}
void IR::Meter::visit_children(Visitor & v) const {
    CounterOrMeter::visit_children(v);
    v.visit(result, "result");
    v.visit(pre_color, "pre_color");
}
void IR::Meter::dump_fields(std::ostream & out) const {
    CounterOrMeter::dump_fields(out);
        out << " implementation=" << implementation;
}
void IR::Meter::toJSON(JSONGenerator & json) const {
    CounterOrMeter::toJSON(json);
    if (result != nullptr)     json << "," << std::endl << json.indent << "\"result\" : " << this->result;
    if (pre_color != nullptr)     json << "," << std::endl << json.indent << "\"pre_color\" : " << this->pre_color;
    json << "," << std::endl << json.indent << "\"implementation\" : " << this->implementation;
}
IR::Meter::Meter(JSONLoader & json) : CounterOrMeter(json) {
    json.load("result", result);
    json.load("pre_color", pre_color);
    json.load("implementation", implementation);
}
IR::Node * IR::Meter::fromJSON(JSONLoader & json) { return new Meter(json); }
IR::Meter::Meter(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    CounterOrMeter(srcInfo, name, annotations)
    { validate(); }
IR::Meter::Meter(IR::ID name, const IR::Annotations* annotations) :
    CounterOrMeter(name, annotations)
    { validate(); }
IR::Meter::Meter(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    CounterOrMeter(srcInfo, annotations)
    { validate(); }
IR::Meter::Meter(const IR::Annotations* annotations) :
    CounterOrMeter(annotations)
    { validate(); }
IR::Meter::Meter(Util::SourceInfo srcInfo, IR::ID name) :
    CounterOrMeter(srcInfo, name)
    { validate(); }
IR::Meter::Meter(IR::ID name) :
    CounterOrMeter(name)
    { validate(); }
IR::Meter::Meter(Util::SourceInfo srcInfo) :
    CounterOrMeter(srcInfo)
    { validate(); }
IR::Meter::Meter() 
    { validate(); }

#line 338 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
char const * IR::Register::kind() const { return "register"; }
#line 9983 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 339 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
const IR::Type *IR::Register::getType() const { return Type_Register::get(); }
#line 9986 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Register::operator==(IR::Register const & a) const {
        return Stateful::operator==(static_cast<const Stateful &>(a))
        && layout == a.layout
        && width == a.width
        && signed_ == a.signed_;
    }
bool IR::Register::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Stateful::equiv(a_)) return false;
        auto &a = static_cast<const Register &>(a_);
        return layout == a.layout
        && width == a.width
        && signed_ == a.signed_;
    }
void IR::Register::dump_fields(std::ostream & out) const {
    Stateful::dump_fields(out);
        out << " layout=" << layout;
        out << " width=" << width;
        out << " signed_=" << signed_;
}
void IR::Register::toJSON(JSONGenerator & json) const {
    Stateful::toJSON(json);
    json << "," << std::endl << json.indent << "\"layout\" : " << this->layout;
    json << "," << std::endl << json.indent << "\"width\" : " << this->width;
    json << "," << std::endl << json.indent << "\"signed_\" : " << this->signed_;
}
IR::Register::Register(JSONLoader & json) : Stateful(json) {
    json.load("layout", layout);
    json.load("width", width);
    json.load("signed_", signed_);
}
IR::Node * IR::Register::fromJSON(JSONLoader & json) { return new Register(json); }
IR::Register::Register(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Stateful(srcInfo, name, annotations)
    { validate(); }
IR::Register::Register(IR::ID name, const IR::Annotations* annotations) :
    Stateful(name, annotations)
    { validate(); }
IR::Register::Register(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    Stateful(srcInfo, annotations)
    { validate(); }
IR::Register::Register(const IR::Annotations* annotations) :
    Stateful(annotations)
    { validate(); }
IR::Register::Register(Util::SourceInfo srcInfo, IR::ID name) :
    Stateful(srcInfo, name)
    { validate(); }
IR::Register::Register(IR::ID name) :
    Stateful(name)
    { validate(); }
IR::Register::Register(Util::SourceInfo srcInfo) :
    Stateful(srcInfo)
    { validate(); }
IR::Register::Register() 
    { validate(); }
bool IR::PrimitiveAction::operator==(IR::PrimitiveAction const & a) const {
        return typeid(*this) == typeid(a);
    }
bool IR::PrimitiveAction::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        return true;
    }
void IR::PrimitiveAction::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
}
IR::PrimitiveAction::PrimitiveAction(JSONLoader & json) : Node(json) {
}
IR::Node * IR::PrimitiveAction::fromJSON(JSONLoader & json) { return new PrimitiveAction(json); }
IR::PrimitiveAction::PrimitiveAction(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::PrimitiveAction::PrimitiveAction() 
    { validate(); }
#line 346 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
IR::NameList::NameList(Util::SourceInfo si, cstring n) { names.emplace_back(si, n); }
#line 10063 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 347 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
IR::NameList::NameList(Util::SourceInfo si, IR::ID n) { names.emplace_back(si, n); }
#line 10066 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 348 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::NameList::dump_fields(std::ostream & out) const { out << "names=" << names; }
#line 10069 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::NameList::operator==(IR::NameList const & a) const {
        return typeid(*this) == typeid(a)
        && names == a.names;
    }
bool IR::NameList::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const NameList &>(a_);
        return names == a.names;
    }
void IR::NameList::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"names\" : " << this->names;
}
IR::NameList::NameList(JSONLoader & json) : Node(json) {
    json.load("names", names);
}
IR::Node * IR::NameList::fromJSON(JSONLoader & json) { return new NameList(json); }
IR::NameList::NameList(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::NameList::NameList() 
    { validate(); }
#line 357 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::ActionArg::dbprint(std::ostream & out) const { out << action_name << ':' << name; }
#line 10095 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 358 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
cstring IR::ActionArg::toString() const { return name.name; }
#line 10098 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::ActionArg::operator==(IR::ActionArg const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && action_name == a.action_name
        && name == a.name
        && read == a.read
        && write == a.write;
    }
bool IR::ActionArg::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const ActionArg &>(a_);
        return action_name == a.action_name
        && name == a.name
        && read == a.read
        && write == a.write;
    }
void IR::ActionArg::dump_fields(std::ostream & out) const {
    Expression::dump_fields(out);
        out << " action_name=" << action_name;
        out << " name=" << name;
        out << " read=" << read;
        out << " write=" << write;
}
void IR::ActionArg::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"action_name\" : " << this->action_name;
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"read\" : " << this->read;
    json << "," << std::endl << json.indent << "\"write\" : " << this->write;
}
IR::ActionArg::ActionArg(JSONLoader & json) : Expression(json) {
    json.load("action_name", action_name);
    json.load("name", name);
    json.load("read", read);
    json.load("write", write);
}
IR::Node * IR::ActionArg::fromJSON(JSONLoader & json) { return new ActionArg(json); }
IR::ActionArg::ActionArg(Util::SourceInfo srcInfo, const IR::Type* type, cstring action_name, IR::ID name) :
    Expression(srcInfo, type), action_name(action_name), name(name)
    {
#line 356 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 10141 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::ActionArg::ActionArg(const IR::Type* type, cstring action_name, IR::ID name) :
    Expression(type), action_name(action_name), name(name)
    {
#line 356 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 10148 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::ActionArg::ActionArg(Util::SourceInfo srcInfo, cstring action_name, IR::ID name) :
    Expression(srcInfo), action_name(action_name), name(name)
    {
#line 356 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 10155 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::ActionArg::ActionArg(cstring action_name, IR::ID name) :
    action_name(action_name), name(name)
    {
#line 356 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 10162 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
#line 368 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
const IR::Annotations *IR::ActionFunction::getAnnotations() const { return annotations; }
#line 10166 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 369 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
const IR::ActionArg *IR::ActionFunction::arg(cstring n) const {
        for (auto a : args)
            if (a->name == n)
                return a;
        return nullptr; }
#line 10173 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 374 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::ActionFunction::visit_children(Visitor & v) {
        v.visit(action, "action");
        // DANGER -- visiting action first so type inferencing will push types to
        // DANGER -- action args based on use.  This is immoral.
        for (auto &a : args) v.visit(a, "arg");
        v.visit(annotations, "annotations");
    }
#line 374 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::ActionFunction::visit_children(Visitor & v) const {
        v.visit(action, "action");
        // DANGER -- visiting action first so type inferencing will push types to
        // DANGER -- action args based on use.  This is immoral.
        for (auto &a : args) v.visit(a, "arg");
        v.visit(annotations, "annotations");
    }
#line 10190 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 381 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
cstring IR::ActionFunction::toString() const {
        return cstring("action ") + name + " {\n" +
                 cstring::join(action.begin(), action.end(), ";\n") +
                 " }"; }
#line 10196 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::ActionFunction::operator==(IR::ActionFunction const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && action == a.action
        && args == a.args
        && annotations == a.annotations;
    }
bool IR::ActionFunction::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const ActionFunction &>(a_);
        return name == a.name
        && action.equiv(a.action)
        && args == a.args
        && (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr);
    }
void IR::ActionFunction::validate() const {
#line 10214 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        action.validate();
        CHECK_NULL(annotations); }
void IR::ActionFunction::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
}
void IR::ActionFunction::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"action\" : " << this->action;
    json << "," << std::endl << json.indent << "\"args\" : " << this->args;
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
}
IR::ActionFunction::ActionFunction(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("action", action);
    json.load("args", args);
    json.load("annotations", annotations);
}
IR::Node * IR::ActionFunction::fromJSON(JSONLoader & json) { return new ActionFunction(json); }
IR::ActionFunction::ActionFunction(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Node(srcInfo), name(name), annotations(annotations)
    { validate(); }
IR::ActionFunction::ActionFunction(IR::ID name, const IR::Annotations* annotations) :
    name(name), annotations(annotations)
    { validate(); }
IR::ActionFunction::ActionFunction(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    Node(srcInfo), annotations(annotations)
    { validate(); }
IR::ActionFunction::ActionFunction(const IR::Annotations* annotations) :
    annotations(annotations)
    { validate(); }
IR::ActionFunction::ActionFunction(Util::SourceInfo srcInfo, IR::ID name) :
    Node(srcInfo), name(name)
    { validate(); }
IR::ActionFunction::ActionFunction(IR::ID name) :
    name(name)
    { validate(); }
IR::ActionFunction::ActionFunction(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::ActionFunction::ActionFunction() 
    { validate(); }
#line 391 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
char const * IR::ActionProfile::kind() const { return "action_profile"; }
#line 10261 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 392 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
bool IR::ActionProfile::indexed() const { return true; }
#line 10264 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::ActionProfile::operator==(IR::ActionProfile const & a) const {
        return Attached::operator==(static_cast<const Attached &>(a))
        && selector == a.selector
        && actions == a.actions
        && size == a.size;
    }
bool IR::ActionProfile::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Attached::equiv(a_)) return false;
        auto &a = static_cast<const ActionProfile &>(a_);
        return selector == a.selector
        && actions == a.actions
        && size == a.size;
    }
void IR::ActionProfile::dump_fields(std::ostream & out) const {
    Attached::dump_fields(out);
        out << " selector=" << selector;
        out << " size=" << size;
}
void IR::ActionProfile::toJSON(JSONGenerator & json) const {
    Attached::toJSON(json);
    json << "," << std::endl << json.indent << "\"selector\" : " << this->selector;
    json << "," << std::endl << json.indent << "\"actions\" : " << this->actions;
    json << "," << std::endl << json.indent << "\"size\" : " << this->size;
}
IR::ActionProfile::ActionProfile(JSONLoader & json) : Attached(json) {
    json.load("selector", selector);
    json.load("actions", actions);
    json.load("size", size);
}
IR::Node * IR::ActionProfile::fromJSON(JSONLoader & json) { return new ActionProfile(json); }
IR::ActionProfile::ActionProfile(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Attached(srcInfo, name, annotations)
    { validate(); }
IR::ActionProfile::ActionProfile(IR::ID name, const IR::Annotations* annotations) :
    Attached(name, annotations)
    { validate(); }
IR::ActionProfile::ActionProfile(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    Attached(srcInfo, annotations)
    { validate(); }
IR::ActionProfile::ActionProfile(const IR::Annotations* annotations) :
    Attached(annotations)
    { validate(); }
IR::ActionProfile::ActionProfile(Util::SourceInfo srcInfo, IR::ID name) :
    Attached(srcInfo, name)
    { validate(); }
IR::ActionProfile::ActionProfile(IR::ID name) :
    Attached(name)
    { validate(); }
IR::ActionProfile::ActionProfile(Util::SourceInfo srcInfo) :
    Attached(srcInfo)
    { validate(); }
IR::ActionProfile::ActionProfile() 
    { validate(); }
#line 400 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
char const * IR::ActionSelector::kind() const { return "action_selector"; }
#line 10321 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::ActionSelector::operator==(IR::ActionSelector const & a) const {
        return Attached::operator==(static_cast<const Attached &>(a))
        && key == a.key
        && key_fields == a.key_fields
        && mode == a.mode
        && type == a.type;
    }
bool IR::ActionSelector::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Attached::equiv(a_)) return false;
        auto &a = static_cast<const ActionSelector &>(a_);
        return key == a.key
        && (key_fields ? a.key_fields ? key_fields->equiv(*a.key_fields) : false : a.key_fields == nullptr)
        && mode == a.mode
        && type == a.type;
    }
void IR::ActionSelector::visit_children(Visitor & v) {
    Attached::visit_children(v);
    v.visit(key_fields, "key_fields");
}
void IR::ActionSelector::visit_children(Visitor & v) const {
    Attached::visit_children(v);
    v.visit(key_fields, "key_fields");
}
void IR::ActionSelector::dump_fields(std::ostream & out) const {
    Attached::dump_fields(out);
        out << " key=" << key;
        out << " mode=" << mode;
        out << " type=" << type;
}
void IR::ActionSelector::toJSON(JSONGenerator & json) const {
    Attached::toJSON(json);
    json << "," << std::endl << json.indent << "\"key\" : " << this->key;
    if (key_fields != nullptr)     json << "," << std::endl << json.indent << "\"key_fields\" : " << this->key_fields;
    json << "," << std::endl << json.indent << "\"mode\" : " << this->mode;
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
}
IR::ActionSelector::ActionSelector(JSONLoader & json) : Attached(json) {
    json.load("key", key);
    json.load("key_fields", key_fields);
    json.load("mode", mode);
    json.load("type", type);
}
IR::Node * IR::ActionSelector::fromJSON(JSONLoader & json) { return new ActionSelector(json); }
IR::ActionSelector::ActionSelector(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Attached(srcInfo, name, annotations)
    { validate(); }
IR::ActionSelector::ActionSelector(IR::ID name, const IR::Annotations* annotations) :
    Attached(name, annotations)
    { validate(); }
IR::ActionSelector::ActionSelector(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    Attached(srcInfo, annotations)
    { validate(); }
IR::ActionSelector::ActionSelector(const IR::Annotations* annotations) :
    Attached(annotations)
    { validate(); }
IR::ActionSelector::ActionSelector(Util::SourceInfo srcInfo, IR::ID name) :
    Attached(srcInfo, name)
    { validate(); }
IR::ActionSelector::ActionSelector(IR::ID name) :
    Attached(name)
    { validate(); }
IR::ActionSelector::ActionSelector(Util::SourceInfo srcInfo) :
    Attached(srcInfo)
    { validate(); }
IR::ActionSelector::ActionSelector() 
    { validate(); }

#line 418 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::V1Table::addProperty(const IR::Property* prop) { properties.push_back(prop); }
#line 10392 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 419 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
const IR::Annotations *IR::V1Table::getAnnotations() const { return annotations; }
#line 10395 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 420 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
cstring IR::V1Table::toString() const { return node_type_name() + " " + name; }
#line 10398 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 421 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
cstring IR::V1Table::Name() const { return name; }
#line 10401 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 422 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
const IR::Type *IR::V1Table::getType() const { return Type_AnyTable::get(); }
#line 10404 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::V1Table::operator==(IR::V1Table const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && reads == a.reads
        && reads_types == a.reads_types
        && min_size == a.min_size
        && max_size == a.max_size
        && size == a.size
        && action_profile == a.action_profile
        && actions == a.actions
        && default_action == a.default_action
        && default_action_is_const == a.default_action_is_const
        && default_action_args == a.default_action_args
        && properties == a.properties
        && annotations == a.annotations;
    }
bool IR::V1Table::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const V1Table &>(a_);
        return name == a.name
        && (reads ? a.reads ? reads->equiv(*a.reads) : false : a.reads == nullptr)
        && reads_types == a.reads_types
        && min_size == a.min_size
        && max_size == a.max_size
        && size == a.size
        && action_profile == a.action_profile
        && actions == a.actions
        && default_action == a.default_action
        && default_action_is_const == a.default_action_is_const
        && (default_action_args ? a.default_action_args ? default_action_args->equiv(*a.default_action_args) : false : a.default_action_args == nullptr)
        && properties.equiv(a.properties)
        && (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr);
    }
void IR::V1Table::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(reads, "reads");
    v.visit(default_action_args, "default_action_args");
    properties.visit_children(v);
    v.visit(annotations, "annotations");
}
void IR::V1Table::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(reads, "reads");
    v.visit(default_action_args, "default_action_args");
    properties.visit_children(v);
    v.visit(annotations, "annotations");
}
void IR::V1Table::validate() const {
#line 10454 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        properties.validate();
        CHECK_NULL(annotations); }
void IR::V1Table::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
        out << " min_size=" << min_size;
        out << " max_size=" << max_size;
        out << " size=" << size;
        out << " action_profile=" << action_profile;
        out << " default_action=" << default_action;
        out << " default_action_is_const=" << default_action_is_const;
}
void IR::V1Table::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    if (reads != nullptr)     json << "," << std::endl << json.indent << "\"reads\" : " << this->reads;
    json << "," << std::endl << json.indent << "\"reads_types\" : " << this->reads_types;
    json << "," << std::endl << json.indent << "\"min_size\" : " << this->min_size;
    json << "," << std::endl << json.indent << "\"max_size\" : " << this->max_size;
    json << "," << std::endl << json.indent << "\"size\" : " << this->size;
    json << "," << std::endl << json.indent << "\"action_profile\" : " << this->action_profile;
    json << "," << std::endl << json.indent << "\"actions\" : " << this->actions;
    json << "," << std::endl << json.indent << "\"default_action\" : " << this->default_action;
    json << "," << std::endl << json.indent << "\"default_action_is_const\" : " << this->default_action_is_const;
    if (default_action_args != nullptr)     json << "," << std::endl << json.indent << "\"default_action_args\" : " << this->default_action_args;
    json << "," << std::endl << json.indent << "\"properties\" : " << this->properties;
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
}
IR::V1Table::V1Table(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("reads", reads);
    json.load("reads_types", reads_types);
    json.load("min_size", min_size);
    json.load("max_size", max_size);
    json.load("size", size);
    json.load("action_profile", action_profile);
    json.load("actions", actions);
    json.load("default_action", default_action);
    json.load("default_action_is_const", default_action_is_const);
    json.load("default_action_args", default_action_args);
    json.load("properties", properties);
    json.load("annotations", annotations);
}
IR::Node * IR::V1Table::fromJSON(JSONLoader & json) { return new V1Table(json); }
IR::V1Table::V1Table(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Node(srcInfo), name(name), annotations(annotations)
    { validate(); }
IR::V1Table::V1Table(IR::ID name, const IR::Annotations* annotations) :
    name(name), annotations(annotations)
    { validate(); }
IR::V1Table::V1Table(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    Node(srcInfo), annotations(annotations)
    { validate(); }
IR::V1Table::V1Table(const IR::Annotations* annotations) :
    annotations(annotations)
    { validate(); }
IR::V1Table::V1Table(Util::SourceInfo srcInfo, IR::ID name) :
    Node(srcInfo), name(name)
    { validate(); }
IR::V1Table::V1Table(IR::ID name) :
    name(name)
    { validate(); }
IR::V1Table::V1Table(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::V1Table::V1Table() 
    { validate(); }
#line 430 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
IR::V1Control::V1Control(IR::ID n) : name(n), code(new Vector<Expression>()) {}
#line 10525 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 431 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
IR::V1Control::V1Control(Util::SourceInfo si, IR::ID n) : Node(si), name(n), code(new Vector<Expression>()) {}
#line 10528 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
IRNODE_DEFINE_APPLY_OVERLOAD(V1Control, , )
#line 433 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
const IR::Annotations *IR::V1Control::getAnnotations() const { return annotations; }
#line 10532 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 434 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
cstring IR::V1Control::toString() const { return node_type_name() + " " + name; }
#line 10535 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::V1Control::operator==(IR::V1Control const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && code == a.code
        && annotations == a.annotations;
    }
bool IR::V1Control::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const V1Control &>(a_);
        return name == a.name
        && (code ? a.code ? code->equiv(*a.code) : false : a.code == nullptr)
        && (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr);
    }
void IR::V1Control::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(code, "code");
    v.visit(annotations, "annotations");
}
void IR::V1Control::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(code, "code");
    v.visit(annotations, "annotations");
}
void IR::V1Control::validate() const {
#line 10561 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(code);
        CHECK_NULL(annotations); }
void IR::V1Control::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
}
void IR::V1Control::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"code\" : " << this->code;
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
}
IR::V1Control::V1Control(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("code", code);
    json.load("annotations", annotations);
}
IR::Node * IR::V1Control::fromJSON(JSONLoader & json) { return new V1Control(json); }
IR::V1Control::V1Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Vector<IR::Expression>* code, const IR::Annotations* annotations) :
    Node(srcInfo), name(name), code(code), annotations(annotations)
    { validate(); }
IR::V1Control::V1Control(IR::ID name, const IR::Vector<IR::Expression>* code, const IR::Annotations* annotations) :
    name(name), code(code), annotations(annotations)
    { validate(); }
#line 439 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
IR::ID IR::AttribLocal::getName() const { return name; }
#line 10589 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 440 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::AttribLocal::dbprint(std::ostream & out) const { out << name; }
#line 10592 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::AttribLocal::operator==(IR::AttribLocal const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && name == a.name;
    }
bool IR::AttribLocal::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const AttribLocal &>(a_);
        return name == a.name;
    }
void IR::AttribLocal::dump_fields(std::ostream & out) const {
    Expression::dump_fields(out);
        out << " name=" << name;
}
void IR::AttribLocal::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
}
IR::AttribLocal::AttribLocal(JSONLoader & json) : Expression(json) {
    json.load("name", name);
}
IR::Node * IR::AttribLocal::fromJSON(JSONLoader & json) { return new AttribLocal(json); }
IR::AttribLocal::AttribLocal(Util::SourceInfo srcInfo, const IR::Type* type, IR::ID name) :
    Expression(srcInfo, type), name(name)
    { validate(); }
IR::AttribLocal::AttribLocal(const IR::Type* type, IR::ID name) :
    Expression(type), name(name)
    { validate(); }
IR::AttribLocal::AttribLocal(Util::SourceInfo srcInfo, IR::ID name) :
    Expression(srcInfo), name(name)
    { validate(); }
IR::AttribLocal::AttribLocal(IR::ID name) :
    name(name)
    { validate(); }
#line 446 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
Util::Enumerator<const IR::IDeclaration *> * IR::AttribLocals::getDeclarations() const {
        return locals.valueEnumerator()->as<const IDeclaration *>(); }
#line 10630 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 448 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
const IR::IDeclaration *IR::AttribLocals::getDeclByName(cstring name) const { return locals[name]; }
#line 10633 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::AttribLocals::operator==(IR::AttribLocals const & a) const {
        return typeid(*this) == typeid(a)
        && locals == a.locals;
    }
bool IR::AttribLocals::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const AttribLocals &>(a_);
        return locals.equiv(a.locals);
    }
void IR::AttribLocals::visit_children(Visitor & v) {
    Node::visit_children(v);
    locals.visit_children(v);
}
void IR::AttribLocals::visit_children(Visitor & v) const {
    Node::visit_children(v);
    locals.visit_children(v);
}
void IR::AttribLocals::validate() const {
#line 10653 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        locals.validate(); }
void IR::AttribLocals::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"locals\" : " << this->locals;
}
IR::AttribLocals::AttribLocals(JSONLoader & json) : Node(json) {
    json.load("locals", locals);
}
IR::Node * IR::AttribLocals::fromJSON(JSONLoader & json) { return new AttribLocals(json); }
IR::AttribLocals::AttribLocals(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::AttribLocals::AttribLocals() 
    { validate(); }
#line 455 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::Attribute::dbprint(std::ostream & out) const { if (type) out << type << ' '; out << name; }
#line 10671 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::Attribute::operator==(IR::Attribute const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && type == a.type
        && locals == a.locals
        && optional == a.optional;
    }
bool IR::Attribute::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Attribute &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (locals ? a.locals ? locals->equiv(*a.locals) : false : a.locals == nullptr)
        && optional == a.optional;
    }
void IR::Attribute::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(type, "type");
    v.visit(locals, "locals");
}
void IR::Attribute::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(type, "type");
    v.visit(locals, "locals");
}
void IR::Attribute::dump_fields(std::ostream & out) const {
    Declaration::dump_fields(out);
        out << " optional=" << optional;
}
void IR::Attribute::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    if (type != nullptr)     json << "," << std::endl << json.indent << "\"type\" : " << this->type;
    if (locals != nullptr)     json << "," << std::endl << json.indent << "\"locals\" : " << this->locals;
    json << "," << std::endl << json.indent << "\"optional\" : " << this->optional;
}
IR::Attribute::Attribute(JSONLoader & json) : Declaration(json) {
    json.load("type", type);
    json.load("locals", locals);
    json.load("optional", optional);
}
IR::Node * IR::Attribute::fromJSON(JSONLoader & json) { return new Attribute(json); }
IR::Attribute::Attribute(Util::SourceInfo srcInfo, IR::ID name) :
    Declaration(srcInfo, name)
    { validate(); }
IR::Attribute::Attribute(IR::ID name) :
    Declaration(name)
    { validate(); }


#line 462 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::GlobalRef::validate() const {
#line 10722 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(obj);
#line 462 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
{ obj->is<IInstance>(); } }
#line 10727 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 463 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
cstring IR::GlobalRef::toString() const { return obj->to<IInstance>()->Name(); }
#line 10730 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 464 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::GlobalRef::dbprint(std::ostream & out) const { out << obj->to<IInstance>()->Name(); }
#line 10733 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::GlobalRef::operator==(IR::GlobalRef const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && obj == a.obj;
    }
bool IR::GlobalRef::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const GlobalRef &>(a_);
        return (obj ? a.obj ? obj->equiv(*a.obj) : false : a.obj == nullptr);
    }
void IR::GlobalRef::visit_children(Visitor & v) {
    Expression::visit_children(v);
    v.visit(obj, "obj");
}
void IR::GlobalRef::visit_children(Visitor & v) const {
    Expression::visit_children(v);
    v.visit(obj, "obj");
}
void IR::GlobalRef::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"obj\" : " << this->obj;
}
IR::GlobalRef::GlobalRef(JSONLoader & json) : Expression(json) {
    json.load("obj", obj);
}
IR::Node * IR::GlobalRef::fromJSON(JSONLoader & json) { return new GlobalRef(json); }
IR::GlobalRef::GlobalRef(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Node* obj) :
    Expression(srcInfo, type), obj(obj)
    {
#line 461 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
{ type = obj->to<IInstance>()->getType(); }
#line 10765 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::GlobalRef::GlobalRef(const IR::Type* type, const IR::Node* obj) :
    Expression(type), obj(obj)
    {
#line 461 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
{ type = obj->to<IInstance>()->getType(); }
#line 10772 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::GlobalRef::GlobalRef(Util::SourceInfo srcInfo, const IR::Node* obj) :
    Expression(srcInfo), obj(obj)
    {
#line 461 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
{ type = obj->to<IInstance>()->getType(); }
#line 10779 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::GlobalRef::GlobalRef(const IR::Node* obj) :
    obj(obj)
    {
#line 461 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
{ type = obj->to<IInstance>()->getType(); }
#line 10786 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
#line 472 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
cstring IR::AttributeRef::toString() const { return attrib->name; }
#line 10790 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 473 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::AttributeRef::dbprint(std::ostream & out) const { out << attrib->name; }
#line 10793 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::AttributeRef::operator==(IR::AttributeRef const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && extern_name == a.extern_name
        && extern_type == a.extern_type
        && attrib == a.attrib;
    }
bool IR::AttributeRef::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const AttributeRef &>(a_);
        return extern_name == a.extern_name
        && (extern_type ? a.extern_type ? extern_type->equiv(*a.extern_type) : false : a.extern_type == nullptr)
        && (attrib ? a.attrib ? attrib->equiv(*a.attrib) : false : a.attrib == nullptr);
    }
void IR::AttributeRef::visit_children(Visitor & v) {
    Expression::visit_children(v);
    v.visit(extern_type, "extern_type");
    v.visit(attrib, "attrib");
}
void IR::AttributeRef::visit_children(Visitor & v) const {
    Expression::visit_children(v);
    v.visit(extern_type, "extern_type");
    v.visit(attrib, "attrib");
}
void IR::AttributeRef::validate() const {
#line 10819 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(extern_type);
        CHECK_NULL(attrib); }
void IR::AttributeRef::dump_fields(std::ostream & out) const {
    Expression::dump_fields(out);
        out << " extern_name=" << extern_name;
}
void IR::AttributeRef::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"extern_name\" : " << this->extern_name;
    json << "," << std::endl << json.indent << "\"extern_type\" : " << this->extern_type;
    json << "," << std::endl << json.indent << "\"attrib\" : " << this->attrib;
}
IR::AttributeRef::AttributeRef(JSONLoader & json) : Expression(json) {
    json.load("extern_name", extern_name);
    json.load("extern_type", extern_type);
    json.load("attrib", attrib);
}
IR::Node * IR::AttributeRef::fromJSON(JSONLoader & json) { return new AttributeRef(json); }
IR::AttributeRef::AttributeRef(Util::SourceInfo srcInfo, const IR::Type* type, cstring extern_name, const IR::Type_Extern* extern_type, const IR::Attribute* attrib) :
    Expression(srcInfo, type), extern_name(extern_name), extern_type(extern_type), attrib(attrib)
    {
#line 471 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
{ type = attrib->type; }
#line 10844 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::AttributeRef::AttributeRef(const IR::Type* type, cstring extern_name, const IR::Type_Extern* extern_type, const IR::Attribute* attrib) :
    Expression(type), extern_name(extern_name), extern_type(extern_type), attrib(attrib)
    {
#line 471 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
{ type = attrib->type; }
#line 10851 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::AttributeRef::AttributeRef(Util::SourceInfo srcInfo, cstring extern_name, const IR::Type_Extern* extern_type, const IR::Attribute* attrib) :
    Expression(srcInfo), extern_name(extern_name), extern_type(extern_type), attrib(attrib)
    {
#line 471 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
{ type = attrib->type; }
#line 10858 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
IR::AttributeRef::AttributeRef(cstring extern_name, const IR::Type_Extern* extern_type, const IR::Attribute* attrib) :
    extern_name(extern_name), extern_type(extern_type), attrib(attrib)
    {
#line 471 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
{ type = attrib->type; }
#line 10865 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
     validate(); }
#line 484 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/ir/v1.def"
void IR::V1Program::add(cstring name, IR::Node const * n) { scope.add(name, n); }
#line 10869 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
IRNODE_DEFINE_APPLY_OVERLOAD(V1Program, , )
bool IR::V1Program::operator==(IR::V1Program const & a) const {
        return typeid(*this) == typeid(a)
        && scope == a.scope;
    }
bool IR::V1Program::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const V1Program &>(a_);
        return scope.equiv(a.scope);
    }
void IR::V1Program::visit_children(Visitor & v) {
    Node::visit_children(v);
    scope.visit_children(v);
}
void IR::V1Program::visit_children(Visitor & v) const {
    Node::visit_children(v);
    scope.visit_children(v);
}
void IR::V1Program::validate() const {
#line 10890 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        scope.validate(); }
void IR::V1Program::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"scope\" : " << this->scope;
}
IR::V1Program::V1Program(JSONLoader & json) : Node(json) {
    json.load("scope", scope);
}
IR::Node * IR::V1Program::fromJSON(JSONLoader & json) { return new V1Program(json); }
bool IR::DpdkDeclaration::operator==(IR::DpdkDeclaration const & a) const {
        return typeid(*this) == typeid(a)
        && global == a.global;
    }
bool IR::DpdkDeclaration::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const DpdkDeclaration &>(a_);
        return (global ? a.global ? global->equiv(*a.global) : false : a.global == nullptr);
    }
void IR::DpdkDeclaration::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(global, "global");
}
void IR::DpdkDeclaration::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(global, "global");
}
void IR::DpdkDeclaration::validate() const {
#line 10920 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(global); }
void IR::DpdkDeclaration::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"global\" : " << this->global;
}
IR::DpdkDeclaration::DpdkDeclaration(JSONLoader & json) : Node(json) {
    json.load("global", global);
}
IR::Node * IR::DpdkDeclaration::fromJSON(JSONLoader & json) { return new DpdkDeclaration(json); }
IR::DpdkDeclaration::DpdkDeclaration(Util::SourceInfo srcInfo, const IR::Declaration* global) :
    Node(srcInfo), global(global)
    { validate(); }
IR::DpdkDeclaration::DpdkDeclaration(const IR::Declaration* global) :
    global(global)
    { validate(); }
bool IR::DpdkHeaderType::operator==(IR::DpdkHeaderType const & a) const {
        return Type_Header::operator==(static_cast<const Type_Header &>(a));
    }
bool IR::DpdkHeaderType::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Header::equiv(a_)) return false;
        return true;
    }
void IR::DpdkHeaderType::toJSON(JSONGenerator & json) const {
    Type_Header::toJSON(json);
}
IR::DpdkHeaderType::DpdkHeaderType(JSONLoader & json) : Type_Header(json) {
}
IR::Node * IR::DpdkHeaderType::fromJSON(JSONLoader & json) { return new DpdkHeaderType(json); }
IR::DpdkHeaderType::DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Header(srcInfo, name, annotations, typeParameters, fields)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Header(name, annotations, typeParameters, fields)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Header(srcInfo, name, typeParameters, fields)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Header(name, typeParameters, fields)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_Header(srcInfo, name, annotations, fields)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_Header(name, annotations, fields)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_Header(srcInfo, name, fields)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_Header(name, fields)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_Header(srcInfo, name, annotations, typeParameters)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_Header(name, annotations, typeParameters)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Header(srcInfo, name, typeParameters)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Header(name, typeParameters)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Type_Header(srcInfo, name, annotations)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(IR::ID name, const IR::Annotations* annotations) :
    Type_Header(name, annotations)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name) :
    Type_Header(srcInfo, name)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(IR::ID name) :
    Type_Header(name)
    { validate(); }
bool IR::DpdkStructType::operator==(IR::DpdkStructType const & a) const {
        return Type_Struct::operator==(static_cast<const Type_Struct &>(a));
    }
bool IR::DpdkStructType::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Struct::equiv(a_)) return false;
        return true;
    }
void IR::DpdkStructType::toJSON(JSONGenerator & json) const {
    Type_Struct::toJSON(json);
}
IR::DpdkStructType::DpdkStructType(JSONLoader & json) : Type_Struct(json) {
}
IR::Node * IR::DpdkStructType::fromJSON(JSONLoader & json) { return new DpdkStructType(json); }
IR::DpdkStructType::DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Struct(srcInfo, name, annotations, typeParameters, fields)
    { validate(); }
IR::DpdkStructType::DpdkStructType(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Struct(name, annotations, typeParameters, fields)
    { validate(); }
IR::DpdkStructType::DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Struct(srcInfo, name, typeParameters, fields)
    { validate(); }
IR::DpdkStructType::DpdkStructType(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Struct(name, typeParameters, fields)
    { validate(); }
IR::DpdkStructType::DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_Struct(srcInfo, name, annotations, fields)
    { validate(); }
IR::DpdkStructType::DpdkStructType(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_Struct(name, annotations, fields)
    { validate(); }
IR::DpdkStructType::DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_Struct(srcInfo, name, fields)
    { validate(); }
IR::DpdkStructType::DpdkStructType(IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_Struct(name, fields)
    { validate(); }
IR::DpdkStructType::DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_Struct(srcInfo, name, annotations, typeParameters)
    { validate(); }
IR::DpdkStructType::DpdkStructType(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_Struct(name, annotations, typeParameters)
    { validate(); }
IR::DpdkStructType::DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Struct(srcInfo, name, typeParameters)
    { validate(); }
IR::DpdkStructType::DpdkStructType(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Struct(name, typeParameters)
    { validate(); }
IR::DpdkStructType::DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Type_Struct(srcInfo, name, annotations)
    { validate(); }
IR::DpdkStructType::DpdkStructType(IR::ID name, const IR::Annotations* annotations) :
    Type_Struct(name, annotations)
    { validate(); }
IR::DpdkStructType::DpdkStructType(Util::SourceInfo srcInfo, IR::ID name) :
    Type_Struct(srcInfo, name)
    { validate(); }
IR::DpdkStructType::DpdkStructType(IR::ID name) :
    Type_Struct(name)
    { validate(); }
bool IR::DpdkAsmStatement::operator==(IR::DpdkAsmStatement const & a) const {
        return typeid(*this) == typeid(a);
    }
bool IR::DpdkAsmStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        return true;
    }
void IR::DpdkAsmStatement::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
}
IR::DpdkAsmStatement::DpdkAsmStatement(JSONLoader & json) : Node(json) {
}
IR::DpdkAsmStatement::DpdkAsmStatement(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::DpdkAsmStatement::DpdkAsmStatement() 
    { validate(); }
bool IR::DpdkAction::operator==(IR::DpdkAction const & a) const {
        return typeid(*this) == typeid(a)
        && statements == a.statements
        && name == a.name
        && para == a.para;
    }
bool IR::DpdkAction::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const DpdkAction &>(a_);
        return statements.equiv(a.statements)
        && name == a.name
        && para.equiv(a.para);
    }
void IR::DpdkAction::visit_children(Visitor & v) {
    Node::visit_children(v);
    statements.visit_children(v);
    para.visit_children(v);
}
void IR::DpdkAction::visit_children(Visitor & v) const {
    Node::visit_children(v);
    statements.visit_children(v);
    para.visit_children(v);
}
void IR::DpdkAction::validate() const {
#line 11104 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        statements.validate();
        para.validate(); }
void IR::DpdkAction::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
}
void IR::DpdkAction::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"statements\" : " << this->statements;
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"para\" : " << this->para;
}
IR::DpdkAction::DpdkAction(JSONLoader & json) : Node(json) {
    json.load("statements", statements);
    json.load("name", name);
    json.load("para", para);
}
IR::Node * IR::DpdkAction::fromJSON(JSONLoader & json) { return new DpdkAction(json); }
IR::DpdkAction::DpdkAction(Util::SourceInfo srcInfo, IR::IndexedVector<IR::DpdkAsmStatement> statements, cstring name, IR::ParameterList para) :
    Node(srcInfo), statements(statements), name(name), para(para)
    { validate(); }
IR::DpdkAction::DpdkAction(IR::IndexedVector<IR::DpdkAsmStatement> statements, cstring name, IR::ParameterList para) :
    statements(statements), name(name), para(para)
    { validate(); }
bool IR::DpdkTable::operator==(IR::DpdkTable const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && match_keys == a.match_keys
        && actions == a.actions
        && default_action == a.default_action
        && properties == a.properties;
    }
bool IR::DpdkTable::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const DpdkTable &>(a_);
        return name == a.name
        && (match_keys ? a.match_keys ? match_keys->equiv(*a.match_keys) : false : a.match_keys == nullptr)
        && (actions ? a.actions ? actions->equiv(*a.actions) : false : a.actions == nullptr)
        && (default_action ? a.default_action ? default_action->equiv(*a.default_action) : false : a.default_action == nullptr)
        && (properties ? a.properties ? properties->equiv(*a.properties) : false : a.properties == nullptr);
    }
void IR::DpdkTable::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(match_keys, "match_keys");
    v.visit(actions, "actions");
    v.visit(default_action, "default_action");
    v.visit(properties, "properties");
}
void IR::DpdkTable::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(match_keys, "match_keys");
    v.visit(actions, "actions");
    v.visit(default_action, "default_action");
    v.visit(properties, "properties");
}
void IR::DpdkTable::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
}
void IR::DpdkTable::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"match_keys\" : " << this->match_keys;
    json << "," << std::endl << json.indent << "\"actions\" : " << this->actions;
    json << "," << std::endl << json.indent << "\"default_action\" : " << this->default_action;
    json << "," << std::endl << json.indent << "\"properties\" : " << this->properties;
}
IR::DpdkTable::DpdkTable(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("match_keys", match_keys);
    json.load("actions", actions);
    json.load("default_action", default_action);
    json.load("properties", properties);
}
IR::Node * IR::DpdkTable::fromJSON(JSONLoader & json) { return new DpdkTable(json); }
IR::DpdkTable::DpdkTable(Util::SourceInfo srcInfo, cstring name, const IR::Key* match_keys, const IR::ActionList* actions, const IR::Expression* default_action, const IR::TableProperties* properties) :
    Node(srcInfo), name(name), match_keys(match_keys), actions(actions), default_action(default_action), properties(properties)
    { validate(); }
IR::DpdkTable::DpdkTable(cstring name, const IR::Key* match_keys, const IR::ActionList* actions, const IR::Expression* default_action, const IR::TableProperties* properties) :
    name(name), match_keys(match_keys), actions(actions), default_action(default_action), properties(properties)
    { validate(); }
bool IR::DpdkAsmProgram::operator==(IR::DpdkAsmProgram const & a) const {
        return typeid(*this) == typeid(a)
        && headerType == a.headerType
        && structType == a.structType
        && actions == a.actions
        && tables == a.tables
        && statements == a.statements
        && globals == a.globals;
    }
bool IR::DpdkAsmProgram::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const DpdkAsmProgram &>(a_);
        return headerType.equiv(a.headerType)
        && structType.equiv(a.structType)
        && actions.equiv(a.actions)
        && tables.equiv(a.tables)
        && statements.equiv(a.statements)
        && globals.equiv(a.globals);
    }
void IR::DpdkAsmProgram::visit_children(Visitor & v) {
    Node::visit_children(v);
    headerType.visit_children(v);
    structType.visit_children(v);
    actions.visit_children(v);
    tables.visit_children(v);
    statements.visit_children(v);
    globals.visit_children(v);
}
void IR::DpdkAsmProgram::visit_children(Visitor & v) const {
    Node::visit_children(v);
    headerType.visit_children(v);
    structType.visit_children(v);
    actions.visit_children(v);
    tables.visit_children(v);
    statements.visit_children(v);
    globals.visit_children(v);
}
void IR::DpdkAsmProgram::validate() const {
#line 11227 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        headerType.validate();
        structType.validate();
        actions.validate();
        tables.validate();
        statements.validate();
        globals.validate(); }
void IR::DpdkAsmProgram::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"headerType\" : " << this->headerType;
    json << "," << std::endl << json.indent << "\"structType\" : " << this->structType;
    json << "," << std::endl << json.indent << "\"actions\" : " << this->actions;
    json << "," << std::endl << json.indent << "\"tables\" : " << this->tables;
    json << "," << std::endl << json.indent << "\"statements\" : " << this->statements;
    json << "," << std::endl << json.indent << "\"globals\" : " << this->globals;
}
IR::DpdkAsmProgram::DpdkAsmProgram(JSONLoader & json) : Node(json) {
    json.load("headerType", headerType);
    json.load("structType", structType);
    json.load("actions", actions);
    json.load("tables", tables);
    json.load("statements", statements);
    json.load("globals", globals);
}
IR::Node * IR::DpdkAsmProgram::fromJSON(JSONLoader & json) { return new DpdkAsmProgram(json); }
IR::DpdkAsmProgram::DpdkAsmProgram(Util::SourceInfo srcInfo, IR::IndexedVector<IR::DpdkHeaderType> headerType, IR::IndexedVector<IR::DpdkStructType> structType, IR::IndexedVector<IR::DpdkAction> actions, IR::IndexedVector<IR::DpdkTable> tables, IR::IndexedVector<IR::DpdkAsmStatement> statements, IR::IndexedVector<IR::DpdkDeclaration> globals) :
    Node(srcInfo), headerType(headerType), structType(structType), actions(actions), tables(tables), statements(statements), globals(globals)
    { validate(); }
IR::DpdkAsmProgram::DpdkAsmProgram(IR::IndexedVector<IR::DpdkHeaderType> headerType, IR::IndexedVector<IR::DpdkStructType> structType, IR::IndexedVector<IR::DpdkAction> actions, IR::IndexedVector<IR::DpdkTable> tables, IR::IndexedVector<IR::DpdkAsmStatement> statements, IR::IndexedVector<IR::DpdkDeclaration> globals) :
    headerType(headerType), structType(structType), actions(actions), tables(tables), statements(statements), globals(globals)
    { validate(); }
bool IR::DpdkListStatement::operator==(IR::DpdkListStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && name == a.name
        && statements == a.statements;
    }
bool IR::DpdkListStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkListStatement &>(a_);
        return name == a.name
        && statements.equiv(a.statements);
    }
void IR::DpdkListStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    statements.visit_children(v);
}
void IR::DpdkListStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    statements.visit_children(v);
}
void IR::DpdkListStatement::validate() const {
#line 11280 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        statements.validate(); }
void IR::DpdkListStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " name=" << name;
}
void IR::DpdkListStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"statements\" : " << this->statements;
}
IR::DpdkListStatement::DpdkListStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("name", name);
    json.load("statements", statements);
}
IR::Node * IR::DpdkListStatement::fromJSON(JSONLoader & json) { return new DpdkListStatement(json); }
IR::DpdkListStatement::DpdkListStatement(Util::SourceInfo srcInfo, cstring name, IR::IndexedVector<IR::DpdkAsmStatement> statements) :
    DpdkAsmStatement(srcInfo), name(name), statements(statements)
    { validate(); }
IR::DpdkListStatement::DpdkListStatement(cstring name, IR::IndexedVector<IR::DpdkAsmStatement> statements) :
    name(name), statements(statements)
    { validate(); }
IR::DpdkListStatement::DpdkListStatement(Util::SourceInfo srcInfo, IR::IndexedVector<IR::DpdkAsmStatement> statements) :
    DpdkAsmStatement(srcInfo), statements(statements)
    { validate(); }
IR::DpdkListStatement::DpdkListStatement(IR::IndexedVector<IR::DpdkAsmStatement> statements) :
    statements(statements)
    { validate(); }
IR::DpdkListStatement::DpdkListStatement(Util::SourceInfo srcInfo, cstring name) :
    DpdkAsmStatement(srcInfo), name(name)
    { validate(); }
IR::DpdkListStatement::DpdkListStatement(cstring name) :
    name(name)
    { validate(); }
IR::DpdkListStatement::DpdkListStatement(Util::SourceInfo srcInfo) :
    DpdkAsmStatement(srcInfo)
    { validate(); }
IR::DpdkListStatement::DpdkListStatement() 
    { validate(); }
bool IR::DpdkApplyStatement::operator==(IR::DpdkApplyStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && table == a.table;
    }
bool IR::DpdkApplyStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkApplyStatement &>(a_);
        return table == a.table;
    }
void IR::DpdkApplyStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " table=" << table;
}
void IR::DpdkApplyStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"table\" : " << this->table;
}
IR::DpdkApplyStatement::DpdkApplyStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("table", table);
}
IR::Node * IR::DpdkApplyStatement::fromJSON(JSONLoader & json) { return new DpdkApplyStatement(json); }
IR::DpdkApplyStatement::DpdkApplyStatement(Util::SourceInfo srcInfo, cstring table) :
    DpdkAsmStatement(srcInfo), table(table)
    { validate(); }
IR::DpdkApplyStatement::DpdkApplyStatement(cstring table) :
    table(table)
    { validate(); }
bool IR::DpdkEmitStatement::operator==(IR::DpdkEmitStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && header == a.header;
    }
bool IR::DpdkEmitStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkEmitStatement &>(a_);
        return (header ? a.header ? header->equiv(*a.header) : false : a.header == nullptr);
    }
void IR::DpdkEmitStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(header, "header");
}
void IR::DpdkEmitStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(header, "header");
}
void IR::DpdkEmitStatement::validate() const {
#line 11367 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(header); }
void IR::DpdkEmitStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"header\" : " << this->header;
}
IR::DpdkEmitStatement::DpdkEmitStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("header", header);
}
IR::Node * IR::DpdkEmitStatement::fromJSON(JSONLoader & json) { return new DpdkEmitStatement(json); }
IR::DpdkEmitStatement::DpdkEmitStatement(Util::SourceInfo srcInfo, const IR::Expression* header) :
    DpdkAsmStatement(srcInfo), header(header)
    { validate(); }
IR::DpdkEmitStatement::DpdkEmitStatement(const IR::Expression* header) :
    header(header)
    { validate(); }
bool IR::DpdkExtractStatement::operator==(IR::DpdkExtractStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && header == a.header;
    }
bool IR::DpdkExtractStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkExtractStatement &>(a_);
        return (header ? a.header ? header->equiv(*a.header) : false : a.header == nullptr);
    }
void IR::DpdkExtractStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(header, "header");
}
void IR::DpdkExtractStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(header, "header");
}
void IR::DpdkExtractStatement::validate() const {
#line 11403 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(header); }
void IR::DpdkExtractStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"header\" : " << this->header;
}
IR::DpdkExtractStatement::DpdkExtractStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("header", header);
}
IR::Node * IR::DpdkExtractStatement::fromJSON(JSONLoader & json) { return new DpdkExtractStatement(json); }
IR::DpdkExtractStatement::DpdkExtractStatement(Util::SourceInfo srcInfo, const IR::Expression* header) :
    DpdkAsmStatement(srcInfo), header(header)
    { validate(); }
IR::DpdkExtractStatement::DpdkExtractStatement(const IR::Expression* header) :
    header(header)
    { validate(); }
#line 84 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkJmpStatement::DpdkJmpStatement(cstring instruction, cstring l) :
        instruction(instruction), label(l.toUpper()) { }
#line 11423 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkJmpStatement::operator==(IR::DpdkJmpStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && instruction == a.instruction
        && label == a.label;
    }
bool IR::DpdkJmpStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkJmpStatement &>(a_);
        return instruction == a.instruction
        && label == a.label;
    }
void IR::DpdkJmpStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " instruction=" << instruction;
        out << " label=" << label;
}
void IR::DpdkJmpStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"instruction\" : " << this->instruction;
    json << "," << std::endl << json.indent << "\"label\" : " << this->label;
}
IR::DpdkJmpStatement::DpdkJmpStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("instruction", instruction);
    json.load("label", label);
}
#line 90 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkJmpLabelStatement::DpdkJmpLabelStatement(cstring label) :
        DpdkJmpStatement("jmp", label) { }
#line 11453 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkJmpLabelStatement::operator==(IR::DpdkJmpLabelStatement const & a) const {
        return DpdkJmpStatement::operator==(static_cast<const DpdkJmpStatement &>(a));
    }
bool IR::DpdkJmpLabelStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpLabelStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpStatement::toJSON(json);
}
IR::DpdkJmpLabelStatement::DpdkJmpLabelStatement(JSONLoader & json) : DpdkJmpStatement(json) {
}
IR::Node * IR::DpdkJmpLabelStatement::fromJSON(JSONLoader & json) { return new DpdkJmpLabelStatement(json); }
#line 97 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkJmpHitStatement::DpdkJmpHitStatement(cstring label) :
        DpdkJmpStatement("jmph", label) { }
#line 11471 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkJmpHitStatement::operator==(IR::DpdkJmpHitStatement const & a) const {
        return DpdkJmpStatement::operator==(static_cast<const DpdkJmpStatement &>(a));
    }
bool IR::DpdkJmpHitStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpHitStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpStatement::toJSON(json);
}
IR::DpdkJmpHitStatement::DpdkJmpHitStatement(JSONLoader & json) : DpdkJmpStatement(json) {
}
IR::Node * IR::DpdkJmpHitStatement::fromJSON(JSONLoader & json) { return new DpdkJmpHitStatement(json); }
#line 104 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkJmpMissStatement::DpdkJmpMissStatement(cstring label) :
        DpdkJmpStatement("jmpnh", label) { }
#line 11489 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkJmpMissStatement::operator==(IR::DpdkJmpMissStatement const & a) const {
        return DpdkJmpStatement::operator==(static_cast<const DpdkJmpStatement &>(a));
    }
bool IR::DpdkJmpMissStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpMissStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpStatement::toJSON(json);
}
IR::DpdkJmpMissStatement::DpdkJmpMissStatement(JSONLoader & json) : DpdkJmpStatement(json) {
}
IR::Node * IR::DpdkJmpMissStatement::fromJSON(JSONLoader & json) { return new DpdkJmpMissStatement(json); }
#line 112 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkJmpHeaderStatement::DpdkJmpHeaderStatement(cstring instruction, cstring label, const IR::Expression* hdr) :
        DpdkJmpStatement(instruction, label), header(hdr) { }
#line 11507 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkJmpHeaderStatement::operator==(IR::DpdkJmpHeaderStatement const & a) const {
        return DpdkJmpStatement::operator==(static_cast<const DpdkJmpStatement &>(a))
        && header == a.header;
    }
bool IR::DpdkJmpHeaderStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkJmpHeaderStatement &>(a_);
        return (header ? a.header ? header->equiv(*a.header) : false : a.header == nullptr);
    }
void IR::DpdkJmpHeaderStatement::visit_children(Visitor & v) {
    DpdkJmpStatement::visit_children(v);
    v.visit(header, "header");
}
void IR::DpdkJmpHeaderStatement::visit_children(Visitor & v) const {
    DpdkJmpStatement::visit_children(v);
    v.visit(header, "header");
}
void IR::DpdkJmpHeaderStatement::validate() const {
#line 11527 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(header); }
void IR::DpdkJmpHeaderStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"header\" : " << this->header;
}
IR::DpdkJmpHeaderStatement::DpdkJmpHeaderStatement(JSONLoader & json) : DpdkJmpStatement(json) {
    json.load("header", header);
}
#line 118 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkJmpIfInvalidStatement::DpdkJmpIfInvalidStatement(cstring label, const IR::Expression* hdr) :
        DpdkJmpHeaderStatement("jmpnv", label, hdr) { }
#line 11540 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkJmpIfInvalidStatement::operator==(IR::DpdkJmpIfInvalidStatement const & a) const {
        return DpdkJmpHeaderStatement::operator==(static_cast<const DpdkJmpHeaderStatement &>(a));
    }
bool IR::DpdkJmpIfInvalidStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpHeaderStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpIfInvalidStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpHeaderStatement::toJSON(json);
}
IR::DpdkJmpIfInvalidStatement::DpdkJmpIfInvalidStatement(JSONLoader & json) : DpdkJmpHeaderStatement(json) {
}
IR::Node * IR::DpdkJmpIfInvalidStatement::fromJSON(JSONLoader & json) { return new DpdkJmpIfInvalidStatement(json); }
#line 125 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkJmpIfValidStatement::DpdkJmpIfValidStatement(cstring label, const IR::Expression* hdr) :
        DpdkJmpHeaderStatement("jmpv", label, hdr) { }
#line 11558 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkJmpIfValidStatement::operator==(IR::DpdkJmpIfValidStatement const & a) const {
        return DpdkJmpHeaderStatement::operator==(static_cast<const DpdkJmpHeaderStatement &>(a));
    }
bool IR::DpdkJmpIfValidStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpHeaderStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpIfValidStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpHeaderStatement::toJSON(json);
}
IR::DpdkJmpIfValidStatement::DpdkJmpIfValidStatement(JSONLoader & json) : DpdkJmpHeaderStatement(json) {
}
IR::Node * IR::DpdkJmpIfValidStatement::fromJSON(JSONLoader & json) { return new DpdkJmpIfValidStatement(json); }
#line 134 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkJmpCondStatement::DpdkJmpCondStatement(cstring instruction, cstring label, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkJmpStatement(instruction, label), src1(src1), src2(src2) { }
#line 11576 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkJmpCondStatement::operator==(IR::DpdkJmpCondStatement const & a) const {
        return DpdkJmpStatement::operator==(static_cast<const DpdkJmpStatement &>(a))
        && src1 == a.src1
        && src2 == a.src2;
    }
bool IR::DpdkJmpCondStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkJmpCondStatement &>(a_);
        return (src1 ? a.src1 ? src1->equiv(*a.src1) : false : a.src1 == nullptr)
        && (src2 ? a.src2 ? src2->equiv(*a.src2) : false : a.src2 == nullptr);
    }
void IR::DpdkJmpCondStatement::visit_children(Visitor & v) {
    DpdkJmpStatement::visit_children(v);
    v.visit(src1, "src1");
    v.visit(src2, "src2");
}
void IR::DpdkJmpCondStatement::visit_children(Visitor & v) const {
    DpdkJmpStatement::visit_children(v);
    v.visit(src1, "src1");
    v.visit(src2, "src2");
}
void IR::DpdkJmpCondStatement::validate() const {
#line 11600 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(src1);
        CHECK_NULL(src2); }
void IR::DpdkJmpCondStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"src1\" : " << this->src1;
    json << "," << std::endl << json.indent << "\"src2\" : " << this->src2;
}
IR::DpdkJmpCondStatement::DpdkJmpCondStatement(JSONLoader & json) : DpdkJmpStatement(json) {
    json.load("src1", src1);
    json.load("src2", src2);
}
#line 141 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkJmpEqualStatement::DpdkJmpEqualStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkJmpCondStatement("jmpeq", label, src1, src2) { }
#line 11616 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkJmpEqualStatement::operator==(IR::DpdkJmpEqualStatement const & a) const {
        return DpdkJmpCondStatement::operator==(static_cast<const DpdkJmpCondStatement &>(a));
    }
bool IR::DpdkJmpEqualStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpCondStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpEqualStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpCondStatement::toJSON(json);
}
IR::DpdkJmpEqualStatement::DpdkJmpEqualStatement(JSONLoader & json) : DpdkJmpCondStatement(json) {
}
IR::Node * IR::DpdkJmpEqualStatement::fromJSON(JSONLoader & json) { return new DpdkJmpEqualStatement(json); }
#line 147 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkJmpNotEqualStatement::DpdkJmpNotEqualStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkJmpCondStatement("jmpneq", label, src1, src2) { }
#line 11634 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkJmpNotEqualStatement::operator==(IR::DpdkJmpNotEqualStatement const & a) const {
        return DpdkJmpCondStatement::operator==(static_cast<const DpdkJmpCondStatement &>(a));
    }
bool IR::DpdkJmpNotEqualStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpCondStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpNotEqualStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpCondStatement::toJSON(json);
}
IR::DpdkJmpNotEqualStatement::DpdkJmpNotEqualStatement(JSONLoader & json) : DpdkJmpCondStatement(json) {
}
IR::Node * IR::DpdkJmpNotEqualStatement::fromJSON(JSONLoader & json) { return new DpdkJmpNotEqualStatement(json); }
#line 154 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkJmpGreaterEqualStatement::DpdkJmpGreaterEqualStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkJmpCondStatement("jmpge", label, src1, src2) { }
#line 11652 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkJmpGreaterEqualStatement::operator==(IR::DpdkJmpGreaterEqualStatement const & a) const {
        return DpdkJmpCondStatement::operator==(static_cast<const DpdkJmpCondStatement &>(a));
    }
bool IR::DpdkJmpGreaterEqualStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpCondStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpGreaterEqualStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpCondStatement::toJSON(json);
}
IR::DpdkJmpGreaterEqualStatement::DpdkJmpGreaterEqualStatement(JSONLoader & json) : DpdkJmpCondStatement(json) {
}
IR::Node * IR::DpdkJmpGreaterEqualStatement::fromJSON(JSONLoader & json) { return new DpdkJmpGreaterEqualStatement(json); }
#line 161 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkJmpGreaterStatement::DpdkJmpGreaterStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkJmpCondStatement("jmpgt", label, src1, src2) { }
#line 11670 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkJmpGreaterStatement::operator==(IR::DpdkJmpGreaterStatement const & a) const {
        return DpdkJmpCondStatement::operator==(static_cast<const DpdkJmpCondStatement &>(a));
    }
bool IR::DpdkJmpGreaterStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpCondStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpGreaterStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpCondStatement::toJSON(json);
}
IR::DpdkJmpGreaterStatement::DpdkJmpGreaterStatement(JSONLoader & json) : DpdkJmpCondStatement(json) {
}
IR::Node * IR::DpdkJmpGreaterStatement::fromJSON(JSONLoader & json) { return new DpdkJmpGreaterStatement(json); }
#line 168 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkJmpLessOrEqualStatement::DpdkJmpLessOrEqualStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkJmpCondStatement("jmple", label, src1, src2) { }
#line 11688 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkJmpLessOrEqualStatement::operator==(IR::DpdkJmpLessOrEqualStatement const & a) const {
        return DpdkJmpCondStatement::operator==(static_cast<const DpdkJmpCondStatement &>(a));
    }
bool IR::DpdkJmpLessOrEqualStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpCondStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpLessOrEqualStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpCondStatement::toJSON(json);
}
IR::DpdkJmpLessOrEqualStatement::DpdkJmpLessOrEqualStatement(JSONLoader & json) : DpdkJmpCondStatement(json) {
}
IR::Node * IR::DpdkJmpLessOrEqualStatement::fromJSON(JSONLoader & json) { return new DpdkJmpLessOrEqualStatement(json); }
#line 175 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkJmpLessStatement::DpdkJmpLessStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkJmpCondStatement("jmplt", label, src1, src2) { }
#line 11706 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkJmpLessStatement::operator==(IR::DpdkJmpLessStatement const & a) const {
        return DpdkJmpCondStatement::operator==(static_cast<const DpdkJmpCondStatement &>(a));
    }
bool IR::DpdkJmpLessStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpCondStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpLessStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpCondStatement::toJSON(json);
}
IR::DpdkJmpLessStatement::DpdkJmpLessStatement(JSONLoader & json) : DpdkJmpCondStatement(json) {
}
IR::Node * IR::DpdkJmpLessStatement::fromJSON(JSONLoader & json) { return new DpdkJmpLessStatement(json); }
bool IR::DpdkRxStatement::operator==(IR::DpdkRxStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a));
    }
bool IR::DpdkRxStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkRxStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
}
IR::DpdkRxStatement::DpdkRxStatement(JSONLoader & json) : DpdkAsmStatement(json) {
}
IR::Node * IR::DpdkRxStatement::fromJSON(JSONLoader & json) { return new DpdkRxStatement(json); }
IR::DpdkRxStatement::DpdkRxStatement(Util::SourceInfo srcInfo) :
    DpdkAsmStatement(srcInfo)
    { validate(); }
IR::DpdkRxStatement::DpdkRxStatement() 
    { validate(); }
bool IR::DpdkTxStatement::operator==(IR::DpdkTxStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a));
    }
bool IR::DpdkTxStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkTxStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
}
IR::DpdkTxStatement::DpdkTxStatement(JSONLoader & json) : DpdkAsmStatement(json) {
}
IR::Node * IR::DpdkTxStatement::fromJSON(JSONLoader & json) { return new DpdkTxStatement(json); }
IR::DpdkTxStatement::DpdkTxStatement(Util::SourceInfo srcInfo) :
    DpdkAsmStatement(srcInfo)
    { validate(); }
IR::DpdkTxStatement::DpdkTxStatement() 
    { validate(); }
#line 193 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkAssignmentStatement::DpdkAssignmentStatement(cstring instruction, const IR::Expression* dst) :
        instruction(instruction), dst(dst) { }
#line 11762 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkAssignmentStatement::operator==(IR::DpdkAssignmentStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && instruction == a.instruction
        && dst == a.dst;
    }
bool IR::DpdkAssignmentStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkAssignmentStatement &>(a_);
        return instruction == a.instruction
        && (dst ? a.dst ? dst->equiv(*a.dst) : false : a.dst == nullptr);
    }
void IR::DpdkAssignmentStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(dst, "dst");
}
void IR::DpdkAssignmentStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(dst, "dst");
}
void IR::DpdkAssignmentStatement::validate() const {
#line 11784 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(dst); }
void IR::DpdkAssignmentStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " instruction=" << instruction;
}
void IR::DpdkAssignmentStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"instruction\" : " << this->instruction;
    json << "," << std::endl << json.indent << "\"dst\" : " << this->dst;
}
IR::DpdkAssignmentStatement::DpdkAssignmentStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("instruction", instruction);
    json.load("dst", dst);
}
#line 201 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkUnaryStatement::DpdkUnaryStatement(cstring instruction, const IR::Expression* dst, const IR::Expression* src) :
        DpdkAssignmentStatement(instruction, dst), src(src) { }
#line 11803 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkUnaryStatement::operator==(IR::DpdkUnaryStatement const & a) const {
        return DpdkAssignmentStatement::operator==(static_cast<const DpdkAssignmentStatement &>(a))
        && src == a.src;
    }
bool IR::DpdkUnaryStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAssignmentStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkUnaryStatement &>(a_);
        return (src ? a.src ? src->equiv(*a.src) : false : a.src == nullptr);
    }
void IR::DpdkUnaryStatement::visit_children(Visitor & v) {
    DpdkAssignmentStatement::visit_children(v);
    v.visit(src, "src");
}
void IR::DpdkUnaryStatement::visit_children(Visitor & v) const {
    DpdkAssignmentStatement::visit_children(v);
    v.visit(src, "src");
}
void IR::DpdkUnaryStatement::validate() const {
#line 11823 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(src); }
void IR::DpdkUnaryStatement::toJSON(JSONGenerator & json) const {
    DpdkAssignmentStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"src\" : " << this->src;
}
IR::DpdkUnaryStatement::DpdkUnaryStatement(JSONLoader & json) : DpdkAssignmentStatement(json) {
    json.load("src", src);
}
#line 208 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkMovStatement::DpdkMovStatement(const IR::Expression* dst, const IR::Expression* src) :
        DpdkUnaryStatement("mov", dst, src) { }
#line 11836 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkMovStatement::operator==(IR::DpdkMovStatement const & a) const {
        return DpdkUnaryStatement::operator==(static_cast<const DpdkUnaryStatement &>(a));
    }
bool IR::DpdkMovStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkUnaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkMovStatement::toJSON(JSONGenerator & json) const {
    DpdkUnaryStatement::toJSON(json);
}
IR::DpdkMovStatement::DpdkMovStatement(JSONLoader & json) : DpdkUnaryStatement(json) {
}
IR::Node * IR::DpdkMovStatement::fromJSON(JSONLoader & json) { return new DpdkMovStatement(json); }
#line 215 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkNegStatement::DpdkNegStatement(const IR::Expression* dst, const IR::Expression* src) :
        DpdkUnaryStatement("neg", dst, src) { }
#line 11854 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkNegStatement::operator==(IR::DpdkNegStatement const & a) const {
        return DpdkUnaryStatement::operator==(static_cast<const DpdkUnaryStatement &>(a));
    }
bool IR::DpdkNegStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkUnaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkNegStatement::toJSON(JSONGenerator & json) const {
    DpdkUnaryStatement::toJSON(json);
}
IR::DpdkNegStatement::DpdkNegStatement(JSONLoader & json) : DpdkUnaryStatement(json) {
}
IR::Node * IR::DpdkNegStatement::fromJSON(JSONLoader & json) { return new DpdkNegStatement(json); }
#line 222 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkCmplStatement::DpdkCmplStatement(const IR::Expression* dst, const IR::Expression* src) :
        DpdkUnaryStatement("compl", dst, src) { }
#line 11872 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkCmplStatement::operator==(IR::DpdkCmplStatement const & a) const {
        return DpdkUnaryStatement::operator==(static_cast<const DpdkUnaryStatement &>(a));
    }
bool IR::DpdkCmplStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkUnaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkCmplStatement::toJSON(JSONGenerator & json) const {
    DpdkUnaryStatement::toJSON(json);
}
IR::DpdkCmplStatement::DpdkCmplStatement(JSONLoader & json) : DpdkUnaryStatement(json) {
}
IR::Node * IR::DpdkCmplStatement::fromJSON(JSONLoader & json) { return new DpdkCmplStatement(json); }
#line 229 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkLNotStatement::DpdkLNotStatement(const IR::Expression* dst, const IR::Expression* src) :
        DpdkUnaryStatement("lnot", dst, src) { }
#line 11890 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkLNotStatement::operator==(IR::DpdkLNotStatement const & a) const {
        return DpdkUnaryStatement::operator==(static_cast<const DpdkUnaryStatement &>(a));
    }
bool IR::DpdkLNotStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkUnaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkLNotStatement::toJSON(JSONGenerator & json) const {
    DpdkUnaryStatement::toJSON(json);
}
IR::DpdkLNotStatement::DpdkLNotStatement(JSONLoader & json) : DpdkUnaryStatement(json) {
}
IR::Node * IR::DpdkLNotStatement::fromJSON(JSONLoader & json) { return new DpdkLNotStatement(json); }
#line 238 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkBinaryStatement::DpdkBinaryStatement(cstring instruction, const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkAssignmentStatement(instruction, dst), src1(src1), src2(src2) { }
#line 11908 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkBinaryStatement::operator==(IR::DpdkBinaryStatement const & a) const {
        return DpdkAssignmentStatement::operator==(static_cast<const DpdkAssignmentStatement &>(a))
        && src1 == a.src1
        && src2 == a.src2;
    }
bool IR::DpdkBinaryStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAssignmentStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkBinaryStatement &>(a_);
        return (src1 ? a.src1 ? src1->equiv(*a.src1) : false : a.src1 == nullptr)
        && (src2 ? a.src2 ? src2->equiv(*a.src2) : false : a.src2 == nullptr);
    }
void IR::DpdkBinaryStatement::visit_children(Visitor & v) {
    DpdkAssignmentStatement::visit_children(v);
    v.visit(src1, "src1");
    v.visit(src2, "src2");
}
void IR::DpdkBinaryStatement::visit_children(Visitor & v) const {
    DpdkAssignmentStatement::visit_children(v);
    v.visit(src1, "src1");
    v.visit(src2, "src2");
}
void IR::DpdkBinaryStatement::validate() const {
#line 11932 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(src1);
        CHECK_NULL(src2); }
void IR::DpdkBinaryStatement::toJSON(JSONGenerator & json) const {
    DpdkAssignmentStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"src1\" : " << this->src1;
    json << "," << std::endl << json.indent << "\"src2\" : " << this->src2;
}
IR::DpdkBinaryStatement::DpdkBinaryStatement(JSONLoader & json) : DpdkAssignmentStatement(json) {
    json.load("src1", src1);
    json.load("src2", src2);
}
#line 245 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkAddStatement::DpdkAddStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("add", dst, src1, src2) { }
#line 11948 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkAddStatement::operator==(IR::DpdkAddStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkAddStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkAddStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkAddStatement::DpdkAddStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkAddStatement::fromJSON(JSONLoader & json) { return new DpdkAddStatement(json); }
#line 252 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkAndStatement::DpdkAndStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("and", dst, src1, src2) { }
#line 11966 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkAndStatement::operator==(IR::DpdkAndStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkAndStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkAndStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkAndStatement::DpdkAndStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkAndStatement::fromJSON(JSONLoader & json) { return new DpdkAndStatement(json); }
#line 259 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkShlStatement::DpdkShlStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("shl", dst, src1, src2) { }
#line 11984 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkShlStatement::operator==(IR::DpdkShlStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkShlStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkShlStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkShlStatement::DpdkShlStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkShlStatement::fromJSON(JSONLoader & json) { return new DpdkShlStatement(json); }
#line 266 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkShrStatement::DpdkShrStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("shr", dst, src1, src2) { }
#line 12002 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkShrStatement::operator==(IR::DpdkShrStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkShrStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkShrStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkShrStatement::DpdkShrStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkShrStatement::fromJSON(JSONLoader & json) { return new DpdkShrStatement(json); }
#line 273 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkSubStatement::DpdkSubStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("sub", dst, src1, src2) { }
#line 12020 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkSubStatement::operator==(IR::DpdkSubStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkSubStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkSubStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkSubStatement::DpdkSubStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkSubStatement::fromJSON(JSONLoader & json) { return new DpdkSubStatement(json); }
#line 280 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkOrStatement::DpdkOrStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("or", dst, src1, src2) { }
#line 12038 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkOrStatement::operator==(IR::DpdkOrStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkOrStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkOrStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkOrStatement::DpdkOrStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkOrStatement::fromJSON(JSONLoader & json) { return new DpdkOrStatement(json); }
#line 287 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkEquStatement::DpdkEquStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("equ", dst, src1, src2) { }
#line 12056 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkEquStatement::operator==(IR::DpdkEquStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkEquStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkEquStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkEquStatement::DpdkEquStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkEquStatement::fromJSON(JSONLoader & json) { return new DpdkEquStatement(json); }
#line 294 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkXorStatement::DpdkXorStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("xor", dst, src1, src2) { }
#line 12074 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkXorStatement::operator==(IR::DpdkXorStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkXorStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkXorStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkXorStatement::DpdkXorStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkXorStatement::fromJSON(JSONLoader & json) { return new DpdkXorStatement(json); }
#line 301 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkCmpStatement::DpdkCmpStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("cmp", dst, src1, src2) { }
#line 12092 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkCmpStatement::operator==(IR::DpdkCmpStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkCmpStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkCmpStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkCmpStatement::DpdkCmpStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkCmpStatement::fromJSON(JSONLoader & json) { return new DpdkCmpStatement(json); }
#line 308 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkLAndStatement::DpdkLAndStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("land", dst, src1, src2) { }
#line 12110 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkLAndStatement::operator==(IR::DpdkLAndStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkLAndStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkLAndStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkLAndStatement::DpdkLAndStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkLAndStatement::fromJSON(JSONLoader & json) { return new DpdkLAndStatement(json); }
#line 315 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkLeqStatement::DpdkLeqStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("leq", dst, src1, src2) { }
#line 12128 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkLeqStatement::operator==(IR::DpdkLeqStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkLeqStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkLeqStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkLeqStatement::DpdkLeqStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkLeqStatement::fromJSON(JSONLoader & json) { return new DpdkLeqStatement(json); }
#line 322 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkLssStatement::DpdkLssStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("lss", dst, src1, src2) { }
#line 12146 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkLssStatement::operator==(IR::DpdkLssStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkLssStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkLssStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkLssStatement::DpdkLssStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkLssStatement::fromJSON(JSONLoader & json) { return new DpdkLssStatement(json); }
#line 329 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkGrtStatement::DpdkGrtStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("grt", dst, src1, src2) { }
#line 12164 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkGrtStatement::operator==(IR::DpdkGrtStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkGrtStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkGrtStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkGrtStatement::DpdkGrtStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkGrtStatement::fromJSON(JSONLoader & json) { return new DpdkGrtStatement(json); }
#line 336 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkGeqStatement::DpdkGeqStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("geq", dst, src1, src2) { }
#line 12182 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkGeqStatement::operator==(IR::DpdkGeqStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkGeqStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkGeqStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkGeqStatement::DpdkGeqStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkGeqStatement::fromJSON(JSONLoader & json) { return new DpdkGeqStatement(json); }
#line 343 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkNeqStatement::DpdkNeqStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("neq", dst, src1, src2) { }
#line 12200 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkNeqStatement::operator==(IR::DpdkNeqStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkNeqStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkNeqStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkNeqStatement::DpdkNeqStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkNeqStatement::fromJSON(JSONLoader & json) { return new DpdkNeqStatement(json); }
bool IR::DpdkExternObjStatement::operator==(IR::DpdkExternObjStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && methodCall == a.methodCall;
    }
bool IR::DpdkExternObjStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkExternObjStatement &>(a_);
        return (methodCall ? a.methodCall ? methodCall->equiv(*a.methodCall) : false : a.methodCall == nullptr);
    }
void IR::DpdkExternObjStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(methodCall, "methodCall");
}
void IR::DpdkExternObjStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(methodCall, "methodCall");
}
void IR::DpdkExternObjStatement::validate() const {
#line 12234 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(methodCall); }
void IR::DpdkExternObjStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"methodCall\" : " << this->methodCall;
}
IR::DpdkExternObjStatement::DpdkExternObjStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("methodCall", methodCall);
}
IR::Node * IR::DpdkExternObjStatement::fromJSON(JSONLoader & json) { return new DpdkExternObjStatement(json); }
IR::DpdkExternObjStatement::DpdkExternObjStatement(Util::SourceInfo srcInfo, const IR::Expression* methodCall) :
    DpdkAsmStatement(srcInfo), methodCall(methodCall)
    { validate(); }
IR::DpdkExternObjStatement::DpdkExternObjStatement(const IR::Expression* methodCall) :
    methodCall(methodCall)
    { validate(); }
bool IR::DpdkExternFuncStatement::operator==(IR::DpdkExternFuncStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a));
    }
bool IR::DpdkExternFuncStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkExternFuncStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
}
IR::DpdkExternFuncStatement::DpdkExternFuncStatement(JSONLoader & json) : DpdkAsmStatement(json) {
}
IR::Node * IR::DpdkExternFuncStatement::fromJSON(JSONLoader & json) { return new DpdkExternFuncStatement(json); }
IR::DpdkExternFuncStatement::DpdkExternFuncStatement(Util::SourceInfo srcInfo) :
    DpdkAsmStatement(srcInfo)
    { validate(); }
IR::DpdkExternFuncStatement::DpdkExternFuncStatement() 
    { validate(); }
bool IR::DpdkReturnStatement::operator==(IR::DpdkReturnStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a));
    }
bool IR::DpdkReturnStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkReturnStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
}
IR::DpdkReturnStatement::DpdkReturnStatement(JSONLoader & json) : DpdkAsmStatement(json) {
}
IR::Node * IR::DpdkReturnStatement::fromJSON(JSONLoader & json) { return new DpdkReturnStatement(json); }
IR::DpdkReturnStatement::DpdkReturnStatement(Util::SourceInfo srcInfo) :
    DpdkAsmStatement(srcInfo)
    { validate(); }
IR::DpdkReturnStatement::DpdkReturnStatement() 
    { validate(); }
#line 367 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkLabelStatement::DpdkLabelStatement(cstring l) : label(l.toUpper()) { }
#line 12291 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkLabelStatement::operator==(IR::DpdkLabelStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && label == a.label;
    }
bool IR::DpdkLabelStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkLabelStatement &>(a_);
        return label == a.label;
    }
void IR::DpdkLabelStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " label=" << label;
}
void IR::DpdkLabelStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"label\" : " << this->label;
}
IR::DpdkLabelStatement::DpdkLabelStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("label", label);
}
IR::Node * IR::DpdkLabelStatement::fromJSON(JSONLoader & json) { return new DpdkLabelStatement(json); }
bool IR::DpdkChecksumAddStatement::operator==(IR::DpdkChecksumAddStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && csum == a.csum
        && intermediate_value == a.intermediate_value
        && field == a.field;
    }
bool IR::DpdkChecksumAddStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkChecksumAddStatement &>(a_);
        return csum == a.csum
        && intermediate_value == a.intermediate_value
        && (field ? a.field ? field->equiv(*a.field) : false : a.field == nullptr);
    }
void IR::DpdkChecksumAddStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(field, "field");
}
void IR::DpdkChecksumAddStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(field, "field");
}
void IR::DpdkChecksumAddStatement::validate() const {
#line 12337 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(field); }
void IR::DpdkChecksumAddStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " csum=" << csum;
        out << " intermediate_value=" << intermediate_value;
}
void IR::DpdkChecksumAddStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"csum\" : " << this->csum;
    json << "," << std::endl << json.indent << "\"intermediate_value\" : " << this->intermediate_value;
    json << "," << std::endl << json.indent << "\"field\" : " << this->field;
}
IR::DpdkChecksumAddStatement::DpdkChecksumAddStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("csum", csum);
    json.load("intermediate_value", intermediate_value);
    json.load("field", field);
}
IR::Node * IR::DpdkChecksumAddStatement::fromJSON(JSONLoader & json) { return new DpdkChecksumAddStatement(json); }
IR::DpdkChecksumAddStatement::DpdkChecksumAddStatement(Util::SourceInfo srcInfo, cstring csum, cstring intermediate_value, const IR::Expression* field) :
    DpdkAsmStatement(srcInfo), csum(csum), intermediate_value(intermediate_value), field(field)
    { validate(); }
IR::DpdkChecksumAddStatement::DpdkChecksumAddStatement(cstring csum, cstring intermediate_value, const IR::Expression* field) :
    csum(csum), intermediate_value(intermediate_value), field(field)
    { validate(); }
bool IR::DpdkGetHashStatement::operator==(IR::DpdkGetHashStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && hash == a.hash
        && fields == a.fields
        && dst == a.dst;
    }
bool IR::DpdkGetHashStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkGetHashStatement &>(a_);
        return hash == a.hash
        && (fields ? a.fields ? fields->equiv(*a.fields) : false : a.fields == nullptr)
        && (dst ? a.dst ? dst->equiv(*a.dst) : false : a.dst == nullptr);
    }
void IR::DpdkGetHashStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(fields, "fields");
    v.visit(dst, "dst");
}
void IR::DpdkGetHashStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(fields, "fields");
    v.visit(dst, "dst");
}
void IR::DpdkGetHashStatement::validate() const {
#line 12388 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(fields);
        CHECK_NULL(dst); }
void IR::DpdkGetHashStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " hash=" << hash;
}
void IR::DpdkGetHashStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"hash\" : " << this->hash;
    json << "," << std::endl << json.indent << "\"fields\" : " << this->fields;
    json << "," << std::endl << json.indent << "\"dst\" : " << this->dst;
}
IR::DpdkGetHashStatement::DpdkGetHashStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("hash", hash);
    json.load("fields", fields);
    json.load("dst", dst);
}
IR::Node * IR::DpdkGetHashStatement::fromJSON(JSONLoader & json) { return new DpdkGetHashStatement(json); }
IR::DpdkGetHashStatement::DpdkGetHashStatement(Util::SourceInfo srcInfo, cstring hash, const IR::Expression* fields, const IR::Expression* dst) :
    DpdkAsmStatement(srcInfo), hash(hash), fields(fields), dst(dst)
    { validate(); }
IR::DpdkGetHashStatement::DpdkGetHashStatement(cstring hash, const IR::Expression* fields, const IR::Expression* dst) :
    hash(hash), fields(fields), dst(dst)
    { validate(); }
bool IR::DpdkGetChecksumStatement::operator==(IR::DpdkGetChecksumStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && dst == a.dst
        && checksum == a.checksum
        && intermediate_value == a.intermediate_value;
    }
bool IR::DpdkGetChecksumStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkGetChecksumStatement &>(a_);
        return (dst ? a.dst ? dst->equiv(*a.dst) : false : a.dst == nullptr)
        && checksum == a.checksum
        && intermediate_value == a.intermediate_value;
    }
void IR::DpdkGetChecksumStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(dst, "dst");
}
void IR::DpdkGetChecksumStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(dst, "dst");
}
void IR::DpdkGetChecksumStatement::validate() const {
#line 12437 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(dst); }
void IR::DpdkGetChecksumStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " checksum=" << checksum;
        out << " intermediate_value=" << intermediate_value;
}
void IR::DpdkGetChecksumStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"dst\" : " << this->dst;
    json << "," << std::endl << json.indent << "\"checksum\" : " << this->checksum;
    json << "," << std::endl << json.indent << "\"intermediate_value\" : " << this->intermediate_value;
}
IR::DpdkGetChecksumStatement::DpdkGetChecksumStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("dst", dst);
    json.load("checksum", checksum);
    json.load("intermediate_value", intermediate_value);
}
IR::Node * IR::DpdkGetChecksumStatement::fromJSON(JSONLoader & json) { return new DpdkGetChecksumStatement(json); }
IR::DpdkGetChecksumStatement::DpdkGetChecksumStatement(Util::SourceInfo srcInfo, const IR::Expression* dst, cstring checksum, cstring intermediate_value) :
    DpdkAsmStatement(srcInfo), dst(dst), checksum(checksum), intermediate_value(intermediate_value)
    { validate(); }
IR::DpdkGetChecksumStatement::DpdkGetChecksumStatement(const IR::Expression* dst, cstring checksum, cstring intermediate_value) :
    dst(dst), checksum(checksum), intermediate_value(intermediate_value)
    { validate(); }
bool IR::DpdkCastStatement::operator==(IR::DpdkCastStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && src == a.src
        && dst == a.dst
        && type == a.type;
    }
bool IR::DpdkCastStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkCastStatement &>(a_);
        return (src ? a.src ? src->equiv(*a.src) : false : a.src == nullptr)
        && (dst ? a.dst ? dst->equiv(*a.dst) : false : a.dst == nullptr)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr);
    }
void IR::DpdkCastStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(src, "src");
    v.visit(dst, "dst");
    v.visit(type, "type");
}
void IR::DpdkCastStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(src, "src");
    v.visit(dst, "dst");
    v.visit(type, "type");
}
void IR::DpdkCastStatement::validate() const {
#line 12490 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(src);
        CHECK_NULL(dst);
        CHECK_NULL(type); }
void IR::DpdkCastStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"src\" : " << this->src;
    json << "," << std::endl << json.indent << "\"dst\" : " << this->dst;
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
}
IR::DpdkCastStatement::DpdkCastStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("src", src);
    json.load("dst", dst);
    json.load("type", type);
}
IR::Node * IR::DpdkCastStatement::fromJSON(JSONLoader & json) { return new DpdkCastStatement(json); }
IR::DpdkCastStatement::DpdkCastStatement(Util::SourceInfo srcInfo, const IR::Expression* src, const IR::Expression* dst, const IR::Type* type) :
    DpdkAsmStatement(srcInfo), src(src), dst(dst), type(type)
    { validate(); }
IR::DpdkCastStatement::DpdkCastStatement(const IR::Expression* src, const IR::Expression* dst, const IR::Type* type) :
    src(src), dst(dst), type(type)
    { validate(); }
bool IR::DpdkVerifyStatement::operator==(IR::DpdkVerifyStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && condition == a.condition
        && error == a.error;
    }
bool IR::DpdkVerifyStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkVerifyStatement &>(a_);
        return (condition ? a.condition ? condition->equiv(*a.condition) : false : a.condition == nullptr)
        && (error ? a.error ? error->equiv(*a.error) : false : a.error == nullptr);
    }
void IR::DpdkVerifyStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(condition, "condition");
    v.visit(error, "error");
}
void IR::DpdkVerifyStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(condition, "condition");
    v.visit(error, "error");
}
void IR::DpdkVerifyStatement::validate() const {
#line 12536 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(condition);
        CHECK_NULL(error); }
void IR::DpdkVerifyStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"condition\" : " << this->condition;
    json << "," << std::endl << json.indent << "\"error\" : " << this->error;
}
IR::DpdkVerifyStatement::DpdkVerifyStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("condition", condition);
    json.load("error", error);
}
IR::Node * IR::DpdkVerifyStatement::fromJSON(JSONLoader & json) { return new DpdkVerifyStatement(json); }
IR::DpdkVerifyStatement::DpdkVerifyStatement(Util::SourceInfo srcInfo, const IR::Expression* condition, const IR::Expression* error) :
    DpdkAsmStatement(srcInfo), condition(condition), error(error)
    { validate(); }
IR::DpdkVerifyStatement::DpdkVerifyStatement(const IR::Expression* condition, const IR::Expression* error) :
    condition(condition), error(error)
    { validate(); }
bool IR::DpdkMeterExecuteStatement::operator==(IR::DpdkMeterExecuteStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && meter == a.meter
        && index == a.index
        && color == a.color;
    }
bool IR::DpdkMeterExecuteStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkMeterExecuteStatement &>(a_);
        return meter == a.meter
        && (index ? a.index ? index->equiv(*a.index) : false : a.index == nullptr)
        && (color ? a.color ? color->equiv(*a.color) : false : a.color == nullptr);
    }
void IR::DpdkMeterExecuteStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(index, "index");
    v.visit(color, "color");
}
void IR::DpdkMeterExecuteStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(index, "index");
    v.visit(color, "color");
}
void IR::DpdkMeterExecuteStatement::validate() const {
#line 12581 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(index);
        CHECK_NULL(color); }
void IR::DpdkMeterExecuteStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " meter=" << meter;
}
void IR::DpdkMeterExecuteStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"meter\" : " << this->meter;
    json << "," << std::endl << json.indent << "\"index\" : " << this->index;
    json << "," << std::endl << json.indent << "\"color\" : " << this->color;
}
IR::DpdkMeterExecuteStatement::DpdkMeterExecuteStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("meter", meter);
    json.load("index", index);
    json.load("color", color);
}
IR::Node * IR::DpdkMeterExecuteStatement::fromJSON(JSONLoader & json) { return new DpdkMeterExecuteStatement(json); }
IR::DpdkMeterExecuteStatement::DpdkMeterExecuteStatement(Util::SourceInfo srcInfo, cstring meter, const IR::Expression* index, const IR::Expression* color) :
    DpdkAsmStatement(srcInfo), meter(meter), index(index), color(color)
    { validate(); }
IR::DpdkMeterExecuteStatement::DpdkMeterExecuteStatement(cstring meter, const IR::Expression* index, const IR::Expression* color) :
    meter(meter), index(index), color(color)
    { validate(); }
bool IR::DpdkCounterCountStatement::operator==(IR::DpdkCounterCountStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && counter == a.counter
        && index == a.index;
    }
bool IR::DpdkCounterCountStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkCounterCountStatement &>(a_);
        return counter == a.counter
        && (index ? a.index ? index->equiv(*a.index) : false : a.index == nullptr);
    }
void IR::DpdkCounterCountStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(index, "index");
}
void IR::DpdkCounterCountStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(index, "index");
}
void IR::DpdkCounterCountStatement::validate() const {
#line 12628 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(index); }
void IR::DpdkCounterCountStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " counter=" << counter;
}
void IR::DpdkCounterCountStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"counter\" : " << this->counter;
    json << "," << std::endl << json.indent << "\"index\" : " << this->index;
}
IR::DpdkCounterCountStatement::DpdkCounterCountStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("counter", counter);
    json.load("index", index);
}
IR::Node * IR::DpdkCounterCountStatement::fromJSON(JSONLoader & json) { return new DpdkCounterCountStatement(json); }
IR::DpdkCounterCountStatement::DpdkCounterCountStatement(Util::SourceInfo srcInfo, cstring counter, const IR::Expression* index) :
    DpdkAsmStatement(srcInfo), counter(counter), index(index)
    { validate(); }
IR::DpdkCounterCountStatement::DpdkCounterCountStatement(cstring counter, const IR::Expression* index) :
    counter(counter), index(index)
    { validate(); }
#line 430 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/backends/dpdk/dpdk.def"
IR::DpdkRegisterReadStatement::DpdkRegisterReadStatement(const IR::Expression* dst, cstring reg, const IR::Expression* index) :
        DpdkAssignmentStatement("read", dst), reg(reg), index(index) { }
#line 12654 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::DpdkRegisterReadStatement::operator==(IR::DpdkRegisterReadStatement const & a) const {
        return DpdkAssignmentStatement::operator==(static_cast<const DpdkAssignmentStatement &>(a))
        && reg == a.reg
        && index == a.index;
    }
bool IR::DpdkRegisterReadStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAssignmentStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkRegisterReadStatement &>(a_);
        return reg == a.reg
        && (index ? a.index ? index->equiv(*a.index) : false : a.index == nullptr);
    }
void IR::DpdkRegisterReadStatement::visit_children(Visitor & v) {
    DpdkAssignmentStatement::visit_children(v);
    v.visit(index, "index");
}
void IR::DpdkRegisterReadStatement::visit_children(Visitor & v) const {
    DpdkAssignmentStatement::visit_children(v);
    v.visit(index, "index");
}
void IR::DpdkRegisterReadStatement::validate() const {
#line 12676 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(index); }
void IR::DpdkRegisterReadStatement::dump_fields(std::ostream & out) const {
    DpdkAssignmentStatement::dump_fields(out);
        out << " reg=" << reg;
}
void IR::DpdkRegisterReadStatement::toJSON(JSONGenerator & json) const {
    DpdkAssignmentStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"reg\" : " << this->reg;
    json << "," << std::endl << json.indent << "\"index\" : " << this->index;
}
IR::DpdkRegisterReadStatement::DpdkRegisterReadStatement(JSONLoader & json) : DpdkAssignmentStatement(json) {
    json.load("reg", reg);
    json.load("index", index);
}
IR::Node * IR::DpdkRegisterReadStatement::fromJSON(JSONLoader & json) { return new DpdkRegisterReadStatement(json); }
bool IR::DpdkRegisterWriteStatement::operator==(IR::DpdkRegisterWriteStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && reg == a.reg
        && index == a.index
        && src == a.src;
    }
bool IR::DpdkRegisterWriteStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkRegisterWriteStatement &>(a_);
        return reg == a.reg
        && (index ? a.index ? index->equiv(*a.index) : false : a.index == nullptr)
        && (src ? a.src ? src->equiv(*a.src) : false : a.src == nullptr);
    }
void IR::DpdkRegisterWriteStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(index, "index");
    v.visit(src, "src");
}
void IR::DpdkRegisterWriteStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(index, "index");
    v.visit(src, "src");
}
void IR::DpdkRegisterWriteStatement::validate() const {
#line 12718 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(index);
        CHECK_NULL(src); }
void IR::DpdkRegisterWriteStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " reg=" << reg;
}
void IR::DpdkRegisterWriteStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"reg\" : " << this->reg;
    json << "," << std::endl << json.indent << "\"index\" : " << this->index;
    json << "," << std::endl << json.indent << "\"src\" : " << this->src;
}
IR::DpdkRegisterWriteStatement::DpdkRegisterWriteStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("reg", reg);
    json.load("index", index);
    json.load("src", src);
}
IR::Node * IR::DpdkRegisterWriteStatement::fromJSON(JSONLoader & json) { return new DpdkRegisterWriteStatement(json); }
IR::DpdkRegisterWriteStatement::DpdkRegisterWriteStatement(Util::SourceInfo srcInfo, cstring reg, const IR::Expression* index, const IR::Expression* src) :
    DpdkAsmStatement(srcInfo), reg(reg), index(index), src(src)
    { validate(); }
IR::DpdkRegisterWriteStatement::DpdkRegisterWriteStatement(cstring reg, const IR::Expression* index, const IR::Expression* src) :
    reg(reg), index(index), src(src)
    { validate(); }
#line 7 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/frontends/p4-14/ir-v1.def"
IR::v1HeaderType::v1HeaderType(IR::Type_Struct const * m, IR::Type_Header const * h) : v1HeaderType(Util::SourceInfo(), m->name, m, h) {}
#line 12746 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
#line 9 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/frontends/p4-14/ir-v1.def"
void IR::v1HeaderType::dbprint(std::ostream & out) const { out << "header " << name; }
#line 12749 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"
bool IR::v1HeaderType::operator==(IR::v1HeaderType const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && as_metadata == a.as_metadata
        && as_header == a.as_header;
    }
bool IR::v1HeaderType::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const v1HeaderType &>(a_);
        return name == a.name
        && (as_metadata ? a.as_metadata ? as_metadata->equiv(*a.as_metadata) : false : a.as_metadata == nullptr)
        && (as_header ? a.as_header ? as_header->equiv(*a.as_header) : false : a.as_header == nullptr);
    }
void IR::v1HeaderType::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(as_metadata, "as_metadata");
    v.visit(as_header, "as_header");
}
void IR::v1HeaderType::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(as_metadata, "as_metadata");
    v.visit(as_header, "as_header");
}
void IR::v1HeaderType::validate() const {
#line 12775 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/ir-generated.cpp"

        CHECK_NULL(as_metadata); }
void IR::v1HeaderType::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
}
void IR::v1HeaderType::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"as_metadata\" : " << this->as_metadata;
    if (as_header != nullptr)     json << "," << std::endl << json.indent << "\"as_header\" : " << this->as_header;
}
IR::v1HeaderType::v1HeaderType(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("as_metadata", as_metadata);
    json.load("as_header", as_header);
}
IR::Node * IR::v1HeaderType::fromJSON(JSONLoader & json) { return new v1HeaderType(json); }
IR::v1HeaderType::v1HeaderType(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Struct* as_metadata, const IR::Type_Header* as_header) :
    Node(srcInfo), name(name), as_metadata(as_metadata), as_header(as_header)
    { validate(); }
IR::v1HeaderType::v1HeaderType(IR::ID name, const IR::Type_Struct* as_metadata, const IR::Type_Header* as_header) :
    name(name), as_metadata(as_metadata), as_header(as_header)
    { validate(); }
bool IR::IntMod::operator==(IR::IntMod const & a) const {
        return Operation_Unary::operator==(static_cast<const Operation_Unary &>(a))
        && width == a.width;
    }
bool IR::IntMod::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Unary::equiv(a_)) return false;
        auto &a = static_cast<const IntMod &>(a_);
        return width == a.width;
    }
void IR::IntMod::dump_fields(std::ostream & out) const {
    Operation_Unary::dump_fields(out);
        out << " width=" << width;
}
void IR::IntMod::toJSON(JSONGenerator & json) const {
    Operation_Unary::toJSON(json);
    json << "," << std::endl << json.indent << "\"width\" : " << this->width;
}
IR::IntMod::IntMod(JSONLoader & json) : Operation_Unary(json) {
    json.load("width", width);
}
IR::Node * IR::IntMod::fromJSON(JSONLoader & json) { return new IntMod(json); }
IR::IntMod::IntMod(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr, unsigned width) :
    Operation_Unary(srcInfo, type, expr), width(width)
    { validate(); }
IR::IntMod::IntMod(const IR::Type* type, const IR::Expression* expr, unsigned width) :
    Operation_Unary(type, expr), width(width)
    { validate(); }
IR::IntMod::IntMod(Util::SourceInfo srcInfo, const IR::Expression* expr, unsigned width) :
    Operation_Unary(srcInfo, expr), width(width)
    { validate(); }
IR::IntMod::IntMod(const IR::Expression* expr, unsigned width) :
    Operation_Unary(expr), width(width)
    { validate(); }
