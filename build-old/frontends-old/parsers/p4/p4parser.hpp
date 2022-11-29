// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

/**
 ** \file /media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.hpp
 ** Define the P4::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_YY_MEDIA_YEC_WORK_PROGRAMS_P4_VERIFICATION_P4B_TRANSLATOR_BUILD_FRONTENDS_PARSERS_P4_P4PARSER_HPP_INCLUDED
# define YY_YY_MEDIA_YEC_WORK_PROGRAMS_P4_VERIFICATION_P4B_TRANSLATOR_BUILD_FRONTENDS_PARSERS_P4_P4PARSER_HPP_INCLUDED
// //                    "%code requires" blocks.
#line 37 "parsers/p4/p4parser.ypp" // lalr1.cc:377

#include <cassert>   // NOLINT(build/include_order)
#include <iostream>  // NOLINT(build/include_order)

#include "frontends/common/constantParsing.h"
#include "frontends/common/options.h"
#include "ir/ir.h"
#include "lib/cstring.h"
#include "lib/source_file.h"

namespace P4 {
class AbstractP4Lexer;
class P4ParserDriver;

// This is a workaround for an UndefinedBehaviorSanitizer issue triggered by
// Bison's variant implementation. When variant::move() is used to move a value
// from an initialized instance of variant to an uninitialized instance, it uses
// placement new to initialize the uninitialized instance, then calls
// variant::swap(), then destroys the moved-from instance. The problem is that
// placement new does not perform any initialization for primitive types, and
// for bool or enum types that can result in a value that isn't a valid element
// of those types, which UndefinedBehaviorSanitizer doesn't like.
struct OptionalConst {
    OptionalConst() = default;
    explicit OptionalConst(bool isConst) : isConst(isConst) { }
    bool isConst = false;
};
}  // namespace P4

inline std::ostream& operator<<(std::ostream& out, const P4::OptionalConst& oc) {
    out << "OptionalConst(" << oc.isConst << ')';
    return out;
}

// Bison uses the types you provide to %type to make constructors for the
// variant type it uses under the hood, but its code generation is a little
// naive and it always prepends 'const' to the type. This is problematic when
// the symbol type we want is itself const, since duplicate const qualifiers are
// forbidden in C++. We avoid the problem using a typedef.
typedef const IR::Type ConstType;

#ifndef YYDEBUG
#define YYDEBUG 1
#endif

#define YY_NULLPTR nullptr

namespace P4 {
class Token {
 public:
    int type;
    cstring text;
    UnparsedConstant* unparsedConstant;

    Token() : Token(0, "", nullptr) { }
    Token(int type, cstring text) : Token(type, text, nullptr) { }
    Token(int type, UnparsedConstant unparsedConstant)
            : Token(type, unparsedConstant.text,
                    new UnparsedConstant(unparsedConstant)) { }

 private:
    Token(int type, cstring text, UnparsedConstant* unparsedConstant)
            : type(type), text(text), unparsedConstant(unparsedConstant) { }
};

} // namespace P4

inline std::ostream& operator<<(std::ostream& out, const P4::Token& t) {
    out << t.text;
    return out;
}

#line 117 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.hpp" // lalr1.cc:377

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>
# include "stack.hh"

#include <typeinfo>
#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
#endif


#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

#line 23 "parsers/p4/p4parser.ypp" // lalr1.cc:377
namespace P4 {
#line 194 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.hpp" // lalr1.cc:377



  /// A char[S] buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current state.
  template <size_t S>
  struct variant
  {
    /// Type of *this.
    typedef variant<S> self_type;

    /// Empty construction.
    variant ()
      : yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    variant (const T& t)
      : yytypeid_ (&typeid (T))
    {
      YYASSERT (sizeof (T) <= S);
      new (yyas_<T> ()) T (t);
    }

    /// Destruction, allowed only if empty.
    ~variant ()
    {
      YYASSERT (!yytypeid_);
    }

    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    build ()
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= S);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T;
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    build (const T& t)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= S);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as ()
    {
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= S);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const
    {
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= S);
      return *yyas_<T> ();
    }

    /// Swap the content with \a other, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsability.
    /// Swapping between built and (possibly) non-built is done with
    /// variant::move ().
    template <typename T>
    void
    swap (self_type& other)
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == *other.yytypeid_);
      std::swap (as<T> (), other.as<T> ());
    }

    /// Move the content of \a other to this.
    ///
    /// Destroys \a other.
    template <typename T>
    void
    move (self_type& other)
    {
      build<T> ();
      swap<T> (other);
      other.destroy<T> ();
    }

    /// Copy the content of \a other to this.
    template <typename T>
    void
    copy (const self_type& other)
    {
      build<T> (other.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
    /// Prohibit blind copies.
    self_type& operator=(const self_type&);
    variant (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ ()
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[S];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };


  /// A Bison parser.
  class P4Parser
  {
  public:
#ifndef YYSTYPE
    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // typeRef
      // namedType
      // tupleType
      // headerStackType
      // specializedType
      // baseType
      // typeOrVoid
      // typeArg
      // realTypeArg
      char dummy1[sizeof(ConstType*)];

      // annotation
      char dummy2[sizeof(IR::Annotation*)];

      // optAnnotations
      char dummy3[sizeof(IR::Annotations*)];

      // argument
      char dummy4[sizeof(IR::Argument*)];

      // objInitializer
      // parserBlockStatement
      // controlBody
      // blockStatement
      char dummy5[sizeof(IR::BlockStatement*)];

      // instantiation
      // objDeclaration
      // parserLocalElement
      // valueSetDeclaration
      // controlLocalDeclaration
      // tableDeclaration
      // actionDeclaration
      // variableDeclaration
      // constantDeclaration
      // functionDeclaration
      char dummy6[sizeof(IR::Declaration*)];

      // direction
      char dummy7[sizeof(IR::Direction)];

      // entry
      char dummy8[sizeof(IR::Entry*)];

      // p4rtControllerType
      // transitionStatement
      // stateExpression
      // selectExpression
      // keysetExpression
      // reducedSimpleKeysetExpression
      // simpleKeysetExpression
      // switchLabel
      // actionRef
      // optInitializer
      // initializer
      // lvalue
      // expression
      // nonBraceExpression
      // intOrStr
      char dummy9[sizeof(IR::Expression*)];

      // nonTypeName
      // name
      // nonTableKwName
      // dot_name
      char dummy10[sizeof(IR::ID*)];

      // actionList
      char dummy11[sizeof(IR::IndexedVector<IR::ActionListElement>*)];

      // parserLocalElements
      // controlLocalDeclarations
      char dummy12[sizeof(IR::IndexedVector<IR::Declaration>*)];

      // identifierList
      char dummy13[sizeof(IR::IndexedVector<IR::Declaration_ID>*)];

      // kvList
      char dummy14[sizeof(IR::IndexedVector<IR::NamedExpression>*)];

      // parameterList
      // nonEmptyParameterList
      // optConstructorParameters
      char dummy15[sizeof(IR::IndexedVector<IR::Parameter>*)];

      // parserStates
      char dummy16[sizeof(IR::IndexedVector<IR::ParserState>*)];

      // tablePropertyList
      char dummy17[sizeof(IR::IndexedVector<IR::Property>*)];

      // specifiedIdentifierList
      char dummy18[sizeof(IR::IndexedVector<IR::SerEnumMember>*)];

      // objDeclarations
      // parserStatements
      // statOrDeclList
      char dummy19[sizeof(IR::IndexedVector<IR::StatOrDecl>*)];

      // structFieldList
      char dummy20[sizeof(IR::IndexedVector<IR::StructField>*)];

      // typeParameterList
      char dummy21[sizeof(IR::IndexedVector<IR::Type_Var>*)];

      // keyElement
      char dummy22[sizeof(IR::KeyElement*)];

      // functionPrototype
      // methodPrototype
      char dummy23[sizeof(IR::Method*)];

      // kvPair
      char dummy24[sizeof(IR::NamedExpression*)];

      // fragment
      // declaration
      // externDeclaration
      // matchKindDeclaration
      char dummy25[sizeof(IR::Node*)];

      // parameter
      char dummy26[sizeof(IR::Parameter*)];

      // parserState
      char dummy27[sizeof(IR::ParserState*)];

      // prefixedType
      // prefixedNonTypeName
      char dummy28[sizeof(IR::Path*)];

      // tableProperty
      char dummy29[sizeof(IR::Property*)];

      // selectCase
      char dummy30[sizeof(IR::SelectCase*)];

      // specifiedIdentifier
      char dummy31[sizeof(IR::SerEnumMember*)];

      // parserStatement
      // statementOrDeclaration
      char dummy32[sizeof(IR::StatOrDecl*)];

      // assignmentOrMethodCallStatement
      // emptyStatement
      // exitStatement
      // returnStatement
      // conditionalStatement
      // directApplication
      // statement
      // switchStatement
      char dummy33[sizeof(IR::Statement*)];

      // structField
      char dummy34[sizeof(IR::StructField*)];

      // switchCase
      char dummy35[sizeof(IR::SwitchCase*)];

      // optTypeParameters
      // typeParameters
      char dummy36[sizeof(IR::TypeParameters*)];

      // controlTypeDeclaration
      char dummy37[sizeof(IR::Type_Control*)];

      // packageTypeDeclaration
      // parserDeclaration
      // controlDeclaration
      // typeDeclaration
      // derivedTypeDeclaration
      // headerTypeDeclaration
      // structTypeDeclaration
      // headerUnionDeclaration
      // enumDeclaration
      // typedefDeclaration
      char dummy38[sizeof(IR::Type_Declaration*)];

      // errorDeclaration
      char dummy39[sizeof(IR::Type_Error*)];

      // typeName
      char dummy40[sizeof(IR::Type_Name*)];

      // parserTypeDeclaration
      char dummy41[sizeof(IR::Type_Parser*)];

      // annotations
      char dummy42[sizeof(IR::Vector<IR::Annotation>*)];

      // annotationBody
      char dummy43[sizeof(IR::Vector<IR::AnnotationToken>*)];

      // argumentList
      // nonEmptyArgList
      char dummy44[sizeof(IR::Vector<IR::Argument>*)];

      // entriesList
      char dummy45[sizeof(IR::Vector<IR::Entry>*)];

      // tupleKeysetExpression
      // simpleExpressionList
      // expressionList
      // intList
      // intOrStrList
      // strList
      char dummy46[sizeof(IR::Vector<IR::Expression>*)];

      // keyElementList
      char dummy47[sizeof(IR::Vector<IR::KeyElement>*)];

      // methodPrototypes
      char dummy48[sizeof(IR::Vector<IR::Method>*)];

      // selectCaseList
      char dummy49[sizeof(IR::Vector<IR::SelectCase>*)];

      // switchCases
      char dummy50[sizeof(IR::Vector<IR::SwitchCase>*)];

      // typeArgumentList
      // realTypeArgumentList
      char dummy51[sizeof(IR::Vector<IR::Type>*)];

      // optCONST
      char dummy52[sizeof(OptionalConst)];

      // UNEXPECTED_TOKEN
      // END_PRAGMA
      // "<="
      // ">="
      // "<<"
      // "&&"
      // "||"
      // "!="
      // "=="
      // "+"
      // "-"
      // "|+|"
      // "|-|"
      // "*"
      // "/"
      // "%"
      // "|"
      // "&"
      // "^"
      // "~"
      // "["
      // "]"
      // "{"
      // "}"
      // "<"
      // L_ANGLE_ARGS
      // ">"
      // R_ANGLE_SHIFT
      // "("
      // ")"
      // "!"
      // ":"
      // ","
      // "?"
      // "."
      // "="
      // ";"
      // "@"
      // "++"
      // "_"
      // "&&&"
      // ".."
      // TRUE
      // FALSE
      // THIS
      // ABSTRACT
      // ACTION
      // ACTIONS
      // APPLY
      // BOOL
      // BIT
      // CONST
      // CONTROL
      // DEFAULT
      // ELSE
      // ENTRIES
      // ENUM
      // ERROR
      // EXIT
      // EXTERN
      // HEADER
      // HEADER_UNION
      // IF
      // IN
      // INOUT
      // INT
      // KEY
      // SELECT
      // MATCH_KIND
      // TYPE
      // OUT
      // PACKAGE
      // PARSER
      // PRAGMA
      // RETURN
      // STATE
      // STRING
      // STRUCT
      // SWITCH
      // TABLE
      // TRANSITION
      // TUPLE
      // TYPEDEF
      // VARBIT
      // VALUESET
      // VOID
      // annotationToken
      char dummy53[sizeof(Token)];

      // INTEGER
      char dummy54[sizeof(UnparsedConstant)];

      // IDENTIFIER
      // TYPE_IDENTIFIER
      // STRING_LITERAL
      char dummy55[sizeof(cstring)];
};

    /// Symbol semantic values.
    typedef variant<sizeof(union_type)> semantic_type;
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef Util::SourceInfo location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m);
      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        TOK_START_PROGRAM = 258,
        TOK_START_EXPRESSION_LIST = 259,
        TOK_START_KV_LIST = 260,
        TOK_START_INTEGER_LIST = 261,
        TOK_START_INTEGER_OR_STRING_LITERAL_LIST = 262,
        TOK_START_STRING_LITERAL_LIST = 263,
        TOK_START_EXPRESSION = 264,
        TOK_START_INTEGER = 265,
        TOK_START_INTEGER_OR_STRING_LITERAL = 266,
        TOK_START_STRING_LITERAL = 267,
        TOK_START_EXPRESSION_PAIR = 268,
        TOK_START_INTEGER_PAIR = 269,
        TOK_START_STRING_LITERAL_PAIR = 270,
        TOK_START_EXPRESSION_TRIPLE = 271,
        TOK_START_INTEGER_TRIPLE = 272,
        TOK_START_STRING_LITERAL_TRIPLE = 273,
        TOK_START_P4RT_TRANSLATION_ANNOTATION = 274,
        TOK_END = 275,
        TOK_END_ANNOTATION = 276,
        TOK_UNEXPECTED_TOKEN = 277,
        TOK_END_PRAGMA = 278,
        TOK_LE = 279,
        TOK_GE = 280,
        TOK_SHL = 281,
        TOK_AND = 282,
        TOK_OR = 283,
        TOK_NE = 284,
        TOK_EQ = 285,
        TOK_PLUS = 286,
        TOK_MINUS = 287,
        TOK_PLUS_SAT = 288,
        TOK_MINUS_SAT = 289,
        TOK_MUL = 290,
        TOK_DIV = 291,
        TOK_MOD = 292,
        TOK_BIT_OR = 293,
        TOK_BIT_AND = 294,
        TOK_BIT_XOR = 295,
        TOK_COMPLEMENT = 296,
        TOK_L_BRACKET = 297,
        TOK_R_BRACKET = 298,
        TOK_L_BRACE = 299,
        TOK_R_BRACE = 300,
        TOK_L_ANGLE = 301,
        TOK_L_ANGLE_ARGS = 302,
        TOK_R_ANGLE = 303,
        TOK_R_ANGLE_SHIFT = 304,
        TOK_L_PAREN = 305,
        TOK_R_PAREN = 306,
        TOK_NOT = 307,
        TOK_COLON = 308,
        TOK_COMMA = 309,
        TOK_QUESTION = 310,
        TOK_DOT = 311,
        TOK_ASSIGN = 312,
        TOK_SEMICOLON = 313,
        TOK_AT = 314,
        TOK_PP = 315,
        TOK_DONTCARE = 316,
        TOK_MASK = 317,
        TOK_RANGE = 318,
        TOK_TRUE = 319,
        TOK_FALSE = 320,
        TOK_THIS = 321,
        TOK_ABSTRACT = 322,
        TOK_ACTION = 323,
        TOK_ACTIONS = 324,
        TOK_APPLY = 325,
        TOK_BOOL = 326,
        TOK_BIT = 327,
        TOK_CONST = 328,
        TOK_CONTROL = 329,
        TOK_DEFAULT = 330,
        TOK_ELSE = 331,
        TOK_ENTRIES = 332,
        TOK_ENUM = 333,
        TOK_ERROR = 334,
        TOK_EXIT = 335,
        TOK_EXTERN = 336,
        TOK_HEADER = 337,
        TOK_HEADER_UNION = 338,
        TOK_IF = 339,
        TOK_IN = 340,
        TOK_INOUT = 341,
        TOK_INT = 342,
        TOK_KEY = 343,
        TOK_SELECT = 344,
        TOK_MATCH_KIND = 345,
        TOK_TYPE = 346,
        TOK_OUT = 347,
        TOK_PACKAGE = 348,
        TOK_PARSER = 349,
        TOK_PRAGMA = 350,
        TOK_RETURN = 351,
        TOK_STATE = 352,
        TOK_STRING = 353,
        TOK_STRUCT = 354,
        TOK_SWITCH = 355,
        TOK_TABLE = 356,
        TOK_TRANSITION = 357,
        TOK_TUPLE = 358,
        TOK_TYPEDEF = 359,
        TOK_VARBIT = 360,
        TOK_VALUESET = 361,
        TOK_VOID = 362,
        TOK_IDENTIFIER = 363,
        TOK_TYPE_IDENTIFIER = 364,
        TOK_STRING_LITERAL = 365,
        TOK_INTEGER = 366,
        TOK_PREFIX = 367,
        TOK_THEN = 368
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Copy constructor.
      basic_symbol (const basic_symbol& other);

      /// Constructor for valueless symbols, and symbols from each type.

  basic_symbol (typename Base::kind_type t, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ConstType* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Annotation* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Annotations* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Argument* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::BlockStatement* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Declaration* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Direction v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Entry* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Expression* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::ID* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::IndexedVector<IR::ActionListElement>* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::IndexedVector<IR::Declaration>* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::IndexedVector<IR::Declaration_ID>* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::IndexedVector<IR::NamedExpression>* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::IndexedVector<IR::Parameter>* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::IndexedVector<IR::ParserState>* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::IndexedVector<IR::Property>* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::IndexedVector<IR::SerEnumMember>* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::IndexedVector<IR::StatOrDecl>* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::IndexedVector<IR::StructField>* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::IndexedVector<IR::Type_Var>* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::KeyElement* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Method* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::NamedExpression* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Node* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Parameter* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::ParserState* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Path* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Property* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::SelectCase* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::SerEnumMember* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::StatOrDecl* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Statement* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::StructField* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::SwitchCase* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::TypeParameters* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Type_Control* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Type_Declaration* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Type_Error* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Type_Name* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Type_Parser* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Vector<IR::Annotation>* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Vector<IR::AnnotationToken>* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Vector<IR::Argument>* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Vector<IR::Entry>* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Vector<IR::Expression>* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Vector<IR::KeyElement>* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Vector<IR::Method>* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Vector<IR::SelectCase>* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Vector<IR::SwitchCase>* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Vector<IR::Type>* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const OptionalConst v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const Token v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const UnparsedConstant v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const cstring v, const location_type& l);


      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    const semantic_type& v,
                    const location_type& l);

      /// Destroy the symbol.
      ~basic_symbol ();

      /// Destroy contents, and record that is empty.
      void clear ();

      /// Whether empty.
      bool empty () const;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;

    // Symbol constructors declarations.
    static inline
    symbol_type
    make_START_PROGRAM (const location_type& l);

    static inline
    symbol_type
    make_START_EXPRESSION_LIST (const location_type& l);

    static inline
    symbol_type
    make_START_KV_LIST (const location_type& l);

    static inline
    symbol_type
    make_START_INTEGER_LIST (const location_type& l);

    static inline
    symbol_type
    make_START_INTEGER_OR_STRING_LITERAL_LIST (const location_type& l);

    static inline
    symbol_type
    make_START_STRING_LITERAL_LIST (const location_type& l);

    static inline
    symbol_type
    make_START_EXPRESSION (const location_type& l);

    static inline
    symbol_type
    make_START_INTEGER (const location_type& l);

    static inline
    symbol_type
    make_START_INTEGER_OR_STRING_LITERAL (const location_type& l);

    static inline
    symbol_type
    make_START_STRING_LITERAL (const location_type& l);

    static inline
    symbol_type
    make_START_EXPRESSION_PAIR (const location_type& l);

    static inline
    symbol_type
    make_START_INTEGER_PAIR (const location_type& l);

    static inline
    symbol_type
    make_START_STRING_LITERAL_PAIR (const location_type& l);

    static inline
    symbol_type
    make_START_EXPRESSION_TRIPLE (const location_type& l);

    static inline
    symbol_type
    make_START_INTEGER_TRIPLE (const location_type& l);

    static inline
    symbol_type
    make_START_STRING_LITERAL_TRIPLE (const location_type& l);

    static inline
    symbol_type
    make_START_P4RT_TRANSLATION_ANNOTATION (const location_type& l);

    static inline
    symbol_type
    make_END (const location_type& l);

    static inline
    symbol_type
    make_END_ANNOTATION (const location_type& l);

    static inline
    symbol_type
    make_UNEXPECTED_TOKEN (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_END_PRAGMA (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_LE (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_GE (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_SHL (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_AND (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_OR (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_NE (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_EQ (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_PLUS (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_MINUS (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_PLUS_SAT (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_MINUS_SAT (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_MUL (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_DIV (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_MOD (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_BIT_OR (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_BIT_AND (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_BIT_XOR (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_COMPLEMENT (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_L_BRACKET (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_R_BRACKET (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_L_BRACE (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_R_BRACE (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_L_ANGLE (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_L_ANGLE_ARGS (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_R_ANGLE (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_R_ANGLE_SHIFT (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_L_PAREN (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_R_PAREN (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_NOT (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_COLON (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_COMMA (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_QUESTION (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_DOT (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_ASSIGN (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_SEMICOLON (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_AT (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_PP (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_DONTCARE (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_MASK (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_RANGE (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_TRUE (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_FALSE (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_THIS (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_ABSTRACT (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_ACTION (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_ACTIONS (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_APPLY (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_BOOL (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_BIT (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_CONST (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_CONTROL (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_DEFAULT (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_ELSE (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_ENTRIES (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_ENUM (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_ERROR (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_EXIT (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_EXTERN (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_HEADER (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_HEADER_UNION (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_IF (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_IN (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_INOUT (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_INT (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_KEY (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_SELECT (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_MATCH_KIND (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_TYPE (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_OUT (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_PACKAGE (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_PARSER (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_PRAGMA (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_RETURN (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_STATE (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_STRING (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_STRUCT (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_SWITCH (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_TABLE (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_TRANSITION (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_TUPLE (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_TYPEDEF (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_VARBIT (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_VALUESET (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_VOID (const Token& v, const location_type& l);

    static inline
    symbol_type
    make_IDENTIFIER (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_TYPE_IDENTIFIER (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_STRING_LITERAL (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_INTEGER (const UnparsedConstant& v, const location_type& l);

    static inline
    symbol_type
    make_PREFIX (const location_type& l);

    static inline
    symbol_type
    make_THEN (const location_type& l);


    /// Build a parser object.
    P4Parser (P4::P4ParserDriver& driver_yyarg, P4::AbstractP4Lexer& lexer_yyarg);
    virtual ~P4Parser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

  private:
    /// This class is not copyable.
    P4Parser (const P4Parser&);
    P4Parser& operator= (const P4Parser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short int yypact_ninf_;
    static const short int yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (token_type t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const short int yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned short int yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const short int yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const short int yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const short int yytable_[];

  static const short int yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned short int yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned short int yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short int yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    // Debugging.
    int yydebug_;
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state ();

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s);

      /// Copy constructor.
      by_state (const by_state& other);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, symbol_type& sym);
      /// Assignment, needed by push_back.
      stack_symbol_type& operator= (const stack_symbol_type& that);
    };

    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, stack_symbol_type& s);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, state_type s, symbol_type& sym);

    /// Pop \a n symbols the three stacks.
    void yypop_ (unsigned int n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 4171,     ///< Last index in yytable_.
      yynnts_ = 154,  ///< Number of nonterminal symbols.
      yyfinal_ = 75, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 114  ///< Number of tokens.
    };


    // User arguments.
    P4::P4ParserDriver& driver;
    P4::AbstractP4Lexer& lexer;
  };

  // Symbol number corresponding to token number t.
  inline
  P4Parser::token_number_type
  P4Parser::yytranslate_ (token_type t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113
    };
    const unsigned int user_token_number_max_ = 368;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

  inline
  P4Parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  P4Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  P4Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      case 184: // typeRef
      case 185: // namedType
      case 188: // tupleType
      case 189: // headerStackType
      case 190: // specializedType
      case 191: // baseType
      case 192: // typeOrVoid
      case 196: // typeArg
      case 198: // realTypeArg
        value.copy< ConstType* > (other.value);
        break;

      case 127: // annotation
        value.copy< IR::Annotation* > (other.value);
        break;

      case 125: // optAnnotations
        value.copy< IR::Annotations* > (other.value);
        break;

      case 254: // argument
        value.copy< IR::Argument* > (other.value);
        break;

      case 140: // objInitializer
      case 157: // parserBlockStatement
      case 176: // controlBody
      case 229: // blockStatement
        value.copy< IR::BlockStatement* > (other.value);
        break;

      case 139: // instantiation
      case 143: // objDeclaration
      case 148: // parserLocalElement
      case 169: // valueSetDeclaration
      case 175: // controlLocalDeclaration
      case 237: // tableDeclaration
      case 246: // actionDeclaration
      case 247: // variableDeclaration
      case 248: // constantDeclaration
      case 251: // functionDeclaration
        value.copy< IR::Declaration* > (other.value);
        break;

      case 135: // direction
        value.copy< IR::Direction > (other.value);
        break;

      case 244: // entry
        value.copy< IR::Entry* > (other.value);
        break;

      case 117: // p4rtControllerType
      case 159: // transitionStatement
      case 160: // stateExpression
      case 161: // selectExpression
      case 164: // keysetExpression
      case 167: // reducedSimpleKeysetExpression
      case 168: // simpleKeysetExpression
      case 235: // switchLabel
      case 243: // actionRef
      case 249: // optInitializer
      case 250: // initializer
      case 259: // lvalue
      case 260: // expression
      case 261: // nonBraceExpression
      case 262: // intOrStr
        value.copy< IR::Expression* > (other.value);
        break;

      case 121: // nonTypeName
      case 122: // name
      case 123: // nonTableKwName
      case 257: // dot_name
        value.copy< IR::ID* > (other.value);
        break;

      case 242: // actionList
        value.copy< IR::IndexedVector<IR::ActionListElement>* > (other.value);
        break;

      case 147: // parserLocalElements
      case 174: // controlLocalDeclarations
        value.copy< IR::IndexedVector<IR::Declaration>* > (other.value);
        break;

      case 220: // identifierList
        value.copy< IR::IndexedVector<IR::Declaration_ID>* > (other.value);
        break;

      case 130: // kvList
        value.copy< IR::IndexedVector<IR::NamedExpression>* > (other.value);
        break;

      case 132: // parameterList
      case 133: // nonEmptyParameterList
      case 144: // optConstructorParameters
        value.copy< IR::IndexedVector<IR::Parameter>* > (other.value);
        break;

      case 152: // parserStates
        value.copy< IR::IndexedVector<IR::ParserState>* > (other.value);
        break;

      case 238: // tablePropertyList
        value.copy< IR::IndexedVector<IR::Property>* > (other.value);
        break;

      case 216: // specifiedIdentifierList
        value.copy< IR::IndexedVector<IR::SerEnumMember>* > (other.value);
        break;

      case 142: // objDeclarations
      case 155: // parserStatements
      case 231: // statOrDeclList
        value.copy< IR::IndexedVector<IR::StatOrDecl>* > (other.value);
        break;

      case 211: // structFieldList
        value.copy< IR::IndexedVector<IR::StructField>* > (other.value);
        break;

      case 195: // typeParameterList
        value.copy< IR::IndexedVector<IR::Type_Var>* > (other.value);
        break;

      case 241: // keyElement
        value.copy< IR::KeyElement* > (other.value);
        break;

      case 181: // functionPrototype
      case 183: // methodPrototype
        value.copy< IR::Method* > (other.value);
        break;

      case 131: // kvPair
        value.copy< IR::NamedExpression* > (other.value);
        break;

      case 116: // fragment
      case 120: // declaration
      case 177: // externDeclaration
      case 219: // matchKindDeclaration
        value.copy< IR::Node* > (other.value);
        break;

      case 134: // parameter
        value.copy< IR::Parameter* > (other.value);
        break;

      case 153: // parserState
        value.copy< IR::ParserState* > (other.value);
        break;

      case 186: // prefixedType
      case 256: // prefixedNonTypeName
        value.copy< IR::Path* > (other.value);
        break;

      case 239: // tableProperty
        value.copy< IR::Property* > (other.value);
        break;

      case 163: // selectCase
        value.copy< IR::SelectCase* > (other.value);
        break;

      case 217: // specifiedIdentifier
        value.copy< IR::SerEnumMember* > (other.value);
        break;

      case 156: // parserStatement
      case 236: // statementOrDeclaration
        value.copy< IR::StatOrDecl* > (other.value);
        break;

      case 222: // assignmentOrMethodCallStatement
      case 223: // emptyStatement
      case 224: // exitStatement
      case 225: // returnStatement
      case 226: // conditionalStatement
      case 227: // directApplication
      case 228: // statement
      case 232: // switchStatement
        value.copy< IR::Statement* > (other.value);
        break;

      case 212: // structField
        value.copy< IR::StructField* > (other.value);
        break;

      case 234: // switchCase
        value.copy< IR::SwitchCase* > (other.value);
        break;

      case 193: // optTypeParameters
      case 194: // typeParameters
        value.copy< IR::TypeParameters* > (other.value);
        break;

      case 171: // controlTypeDeclaration
        value.copy< IR::Type_Control* > (other.value);
        break;

      case 136: // packageTypeDeclaration
      case 146: // parserDeclaration
      case 170: // controlDeclaration
      case 200: // typeDeclaration
      case 201: // derivedTypeDeclaration
      case 202: // headerTypeDeclaration
      case 205: // structTypeDeclaration
      case 208: // headerUnionDeclaration
      case 213: // enumDeclaration
      case 221: // typedefDeclaration
        value.copy< IR::Type_Declaration* > (other.value);
        break;

      case 218: // errorDeclaration
        value.copy< IR::Type_Error* > (other.value);
        break;

      case 187: // typeName
        value.copy< IR::Type_Name* > (other.value);
        break;

      case 149: // parserTypeDeclaration
        value.copy< IR::Type_Parser* > (other.value);
        break;

      case 126: // annotations
        value.copy< IR::Vector<IR::Annotation>* > (other.value);
        break;

      case 128: // annotationBody
        value.copy< IR::Vector<IR::AnnotationToken>* > (other.value);
        break;

      case 252: // argumentList
      case 253: // nonEmptyArgList
        value.copy< IR::Vector<IR::Argument>* > (other.value);
        break;

      case 245: // entriesList
        value.copy< IR::Vector<IR::Entry>* > (other.value);
        break;

      case 165: // tupleKeysetExpression
      case 166: // simpleExpressionList
      case 255: // expressionList
      case 263: // intList
      case 264: // intOrStrList
      case 265: // strList
        value.copy< IR::Vector<IR::Expression>* > (other.value);
        break;

      case 240: // keyElementList
        value.copy< IR::Vector<IR::KeyElement>* > (other.value);
        break;

      case 180: // methodPrototypes
        value.copy< IR::Vector<IR::Method>* > (other.value);
        break;

      case 162: // selectCaseList
        value.copy< IR::Vector<IR::SelectCase>* > (other.value);
        break;

      case 233: // switchCases
        value.copy< IR::Vector<IR::SwitchCase>* > (other.value);
        break;

      case 197: // typeArgumentList
      case 199: // realTypeArgumentList
        value.copy< IR::Vector<IR::Type>* > (other.value);
        break;

      case 124: // optCONST
        value.copy< OptionalConst > (other.value);
        break;

      case 22: // UNEXPECTED_TOKEN
      case 23: // END_PRAGMA
      case 24: // "<="
      case 25: // ">="
      case 26: // "<<"
      case 27: // "&&"
      case 28: // "||"
      case 29: // "!="
      case 30: // "=="
      case 31: // "+"
      case 32: // "-"
      case 33: // "|+|"
      case 34: // "|-|"
      case 35: // "*"
      case 36: // "/"
      case 37: // "%"
      case 38: // "|"
      case 39: // "&"
      case 40: // "^"
      case 41: // "~"
      case 42: // "["
      case 43: // "]"
      case 44: // "{"
      case 45: // "}"
      case 46: // "<"
      case 47: // L_ANGLE_ARGS
      case 48: // ">"
      case 49: // R_ANGLE_SHIFT
      case 50: // "("
      case 51: // ")"
      case 52: // "!"
      case 53: // ":"
      case 54: // ","
      case 55: // "?"
      case 56: // "."
      case 57: // "="
      case 58: // ";"
      case 59: // "@"
      case 60: // "++"
      case 61: // "_"
      case 62: // "&&&"
      case 63: // ".."
      case 64: // TRUE
      case 65: // FALSE
      case 66: // THIS
      case 67: // ABSTRACT
      case 68: // ACTION
      case 69: // ACTIONS
      case 70: // APPLY
      case 71: // BOOL
      case 72: // BIT
      case 73: // CONST
      case 74: // CONTROL
      case 75: // DEFAULT
      case 76: // ELSE
      case 77: // ENTRIES
      case 78: // ENUM
      case 79: // ERROR
      case 80: // EXIT
      case 81: // EXTERN
      case 82: // HEADER
      case 83: // HEADER_UNION
      case 84: // IF
      case 85: // IN
      case 86: // INOUT
      case 87: // INT
      case 88: // KEY
      case 89: // SELECT
      case 90: // MATCH_KIND
      case 91: // TYPE
      case 92: // OUT
      case 93: // PACKAGE
      case 94: // PARSER
      case 95: // PRAGMA
      case 96: // RETURN
      case 97: // STATE
      case 98: // STRING
      case 99: // STRUCT
      case 100: // SWITCH
      case 101: // TABLE
      case 102: // TRANSITION
      case 103: // TUPLE
      case 104: // TYPEDEF
      case 105: // VARBIT
      case 106: // VALUESET
      case 107: // VOID
      case 129: // annotationToken
        value.copy< Token > (other.value);
        break;

      case 111: // INTEGER
        value.copy< UnparsedConstant > (other.value);
        break;

      case 108: // IDENTIFIER
      case 109: // TYPE_IDENTIFIER
      case 110: // STRING_LITERAL
        value.copy< cstring > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      case 184: // typeRef
      case 185: // namedType
      case 188: // tupleType
      case 189: // headerStackType
      case 190: // specializedType
      case 191: // baseType
      case 192: // typeOrVoid
      case 196: // typeArg
      case 198: // realTypeArg
        value.copy< ConstType* > (v);
        break;

      case 127: // annotation
        value.copy< IR::Annotation* > (v);
        break;

      case 125: // optAnnotations
        value.copy< IR::Annotations* > (v);
        break;

      case 254: // argument
        value.copy< IR::Argument* > (v);
        break;

      case 140: // objInitializer
      case 157: // parserBlockStatement
      case 176: // controlBody
      case 229: // blockStatement
        value.copy< IR::BlockStatement* > (v);
        break;

      case 139: // instantiation
      case 143: // objDeclaration
      case 148: // parserLocalElement
      case 169: // valueSetDeclaration
      case 175: // controlLocalDeclaration
      case 237: // tableDeclaration
      case 246: // actionDeclaration
      case 247: // variableDeclaration
      case 248: // constantDeclaration
      case 251: // functionDeclaration
        value.copy< IR::Declaration* > (v);
        break;

      case 135: // direction
        value.copy< IR::Direction > (v);
        break;

      case 244: // entry
        value.copy< IR::Entry* > (v);
        break;

      case 117: // p4rtControllerType
      case 159: // transitionStatement
      case 160: // stateExpression
      case 161: // selectExpression
      case 164: // keysetExpression
      case 167: // reducedSimpleKeysetExpression
      case 168: // simpleKeysetExpression
      case 235: // switchLabel
      case 243: // actionRef
      case 249: // optInitializer
      case 250: // initializer
      case 259: // lvalue
      case 260: // expression
      case 261: // nonBraceExpression
      case 262: // intOrStr
        value.copy< IR::Expression* > (v);
        break;

      case 121: // nonTypeName
      case 122: // name
      case 123: // nonTableKwName
      case 257: // dot_name
        value.copy< IR::ID* > (v);
        break;

      case 242: // actionList
        value.copy< IR::IndexedVector<IR::ActionListElement>* > (v);
        break;

      case 147: // parserLocalElements
      case 174: // controlLocalDeclarations
        value.copy< IR::IndexedVector<IR::Declaration>* > (v);
        break;

      case 220: // identifierList
        value.copy< IR::IndexedVector<IR::Declaration_ID>* > (v);
        break;

      case 130: // kvList
        value.copy< IR::IndexedVector<IR::NamedExpression>* > (v);
        break;

      case 132: // parameterList
      case 133: // nonEmptyParameterList
      case 144: // optConstructorParameters
        value.copy< IR::IndexedVector<IR::Parameter>* > (v);
        break;

      case 152: // parserStates
        value.copy< IR::IndexedVector<IR::ParserState>* > (v);
        break;

      case 238: // tablePropertyList
        value.copy< IR::IndexedVector<IR::Property>* > (v);
        break;

      case 216: // specifiedIdentifierList
        value.copy< IR::IndexedVector<IR::SerEnumMember>* > (v);
        break;

      case 142: // objDeclarations
      case 155: // parserStatements
      case 231: // statOrDeclList
        value.copy< IR::IndexedVector<IR::StatOrDecl>* > (v);
        break;

      case 211: // structFieldList
        value.copy< IR::IndexedVector<IR::StructField>* > (v);
        break;

      case 195: // typeParameterList
        value.copy< IR::IndexedVector<IR::Type_Var>* > (v);
        break;

      case 241: // keyElement
        value.copy< IR::KeyElement* > (v);
        break;

      case 181: // functionPrototype
      case 183: // methodPrototype
        value.copy< IR::Method* > (v);
        break;

      case 131: // kvPair
        value.copy< IR::NamedExpression* > (v);
        break;

      case 116: // fragment
      case 120: // declaration
      case 177: // externDeclaration
      case 219: // matchKindDeclaration
        value.copy< IR::Node* > (v);
        break;

      case 134: // parameter
        value.copy< IR::Parameter* > (v);
        break;

      case 153: // parserState
        value.copy< IR::ParserState* > (v);
        break;

      case 186: // prefixedType
      case 256: // prefixedNonTypeName
        value.copy< IR::Path* > (v);
        break;

      case 239: // tableProperty
        value.copy< IR::Property* > (v);
        break;

      case 163: // selectCase
        value.copy< IR::SelectCase* > (v);
        break;

      case 217: // specifiedIdentifier
        value.copy< IR::SerEnumMember* > (v);
        break;

      case 156: // parserStatement
      case 236: // statementOrDeclaration
        value.copy< IR::StatOrDecl* > (v);
        break;

      case 222: // assignmentOrMethodCallStatement
      case 223: // emptyStatement
      case 224: // exitStatement
      case 225: // returnStatement
      case 226: // conditionalStatement
      case 227: // directApplication
      case 228: // statement
      case 232: // switchStatement
        value.copy< IR::Statement* > (v);
        break;

      case 212: // structField
        value.copy< IR::StructField* > (v);
        break;

      case 234: // switchCase
        value.copy< IR::SwitchCase* > (v);
        break;

      case 193: // optTypeParameters
      case 194: // typeParameters
        value.copy< IR::TypeParameters* > (v);
        break;

      case 171: // controlTypeDeclaration
        value.copy< IR::Type_Control* > (v);
        break;

      case 136: // packageTypeDeclaration
      case 146: // parserDeclaration
      case 170: // controlDeclaration
      case 200: // typeDeclaration
      case 201: // derivedTypeDeclaration
      case 202: // headerTypeDeclaration
      case 205: // structTypeDeclaration
      case 208: // headerUnionDeclaration
      case 213: // enumDeclaration
      case 221: // typedefDeclaration
        value.copy< IR::Type_Declaration* > (v);
        break;

      case 218: // errorDeclaration
        value.copy< IR::Type_Error* > (v);
        break;

      case 187: // typeName
        value.copy< IR::Type_Name* > (v);
        break;

      case 149: // parserTypeDeclaration
        value.copy< IR::Type_Parser* > (v);
        break;

      case 126: // annotations
        value.copy< IR::Vector<IR::Annotation>* > (v);
        break;

      case 128: // annotationBody
        value.copy< IR::Vector<IR::AnnotationToken>* > (v);
        break;

      case 252: // argumentList
      case 253: // nonEmptyArgList
        value.copy< IR::Vector<IR::Argument>* > (v);
        break;

      case 245: // entriesList
        value.copy< IR::Vector<IR::Entry>* > (v);
        break;

      case 165: // tupleKeysetExpression
      case 166: // simpleExpressionList
      case 255: // expressionList
      case 263: // intList
      case 264: // intOrStrList
      case 265: // strList
        value.copy< IR::Vector<IR::Expression>* > (v);
        break;

      case 240: // keyElementList
        value.copy< IR::Vector<IR::KeyElement>* > (v);
        break;

      case 180: // methodPrototypes
        value.copy< IR::Vector<IR::Method>* > (v);
        break;

      case 162: // selectCaseList
        value.copy< IR::Vector<IR::SelectCase>* > (v);
        break;

      case 233: // switchCases
        value.copy< IR::Vector<IR::SwitchCase>* > (v);
        break;

      case 197: // typeArgumentList
      case 199: // realTypeArgumentList
        value.copy< IR::Vector<IR::Type>* > (v);
        break;

      case 124: // optCONST
        value.copy< OptionalConst > (v);
        break;

      case 22: // UNEXPECTED_TOKEN
      case 23: // END_PRAGMA
      case 24: // "<="
      case 25: // ">="
      case 26: // "<<"
      case 27: // "&&"
      case 28: // "||"
      case 29: // "!="
      case 30: // "=="
      case 31: // "+"
      case 32: // "-"
      case 33: // "|+|"
      case 34: // "|-|"
      case 35: // "*"
      case 36: // "/"
      case 37: // "%"
      case 38: // "|"
      case 39: // "&"
      case 40: // "^"
      case 41: // "~"
      case 42: // "["
      case 43: // "]"
      case 44: // "{"
      case 45: // "}"
      case 46: // "<"
      case 47: // L_ANGLE_ARGS
      case 48: // ">"
      case 49: // R_ANGLE_SHIFT
      case 50: // "("
      case 51: // ")"
      case 52: // "!"
      case 53: // ":"
      case 54: // ","
      case 55: // "?"
      case 56: // "."
      case 57: // "="
      case 58: // ";"
      case 59: // "@"
      case 60: // "++"
      case 61: // "_"
      case 62: // "&&&"
      case 63: // ".."
      case 64: // TRUE
      case 65: // FALSE
      case 66: // THIS
      case 67: // ABSTRACT
      case 68: // ACTION
      case 69: // ACTIONS
      case 70: // APPLY
      case 71: // BOOL
      case 72: // BIT
      case 73: // CONST
      case 74: // CONTROL
      case 75: // DEFAULT
      case 76: // ELSE
      case 77: // ENTRIES
      case 78: // ENUM
      case 79: // ERROR
      case 80: // EXIT
      case 81: // EXTERN
      case 82: // HEADER
      case 83: // HEADER_UNION
      case 84: // IF
      case 85: // IN
      case 86: // INOUT
      case 87: // INT
      case 88: // KEY
      case 89: // SELECT
      case 90: // MATCH_KIND
      case 91: // TYPE
      case 92: // OUT
      case 93: // PACKAGE
      case 94: // PARSER
      case 95: // PRAGMA
      case 96: // RETURN
      case 97: // STATE
      case 98: // STRING
      case 99: // STRUCT
      case 100: // SWITCH
      case 101: // TABLE
      case 102: // TRANSITION
      case 103: // TUPLE
      case 104: // TYPEDEF
      case 105: // VARBIT
      case 106: // VALUESET
      case 107: // VOID
      case 129: // annotationToken
        value.copy< Token > (v);
        break;

      case 111: // INTEGER
        value.copy< UnparsedConstant > (v);
        break;

      case 108: // IDENTIFIER
      case 109: // TYPE_IDENTIFIER
      case 110: // STRING_LITERAL
        value.copy< cstring > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ConstType* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Annotation* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Annotations* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Argument* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::BlockStatement* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Declaration* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Direction v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Entry* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Expression* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::ID* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::IndexedVector<IR::ActionListElement>* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::IndexedVector<IR::Declaration>* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::IndexedVector<IR::Declaration_ID>* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::IndexedVector<IR::NamedExpression>* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::IndexedVector<IR::Parameter>* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::IndexedVector<IR::ParserState>* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::IndexedVector<IR::Property>* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::IndexedVector<IR::SerEnumMember>* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::IndexedVector<IR::StatOrDecl>* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::IndexedVector<IR::StructField>* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::IndexedVector<IR::Type_Var>* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::KeyElement* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Method* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::NamedExpression* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Node* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Parameter* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::ParserState* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Path* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Property* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::SelectCase* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::SerEnumMember* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::StatOrDecl* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Statement* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::StructField* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::SwitchCase* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::TypeParameters* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Type_Control* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Type_Declaration* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Type_Error* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Type_Name* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Type_Parser* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Vector<IR::Annotation>* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Vector<IR::AnnotationToken>* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Vector<IR::Argument>* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Vector<IR::Entry>* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Vector<IR::Expression>* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Vector<IR::KeyElement>* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Vector<IR::Method>* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Vector<IR::SelectCase>* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Vector<IR::SwitchCase>* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Vector<IR::Type>* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const OptionalConst v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const Token v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const UnparsedConstant v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  P4Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const cstring v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  inline
  P4Parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  P4Parser::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 184: // typeRef
      case 185: // namedType
      case 188: // tupleType
      case 189: // headerStackType
      case 190: // specializedType
      case 191: // baseType
      case 192: // typeOrVoid
      case 196: // typeArg
      case 198: // realTypeArg
        value.template destroy< ConstType* > ();
        break;

      case 127: // annotation
        value.template destroy< IR::Annotation* > ();
        break;

      case 125: // optAnnotations
        value.template destroy< IR::Annotations* > ();
        break;

      case 254: // argument
        value.template destroy< IR::Argument* > ();
        break;

      case 140: // objInitializer
      case 157: // parserBlockStatement
      case 176: // controlBody
      case 229: // blockStatement
        value.template destroy< IR::BlockStatement* > ();
        break;

      case 139: // instantiation
      case 143: // objDeclaration
      case 148: // parserLocalElement
      case 169: // valueSetDeclaration
      case 175: // controlLocalDeclaration
      case 237: // tableDeclaration
      case 246: // actionDeclaration
      case 247: // variableDeclaration
      case 248: // constantDeclaration
      case 251: // functionDeclaration
        value.template destroy< IR::Declaration* > ();
        break;

      case 135: // direction
        value.template destroy< IR::Direction > ();
        break;

      case 244: // entry
        value.template destroy< IR::Entry* > ();
        break;

      case 117: // p4rtControllerType
      case 159: // transitionStatement
      case 160: // stateExpression
      case 161: // selectExpression
      case 164: // keysetExpression
      case 167: // reducedSimpleKeysetExpression
      case 168: // simpleKeysetExpression
      case 235: // switchLabel
      case 243: // actionRef
      case 249: // optInitializer
      case 250: // initializer
      case 259: // lvalue
      case 260: // expression
      case 261: // nonBraceExpression
      case 262: // intOrStr
        value.template destroy< IR::Expression* > ();
        break;

      case 121: // nonTypeName
      case 122: // name
      case 123: // nonTableKwName
      case 257: // dot_name
        value.template destroy< IR::ID* > ();
        break;

      case 242: // actionList
        value.template destroy< IR::IndexedVector<IR::ActionListElement>* > ();
        break;

      case 147: // parserLocalElements
      case 174: // controlLocalDeclarations
        value.template destroy< IR::IndexedVector<IR::Declaration>* > ();
        break;

      case 220: // identifierList
        value.template destroy< IR::IndexedVector<IR::Declaration_ID>* > ();
        break;

      case 130: // kvList
        value.template destroy< IR::IndexedVector<IR::NamedExpression>* > ();
        break;

      case 132: // parameterList
      case 133: // nonEmptyParameterList
      case 144: // optConstructorParameters
        value.template destroy< IR::IndexedVector<IR::Parameter>* > ();
        break;

      case 152: // parserStates
        value.template destroy< IR::IndexedVector<IR::ParserState>* > ();
        break;

      case 238: // tablePropertyList
        value.template destroy< IR::IndexedVector<IR::Property>* > ();
        break;

      case 216: // specifiedIdentifierList
        value.template destroy< IR::IndexedVector<IR::SerEnumMember>* > ();
        break;

      case 142: // objDeclarations
      case 155: // parserStatements
      case 231: // statOrDeclList
        value.template destroy< IR::IndexedVector<IR::StatOrDecl>* > ();
        break;

      case 211: // structFieldList
        value.template destroy< IR::IndexedVector<IR::StructField>* > ();
        break;

      case 195: // typeParameterList
        value.template destroy< IR::IndexedVector<IR::Type_Var>* > ();
        break;

      case 241: // keyElement
        value.template destroy< IR::KeyElement* > ();
        break;

      case 181: // functionPrototype
      case 183: // methodPrototype
        value.template destroy< IR::Method* > ();
        break;

      case 131: // kvPair
        value.template destroy< IR::NamedExpression* > ();
        break;

      case 116: // fragment
      case 120: // declaration
      case 177: // externDeclaration
      case 219: // matchKindDeclaration
        value.template destroy< IR::Node* > ();
        break;

      case 134: // parameter
        value.template destroy< IR::Parameter* > ();
        break;

      case 153: // parserState
        value.template destroy< IR::ParserState* > ();
        break;

      case 186: // prefixedType
      case 256: // prefixedNonTypeName
        value.template destroy< IR::Path* > ();
        break;

      case 239: // tableProperty
        value.template destroy< IR::Property* > ();
        break;

      case 163: // selectCase
        value.template destroy< IR::SelectCase* > ();
        break;

      case 217: // specifiedIdentifier
        value.template destroy< IR::SerEnumMember* > ();
        break;

      case 156: // parserStatement
      case 236: // statementOrDeclaration
        value.template destroy< IR::StatOrDecl* > ();
        break;

      case 222: // assignmentOrMethodCallStatement
      case 223: // emptyStatement
      case 224: // exitStatement
      case 225: // returnStatement
      case 226: // conditionalStatement
      case 227: // directApplication
      case 228: // statement
      case 232: // switchStatement
        value.template destroy< IR::Statement* > ();
        break;

      case 212: // structField
        value.template destroy< IR::StructField* > ();
        break;

      case 234: // switchCase
        value.template destroy< IR::SwitchCase* > ();
        break;

      case 193: // optTypeParameters
      case 194: // typeParameters
        value.template destroy< IR::TypeParameters* > ();
        break;

      case 171: // controlTypeDeclaration
        value.template destroy< IR::Type_Control* > ();
        break;

      case 136: // packageTypeDeclaration
      case 146: // parserDeclaration
      case 170: // controlDeclaration
      case 200: // typeDeclaration
      case 201: // derivedTypeDeclaration
      case 202: // headerTypeDeclaration
      case 205: // structTypeDeclaration
      case 208: // headerUnionDeclaration
      case 213: // enumDeclaration
      case 221: // typedefDeclaration
        value.template destroy< IR::Type_Declaration* > ();
        break;

      case 218: // errorDeclaration
        value.template destroy< IR::Type_Error* > ();
        break;

      case 187: // typeName
        value.template destroy< IR::Type_Name* > ();
        break;

      case 149: // parserTypeDeclaration
        value.template destroy< IR::Type_Parser* > ();
        break;

      case 126: // annotations
        value.template destroy< IR::Vector<IR::Annotation>* > ();
        break;

      case 128: // annotationBody
        value.template destroy< IR::Vector<IR::AnnotationToken>* > ();
        break;

      case 252: // argumentList
      case 253: // nonEmptyArgList
        value.template destroy< IR::Vector<IR::Argument>* > ();
        break;

      case 245: // entriesList
        value.template destroy< IR::Vector<IR::Entry>* > ();
        break;

      case 165: // tupleKeysetExpression
      case 166: // simpleExpressionList
      case 255: // expressionList
      case 263: // intList
      case 264: // intOrStrList
      case 265: // strList
        value.template destroy< IR::Vector<IR::Expression>* > ();
        break;

      case 240: // keyElementList
        value.template destroy< IR::Vector<IR::KeyElement>* > ();
        break;

      case 180: // methodPrototypes
        value.template destroy< IR::Vector<IR::Method>* > ();
        break;

      case 162: // selectCaseList
        value.template destroy< IR::Vector<IR::SelectCase>* > ();
        break;

      case 233: // switchCases
        value.template destroy< IR::Vector<IR::SwitchCase>* > ();
        break;

      case 197: // typeArgumentList
      case 199: // realTypeArgumentList
        value.template destroy< IR::Vector<IR::Type>* > ();
        break;

      case 124: // optCONST
        value.template destroy< OptionalConst > ();
        break;

      case 22: // UNEXPECTED_TOKEN
      case 23: // END_PRAGMA
      case 24: // "<="
      case 25: // ">="
      case 26: // "<<"
      case 27: // "&&"
      case 28: // "||"
      case 29: // "!="
      case 30: // "=="
      case 31: // "+"
      case 32: // "-"
      case 33: // "|+|"
      case 34: // "|-|"
      case 35: // "*"
      case 36: // "/"
      case 37: // "%"
      case 38: // "|"
      case 39: // "&"
      case 40: // "^"
      case 41: // "~"
      case 42: // "["
      case 43: // "]"
      case 44: // "{"
      case 45: // "}"
      case 46: // "<"
      case 47: // L_ANGLE_ARGS
      case 48: // ">"
      case 49: // R_ANGLE_SHIFT
      case 50: // "("
      case 51: // ")"
      case 52: // "!"
      case 53: // ":"
      case 54: // ","
      case 55: // "?"
      case 56: // "."
      case 57: // "="
      case 58: // ";"
      case 59: // "@"
      case 60: // "++"
      case 61: // "_"
      case 62: // "&&&"
      case 63: // ".."
      case 64: // TRUE
      case 65: // FALSE
      case 66: // THIS
      case 67: // ABSTRACT
      case 68: // ACTION
      case 69: // ACTIONS
      case 70: // APPLY
      case 71: // BOOL
      case 72: // BIT
      case 73: // CONST
      case 74: // CONTROL
      case 75: // DEFAULT
      case 76: // ELSE
      case 77: // ENTRIES
      case 78: // ENUM
      case 79: // ERROR
      case 80: // EXIT
      case 81: // EXTERN
      case 82: // HEADER
      case 83: // HEADER_UNION
      case 84: // IF
      case 85: // IN
      case 86: // INOUT
      case 87: // INT
      case 88: // KEY
      case 89: // SELECT
      case 90: // MATCH_KIND
      case 91: // TYPE
      case 92: // OUT
      case 93: // PACKAGE
      case 94: // PARSER
      case 95: // PRAGMA
      case 96: // RETURN
      case 97: // STATE
      case 98: // STRING
      case 99: // STRUCT
      case 100: // SWITCH
      case 101: // TABLE
      case 102: // TRANSITION
      case 103: // TUPLE
      case 104: // TYPEDEF
      case 105: // VARBIT
      case 106: // VALUESET
      case 107: // VOID
      case 129: // annotationToken
        value.template destroy< Token > ();
        break;

      case 111: // INTEGER
        value.template destroy< UnparsedConstant > ();
        break;

      case 108: // IDENTIFIER
      case 109: // TYPE_IDENTIFIER
      case 110: // STRING_LITERAL
        value.template destroy< cstring > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  P4Parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  P4Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 184: // typeRef
      case 185: // namedType
      case 188: // tupleType
      case 189: // headerStackType
      case 190: // specializedType
      case 191: // baseType
      case 192: // typeOrVoid
      case 196: // typeArg
      case 198: // realTypeArg
        value.move< ConstType* > (s.value);
        break;

      case 127: // annotation
        value.move< IR::Annotation* > (s.value);
        break;

      case 125: // optAnnotations
        value.move< IR::Annotations* > (s.value);
        break;

      case 254: // argument
        value.move< IR::Argument* > (s.value);
        break;

      case 140: // objInitializer
      case 157: // parserBlockStatement
      case 176: // controlBody
      case 229: // blockStatement
        value.move< IR::BlockStatement* > (s.value);
        break;

      case 139: // instantiation
      case 143: // objDeclaration
      case 148: // parserLocalElement
      case 169: // valueSetDeclaration
      case 175: // controlLocalDeclaration
      case 237: // tableDeclaration
      case 246: // actionDeclaration
      case 247: // variableDeclaration
      case 248: // constantDeclaration
      case 251: // functionDeclaration
        value.move< IR::Declaration* > (s.value);
        break;

      case 135: // direction
        value.move< IR::Direction > (s.value);
        break;

      case 244: // entry
        value.move< IR::Entry* > (s.value);
        break;

      case 117: // p4rtControllerType
      case 159: // transitionStatement
      case 160: // stateExpression
      case 161: // selectExpression
      case 164: // keysetExpression
      case 167: // reducedSimpleKeysetExpression
      case 168: // simpleKeysetExpression
      case 235: // switchLabel
      case 243: // actionRef
      case 249: // optInitializer
      case 250: // initializer
      case 259: // lvalue
      case 260: // expression
      case 261: // nonBraceExpression
      case 262: // intOrStr
        value.move< IR::Expression* > (s.value);
        break;

      case 121: // nonTypeName
      case 122: // name
      case 123: // nonTableKwName
      case 257: // dot_name
        value.move< IR::ID* > (s.value);
        break;

      case 242: // actionList
        value.move< IR::IndexedVector<IR::ActionListElement>* > (s.value);
        break;

      case 147: // parserLocalElements
      case 174: // controlLocalDeclarations
        value.move< IR::IndexedVector<IR::Declaration>* > (s.value);
        break;

      case 220: // identifierList
        value.move< IR::IndexedVector<IR::Declaration_ID>* > (s.value);
        break;

      case 130: // kvList
        value.move< IR::IndexedVector<IR::NamedExpression>* > (s.value);
        break;

      case 132: // parameterList
      case 133: // nonEmptyParameterList
      case 144: // optConstructorParameters
        value.move< IR::IndexedVector<IR::Parameter>* > (s.value);
        break;

      case 152: // parserStates
        value.move< IR::IndexedVector<IR::ParserState>* > (s.value);
        break;

      case 238: // tablePropertyList
        value.move< IR::IndexedVector<IR::Property>* > (s.value);
        break;

      case 216: // specifiedIdentifierList
        value.move< IR::IndexedVector<IR::SerEnumMember>* > (s.value);
        break;

      case 142: // objDeclarations
      case 155: // parserStatements
      case 231: // statOrDeclList
        value.move< IR::IndexedVector<IR::StatOrDecl>* > (s.value);
        break;

      case 211: // structFieldList
        value.move< IR::IndexedVector<IR::StructField>* > (s.value);
        break;

      case 195: // typeParameterList
        value.move< IR::IndexedVector<IR::Type_Var>* > (s.value);
        break;

      case 241: // keyElement
        value.move< IR::KeyElement* > (s.value);
        break;

      case 181: // functionPrototype
      case 183: // methodPrototype
        value.move< IR::Method* > (s.value);
        break;

      case 131: // kvPair
        value.move< IR::NamedExpression* > (s.value);
        break;

      case 116: // fragment
      case 120: // declaration
      case 177: // externDeclaration
      case 219: // matchKindDeclaration
        value.move< IR::Node* > (s.value);
        break;

      case 134: // parameter
        value.move< IR::Parameter* > (s.value);
        break;

      case 153: // parserState
        value.move< IR::ParserState* > (s.value);
        break;

      case 186: // prefixedType
      case 256: // prefixedNonTypeName
        value.move< IR::Path* > (s.value);
        break;

      case 239: // tableProperty
        value.move< IR::Property* > (s.value);
        break;

      case 163: // selectCase
        value.move< IR::SelectCase* > (s.value);
        break;

      case 217: // specifiedIdentifier
        value.move< IR::SerEnumMember* > (s.value);
        break;

      case 156: // parserStatement
      case 236: // statementOrDeclaration
        value.move< IR::StatOrDecl* > (s.value);
        break;

      case 222: // assignmentOrMethodCallStatement
      case 223: // emptyStatement
      case 224: // exitStatement
      case 225: // returnStatement
      case 226: // conditionalStatement
      case 227: // directApplication
      case 228: // statement
      case 232: // switchStatement
        value.move< IR::Statement* > (s.value);
        break;

      case 212: // structField
        value.move< IR::StructField* > (s.value);
        break;

      case 234: // switchCase
        value.move< IR::SwitchCase* > (s.value);
        break;

      case 193: // optTypeParameters
      case 194: // typeParameters
        value.move< IR::TypeParameters* > (s.value);
        break;

      case 171: // controlTypeDeclaration
        value.move< IR::Type_Control* > (s.value);
        break;

      case 136: // packageTypeDeclaration
      case 146: // parserDeclaration
      case 170: // controlDeclaration
      case 200: // typeDeclaration
      case 201: // derivedTypeDeclaration
      case 202: // headerTypeDeclaration
      case 205: // structTypeDeclaration
      case 208: // headerUnionDeclaration
      case 213: // enumDeclaration
      case 221: // typedefDeclaration
        value.move< IR::Type_Declaration* > (s.value);
        break;

      case 218: // errorDeclaration
        value.move< IR::Type_Error* > (s.value);
        break;

      case 187: // typeName
        value.move< IR::Type_Name* > (s.value);
        break;

      case 149: // parserTypeDeclaration
        value.move< IR::Type_Parser* > (s.value);
        break;

      case 126: // annotations
        value.move< IR::Vector<IR::Annotation>* > (s.value);
        break;

      case 128: // annotationBody
        value.move< IR::Vector<IR::AnnotationToken>* > (s.value);
        break;

      case 252: // argumentList
      case 253: // nonEmptyArgList
        value.move< IR::Vector<IR::Argument>* > (s.value);
        break;

      case 245: // entriesList
        value.move< IR::Vector<IR::Entry>* > (s.value);
        break;

      case 165: // tupleKeysetExpression
      case 166: // simpleExpressionList
      case 255: // expressionList
      case 263: // intList
      case 264: // intOrStrList
      case 265: // strList
        value.move< IR::Vector<IR::Expression>* > (s.value);
        break;

      case 240: // keyElementList
        value.move< IR::Vector<IR::KeyElement>* > (s.value);
        break;

      case 180: // methodPrototypes
        value.move< IR::Vector<IR::Method>* > (s.value);
        break;

      case 162: // selectCaseList
        value.move< IR::Vector<IR::SelectCase>* > (s.value);
        break;

      case 233: // switchCases
        value.move< IR::Vector<IR::SwitchCase>* > (s.value);
        break;

      case 197: // typeArgumentList
      case 199: // realTypeArgumentList
        value.move< IR::Vector<IR::Type>* > (s.value);
        break;

      case 124: // optCONST
        value.move< OptionalConst > (s.value);
        break;

      case 22: // UNEXPECTED_TOKEN
      case 23: // END_PRAGMA
      case 24: // "<="
      case 25: // ">="
      case 26: // "<<"
      case 27: // "&&"
      case 28: // "||"
      case 29: // "!="
      case 30: // "=="
      case 31: // "+"
      case 32: // "-"
      case 33: // "|+|"
      case 34: // "|-|"
      case 35: // "*"
      case 36: // "/"
      case 37: // "%"
      case 38: // "|"
      case 39: // "&"
      case 40: // "^"
      case 41: // "~"
      case 42: // "["
      case 43: // "]"
      case 44: // "{"
      case 45: // "}"
      case 46: // "<"
      case 47: // L_ANGLE_ARGS
      case 48: // ">"
      case 49: // R_ANGLE_SHIFT
      case 50: // "("
      case 51: // ")"
      case 52: // "!"
      case 53: // ":"
      case 54: // ","
      case 55: // "?"
      case 56: // "."
      case 57: // "="
      case 58: // ";"
      case 59: // "@"
      case 60: // "++"
      case 61: // "_"
      case 62: // "&&&"
      case 63: // ".."
      case 64: // TRUE
      case 65: // FALSE
      case 66: // THIS
      case 67: // ABSTRACT
      case 68: // ACTION
      case 69: // ACTIONS
      case 70: // APPLY
      case 71: // BOOL
      case 72: // BIT
      case 73: // CONST
      case 74: // CONTROL
      case 75: // DEFAULT
      case 76: // ELSE
      case 77: // ENTRIES
      case 78: // ENUM
      case 79: // ERROR
      case 80: // EXIT
      case 81: // EXTERN
      case 82: // HEADER
      case 83: // HEADER_UNION
      case 84: // IF
      case 85: // IN
      case 86: // INOUT
      case 87: // INT
      case 88: // KEY
      case 89: // SELECT
      case 90: // MATCH_KIND
      case 91: // TYPE
      case 92: // OUT
      case 93: // PACKAGE
      case 94: // PARSER
      case 95: // PRAGMA
      case 96: // RETURN
      case 97: // STATE
      case 98: // STRING
      case 99: // STRUCT
      case 100: // SWITCH
      case 101: // TABLE
      case 102: // TRANSITION
      case 103: // TUPLE
      case 104: // TYPEDEF
      case 105: // VARBIT
      case 106: // VALUESET
      case 107: // VOID
      case 129: // annotationToken
        value.move< Token > (s.value);
        break;

      case 111: // INTEGER
        value.move< UnparsedConstant > (s.value);
        break;

      case 108: // IDENTIFIER
      case 109: // TYPE_IDENTIFIER
      case 110: // STRING_LITERAL
        value.move< cstring > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
  P4Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  P4Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  P4Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  P4Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  P4Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  P4Parser::by_type::type_get () const
  {
    return type;
  }

  inline
  P4Parser::token_type
  P4Parser::by_type::token () const
  {
    // YYTOKNUM[NUM] -- (External) token number corresponding to the
    // (internal) symbol number NUM (which must be that of a token).  */
    static
    const unsigned short int
    yytoken_number_[] =
    {
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368
    };
    return static_cast<token_type> (yytoken_number_[type]);
  }
  // Implementation of make_symbol for each symbol type.
  P4Parser::symbol_type
  P4Parser::make_START_PROGRAM (const location_type& l)
  {
    return symbol_type (token::TOK_START_PROGRAM, l);
  }

  P4Parser::symbol_type
  P4Parser::make_START_EXPRESSION_LIST (const location_type& l)
  {
    return symbol_type (token::TOK_START_EXPRESSION_LIST, l);
  }

  P4Parser::symbol_type
  P4Parser::make_START_KV_LIST (const location_type& l)
  {
    return symbol_type (token::TOK_START_KV_LIST, l);
  }

  P4Parser::symbol_type
  P4Parser::make_START_INTEGER_LIST (const location_type& l)
  {
    return symbol_type (token::TOK_START_INTEGER_LIST, l);
  }

  P4Parser::symbol_type
  P4Parser::make_START_INTEGER_OR_STRING_LITERAL_LIST (const location_type& l)
  {
    return symbol_type (token::TOK_START_INTEGER_OR_STRING_LITERAL_LIST, l);
  }

  P4Parser::symbol_type
  P4Parser::make_START_STRING_LITERAL_LIST (const location_type& l)
  {
    return symbol_type (token::TOK_START_STRING_LITERAL_LIST, l);
  }

  P4Parser::symbol_type
  P4Parser::make_START_EXPRESSION (const location_type& l)
  {
    return symbol_type (token::TOK_START_EXPRESSION, l);
  }

  P4Parser::symbol_type
  P4Parser::make_START_INTEGER (const location_type& l)
  {
    return symbol_type (token::TOK_START_INTEGER, l);
  }

  P4Parser::symbol_type
  P4Parser::make_START_INTEGER_OR_STRING_LITERAL (const location_type& l)
  {
    return symbol_type (token::TOK_START_INTEGER_OR_STRING_LITERAL, l);
  }

  P4Parser::symbol_type
  P4Parser::make_START_STRING_LITERAL (const location_type& l)
  {
    return symbol_type (token::TOK_START_STRING_LITERAL, l);
  }

  P4Parser::symbol_type
  P4Parser::make_START_EXPRESSION_PAIR (const location_type& l)
  {
    return symbol_type (token::TOK_START_EXPRESSION_PAIR, l);
  }

  P4Parser::symbol_type
  P4Parser::make_START_INTEGER_PAIR (const location_type& l)
  {
    return symbol_type (token::TOK_START_INTEGER_PAIR, l);
  }

  P4Parser::symbol_type
  P4Parser::make_START_STRING_LITERAL_PAIR (const location_type& l)
  {
    return symbol_type (token::TOK_START_STRING_LITERAL_PAIR, l);
  }

  P4Parser::symbol_type
  P4Parser::make_START_EXPRESSION_TRIPLE (const location_type& l)
  {
    return symbol_type (token::TOK_START_EXPRESSION_TRIPLE, l);
  }

  P4Parser::symbol_type
  P4Parser::make_START_INTEGER_TRIPLE (const location_type& l)
  {
    return symbol_type (token::TOK_START_INTEGER_TRIPLE, l);
  }

  P4Parser::symbol_type
  P4Parser::make_START_STRING_LITERAL_TRIPLE (const location_type& l)
  {
    return symbol_type (token::TOK_START_STRING_LITERAL_TRIPLE, l);
  }

  P4Parser::symbol_type
  P4Parser::make_START_P4RT_TRANSLATION_ANNOTATION (const location_type& l)
  {
    return symbol_type (token::TOK_START_P4RT_TRANSLATION_ANNOTATION, l);
  }

  P4Parser::symbol_type
  P4Parser::make_END (const location_type& l)
  {
    return symbol_type (token::TOK_END, l);
  }

  P4Parser::symbol_type
  P4Parser::make_END_ANNOTATION (const location_type& l)
  {
    return symbol_type (token::TOK_END_ANNOTATION, l);
  }

  P4Parser::symbol_type
  P4Parser::make_UNEXPECTED_TOKEN (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_UNEXPECTED_TOKEN, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_END_PRAGMA (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_END_PRAGMA, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_LE (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_LE, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_GE (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_GE, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_SHL (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_SHL, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_AND (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_AND, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_OR (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_OR, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_NE (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_NE, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_EQ (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_EQ, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_PLUS (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_PLUS, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_MINUS (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_MINUS, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_PLUS_SAT (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_PLUS_SAT, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_MINUS_SAT (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_MINUS_SAT, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_MUL (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_MUL, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_DIV (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_DIV, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_MOD (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_MOD, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_BIT_OR (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_BIT_OR, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_BIT_AND (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_BIT_AND, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_BIT_XOR (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_BIT_XOR, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_COMPLEMENT (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_COMPLEMENT, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_L_BRACKET (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_L_BRACKET, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_R_BRACKET (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_R_BRACKET, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_L_BRACE (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_L_BRACE, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_R_BRACE (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_R_BRACE, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_L_ANGLE (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_L_ANGLE, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_L_ANGLE_ARGS (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_L_ANGLE_ARGS, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_R_ANGLE (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_R_ANGLE, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_R_ANGLE_SHIFT (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_R_ANGLE_SHIFT, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_L_PAREN (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_L_PAREN, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_R_PAREN (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_R_PAREN, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_NOT (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_NOT, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_COLON (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_COLON, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_COMMA (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_COMMA, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_QUESTION (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_QUESTION, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_DOT (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_DOT, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_ASSIGN (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_ASSIGN, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_SEMICOLON (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_SEMICOLON, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_AT (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_AT, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_PP (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_PP, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_DONTCARE (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_DONTCARE, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_MASK (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_MASK, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_RANGE (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_RANGE, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_TRUE (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_TRUE, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_FALSE (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_FALSE, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_THIS (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_THIS, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_ABSTRACT (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_ABSTRACT, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_ACTION (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_ACTION, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_ACTIONS (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_ACTIONS, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_APPLY (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_APPLY, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_BOOL (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_BOOL, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_BIT (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_BIT, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_CONST (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_CONST, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_CONTROL (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_CONTROL, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_DEFAULT (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_DEFAULT, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_ELSE (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_ELSE, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_ENTRIES (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_ENTRIES, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_ENUM (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_ENUM, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_ERROR (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_ERROR, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_EXIT (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_EXIT, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_EXTERN (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_EXTERN, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_HEADER (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_HEADER, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_HEADER_UNION (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_HEADER_UNION, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_IF (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_IF, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_IN (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_IN, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_INOUT (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_INOUT, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_INT (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_INT, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_KEY (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_KEY, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_SELECT (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_SELECT, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_MATCH_KIND (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_MATCH_KIND, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_TYPE (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_TYPE, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_OUT (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_OUT, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_PACKAGE (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_PACKAGE, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_PARSER (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_PARSER, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_PRAGMA (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_PRAGMA, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_RETURN (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_RETURN, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_STATE (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_STATE, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_STRING (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_STRING, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_STRUCT (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_STRUCT, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_SWITCH (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_SWITCH, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_TABLE (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_TABLE, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_TRANSITION (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_TRANSITION, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_TUPLE (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_TUPLE, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_TYPEDEF (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_TYPEDEF, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_VARBIT (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_VARBIT, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_VALUESET (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_VALUESET, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_VOID (const Token& v, const location_type& l)
  {
    return symbol_type (token::TOK_VOID, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_IDENTIFIER (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_IDENTIFIER, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_TYPE_IDENTIFIER (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_TYPE_IDENTIFIER, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_STRING_LITERAL (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_STRING_LITERAL, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_INTEGER (const UnparsedConstant& v, const location_type& l)
  {
    return symbol_type (token::TOK_INTEGER, v, l);
  }

  P4Parser::symbol_type
  P4Parser::make_PREFIX (const location_type& l)
  {
    return symbol_type (token::TOK_PREFIX, l);
  }

  P4Parser::symbol_type
  P4Parser::make_THEN (const location_type& l)
  {
    return symbol_type (token::TOK_THEN, l);
  }


#line 23 "parsers/p4/p4parser.ypp" // lalr1.cc:377
} // P4
#line 4501 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.hpp" // lalr1.cc:377




#endif // !YY_YY_MEDIA_YEC_WORK_PROGRAMS_P4_VERIFICATION_P4B_TRANSLATOR_BUILD_FRONTENDS_PARSERS_P4_P4PARSER_HPP_INCLUDED
