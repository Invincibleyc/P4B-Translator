// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

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


// First part of user declarations.
#line 117 "parsers/p4/p4parser.ypp" // lalr1.cc:404
 /* -*-C++-*- */
#include "frontends/parsers/parserDriver.h"
#include "frontends/parsers/p4/p4lexer.hpp"
#include "frontends/parsers/p4/p4parser.hpp"

#define YYLLOC_DEFAULT(Cur, Rhs, N)                                             \
    ((Cur) = (N) ? YYRHSLOC(Rhs, 1) + YYRHSLOC(Rhs, N)                          \
                 : Util::SourceInfo(driver.sources, YYRHSLOC(Rhs, 0).getEnd()))

#undef yylex
#define yylex lexer.yylex


#line 50 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "p4parser.hpp"

// User implementation prologue.

#line 64 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:412


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 23 "parsers/p4/p4parser.ypp" // lalr1.cc:479
namespace P4 {
#line 150 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  P4Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  P4Parser::P4Parser (P4::P4ParserDriver& driver_yyarg, P4::AbstractP4Lexer& lexer_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg),
      lexer (lexer_yyarg)
  {}

  P4Parser::~P4Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  P4Parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  P4Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  P4Parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  P4Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  P4Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  P4Parser::symbol_number_type
  P4Parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  P4Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  P4Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
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
        value.move< ConstType* > (that.value);
        break;

      case 127: // annotation
        value.move< IR::Annotation* > (that.value);
        break;

      case 125: // optAnnotations
        value.move< IR::Annotations* > (that.value);
        break;

      case 254: // argument
        value.move< IR::Argument* > (that.value);
        break;

      case 140: // objInitializer
      case 157: // parserBlockStatement
      case 176: // controlBody
      case 229: // blockStatement
        value.move< IR::BlockStatement* > (that.value);
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
        value.move< IR::Declaration* > (that.value);
        break;

      case 135: // direction
        value.move< IR::Direction > (that.value);
        break;

      case 244: // entry
        value.move< IR::Entry* > (that.value);
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
        value.move< IR::Expression* > (that.value);
        break;

      case 121: // nonTypeName
      case 122: // name
      case 123: // nonTableKwName
      case 257: // dot_name
        value.move< IR::ID* > (that.value);
        break;

      case 242: // actionList
        value.move< IR::IndexedVector<IR::ActionListElement>* > (that.value);
        break;

      case 147: // parserLocalElements
      case 174: // controlLocalDeclarations
        value.move< IR::IndexedVector<IR::Declaration>* > (that.value);
        break;

      case 220: // identifierList
        value.move< IR::IndexedVector<IR::Declaration_ID>* > (that.value);
        break;

      case 130: // kvList
        value.move< IR::IndexedVector<IR::NamedExpression>* > (that.value);
        break;

      case 132: // parameterList
      case 133: // nonEmptyParameterList
      case 144: // optConstructorParameters
        value.move< IR::IndexedVector<IR::Parameter>* > (that.value);
        break;

      case 152: // parserStates
        value.move< IR::IndexedVector<IR::ParserState>* > (that.value);
        break;

      case 238: // tablePropertyList
        value.move< IR::IndexedVector<IR::Property>* > (that.value);
        break;

      case 216: // specifiedIdentifierList
        value.move< IR::IndexedVector<IR::SerEnumMember>* > (that.value);
        break;

      case 142: // objDeclarations
      case 155: // parserStatements
      case 231: // statOrDeclList
        value.move< IR::IndexedVector<IR::StatOrDecl>* > (that.value);
        break;

      case 211: // structFieldList
        value.move< IR::IndexedVector<IR::StructField>* > (that.value);
        break;

      case 195: // typeParameterList
        value.move< IR::IndexedVector<IR::Type_Var>* > (that.value);
        break;

      case 241: // keyElement
        value.move< IR::KeyElement* > (that.value);
        break;

      case 181: // functionPrototype
      case 183: // methodPrototype
        value.move< IR::Method* > (that.value);
        break;

      case 131: // kvPair
        value.move< IR::NamedExpression* > (that.value);
        break;

      case 116: // fragment
      case 120: // declaration
      case 177: // externDeclaration
      case 219: // matchKindDeclaration
        value.move< IR::Node* > (that.value);
        break;

      case 134: // parameter
        value.move< IR::Parameter* > (that.value);
        break;

      case 153: // parserState
        value.move< IR::ParserState* > (that.value);
        break;

      case 186: // prefixedType
      case 256: // prefixedNonTypeName
        value.move< IR::Path* > (that.value);
        break;

      case 239: // tableProperty
        value.move< IR::Property* > (that.value);
        break;

      case 163: // selectCase
        value.move< IR::SelectCase* > (that.value);
        break;

      case 217: // specifiedIdentifier
        value.move< IR::SerEnumMember* > (that.value);
        break;

      case 156: // parserStatement
      case 236: // statementOrDeclaration
        value.move< IR::StatOrDecl* > (that.value);
        break;

      case 222: // assignmentOrMethodCallStatement
      case 223: // emptyStatement
      case 224: // exitStatement
      case 225: // returnStatement
      case 226: // conditionalStatement
      case 227: // directApplication
      case 228: // statement
      case 232: // switchStatement
        value.move< IR::Statement* > (that.value);
        break;

      case 212: // structField
        value.move< IR::StructField* > (that.value);
        break;

      case 234: // switchCase
        value.move< IR::SwitchCase* > (that.value);
        break;

      case 193: // optTypeParameters
      case 194: // typeParameters
        value.move< IR::TypeParameters* > (that.value);
        break;

      case 171: // controlTypeDeclaration
        value.move< IR::Type_Control* > (that.value);
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
        value.move< IR::Type_Declaration* > (that.value);
        break;

      case 218: // errorDeclaration
        value.move< IR::Type_Error* > (that.value);
        break;

      case 187: // typeName
        value.move< IR::Type_Name* > (that.value);
        break;

      case 149: // parserTypeDeclaration
        value.move< IR::Type_Parser* > (that.value);
        break;

      case 126: // annotations
        value.move< IR::Vector<IR::Annotation>* > (that.value);
        break;

      case 128: // annotationBody
        value.move< IR::Vector<IR::AnnotationToken>* > (that.value);
        break;

      case 252: // argumentList
      case 253: // nonEmptyArgList
        value.move< IR::Vector<IR::Argument>* > (that.value);
        break;

      case 245: // entriesList
        value.move< IR::Vector<IR::Entry>* > (that.value);
        break;

      case 165: // tupleKeysetExpression
      case 166: // simpleExpressionList
      case 255: // expressionList
      case 263: // intList
      case 264: // intOrStrList
      case 265: // strList
        value.move< IR::Vector<IR::Expression>* > (that.value);
        break;

      case 240: // keyElementList
        value.move< IR::Vector<IR::KeyElement>* > (that.value);
        break;

      case 180: // methodPrototypes
        value.move< IR::Vector<IR::Method>* > (that.value);
        break;

      case 162: // selectCaseList
        value.move< IR::Vector<IR::SelectCase>* > (that.value);
        break;

      case 233: // switchCases
        value.move< IR::Vector<IR::SwitchCase>* > (that.value);
        break;

      case 197: // typeArgumentList
      case 199: // realTypeArgumentList
        value.move< IR::Vector<IR::Type>* > (that.value);
        break;

      case 124: // optCONST
        value.move< OptionalConst > (that.value);
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
        value.move< Token > (that.value);
        break;

      case 111: // INTEGER
        value.move< UnparsedConstant > (that.value);
        break;

      case 108: // IDENTIFIER
      case 109: // TYPE_IDENTIFIER
      case 110: // STRING_LITERAL
        value.move< cstring > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  P4Parser::stack_symbol_type&
  P4Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
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
        value.copy< ConstType* > (that.value);
        break;

      case 127: // annotation
        value.copy< IR::Annotation* > (that.value);
        break;

      case 125: // optAnnotations
        value.copy< IR::Annotations* > (that.value);
        break;

      case 254: // argument
        value.copy< IR::Argument* > (that.value);
        break;

      case 140: // objInitializer
      case 157: // parserBlockStatement
      case 176: // controlBody
      case 229: // blockStatement
        value.copy< IR::BlockStatement* > (that.value);
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
        value.copy< IR::Declaration* > (that.value);
        break;

      case 135: // direction
        value.copy< IR::Direction > (that.value);
        break;

      case 244: // entry
        value.copy< IR::Entry* > (that.value);
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
        value.copy< IR::Expression* > (that.value);
        break;

      case 121: // nonTypeName
      case 122: // name
      case 123: // nonTableKwName
      case 257: // dot_name
        value.copy< IR::ID* > (that.value);
        break;

      case 242: // actionList
        value.copy< IR::IndexedVector<IR::ActionListElement>* > (that.value);
        break;

      case 147: // parserLocalElements
      case 174: // controlLocalDeclarations
        value.copy< IR::IndexedVector<IR::Declaration>* > (that.value);
        break;

      case 220: // identifierList
        value.copy< IR::IndexedVector<IR::Declaration_ID>* > (that.value);
        break;

      case 130: // kvList
        value.copy< IR::IndexedVector<IR::NamedExpression>* > (that.value);
        break;

      case 132: // parameterList
      case 133: // nonEmptyParameterList
      case 144: // optConstructorParameters
        value.copy< IR::IndexedVector<IR::Parameter>* > (that.value);
        break;

      case 152: // parserStates
        value.copy< IR::IndexedVector<IR::ParserState>* > (that.value);
        break;

      case 238: // tablePropertyList
        value.copy< IR::IndexedVector<IR::Property>* > (that.value);
        break;

      case 216: // specifiedIdentifierList
        value.copy< IR::IndexedVector<IR::SerEnumMember>* > (that.value);
        break;

      case 142: // objDeclarations
      case 155: // parserStatements
      case 231: // statOrDeclList
        value.copy< IR::IndexedVector<IR::StatOrDecl>* > (that.value);
        break;

      case 211: // structFieldList
        value.copy< IR::IndexedVector<IR::StructField>* > (that.value);
        break;

      case 195: // typeParameterList
        value.copy< IR::IndexedVector<IR::Type_Var>* > (that.value);
        break;

      case 241: // keyElement
        value.copy< IR::KeyElement* > (that.value);
        break;

      case 181: // functionPrototype
      case 183: // methodPrototype
        value.copy< IR::Method* > (that.value);
        break;

      case 131: // kvPair
        value.copy< IR::NamedExpression* > (that.value);
        break;

      case 116: // fragment
      case 120: // declaration
      case 177: // externDeclaration
      case 219: // matchKindDeclaration
        value.copy< IR::Node* > (that.value);
        break;

      case 134: // parameter
        value.copy< IR::Parameter* > (that.value);
        break;

      case 153: // parserState
        value.copy< IR::ParserState* > (that.value);
        break;

      case 186: // prefixedType
      case 256: // prefixedNonTypeName
        value.copy< IR::Path* > (that.value);
        break;

      case 239: // tableProperty
        value.copy< IR::Property* > (that.value);
        break;

      case 163: // selectCase
        value.copy< IR::SelectCase* > (that.value);
        break;

      case 217: // specifiedIdentifier
        value.copy< IR::SerEnumMember* > (that.value);
        break;

      case 156: // parserStatement
      case 236: // statementOrDeclaration
        value.copy< IR::StatOrDecl* > (that.value);
        break;

      case 222: // assignmentOrMethodCallStatement
      case 223: // emptyStatement
      case 224: // exitStatement
      case 225: // returnStatement
      case 226: // conditionalStatement
      case 227: // directApplication
      case 228: // statement
      case 232: // switchStatement
        value.copy< IR::Statement* > (that.value);
        break;

      case 212: // structField
        value.copy< IR::StructField* > (that.value);
        break;

      case 234: // switchCase
        value.copy< IR::SwitchCase* > (that.value);
        break;

      case 193: // optTypeParameters
      case 194: // typeParameters
        value.copy< IR::TypeParameters* > (that.value);
        break;

      case 171: // controlTypeDeclaration
        value.copy< IR::Type_Control* > (that.value);
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
        value.copy< IR::Type_Declaration* > (that.value);
        break;

      case 218: // errorDeclaration
        value.copy< IR::Type_Error* > (that.value);
        break;

      case 187: // typeName
        value.copy< IR::Type_Name* > (that.value);
        break;

      case 149: // parserTypeDeclaration
        value.copy< IR::Type_Parser* > (that.value);
        break;

      case 126: // annotations
        value.copy< IR::Vector<IR::Annotation>* > (that.value);
        break;

      case 128: // annotationBody
        value.copy< IR::Vector<IR::AnnotationToken>* > (that.value);
        break;

      case 252: // argumentList
      case 253: // nonEmptyArgList
        value.copy< IR::Vector<IR::Argument>* > (that.value);
        break;

      case 245: // entriesList
        value.copy< IR::Vector<IR::Entry>* > (that.value);
        break;

      case 165: // tupleKeysetExpression
      case 166: // simpleExpressionList
      case 255: // expressionList
      case 263: // intList
      case 264: // intOrStrList
      case 265: // strList
        value.copy< IR::Vector<IR::Expression>* > (that.value);
        break;

      case 240: // keyElementList
        value.copy< IR::Vector<IR::KeyElement>* > (that.value);
        break;

      case 180: // methodPrototypes
        value.copy< IR::Vector<IR::Method>* > (that.value);
        break;

      case 162: // selectCaseList
        value.copy< IR::Vector<IR::SelectCase>* > (that.value);
        break;

      case 233: // switchCases
        value.copy< IR::Vector<IR::SwitchCase>* > (that.value);
        break;

      case 197: // typeArgumentList
      case 199: // realTypeArgumentList
        value.copy< IR::Vector<IR::Type>* > (that.value);
        break;

      case 124: // optCONST
        value.copy< OptionalConst > (that.value);
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
        value.copy< Token > (that.value);
        break;

      case 111: // INTEGER
        value.copy< UnparsedConstant > (that.value);
        break;

      case 108: // IDENTIFIER
      case 109: // TYPE_IDENTIFIER
      case 110: // STRING_LITERAL
        value.copy< cstring > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  P4Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  P4Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
            case 22: // UNEXPECTED_TOKEN

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1078 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 23: // END_PRAGMA

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1085 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 24: // "<="

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1092 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 25: // ">="

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1099 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 26: // "<<"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1106 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 27: // "&&"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1113 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 28: // "||"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1120 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 29: // "!="

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1127 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 30: // "=="

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1134 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 31: // "+"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1141 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 32: // "-"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1148 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 33: // "|+|"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1155 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 34: // "|-|"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1162 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 35: // "*"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1169 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 36: // "/"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1176 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 37: // "%"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1183 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 38: // "|"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1190 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 39: // "&"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1197 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 40: // "^"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1204 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 41: // "~"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1211 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 42: // "["

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1218 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 43: // "]"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1225 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 44: // "{"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1232 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 45: // "}"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1239 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 46: // "<"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1246 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 47: // L_ANGLE_ARGS

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1253 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 48: // ">"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1260 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 49: // R_ANGLE_SHIFT

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1267 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 50: // "("

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1274 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 51: // ")"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1281 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 52: // "!"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1288 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 53: // ":"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1295 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 54: // ","

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1302 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 55: // "?"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1309 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 56: // "."

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1316 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 57: // "="

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1323 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 58: // ";"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1330 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 59: // "@"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1337 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 60: // "++"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1344 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 61: // "_"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1351 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 62: // "&&&"

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1358 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 63: // ".."

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1365 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 64: // TRUE

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1372 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 65: // FALSE

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1379 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 66: // THIS

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1386 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 67: // ABSTRACT

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1393 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 68: // ACTION

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1400 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 69: // ACTIONS

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1407 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 70: // APPLY

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1414 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 71: // BOOL

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1421 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 72: // BIT

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1428 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 73: // CONST

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1435 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 74: // CONTROL

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1442 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 75: // DEFAULT

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1449 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 76: // ELSE

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1456 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 77: // ENTRIES

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1463 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 78: // ENUM

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1470 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 79: // ERROR

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1477 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 80: // EXIT

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1484 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 81: // EXTERN

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1491 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 82: // HEADER

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1498 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 83: // HEADER_UNION

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1505 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 84: // IF

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1512 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 85: // IN

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1519 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 86: // INOUT

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1526 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 87: // INT

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1533 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 88: // KEY

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1540 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 89: // SELECT

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1547 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 90: // MATCH_KIND

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1554 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 91: // TYPE

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1561 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 92: // OUT

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1568 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 93: // PACKAGE

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1575 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 94: // PARSER

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1582 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 95: // PRAGMA

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1589 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 96: // RETURN

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1596 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 97: // STATE

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1603 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 98: // STRING

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1610 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 99: // STRUCT

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1617 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 100: // SWITCH

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1624 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 101: // TABLE

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1631 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 102: // TRANSITION

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1638 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 103: // TUPLE

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1645 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 104: // TYPEDEF

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1652 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 105: // VARBIT

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1659 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 106: // VALUESET

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1666 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 107: // VOID

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1673 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 108: // IDENTIFIER

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1680 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 109: // TYPE_IDENTIFIER

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1687 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 110: // STRING_LITERAL

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1694 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 111: // INTEGER

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< UnparsedConstant > (); }
#line 1701 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 116: // fragment

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Node* > (); }
#line 1708 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 117: // p4rtControllerType

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Expression* > (); }
#line 1715 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 120: // declaration

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Node* > (); }
#line 1722 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 121: // nonTypeName

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::ID* > (); }
#line 1729 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 122: // name

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::ID* > (); }
#line 1736 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 123: // nonTableKwName

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::ID* > (); }
#line 1743 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 124: // optCONST

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< OptionalConst > (); }
#line 1750 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 125: // optAnnotations

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Annotations* > (); }
#line 1757 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 126: // annotations

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Vector<IR::Annotation>* > (); }
#line 1764 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 127: // annotation

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Annotation* > (); }
#line 1771 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 128: // annotationBody

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Vector<IR::AnnotationToken>* > (); }
#line 1778 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 129: // annotationToken

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Token > (); }
#line 1785 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 130: // kvList

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::IndexedVector<IR::NamedExpression>* > (); }
#line 1792 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 131: // kvPair

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::NamedExpression* > (); }
#line 1799 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 132: // parameterList

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::IndexedVector<IR::Parameter>* > (); }
#line 1806 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 133: // nonEmptyParameterList

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::IndexedVector<IR::Parameter>* > (); }
#line 1813 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 134: // parameter

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Parameter* > (); }
#line 1820 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 135: // direction

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Direction > (); }
#line 1827 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 136: // packageTypeDeclaration

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Type_Declaration* > (); }
#line 1834 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 139: // instantiation

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Declaration* > (); }
#line 1841 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 140: // objInitializer

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::BlockStatement* > (); }
#line 1848 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 142: // objDeclarations

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::IndexedVector<IR::StatOrDecl>* > (); }
#line 1855 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 143: // objDeclaration

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Declaration* > (); }
#line 1862 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 144: // optConstructorParameters

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::IndexedVector<IR::Parameter>* > (); }
#line 1869 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 146: // parserDeclaration

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Type_Declaration* > (); }
#line 1876 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 147: // parserLocalElements

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::IndexedVector<IR::Declaration>* > (); }
#line 1883 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 148: // parserLocalElement

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Declaration* > (); }
#line 1890 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 149: // parserTypeDeclaration

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Type_Parser* > (); }
#line 1897 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 152: // parserStates

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::IndexedVector<IR::ParserState>* > (); }
#line 1904 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 153: // parserState

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::ParserState* > (); }
#line 1911 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 155: // parserStatements

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::IndexedVector<IR::StatOrDecl>* > (); }
#line 1918 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 156: // parserStatement

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::StatOrDecl* > (); }
#line 1925 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 157: // parserBlockStatement

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::BlockStatement* > (); }
#line 1932 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 159: // transitionStatement

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Expression* > (); }
#line 1939 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 160: // stateExpression

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Expression* > (); }
#line 1946 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 161: // selectExpression

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Expression* > (); }
#line 1953 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 162: // selectCaseList

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Vector<IR::SelectCase>* > (); }
#line 1960 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 163: // selectCase

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::SelectCase* > (); }
#line 1967 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 164: // keysetExpression

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Expression* > (); }
#line 1974 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 165: // tupleKeysetExpression

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Vector<IR::Expression>* > (); }
#line 1981 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 166: // simpleExpressionList

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Vector<IR::Expression>* > (); }
#line 1988 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 167: // reducedSimpleKeysetExpression

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Expression* > (); }
#line 1995 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 168: // simpleKeysetExpression

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Expression* > (); }
#line 2002 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 169: // valueSetDeclaration

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Declaration* > (); }
#line 2009 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 170: // controlDeclaration

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Type_Declaration* > (); }
#line 2016 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 171: // controlTypeDeclaration

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Type_Control* > (); }
#line 2023 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 174: // controlLocalDeclarations

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::IndexedVector<IR::Declaration>* > (); }
#line 2030 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 175: // controlLocalDeclaration

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Declaration* > (); }
#line 2037 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 176: // controlBody

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::BlockStatement* > (); }
#line 2044 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 177: // externDeclaration

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Node* > (); }
#line 2051 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 180: // methodPrototypes

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Vector<IR::Method>* > (); }
#line 2058 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 181: // functionPrototype

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Method* > (); }
#line 2065 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 183: // methodPrototype

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Method* > (); }
#line 2072 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 184: // typeRef

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< ConstType* > (); }
#line 2079 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 185: // namedType

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< ConstType* > (); }
#line 2086 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 186: // prefixedType

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Path* > (); }
#line 2093 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 187: // typeName

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Type_Name* > (); }
#line 2100 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 188: // tupleType

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< ConstType* > (); }
#line 2107 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 189: // headerStackType

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< ConstType* > (); }
#line 2114 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 190: // specializedType

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< ConstType* > (); }
#line 2121 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 191: // baseType

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< ConstType* > (); }
#line 2128 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 192: // typeOrVoid

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< ConstType* > (); }
#line 2135 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 193: // optTypeParameters

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::TypeParameters* > (); }
#line 2142 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 194: // typeParameters

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::TypeParameters* > (); }
#line 2149 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 195: // typeParameterList

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::IndexedVector<IR::Type_Var>* > (); }
#line 2156 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 196: // typeArg

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< ConstType* > (); }
#line 2163 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 197: // typeArgumentList

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Vector<IR::Type>* > (); }
#line 2170 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 198: // realTypeArg

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< ConstType* > (); }
#line 2177 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 199: // realTypeArgumentList

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Vector<IR::Type>* > (); }
#line 2184 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 200: // typeDeclaration

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Type_Declaration* > (); }
#line 2191 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 201: // derivedTypeDeclaration

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Type_Declaration* > (); }
#line 2198 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 202: // headerTypeDeclaration

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Type_Declaration* > (); }
#line 2205 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 205: // structTypeDeclaration

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Type_Declaration* > (); }
#line 2212 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 208: // headerUnionDeclaration

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Type_Declaration* > (); }
#line 2219 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 211: // structFieldList

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::IndexedVector<IR::StructField>* > (); }
#line 2226 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 212: // structField

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::StructField* > (); }
#line 2233 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 213: // enumDeclaration

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Type_Declaration* > (); }
#line 2240 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 216: // specifiedIdentifierList

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::IndexedVector<IR::SerEnumMember>* > (); }
#line 2247 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 217: // specifiedIdentifier

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::SerEnumMember* > (); }
#line 2254 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 218: // errorDeclaration

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Type_Error* > (); }
#line 2261 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 219: // matchKindDeclaration

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Node* > (); }
#line 2268 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 220: // identifierList

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::IndexedVector<IR::Declaration_ID>* > (); }
#line 2275 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 221: // typedefDeclaration

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Type_Declaration* > (); }
#line 2282 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 222: // assignmentOrMethodCallStatement

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Statement* > (); }
#line 2289 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 223: // emptyStatement

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Statement* > (); }
#line 2296 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 224: // exitStatement

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Statement* > (); }
#line 2303 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 225: // returnStatement

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Statement* > (); }
#line 2310 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 226: // conditionalStatement

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Statement* > (); }
#line 2317 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 227: // directApplication

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Statement* > (); }
#line 2324 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 228: // statement

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Statement* > (); }
#line 2331 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 229: // blockStatement

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::BlockStatement* > (); }
#line 2338 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 231: // statOrDeclList

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::IndexedVector<IR::StatOrDecl>* > (); }
#line 2345 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 232: // switchStatement

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Statement* > (); }
#line 2352 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 233: // switchCases

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Vector<IR::SwitchCase>* > (); }
#line 2359 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 234: // switchCase

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::SwitchCase* > (); }
#line 2366 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 235: // switchLabel

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Expression* > (); }
#line 2373 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 236: // statementOrDeclaration

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::StatOrDecl* > (); }
#line 2380 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 237: // tableDeclaration

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Declaration* > (); }
#line 2387 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 238: // tablePropertyList

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::IndexedVector<IR::Property>* > (); }
#line 2394 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 239: // tableProperty

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Property* > (); }
#line 2401 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 240: // keyElementList

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Vector<IR::KeyElement>* > (); }
#line 2408 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 241: // keyElement

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::KeyElement* > (); }
#line 2415 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 242: // actionList

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::IndexedVector<IR::ActionListElement>* > (); }
#line 2422 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 243: // actionRef

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Expression* > (); }
#line 2429 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 244: // entry

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Entry* > (); }
#line 2436 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 245: // entriesList

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Vector<IR::Entry>* > (); }
#line 2443 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 246: // actionDeclaration

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Declaration* > (); }
#line 2450 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 247: // variableDeclaration

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Declaration* > (); }
#line 2457 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 248: // constantDeclaration

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Declaration* > (); }
#line 2464 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 249: // optInitializer

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Expression* > (); }
#line 2471 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 250: // initializer

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Expression* > (); }
#line 2478 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 251: // functionDeclaration

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Declaration* > (); }
#line 2485 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 252: // argumentList

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Vector<IR::Argument>* > (); }
#line 2492 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 253: // nonEmptyArgList

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Vector<IR::Argument>* > (); }
#line 2499 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 254: // argument

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Argument* > (); }
#line 2506 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 255: // expressionList

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Vector<IR::Expression>* > (); }
#line 2513 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 256: // prefixedNonTypeName

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Path* > (); }
#line 2520 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 257: // dot_name

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::ID* > (); }
#line 2527 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 259: // lvalue

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Expression* > (); }
#line 2534 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 260: // expression

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Expression* > (); }
#line 2541 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 261: // nonBraceExpression

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Expression* > (); }
#line 2548 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 262: // intOrStr

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Expression* > (); }
#line 2555 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 263: // intList

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Vector<IR::Expression>* > (); }
#line 2562 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 264: // intOrStrList

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Vector<IR::Expression>* > (); }
#line 2569 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;

      case 265: // strList

#line 132 "parsers/p4/p4parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Vector<IR::Expression>* > (); }
#line 2576 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:636
        break;


      default:
        break;
    }
    yyo << ')';
  }
#endif

  inline
  void
  P4Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  P4Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  P4Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  P4Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  P4Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  P4Parser::debug_level_type
  P4Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  P4Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline P4Parser::state_type
  P4Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  P4Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  P4Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  P4Parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex (driver));
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
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
        yylhs.value.build< ConstType* > ();
        break;

      case 127: // annotation
        yylhs.value.build< IR::Annotation* > ();
        break;

      case 125: // optAnnotations
        yylhs.value.build< IR::Annotations* > ();
        break;

      case 254: // argument
        yylhs.value.build< IR::Argument* > ();
        break;

      case 140: // objInitializer
      case 157: // parserBlockStatement
      case 176: // controlBody
      case 229: // blockStatement
        yylhs.value.build< IR::BlockStatement* > ();
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
        yylhs.value.build< IR::Declaration* > ();
        break;

      case 135: // direction
        yylhs.value.build< IR::Direction > ();
        break;

      case 244: // entry
        yylhs.value.build< IR::Entry* > ();
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
        yylhs.value.build< IR::Expression* > ();
        break;

      case 121: // nonTypeName
      case 122: // name
      case 123: // nonTableKwName
      case 257: // dot_name
        yylhs.value.build< IR::ID* > ();
        break;

      case 242: // actionList
        yylhs.value.build< IR::IndexedVector<IR::ActionListElement>* > ();
        break;

      case 147: // parserLocalElements
      case 174: // controlLocalDeclarations
        yylhs.value.build< IR::IndexedVector<IR::Declaration>* > ();
        break;

      case 220: // identifierList
        yylhs.value.build< IR::IndexedVector<IR::Declaration_ID>* > ();
        break;

      case 130: // kvList
        yylhs.value.build< IR::IndexedVector<IR::NamedExpression>* > ();
        break;

      case 132: // parameterList
      case 133: // nonEmptyParameterList
      case 144: // optConstructorParameters
        yylhs.value.build< IR::IndexedVector<IR::Parameter>* > ();
        break;

      case 152: // parserStates
        yylhs.value.build< IR::IndexedVector<IR::ParserState>* > ();
        break;

      case 238: // tablePropertyList
        yylhs.value.build< IR::IndexedVector<IR::Property>* > ();
        break;

      case 216: // specifiedIdentifierList
        yylhs.value.build< IR::IndexedVector<IR::SerEnumMember>* > ();
        break;

      case 142: // objDeclarations
      case 155: // parserStatements
      case 231: // statOrDeclList
        yylhs.value.build< IR::IndexedVector<IR::StatOrDecl>* > ();
        break;

      case 211: // structFieldList
        yylhs.value.build< IR::IndexedVector<IR::StructField>* > ();
        break;

      case 195: // typeParameterList
        yylhs.value.build< IR::IndexedVector<IR::Type_Var>* > ();
        break;

      case 241: // keyElement
        yylhs.value.build< IR::KeyElement* > ();
        break;

      case 181: // functionPrototype
      case 183: // methodPrototype
        yylhs.value.build< IR::Method* > ();
        break;

      case 131: // kvPair
        yylhs.value.build< IR::NamedExpression* > ();
        break;

      case 116: // fragment
      case 120: // declaration
      case 177: // externDeclaration
      case 219: // matchKindDeclaration
        yylhs.value.build< IR::Node* > ();
        break;

      case 134: // parameter
        yylhs.value.build< IR::Parameter* > ();
        break;

      case 153: // parserState
        yylhs.value.build< IR::ParserState* > ();
        break;

      case 186: // prefixedType
      case 256: // prefixedNonTypeName
        yylhs.value.build< IR::Path* > ();
        break;

      case 239: // tableProperty
        yylhs.value.build< IR::Property* > ();
        break;

      case 163: // selectCase
        yylhs.value.build< IR::SelectCase* > ();
        break;

      case 217: // specifiedIdentifier
        yylhs.value.build< IR::SerEnumMember* > ();
        break;

      case 156: // parserStatement
      case 236: // statementOrDeclaration
        yylhs.value.build< IR::StatOrDecl* > ();
        break;

      case 222: // assignmentOrMethodCallStatement
      case 223: // emptyStatement
      case 224: // exitStatement
      case 225: // returnStatement
      case 226: // conditionalStatement
      case 227: // directApplication
      case 228: // statement
      case 232: // switchStatement
        yylhs.value.build< IR::Statement* > ();
        break;

      case 212: // structField
        yylhs.value.build< IR::StructField* > ();
        break;

      case 234: // switchCase
        yylhs.value.build< IR::SwitchCase* > ();
        break;

      case 193: // optTypeParameters
      case 194: // typeParameters
        yylhs.value.build< IR::TypeParameters* > ();
        break;

      case 171: // controlTypeDeclaration
        yylhs.value.build< IR::Type_Control* > ();
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
        yylhs.value.build< IR::Type_Declaration* > ();
        break;

      case 218: // errorDeclaration
        yylhs.value.build< IR::Type_Error* > ();
        break;

      case 187: // typeName
        yylhs.value.build< IR::Type_Name* > ();
        break;

      case 149: // parserTypeDeclaration
        yylhs.value.build< IR::Type_Parser* > ();
        break;

      case 126: // annotations
        yylhs.value.build< IR::Vector<IR::Annotation>* > ();
        break;

      case 128: // annotationBody
        yylhs.value.build< IR::Vector<IR::AnnotationToken>* > ();
        break;

      case 252: // argumentList
      case 253: // nonEmptyArgList
        yylhs.value.build< IR::Vector<IR::Argument>* > ();
        break;

      case 245: // entriesList
        yylhs.value.build< IR::Vector<IR::Entry>* > ();
        break;

      case 165: // tupleKeysetExpression
      case 166: // simpleExpressionList
      case 255: // expressionList
      case 263: // intList
      case 264: // intOrStrList
      case 265: // strList
        yylhs.value.build< IR::Vector<IR::Expression>* > ();
        break;

      case 240: // keyElementList
        yylhs.value.build< IR::Vector<IR::KeyElement>* > ();
        break;

      case 180: // methodPrototypes
        yylhs.value.build< IR::Vector<IR::Method>* > ();
        break;

      case 162: // selectCaseList
        yylhs.value.build< IR::Vector<IR::SelectCase>* > ();
        break;

      case 233: // switchCases
        yylhs.value.build< IR::Vector<IR::SwitchCase>* > ();
        break;

      case 197: // typeArgumentList
      case 199: // realTypeArgumentList
        yylhs.value.build< IR::Vector<IR::Type>* > ();
        break;

      case 124: // optCONST
        yylhs.value.build< OptionalConst > ();
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
        yylhs.value.build< Token > ();
        break;

      case 111: // INTEGER
        yylhs.value.build< UnparsedConstant > ();
        break;

      case 108: // IDENTIFIER
      case 109: // TYPE_IDENTIFIER
      case 110: // STRING_LITERAL
        yylhs.value.build< cstring > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 348 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.nodes->push_back(yystack_[1].value.as< IR::Node* > ()->getNode()); YYACCEPT; }
#line 3176 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 4:
#line 354 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Node* > () = yystack_[0].value.as< IR::Vector<IR::Expression>* > (); }
#line 3182 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 5:
#line 355 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Node* > () = yystack_[0].value.as< IR::IndexedVector<IR::NamedExpression>* > (); }
#line 3188 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 6:
#line 356 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Node* > () = yystack_[0].value.as< IR::Vector<IR::Expression>* > (); }
#line 3194 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 7:
#line 357 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Node* > () = yystack_[0].value.as< IR::Vector<IR::Expression>* > (); }
#line 3200 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 8:
#line 358 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Node* > () = yystack_[0].value.as< IR::Vector<IR::Expression>* > (); }
#line 3206 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 9:
#line 361 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Node* > () = yystack_[0].value.as< IR::Expression* > (); }
#line 3212 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 10:
#line 362 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Node* > () = parseConstant(yystack_[0].location, yystack_[0].value.as< UnparsedConstant > (), 0); }
#line 3218 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 11:
#line 363 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Node* > () = yystack_[0].value.as< IR::Expression* > (); }
#line 3224 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 12:
#line 364 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Node* > () = new IR::StringLiteral(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 3230 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 13:
#line 368 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { auto* result = new IR::Vector<IR::Expression>();
          result->push_back(yystack_[2].value.as< IR::Expression* > ());
          result->push_back(yystack_[0].value.as< IR::Expression* > ());
          yylhs.value.as< IR::Node* > () = result; }
#line 3239 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 14:
#line 373 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { auto* result = new IR::Vector<IR::Expression>();
          result->push_back(parseConstant(yystack_[2].location, yystack_[2].value.as< UnparsedConstant > (), 0));
          result->push_back(parseConstant(yystack_[0].location, yystack_[0].value.as< UnparsedConstant > (), 0));
          yylhs.value.as< IR::Node* > () = result; }
#line 3248 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 15:
#line 378 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { auto* result = new IR::Vector<IR::Expression>();
          result->push_back(new IR::StringLiteral(yystack_[2].location, yystack_[2].value.as< cstring > ()));
          result->push_back(new IR::StringLiteral(yystack_[0].location, yystack_[0].value.as< cstring > ()));
          yylhs.value.as< IR::Node* > () = result; }
#line 3257 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 16:
#line 385 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { auto* result = new IR::Vector<IR::Expression>();
          result->push_back(yystack_[4].value.as< IR::Expression* > ());
          result->push_back(yystack_[2].value.as< IR::Expression* > ());
          result->push_back(yystack_[0].value.as< IR::Expression* > ());
          yylhs.value.as< IR::Node* > () = result; }
#line 3267 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 17:
#line 391 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { auto* result = new IR::Vector<IR::Expression>();
          result->push_back(parseConstant(yystack_[4].location, yystack_[4].value.as< UnparsedConstant > (), 0));
          result->push_back(parseConstant(yystack_[2].location, yystack_[2].value.as< UnparsedConstant > (), 0));
          result->push_back(parseConstant(yystack_[0].location, yystack_[0].value.as< UnparsedConstant > (), 0));
          yylhs.value.as< IR::Node* > () = result; }
#line 3277 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 18:
#line 398 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { auto* result = new IR::Vector<IR::Expression>();
          result->push_back(new IR::StringLiteral(yystack_[4].location, yystack_[4].value.as< cstring > ()));
          result->push_back(new IR::StringLiteral(yystack_[2].location, yystack_[2].value.as< cstring > ()));
          result->push_back(new IR::StringLiteral(yystack_[0].location, yystack_[0].value.as< cstring > ()));
          yylhs.value.as< IR::Node* > () = result; }
#line 3287 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 406 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { auto* result = new IR::Vector<IR::Expression>();
          result->push_back(new IR::StringLiteral(yystack_[2].location, yystack_[2].value.as< cstring > ()));
          result->push_back(yystack_[0].value.as< IR::Expression* > ());
          yylhs.value.as< IR::Node* > () = result; }
#line 3296 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 20:
#line 418 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::StringLiteral(yystack_[0].location, ""); }
#line 3302 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 21:
#line 420 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Constant(parseConstantChecked(yystack_[1].location, yystack_[1].value.as< UnparsedConstant > ())); }
#line 3308 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 22:
#line 423 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Constant(parseConstantChecked(yystack_[0].location, yystack_[0].value.as< UnparsedConstant > ())); }
#line 3314 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 23:
#line 426 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { YYACCEPT; }
#line 3320 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 25:
#line 430 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { if (yystack_[0].value.as< IR::Node* > ()) driver.nodes->push_back(yystack_[0].value.as< IR::Node* > ()->getNode()); }
#line 3326 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 26:
#line 431 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    {}
#line 3332 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 27:
#line 435 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Node* > () = yystack_[0].value.as< IR::Declaration* > (); }
#line 3338 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 28:
#line 436 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Node* > () = yystack_[0].value.as< IR::Node* > (); }
#line 3344 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 29:
#line 437 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Node* > () = yystack_[0].value.as< IR::Declaration* > (); }
#line 3350 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 30:
#line 438 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Node* > () = yystack_[0].value.as< IR::Type_Declaration* > (); }
#line 3356 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 31:
#line 439 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Node* > () = yystack_[0].value.as< IR::Type_Declaration* > (); }
#line 3362 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 32:
#line 440 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Node* > () = yystack_[0].value.as< IR::Type_Declaration* > (); }
#line 3368 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 33:
#line 441 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Node* > () = yystack_[0].value.as< IR::Declaration* > (); }
#line 3374 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 34:
#line 442 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.onReadErrorDeclaration(yystack_[0].value.as< IR::Type_Error* > ()); yylhs.value.as< IR::Node* > () = nullptr; }
#line 3380 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 35:
#line 443 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Node* > () = yystack_[0].value.as< IR::Node* > (); }
#line 3386 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 36:
#line 444 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Node* > () = yystack_[0].value.as< IR::Declaration* > (); }
#line 3392 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 37:
#line 448 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID* > () = new IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 3398 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 38:
#line 449 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID* > () = new IR::ID(yystack_[0].location, "apply"); }
#line 3404 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 39:
#line 450 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID* > () = new IR::ID(yystack_[0].location, "key"); }
#line 3410 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 40:
#line 451 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID* > () = new IR::ID(yystack_[0].location, "actions"); }
#line 3416 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 41:
#line 452 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID* > () = new IR::ID(yystack_[0].location, "state"); }
#line 3422 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 42:
#line 453 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID* > () = new IR::ID(yystack_[0].location, "entries"); }
#line 3428 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 43:
#line 454 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID* > () = new IR::ID(yystack_[0].location, "type"); }
#line 3434 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 44:
#line 458 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID* > () = yystack_[0].value.as< IR::ID* > (); }
#line 3440 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 45:
#line 459 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID* > () = new IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 3446 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 46:
#line 463 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID* > () = new IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 3452 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 47:
#line 464 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID* > () = new IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 3458 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 48:
#line 465 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID* > () = new IR::ID(yystack_[0].location, "apply"); }
#line 3464 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 49:
#line 466 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID* > () = new IR::ID(yystack_[0].location, "state"); }
#line 3470 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 50:
#line 467 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID* > () = new IR::ID(yystack_[0].location, "type"); }
#line 3476 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 51:
#line 471 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< OptionalConst > () = OptionalConst{false}; }
#line 3482 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 52:
#line 472 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< OptionalConst > () = OptionalConst{true}; }
#line 3488 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 53:
#line 476 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Annotations* > () = IR::Annotations::empty; }
#line 3494 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 54:
#line 477 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Annotations* > () = new IR::Annotations(yystack_[0].location, *yystack_[0].value.as< IR::Vector<IR::Annotation>* > ()); }
#line 3500 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 55:
#line 481 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    {
       yylhs.value.as< IR::Vector<IR::Annotation>* > () = new IR::Vector<IR::Annotation>();
       if (! P4CContext::get().options().isAnnotationDisabled(yystack_[0].value.as< IR::Annotation* > ()))
         yylhs.value.as< IR::Vector<IR::Annotation>* > ()->push_back(yystack_[0].value.as< IR::Annotation* > ()); }
#line 3509 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 56:
#line 485 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    {
       yylhs.value.as< IR::Vector<IR::Annotation>* > () = yystack_[1].value.as< IR::Vector<IR::Annotation>* > ();
       if (! P4CContext::get().options().isAnnotationDisabled(yystack_[0].value.as< IR::Annotation* > ()))
          yylhs.value.as< IR::Vector<IR::Annotation>* > ()->push_back(yystack_[0].value.as< IR::Annotation* > ()); }
#line 3518 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 57:
#line 493 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { // Initialize with an empty sequence of annotation tokens so that the
          // annotation node is marked as unparsed.
          IR::Vector<IR::AnnotationToken> body;
          yylhs.value.as< IR::Annotation* > () = new IR::Annotation(yystack_[1].location, *yystack_[0].value.as< IR::ID* > (), body); }
#line 3527 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 58:
#line 498 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Annotation* > () = new IR::Annotation(yystack_[4].location, *yystack_[3].value.as< IR::ID* > (), *yystack_[1].value.as< IR::Vector<IR::AnnotationToken>* > ()); }
#line 3533 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 59:
#line 500 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Annotation* > () = new IR::Annotation(yystack_[4].location, *yystack_[3].value.as< IR::ID* > (), *yystack_[1].value.as< IR::Vector<IR::Expression>* > (), true); }
#line 3539 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 60:
#line 502 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Annotation* > () = new IR::Annotation(yystack_[4].location, *yystack_[3].value.as< IR::ID* > (), *yystack_[1].value.as< IR::IndexedVector<IR::NamedExpression>* > (), true); }
#line 3545 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 61:
#line 506 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Annotation* > () = new IR::Annotation(yystack_[3].location, *yystack_[2].value.as< IR::ID* > (), *yystack_[1].value.as< IR::Vector<IR::AnnotationToken>* > (), false); }
#line 3551 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 62:
#line 510 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::AnnotationToken>* > () = new IR::Vector<IR::AnnotationToken>; }
#line 3557 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 63:
#line 512 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::AnnotationToken>* > () = yystack_[3].value.as< IR::Vector<IR::AnnotationToken>* > ();
          yylhs.value.as< IR::Vector<IR::AnnotationToken>* > ()->push_back(new IR::AnnotationToken(yystack_[2].location, yystack_[2].value.as< Token > ().type, yystack_[2].value.as< Token > ().text));
          yylhs.value.as< IR::Vector<IR::AnnotationToken>* > ()->append(*yystack_[1].value.as< IR::Vector<IR::AnnotationToken>* > ());
          yylhs.value.as< IR::Vector<IR::AnnotationToken>* > ()->push_back(new IR::AnnotationToken(yystack_[0].location, yystack_[0].value.as< Token > ().type, yystack_[0].value.as< Token > ().text)); }
#line 3566 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 64:
#line 517 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::AnnotationToken>* > () = yystack_[1].value.as< IR::Vector<IR::AnnotationToken>* > ();
          yylhs.value.as< IR::Vector<IR::AnnotationToken>* > ()->push_back(new IR::AnnotationToken(yystack_[0].location, yystack_[0].value.as< Token > ().type, yystack_[0].value.as< Token > ().text, yystack_[0].value.as< Token > ().unparsedConstant)); }
#line 3573 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 65:
#line 522 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3579 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 66:
#line 523 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3585 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 67:
#line 524 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3591 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 68:
#line 525 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3597 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 69:
#line 526 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3603 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 70:
#line 527 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3609 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 71:
#line 528 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3615 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 72:
#line 529 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3621 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 73:
#line 530 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3627 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 74:
#line 531 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3633 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 75:
#line 532 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3639 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 76:
#line 533 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3645 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 77:
#line 534 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3651 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 78:
#line 535 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3657 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 79:
#line 536 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3663 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 80:
#line 537 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3669 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 81:
#line 538 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3675 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 82:
#line 539 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3681 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 83:
#line 540 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3687 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 84:
#line 541 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3693 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 85:
#line 542 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3699 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 86:
#line 543 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3705 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 87:
#line 544 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3711 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 88:
#line 545 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3717 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 89:
#line 546 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3723 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 90:
#line 547 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3729 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 91:
#line 548 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3735 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 92:
#line 549 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3741 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 93:
#line 550 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3747 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 94:
#line 551 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3753 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 95:
#line 552 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3759 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 96:
#line 553 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3765 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 97:
#line 554 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3771 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 98:
#line 555 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3777 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 99:
#line 556 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3783 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 100:
#line 557 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3789 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 101:
#line 558 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3795 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 102:
#line 559 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3801 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 103:
#line 560 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3807 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 104:
#line 561 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3813 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 105:
#line 562 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3819 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 106:
#line 563 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3825 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 107:
#line 564 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3831 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 108:
#line 565 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3837 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 109:
#line 566 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3843 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 110:
#line 567 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3849 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 111:
#line 569 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = Token(token::TOK_IDENTIFIER, yystack_[0].value.as< cstring > ()); }
#line 3855 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 112:
#line 570 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = Token(token::TOK_TYPE_IDENTIFIER, yystack_[0].value.as< cstring > ()); }
#line 3861 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 113:
#line 571 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = Token(token::TOK_STRING_LITERAL, yystack_[0].value.as< cstring > ()); }
#line 3867 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 114:
#line 572 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = Token(token::TOK_INTEGER, yystack_[0].value.as< UnparsedConstant > ()); }
#line 3873 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 115:
#line 574 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3879 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 116:
#line 575 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3885 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 117:
#line 576 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3891 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 118:
#line 577 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3897 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 119:
#line 578 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3903 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 120:
#line 579 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3909 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 121:
#line 580 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3915 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 122:
#line 581 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3921 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 123:
#line 582 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3927 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 124:
#line 583 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3933 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 125:
#line 585 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3939 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 126:
#line 586 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3945 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 127:
#line 587 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3951 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 128:
#line 588 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3957 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 129:
#line 589 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3963 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 130:
#line 590 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3969 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 131:
#line 591 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3975 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 132:
#line 593 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3981 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 133:
#line 594 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3987 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 134:
#line 595 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3993 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 135:
#line 596 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 3999 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 136:
#line 603 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 4005 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 137:
#line 604 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 4011 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 138:
#line 605 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 4017 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 139:
#line 606 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 4023 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 140:
#line 607 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 4029 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 141:
#line 608 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 4035 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 142:
#line 609 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 4041 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 143:
#line 610 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 4047 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 144:
#line 612 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 4053 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 145:
#line 613 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 4059 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 146:
#line 614 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 4065 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 147:
#line 615 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 4071 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 148:
#line 616 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 4077 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 149:
#line 617 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 4083 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 150:
#line 618 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 4089 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 151:
#line 619 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Token > () = yystack_[0].value.as< Token > (); }
#line 4095 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 152:
#line 623 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::NamedExpression>* > () = new IR::IndexedVector<IR::NamedExpression>; yylhs.value.as< IR::IndexedVector<IR::NamedExpression>* > ()->push_back(yystack_[0].value.as< IR::NamedExpression* > ()); }
#line 4101 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 153:
#line 624 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::NamedExpression>* > () = yystack_[2].value.as< IR::IndexedVector<IR::NamedExpression>* > (); yylhs.value.as< IR::IndexedVector<IR::NamedExpression>* > ()->push_back(yystack_[0].value.as< IR::NamedExpression* > ()); }
#line 4107 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 154:
#line 628 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::NamedExpression* > () = new IR::NamedExpression(yystack_[2].location, *yystack_[2].value.as< IR::ID* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 4113 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 155:
#line 632 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::Parameter>* > () = new IR::IndexedVector<IR::Parameter>(); }
#line 4119 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 156:
#line 633 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::Parameter>* > () = yystack_[0].value.as< IR::IndexedVector<IR::Parameter>* > (); }
#line 4125 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 157:
#line 637 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::Parameter>* > () = new IR::IndexedVector<IR::Parameter>();
                                            yylhs.value.as< IR::IndexedVector<IR::Parameter>* > ()->push_back(yystack_[0].value.as< IR::Parameter* > ()); }
#line 4132 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 158:
#line 639 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::Parameter>* > () = yystack_[2].value.as< IR::IndexedVector<IR::Parameter>* > (); yylhs.value.as< IR::IndexedVector<IR::Parameter>* > ()->push_back(yystack_[0].value.as< IR::Parameter* > ()); }
#line 4138 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 159:
#line 643 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Parameter* > () = new IR::Parameter(yystack_[0].location, *yystack_[0].value.as< IR::ID* > (), yystack_[3].value.as< IR::Annotations* > (), yystack_[2].value.as< IR::Direction > (), yystack_[1].value.as< ConstType* > (), nullptr); }
#line 4144 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 160:
#line 644 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Parameter* > () = new IR::Parameter(yystack_[2].location, *yystack_[2].value.as< IR::ID* > (), yystack_[5].value.as< IR::Annotations* > (), yystack_[4].value.as< IR::Direction > (), yystack_[3].value.as< ConstType* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 4150 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 161:
#line 648 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Direction > () = IR::Direction::In; }
#line 4156 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 162:
#line 649 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Direction > () = IR::Direction::Out; }
#line 4162 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 163:
#line 650 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Direction > () = IR::Direction::InOut; }
#line 4168 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 164:
#line 651 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Direction > () = IR::Direction::None; }
#line 4174 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 165:
#line 655 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->pushContainerType(*yystack_[0].value.as< IR::ID* > (), false); }
#line 4180 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 166:
#line 656 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    {
          if (!yystack_[0].value.as< IR::TypeParameters* > ()->empty()) driver.structure->markAsTemplate(*yystack_[2].value.as< IR::ID* > ());
          driver.structure->declareTypes(&yystack_[0].value.as< IR::TypeParameters* > ()->parameters); }
#line 4188 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 167:
#line 659 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    {
          driver.structure->declareParameters(yystack_[1].value.as< IR::IndexedVector<IR::Parameter>* > ());
          auto pl = new IR::ParameterList(yystack_[1].location, *yystack_[1].value.as< IR::IndexedVector<IR::Parameter>* > ());
          yylhs.value.as< IR::Type_Declaration* > () = new IR::Type_Package(yystack_[6].location, *yystack_[6].value.as< IR::ID* > (), yystack_[8].value.as< IR::Annotations* > (), yystack_[4].value.as< IR::TypeParameters* > (), pl); }
#line 4197 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 168:
#line 667 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Declaration* > () = new IR::Declaration_Instance(yystack_[1].location, *yystack_[1].value.as< IR::ID* > (), new IR::Annotations(*yystack_[6].value.as< IR::Vector<IR::Annotation>* > ()),
                                                         yystack_[5].value.as< ConstType* > (), yystack_[3].value.as< IR::Vector<IR::Argument>* > ());
                       driver.structure->declareObject(*yystack_[1].value.as< IR::ID* > (), yystack_[5].value.as< ConstType* > ()->toString()); }
#line 4205 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 169:
#line 671 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Declaration* > () = new IR::Declaration_Instance(yystack_[1].location, *yystack_[1].value.as< IR::ID* > (), yystack_[5].value.as< ConstType* > (), yystack_[3].value.as< IR::Vector<IR::Argument>* > ());
                       driver.structure->declareObject(*yystack_[1].value.as< IR::ID* > (), yystack_[5].value.as< ConstType* > ()->toString()); }
#line 4212 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 170:
#line 675 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Declaration* > () = new IR::Declaration_Instance(yystack_[3].location, *yystack_[3].value.as< IR::ID* > (), new IR::Annotations(*yystack_[8].value.as< IR::Vector<IR::Annotation>* > ()),
                                                         yystack_[7].value.as< ConstType* > (), yystack_[5].value.as< IR::Vector<IR::Argument>* > (), yystack_[1].value.as< IR::BlockStatement* > ());
                       driver.structure->declareObject(*yystack_[3].value.as< IR::ID* > (), yystack_[7].value.as< ConstType* > ()->toString()); }
#line 4220 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 171:
#line 680 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Declaration* > () = new IR::Declaration_Instance(yystack_[3].location, *yystack_[3].value.as< IR::ID* > (), yystack_[7].value.as< ConstType* > (), yystack_[5].value.as< IR::Vector<IR::Argument>* > (), yystack_[1].value.as< IR::BlockStatement* > ());
                       driver.structure->declareObject(*yystack_[3].value.as< IR::ID* > (), yystack_[7].value.as< ConstType* > ()->toString()); }
#line 4227 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 172:
#line 686 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->pushNamespace(yystack_[0].location, false); }
#line 4233 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 173:
#line 687 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->pop();
                                 yylhs.value.as< IR::BlockStatement* > () = new IR::BlockStatement(yystack_[3].location+yystack_[0].location, *yystack_[1].value.as< IR::IndexedVector<IR::StatOrDecl>* > ()); }
#line 4240 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 174:
#line 692 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::StatOrDecl>* > () = new IR::IndexedVector<IR::StatOrDecl>(); }
#line 4246 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 175:
#line 693 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::StatOrDecl>* > () = yystack_[1].value.as< IR::IndexedVector<IR::StatOrDecl>* > (); yystack_[1].value.as< IR::IndexedVector<IR::StatOrDecl>* > ()->push_back(yystack_[0].value.as< IR::Declaration* > ()); }
#line 4252 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 176:
#line 697 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Declaration* > () = yystack_[0].value.as< IR::Declaration* > (); }
#line 4258 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 177:
#line 698 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Declaration* > () = yystack_[0].value.as< IR::Declaration* > (); }
#line 4264 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 178:
#line 702 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::Parameter>* > () = new IR::IndexedVector<IR::Parameter>(); }
#line 4270 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 179:
#line 703 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::Parameter>* > () = yystack_[1].value.as< IR::IndexedVector<IR::Parameter>* > (); }
#line 4276 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 180:
#line 707 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->startAbsolutePath(); }
#line 4282 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 181:
#line 715 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->pop();
                               auto pl = new IR::ParameterList(yystack_[4].location, *yystack_[4].value.as< IR::IndexedVector<IR::Parameter>* > ());
                               yylhs.value.as< IR::Type_Declaration* > () = new IR::P4Parser(yystack_[5].value.as< IR::Type_Parser* > ()->name.srcInfo, yystack_[5].value.as< IR::Type_Parser* > ()->name,
                                                     yystack_[5].value.as< IR::Type_Parser* > (), pl, *yystack_[2].value.as< IR::IndexedVector<IR::Declaration>* > (), *yystack_[1].value.as< IR::IndexedVector<IR::ParserState>* > ());}
#line 4291 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 182:
#line 722 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::Declaration>* > () = new IR::IndexedVector<IR::Declaration>(); }
#line 4297 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 183:
#line 723 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::Declaration>* > () = yystack_[1].value.as< IR::IndexedVector<IR::Declaration>* > (); yylhs.value.as< IR::IndexedVector<IR::Declaration>* > ()->push_back(yystack_[0].value.as< IR::Declaration* > ()); }
#line 4303 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 184:
#line 727 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Declaration* > () = yystack_[0].value.as< IR::Declaration* > (); }
#line 4309 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 185:
#line 728 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Declaration* > () = yystack_[0].value.as< IR::Declaration* > (); }
#line 4315 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 186:
#line 729 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Declaration* > () = yystack_[0].value.as< IR::Declaration* > (); }
#line 4321 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 187:
#line 730 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Declaration* > () = yystack_[0].value.as< IR::Declaration* > (); }
#line 4327 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 188:
#line 735 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->pushContainerType(*yystack_[0].value.as< IR::ID* > (), true); }
#line 4333 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 189:
#line 736 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { if (!yystack_[0].value.as< IR::TypeParameters* > ()->empty()) driver.structure->markAsTemplate(*yystack_[2].value.as< IR::ID* > ());
                            driver.structure->declareTypes(&yystack_[0].value.as< IR::TypeParameters* > ()->parameters); }
#line 4340 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 190:
#line 738 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->declareParameters(yystack_[1].value.as< IR::IndexedVector<IR::Parameter>* > ());
                                auto pl = new IR::ParameterList(yystack_[1].location, *yystack_[1].value.as< IR::IndexedVector<IR::Parameter>* > ());
                                yylhs.value.as< IR::Type_Parser* > () = new IR::Type_Parser(yystack_[6].location, *yystack_[6].value.as< IR::ID* > (), yystack_[8].value.as< IR::Annotations* > (), yystack_[4].value.as< IR::TypeParameters* > (), pl); }
#line 4348 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 191:
#line 744 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::ParserState>* > () = new IR::IndexedVector<IR::ParserState>();
                                        yylhs.value.as< IR::IndexedVector<IR::ParserState>* > ()->push_back(yystack_[0].value.as< IR::ParserState* > ()); }
#line 4355 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 192:
#line 746 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::ParserState>* > () = yystack_[1].value.as< IR::IndexedVector<IR::ParserState>* > (); yylhs.value.as< IR::IndexedVector<IR::ParserState>* > ()->push_back(yystack_[0].value.as< IR::ParserState* > ()); }
#line 4361 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 193:
#line 750 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->pushContainerType(*yystack_[0].value.as< IR::ID* > (), false); }
#line 4367 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 194:
#line 752 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->pop();
                                        yylhs.value.as< IR::ParserState* > () = new IR::ParserState(yystack_[5].location, *yystack_[5].value.as< IR::ID* > (), yystack_[7].value.as< IR::Annotations* > (), *yystack_[2].value.as< IR::IndexedVector<IR::StatOrDecl>* > (), yystack_[1].value.as< IR::Expression* > ()); }
#line 4374 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 195:
#line 757 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::StatOrDecl>* > () = new IR::IndexedVector<IR::StatOrDecl>(); }
#line 4380 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 196:
#line 758 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::StatOrDecl>* > () = yystack_[1].value.as< IR::IndexedVector<IR::StatOrDecl>* > (); yystack_[1].value.as< IR::IndexedVector<IR::StatOrDecl>* > ()->push_back(yystack_[0].value.as< IR::StatOrDecl* > ()); }
#line 4386 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 197:
#line 762 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::StatOrDecl* > () = yystack_[0].value.as< IR::Statement* > (); }
#line 4392 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 198:
#line 763 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::StatOrDecl* > () = yystack_[0].value.as< IR::Statement* > (); }
#line 4398 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 199:
#line 764 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::StatOrDecl* > () = yystack_[0].value.as< IR::Statement* > (); }
#line 4404 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 200:
#line 765 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::StatOrDecl* > () = yystack_[0].value.as< IR::Declaration* > (); }
#line 4410 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 201:
#line 766 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::StatOrDecl* > () = yystack_[0].value.as< IR::Declaration* > (); }
#line 4416 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 202:
#line 767 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::StatOrDecl* > () = yystack_[0].value.as< IR::BlockStatement* > (); }
#line 4422 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 203:
#line 768 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::StatOrDecl* > () = yystack_[0].value.as< IR::Statement* > (); }
#line 4428 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 204:
#line 772 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->pushNamespace(yystack_[0].location, false); }
#line 4434 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 205:
#line 773 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->pop(); yylhs.value.as< IR::BlockStatement* > () = new IR::BlockStatement(yystack_[4].location+yystack_[0].location, yystack_[4].value.as< IR::Annotations* > (), *yystack_[1].value.as< IR::IndexedVector<IR::StatOrDecl>* > ()); }
#line 4440 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 206:
#line 777 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = nullptr; }
#line 4446 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 207:
#line 778 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = yystack_[0].value.as< IR::Expression* > (); }
#line 4452 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 208:
#line 782 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::PathExpression(*yystack_[1].value.as< IR::ID* > ()); }
#line 4458 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 209:
#line 783 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = yystack_[0].value.as< IR::Expression* > (); }
#line 4464 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 210:
#line 788 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::SelectExpression(yystack_[6].location + yystack_[0].location,
                                     new IR::ListExpression(yystack_[4].location, *yystack_[4].value.as< IR::Vector<IR::Expression>* > ()), std::move(*yystack_[1].value.as< IR::Vector<IR::SelectCase>* > ())); }
#line 4471 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 211:
#line 793 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::SelectCase>* > () = new IR::Vector<IR::SelectCase>(); }
#line 4477 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 212:
#line 794 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::SelectCase>* > () = yystack_[1].value.as< IR::Vector<IR::SelectCase>* > (); yylhs.value.as< IR::Vector<IR::SelectCase>* > ()->push_back(yystack_[0].value.as< IR::SelectCase* > ()); }
#line 4483 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 213:
#line 799 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { auto expr = new IR::PathExpression(*yystack_[1].value.as< IR::ID* > ());
        yylhs.value.as< IR::SelectCase* > () = new IR::SelectCase(yystack_[3].location + yystack_[1].location, yystack_[3].value.as< IR::Expression* > (), expr); }
#line 4490 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 214:
#line 804 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::ListExpression(yystack_[0].location, *yystack_[0].value.as< IR::Vector<IR::Expression>* > ()); }
#line 4496 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 215:
#line 805 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = yystack_[0].value.as< IR::Expression* > (); }
#line 4502 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 216:
#line 810 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = yystack_[1].value.as< IR::Vector<IR::Expression>* > (); yystack_[1].value.as< IR::Vector<IR::Expression>* > ()->insert(yystack_[1].value.as< IR::Vector<IR::Expression>* > ()->begin(), yystack_[3].value.as< IR::Expression* > ()); }
#line 4508 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 217:
#line 811 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = new IR::Vector<IR::Expression>(); yylhs.value.as< IR::Vector<IR::Expression>* > ()->push_back(yystack_[1].value.as< IR::Expression* > ()); }
#line 4514 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 218:
#line 815 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = new IR::Vector<IR::Expression>(); yylhs.value.as< IR::Vector<IR::Expression>* > ()->push_back(yystack_[0].value.as< IR::Expression* > ()); }
#line 4520 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 219:
#line 816 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = yystack_[2].value.as< IR::Vector<IR::Expression>* > (); yylhs.value.as< IR::Vector<IR::Expression>* > ()->push_back(yystack_[0].value.as< IR::Expression* > ()); }
#line 4526 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 220:
#line 821 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Mask(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 4532 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 221:
#line 822 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Range(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 4538 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 222:
#line 823 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::DefaultExpression(yystack_[0].location); }
#line 4544 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 223:
#line 824 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::DefaultExpression(yystack_[0].location); }
#line 4550 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 224:
#line 828 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = yystack_[0].value.as< IR::Expression* > (); }
#line 4556 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 225:
#line 829 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Mask(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 4562 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 226:
#line 830 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Range(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 4568 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 227:
#line 831 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::DefaultExpression(yystack_[0].location); }
#line 4574 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 228:
#line 832 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::DefaultExpression(yystack_[0].location); }
#line 4580 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 229:
#line 838 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Declaration* > () = new IR::P4ValueSet(yystack_[1].location, *yystack_[1].value.as< IR::ID* > (), yystack_[9].value.as< IR::Annotations* > (), yystack_[6].value.as< ConstType* > (), yystack_[3].value.as< IR::Expression* > ()); }
#line 4586 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 230:
#line 841 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Declaration* > () = new IR::P4ValueSet(yystack_[1].location, *yystack_[1].value.as< IR::ID* > (), yystack_[9].value.as< IR::Annotations* > (), yystack_[6].value.as< ConstType* > (), yystack_[3].value.as< IR::Expression* > ()); }
#line 4592 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 231:
#line 844 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Declaration* > () = new IR::P4ValueSet(yystack_[1].location, *yystack_[1].value.as< IR::ID* > (), yystack_[9].value.as< IR::Annotations* > (), yystack_[6].value.as< IR::Type_Name* > (), yystack_[3].value.as< IR::Expression* > ()); }
#line 4598 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 232:
#line 852 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->pop();
          auto pl = new IR::ParameterList(yystack_[5].location, *yystack_[5].value.as< IR::IndexedVector<IR::Parameter>* > ());
          yylhs.value.as< IR::Type_Declaration* > () = new IR::P4Control(yystack_[6].value.as< IR::Type_Control* > ()->name.srcInfo, yystack_[6].value.as< IR::Type_Control* > ()->name, yystack_[6].value.as< IR::Type_Control* > (), pl, *yystack_[3].value.as< IR::IndexedVector<IR::Declaration>* > (), yystack_[1].value.as< IR::BlockStatement* > ()); }
#line 4606 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 233:
#line 859 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->pushContainerType(*yystack_[0].value.as< IR::ID* > (), true); }
#line 4612 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 234:
#line 860 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { if (!yystack_[0].value.as< IR::TypeParameters* > ()->empty()) driver.structure->markAsTemplate(*yystack_[2].value.as< IR::ID* > ());
                            driver.structure->declareTypes(&yystack_[0].value.as< IR::TypeParameters* > ()->parameters); }
#line 4619 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 235:
#line 862 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->declareParameters(yystack_[1].value.as< IR::IndexedVector<IR::Parameter>* > ());
                                auto pl = new IR::ParameterList(yystack_[1].location, *yystack_[1].value.as< IR::IndexedVector<IR::Parameter>* > ());
                                yylhs.value.as< IR::Type_Control* > () = new IR::Type_Control(yystack_[6].location, *yystack_[6].value.as< IR::ID* > (), yystack_[8].value.as< IR::Annotations* > (), yystack_[4].value.as< IR::TypeParameters* > (), pl); }
#line 4627 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 236:
#line 868 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::Declaration>* > () = new IR::IndexedVector<IR::Declaration>(); }
#line 4633 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 237:
#line 869 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::Declaration>* > () = yystack_[1].value.as< IR::IndexedVector<IR::Declaration>* > (); yylhs.value.as< IR::IndexedVector<IR::Declaration>* > ()->push_back(yystack_[0].value.as< IR::Declaration* > ()); }
#line 4639 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 238:
#line 873 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Declaration* > () = yystack_[0].value.as< IR::Declaration* > (); }
#line 4645 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 239:
#line 874 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Declaration* > () = yystack_[0].value.as< IR::Declaration* > (); }
#line 4651 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 240:
#line 875 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Declaration* > () = yystack_[0].value.as< IR::Declaration* > (); }
#line 4657 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 241:
#line 876 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Declaration* > () = yystack_[0].value.as< IR::Declaration* > (); }
#line 4663 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 242:
#line 877 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Declaration* > () = yystack_[0].value.as< IR::Declaration* > (); }
#line 4669 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 243:
#line 881 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::BlockStatement* > () = yystack_[0].value.as< IR::BlockStatement* > (); }
#line 4675 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 244:
#line 888 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->pushContainerType(*yystack_[0].value.as< IR::ID* > (), true); }
#line 4681 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 245:
#line 889 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { if (!yystack_[0].value.as< IR::TypeParameters* > ()->empty()) driver.structure->markAsTemplate(*yystack_[2].value.as< IR::ID* > ());
                            driver.structure->declareTypes(&yystack_[0].value.as< IR::TypeParameters* > ()->parameters); }
#line 4688 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 246:
#line 891 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->pop();
                                   yylhs.value.as< IR::Node* > () = new IR::Type_Extern(yystack_[6].location, *yystack_[6].value.as< IR::ID* > (), yystack_[4].value.as< IR::TypeParameters* > (), *yystack_[1].value.as< IR::Vector<IR::Method>* > (), yystack_[8].value.as< IR::Annotations* > ()); }
#line 4695 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 247:
#line 893 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    {
            driver.structure->pop();
            yylhs.value.as< IR::Node* > () = yystack_[1].value.as< IR::Method* > ();
            yystack_[1].value.as< IR::Method* > ()->annotations = yystack_[3].value.as< IR::Annotations* > (); }
#line 4704 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 248:
#line 897 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    {
            // forward declaration;
            driver.structure->pushContainerType(*yystack_[1].value.as< IR::ID* > (), true);
            driver.structure->pop();
            yylhs.value.as< IR::Node* > () = nullptr; }
#line 4714 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 249:
#line 905 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Method>* > () = new IR::Vector<IR::Method>(); }
#line 4720 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 250:
#line 906 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Method>* > () = yystack_[1].value.as< IR::Vector<IR::Method>* > (); yystack_[1].value.as< IR::Vector<IR::Method>* > ()->push_back(yystack_[0].value.as< IR::Method* > ()); }
#line 4726 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 251:
#line 911 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    {
            driver.structure->declareObject(*yystack_[1].value.as< IR::ID* > (), yystack_[2].value.as< ConstType* > ()->toString());
            if (!yystack_[0].value.as< IR::TypeParameters* > ()->empty()) driver.structure->markAsTemplate(*yystack_[1].value.as< IR::ID* > ());
            driver.structure->pushNamespace(yystack_[1].location, false);
            driver.structure->declareTypes(&yystack_[0].value.as< IR::TypeParameters* > ()->parameters); }
#line 4736 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 252:
#line 916 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->declareParameters(yystack_[1].value.as< IR::IndexedVector<IR::Parameter>* > ());
                                auto params = new IR::ParameterList(yystack_[1].location, *yystack_[1].value.as< IR::IndexedVector<IR::Parameter>* > ());
                                auto mt = new IR::Type_Method(yystack_[5].location, yystack_[4].value.as< IR::TypeParameters* > (), yystack_[6].value.as< ConstType* > (), params, *yystack_[5].value.as< IR::ID* > ());
                                yylhs.value.as< IR::Method* > () = new IR::Method(yystack_[5].location, *yystack_[5].value.as< IR::ID* > (), mt); }
#line 4745 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 253:
#line 923 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    {
            driver.structure->pop();
            yylhs.value.as< IR::Method* > () = yystack_[1].value.as< IR::Method* > (); yystack_[1].value.as< IR::Method* > ()->annotations = yystack_[2].value.as< IR::Annotations* > (); }
#line 4753 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 254:
#line 926 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    {
            driver.structure->pop();
            yylhs.value.as< IR::Method* > () = yystack_[1].value.as< IR::Method* > (); yylhs.value.as< IR::Method* > ()->setAbstract();
            yystack_[1].value.as< IR::Method* > ()->annotations = yystack_[3].value.as< IR::Annotations* > (); }
#line 4762 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 255:
#line 931 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { auto par = new IR::ParameterList(yystack_[2].location, *yystack_[2].value.as< IR::IndexedVector<IR::Parameter>* > ());
                                          auto mt = new IR::Type_Method(yystack_[4].location, par, yystack_[4].value.as< cstring > ());
                                          yylhs.value.as< IR::Method* > () = new IR::Method(yystack_[4].location, IR::ID(yystack_[4].location, yystack_[4].value.as< cstring > ()), mt, yystack_[5].value.as< IR::Annotations* > ()); }
#line 4770 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 256:
#line 939 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = yystack_[0].value.as< ConstType* > (); }
#line 4776 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 257:
#line 940 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = yystack_[0].value.as< IR::Type_Name* > (); }
#line 4782 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 258:
#line 941 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = yystack_[0].value.as< ConstType* > (); }
#line 4788 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 259:
#line 942 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = yystack_[0].value.as< ConstType* > (); }
#line 4794 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 260:
#line 943 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = yystack_[0].value.as< ConstType* > (); }
#line 4800 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 261:
#line 947 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = yystack_[0].value.as< IR::Type_Name* > (); }
#line 4806 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 262:
#line 948 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = yystack_[0].value.as< ConstType* > (); }
#line 4812 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 263:
#line 952 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Path* > () = new IR::Path(IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ())); }
#line 4818 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 264:
#line 953 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Path* > () = new IR::Path(IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()), true);
                                         driver.structure->clearPath(); }
#line 4825 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 265:
#line 958 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Type_Name* > () = new IR::Type_Name(yystack_[0].location, yystack_[0].value.as< IR::Path* > ()); }
#line 4831 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 266:
#line 962 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = new IR::Type_Tuple(yystack_[3].location+yystack_[0].location, *yystack_[1].value.as< IR::Vector<IR::Type>* > ()); }
#line 4837 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 267:
#line 966 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = new IR::Type_Stack(yystack_[3].location+yystack_[0].location, yystack_[3].value.as< IR::Type_Name* > (), yystack_[1].value.as< IR::Expression* > ()); }
#line 4843 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 268:
#line 967 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = new IR::Type_Stack(yystack_[3].location+yystack_[0].location, yystack_[3].value.as< ConstType* > (), yystack_[1].value.as< IR::Expression* > ()); }
#line 4849 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 269:
#line 971 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = new IR::Type_Specialized(yystack_[3].location + yystack_[0].location, yystack_[3].value.as< IR::Type_Name* > (), yystack_[1].value.as< IR::Vector<IR::Type>* > ()); }
#line 4855 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 270:
#line 975 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = IR::Type_Boolean::get(); }
#line 4861 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 271:
#line 976 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = new IR::Type_Name(yystack_[0].location, new IR::Path(IR::ID(yystack_[0].location, "error"))); }
#line 4867 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 272:
#line 977 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = IR::Type::Bits::get(yystack_[0].location, 1); }
#line 4873 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 273:
#line 978 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = IR::Type::String::get(); }
#line 4879 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 274:
#line 979 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = new IR::Type_InfInt(); }
#line 4885 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 275:
#line 981 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = IR::Type::Bits::get(yystack_[3].location+yystack_[0].location, parseConstantChecked(yystack_[1].location, yystack_[1].value.as< UnparsedConstant > ()), false); }
#line 4891 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 276:
#line 983 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = IR::Type::Bits::get(yystack_[3].location+yystack_[0].location, parseConstantChecked(yystack_[1].location, yystack_[1].value.as< UnparsedConstant > ()), true); }
#line 4897 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 277:
#line 985 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = IR::Type::Varbits::get(yystack_[3].location+yystack_[0].location, parseConstantChecked(yystack_[1].location, yystack_[1].value.as< UnparsedConstant > ())); }
#line 4903 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 278:
#line 988 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = new IR::Type_Bits(yystack_[5].location+yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), false); }
#line 4909 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 279:
#line 990 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = new IR::Type_Bits(yystack_[5].location+yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), true); }
#line 4915 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 280:
#line 992 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = new IR::Type_Varbits(yystack_[5].location+yystack_[0].location, yystack_[2].value.as< IR::Expression* > ()); }
#line 4921 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 281:
#line 996 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = yystack_[0].value.as< ConstType* > (); }
#line 4927 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 282:
#line 997 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = IR::Type_Void::get(); }
#line 4933 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 283:
#line 998 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = new IR::Type_Name(yystack_[0].location, new IR::Path(*(new IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ())))); }
#line 4939 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 284:
#line 1003 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::TypeParameters* > () = new IR::TypeParameters(); }
#line 4945 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 285:
#line 1004 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::TypeParameters* > () = yystack_[0].value.as< IR::TypeParameters* > (); }
#line 4951 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 286:
#line 1008 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::TypeParameters* > () = new IR::TypeParameters(yystack_[2].location+yystack_[0].location, *yystack_[1].value.as< IR::IndexedVector<IR::Type_Var>* > ()); }
#line 4957 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 287:
#line 1012 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::Type_Var>* > () = new IR::IndexedVector<IR::Type_Var>();
                                       yylhs.value.as< IR::IndexedVector<IR::Type_Var>* > ()->push_back(new IR::Type_Var(yystack_[0].location, *yystack_[0].value.as< IR::ID* > ())); }
#line 4964 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 288:
#line 1014 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::IndexedVector<IR::Type_Var>* > ()=yystack_[2].value.as< IR::IndexedVector<IR::Type_Var>* > ())->push_back(new IR::Type_Var(yystack_[0].location, *yystack_[0].value.as< IR::ID* > ())); }
#line 4970 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 289:
#line 1018 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = yystack_[0].value.as< ConstType* > (); }
#line 4976 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 290:
#line 1019 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = new IR::Type_Name(yystack_[0].location, new IR::Path(*yystack_[0].value.as< IR::ID* > ())); }
#line 4982 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 291:
#line 1021 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = IR::Type_Void::get(); }
#line 4988 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 292:
#line 1022 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = new IR::Type_Dontcare(yystack_[0].location); }
#line 4994 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 293:
#line 1026 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Type>* > () = new IR::Vector<IR::Type>(); }
#line 5000 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 294:
#line 1027 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Type>* > () = new IR::Vector<IR::Type>(); yylhs.value.as< IR::Vector<IR::Type>* > ()->push_back(yystack_[0].value.as< ConstType* > ()); }
#line 5006 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 295:
#line 1028 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Type>* > () = yystack_[2].value.as< IR::Vector<IR::Type>* > (); yylhs.value.as< IR::Vector<IR::Type>* > ()->push_back(yystack_[0].value.as< ConstType* > ()); }
#line 5012 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 296:
#line 1032 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = yystack_[0].value.as< ConstType* > (); }
#line 5018 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 297:
#line 1033 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = IR::Type_Void::get(); }
#line 5024 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 298:
#line 1034 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = new IR::Type_Dontcare(yystack_[0].location); }
#line 5030 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 299:
#line 1040 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Type>* > () = new IR::Vector<IR::Type>(); yylhs.value.as< IR::Vector<IR::Type>* > ()->push_back(yystack_[0].value.as< ConstType* > ()); }
#line 5036 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 300:
#line 1041 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Type>* > () = yystack_[2].value.as< IR::Vector<IR::Type>* > (); yylhs.value.as< IR::Vector<IR::Type>* > ()->push_back(yystack_[0].value.as< ConstType* > ()); }
#line 5042 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 301:
#line 1045 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Type_Declaration* > () = yystack_[0].value.as< IR::Type_Declaration* > (); }
#line 5048 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 302:
#line 1046 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Type_Declaration* > () = yystack_[1].value.as< IR::Type_Declaration* > (); }
#line 5054 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 303:
#line 1047 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->pop(); yylhs.value.as< IR::Type_Declaration* > () = yystack_[1].value.as< IR::Type_Parser* > (); }
#line 5060 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 304:
#line 1048 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->pop(); yylhs.value.as< IR::Type_Declaration* > () = yystack_[1].value.as< IR::Type_Control* > (); }
#line 5066 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 305:
#line 1049 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->pop(); yylhs.value.as< IR::Type_Declaration* > () = yystack_[1].value.as< IR::Type_Declaration* > (); }
#line 5072 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 306:
#line 1053 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Type_Declaration* > () = yystack_[0].value.as< IR::Type_Declaration* > (); }
#line 5078 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 307:
#line 1054 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Type_Declaration* > () = yystack_[0].value.as< IR::Type_Declaration* > (); }
#line 5084 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 308:
#line 1055 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Type_Declaration* > () = yystack_[0].value.as< IR::Type_Declaration* > (); }
#line 5090 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 309:
#line 1056 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Type_Declaration* > () = yystack_[0].value.as< IR::Type_Declaration* > (); }
#line 5096 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 310:
#line 1060 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->pushContainerType(*yystack_[0].value.as< IR::ID* > (), true); }
#line 5102 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 311:
#line 1060 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    {
        // type parameters are experimental
        driver.structure->markAsTemplate(*yystack_[2].value.as< IR::ID* > ());
        driver.structure->declareTypes(&yystack_[0].value.as< IR::TypeParameters* > ()->parameters); }
#line 5111 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 312:
#line 1064 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Type_Declaration* > () = new IR::Type_Header(yystack_[6].location, *yystack_[6].value.as< IR::ID* > (), yystack_[8].value.as< IR::Annotations* > (), yystack_[4].value.as< IR::TypeParameters* > (), *yystack_[1].value.as< IR::IndexedVector<IR::StructField>* > ());
                                driver.structure->pop(); }
#line 5118 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 313:
#line 1069 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->pushContainerType(*yystack_[0].value.as< IR::ID* > (), true); }
#line 5124 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 314:
#line 1069 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    {
        // type parameters are experimental
        driver.structure->markAsTemplate(*yystack_[2].value.as< IR::ID* > ());
        driver.structure->declareTypes(&yystack_[0].value.as< IR::TypeParameters* > ()->parameters); }
#line 5133 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 315:
#line 1073 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Type_Declaration* > () = new IR::Type_Struct(yystack_[6].location, *yystack_[6].value.as< IR::ID* > (), yystack_[8].value.as< IR::Annotations* > (), yystack_[4].value.as< IR::TypeParameters* > (), *yystack_[1].value.as< IR::IndexedVector<IR::StructField>* > ());
                                driver.structure->pop(); }
#line 5140 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 316:
#line 1078 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->pushContainerType(*yystack_[0].value.as< IR::ID* > (), true); }
#line 5146 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 317:
#line 1078 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    {
        // type parameters are experimental
        driver.structure->markAsTemplate(*yystack_[2].value.as< IR::ID* > ());
        driver.structure->declareTypes(&yystack_[0].value.as< IR::TypeParameters* > ()->parameters); }
#line 5155 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 318:
#line 1082 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Type_Declaration* > () = new IR::Type_HeaderUnion(yystack_[6].location, *yystack_[6].value.as< IR::ID* > (), yystack_[8].value.as< IR::Annotations* > (), yystack_[4].value.as< IR::TypeParameters* > (), *yystack_[1].value.as< IR::IndexedVector<IR::StructField>* > ());
                                driver.structure->pop(); }
#line 5162 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 319:
#line 1087 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::StructField>* > () = new IR::IndexedVector<IR::StructField>(); }
#line 5168 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 320:
#line 1088 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::StructField>* > () = yystack_[1].value.as< IR::IndexedVector<IR::StructField>* > (); yystack_[1].value.as< IR::IndexedVector<IR::StructField>* > ()->push_back(yystack_[0].value.as< IR::StructField* > ()); }
#line 5174 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 321:
#line 1092 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::StructField* > () = new IR::StructField(yystack_[1].location, *yystack_[1].value.as< IR::ID* > (), yystack_[3].value.as< IR::Annotations* > (), yystack_[2].value.as< ConstType* > ()); }
#line 5180 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 322:
#line 1097 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->declareType(*yystack_[0].value.as< IR::ID* > ()); }
#line 5186 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 323:
#line 1098 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Type_Declaration* > () = new IR::Type_Enum(yystack_[4].location, *yystack_[4].value.as< IR::ID* > (), *yystack_[1].value.as< IR::IndexedVector<IR::Declaration_ID>* > ()); }
#line 5192 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 324:
#line 1099 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->declareType(*yystack_[0].value.as< IR::ID* > ()); }
#line 5198 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 325:
#line 1100 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    {
              auto type = yystack_[5].value.as< ConstType* > ();
              yylhs.value.as< IR::Type_Declaration* > () = new IR::Type_SerEnum(yystack_[4].location, *yystack_[4].value.as< IR::ID* > (), type, *yystack_[1].value.as< IR::IndexedVector<IR::SerEnumMember>* > ());
	  }
#line 5207 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 326:
#line 1107 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::SerEnumMember>* > () = new IR::IndexedVector<IR::SerEnumMember>(); yylhs.value.as< IR::IndexedVector<IR::SerEnumMember>* > ()->push_back(yystack_[0].value.as< IR::SerEnumMember* > ()); }
#line 5213 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 327:
#line 1108 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::SerEnumMember>* > () = yystack_[2].value.as< IR::IndexedVector<IR::SerEnumMember>* > (); yystack_[2].value.as< IR::IndexedVector<IR::SerEnumMember>* > ()->push_back(yystack_[0].value.as< IR::SerEnumMember* > ()); }
#line 5219 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 328:
#line 1112 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::SerEnumMember* > () = new IR::SerEnumMember(yystack_[2].location+yystack_[0].location, *yystack_[2].value.as< IR::ID* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 5225 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 329:
#line 1117 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Type_Error* > () = new IR::Type_Error(yystack_[3].location + yystack_[0].location, IR::ID(yystack_[3].location, "error"), *yystack_[1].value.as< IR::IndexedVector<IR::Declaration_ID>* > ()); }
#line 5231 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 330:
#line 1122 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Node* > () = new IR::Declaration_MatchKind(yystack_[3].location + yystack_[0].location, *yystack_[1].value.as< IR::IndexedVector<IR::Declaration_ID>* > ()); }
#line 5237 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 331:
#line 1126 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::Declaration_ID>* > () = new IR::IndexedVector<IR::Declaration_ID>();
                                yylhs.value.as< IR::IndexedVector<IR::Declaration_ID>* > ()->push_back(new IR::Declaration_ID(yystack_[0].location, *yystack_[0].value.as< IR::ID* > ()));}
#line 5244 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 332:
#line 1128 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::Declaration_ID>* > () = yystack_[2].value.as< IR::IndexedVector<IR::Declaration_ID>* > (); yylhs.value.as< IR::IndexedVector<IR::Declaration_ID>* > ()->push_back(new IR::Declaration_ID(yystack_[0].location, *yystack_[0].value.as< IR::ID* > ())); }
#line 5250 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 333:
#line 1132 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->declareType(*yystack_[0].value.as< IR::ID* > ());
          yylhs.value.as< IR::Type_Declaration* > () = new IR::Type_Typedef(yystack_[0].location, *yystack_[0].value.as< IR::ID* > (), new IR::Annotations(*yystack_[3].value.as< IR::Annotations* > ()), yystack_[1].value.as< ConstType* > ()); }
#line 5257 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 334:
#line 1134 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->declareType(*yystack_[0].value.as< IR::ID* > ());
                        yylhs.value.as< IR::Type_Declaration* > () = new IR::Type_Typedef(yystack_[0].location, *yystack_[0].value.as< IR::ID* > (), new IR::Annotations(*yystack_[3].value.as< IR::Annotations* > ()), yystack_[1].value.as< IR::Type_Declaration* > ()); }
#line 5264 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 335:
#line 1136 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->declareType(*yystack_[0].value.as< IR::ID* > ());
          yylhs.value.as< IR::Type_Declaration* > () = new IR::Type_Newtype(yystack_[0].location, *yystack_[0].value.as< IR::ID* > (), new IR::Annotations(*yystack_[3].value.as< IR::Annotations* > ()), yystack_[1].value.as< ConstType* > ()); }
#line 5271 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 336:
#line 1138 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->declareType(*yystack_[0].value.as< IR::ID* > ());
                        yylhs.value.as< IR::Type_Declaration* > () = new IR::Type_Newtype(yystack_[0].location, *yystack_[0].value.as< IR::ID* > (), new IR::Annotations(*yystack_[3].value.as< IR::Annotations* > ()), yystack_[1].value.as< IR::Type_Declaration* > ()); }
#line 5278 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 337:
#line 1147 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { auto mc = new IR::MethodCallExpression(yystack_[4].location + yystack_[1].location, yystack_[4].value.as< IR::Expression* > (),
                                                 new IR::Vector<IR::Type>(), yystack_[2].value.as< IR::Vector<IR::Argument>* > ());
          yylhs.value.as< IR::Statement* > () = new IR::MethodCallStatement(yystack_[4].location + yystack_[1].location, mc); }
#line 5286 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 338:
#line 1152 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { auto mc = new IR::MethodCallExpression(yystack_[7].location + yystack_[1].location,
                                                 yystack_[7].value.as< IR::Expression* > (), yystack_[5].value.as< IR::Vector<IR::Type>* > (), yystack_[2].value.as< IR::Vector<IR::Argument>* > ());
          yylhs.value.as< IR::Statement* > () = new IR::MethodCallStatement(yystack_[7].location + yystack_[1].location, mc); }
#line 5294 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 339:
#line 1157 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Statement* > () = new IR::AssignmentStatement(yystack_[2].location, yystack_[3].value.as< IR::Expression* > (), yystack_[1].value.as< IR::Expression* > ()); }
#line 5300 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 340:
#line 1162 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Statement* > () = new IR::EmptyStatement(yystack_[0].location); }
#line 5306 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 341:
#line 1166 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Statement* > () = new IR::ExitStatement(yystack_[1].location); }
#line 5312 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 342:
#line 1170 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Statement* > () = new IR::ReturnStatement(yystack_[1].location, nullptr); }
#line 5318 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 343:
#line 1171 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Statement* > () = new IR::ReturnStatement(yystack_[2].location, yystack_[1].value.as< IR::Expression* > ()); }
#line 5324 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 344:
#line 1176 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Statement* > () = new IR::IfStatement(yystack_[4].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Statement* > (), nullptr); }
#line 5330 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 345:
#line 1178 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Statement* > () = new IR::IfStatement(yystack_[6].location, yystack_[4].value.as< IR::Expression* > (), yystack_[2].value.as< IR::Statement* > (), yystack_[0].value.as< IR::Statement* > ()); }
#line 5336 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 346:
#line 1183 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    {
                                  auto method = new IR::Member(
                                      yystack_[6].location + yystack_[4].location, new IR::TypeNameExpression(yystack_[6].value.as< IR::Type_Name* > ()), IR::ID(yystack_[4].location, "apply"));
                                  auto mce = new IR::MethodCallExpression(yystack_[6].location + yystack_[1].location, method, yystack_[2].value.as< IR::Vector<IR::Argument>* > ());
                                  yylhs.value.as< IR::Statement* > () = new IR::MethodCallStatement(yystack_[6].location + yystack_[1].location, mce); }
#line 5346 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 347:
#line 1191 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Statement* > () = yystack_[0].value.as< IR::Statement* > (); }
#line 5352 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 348:
#line 1192 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Statement* > () = yystack_[0].value.as< IR::Statement* > (); }
#line 5358 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 349:
#line 1193 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Statement* > () = yystack_[0].value.as< IR::Statement* > (); }
#line 5364 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 350:
#line 1194 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Statement* > () = yystack_[0].value.as< IR::Statement* > (); }
#line 5370 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 351:
#line 1195 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Statement* > () = yystack_[0].value.as< IR::BlockStatement* > (); }
#line 5376 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 352:
#line 1196 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Statement* > () = yystack_[0].value.as< IR::Statement* > (); }
#line 5382 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 353:
#line 1197 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Statement* > () = yystack_[0].value.as< IR::Statement* > (); }
#line 5388 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 354:
#line 1198 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Statement* > () = yystack_[0].value.as< IR::Statement* > (); }
#line 5394 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 355:
#line 1202 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->pushNamespace(yystack_[0].location, false); }
#line 5400 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 356:
#line 1203 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->pop();
                           yylhs.value.as< IR::BlockStatement* > () = new IR::BlockStatement(yystack_[4].location + yystack_[0].location, yystack_[4].value.as< IR::Annotations* > (), *yystack_[1].value.as< IR::IndexedVector<IR::StatOrDecl>* > ()); }
#line 5407 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 357:
#line 1208 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::StatOrDecl>* > () = new IR::IndexedVector<IR::StatOrDecl>(); }
#line 5413 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 358:
#line 1209 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::StatOrDecl>* > () = yystack_[1].value.as< IR::IndexedVector<IR::StatOrDecl>* > (); yylhs.value.as< IR::IndexedVector<IR::StatOrDecl>* > ()->push_back(yystack_[0].value.as< IR::StatOrDecl* > ()); }
#line 5419 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 359:
#line 1213 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    {
            yylhs.value.as< IR::Statement* > () = new IR::SwitchStatement(yystack_[6].location, yystack_[4].value.as< IR::Expression* > (), std::move(*yystack_[1].value.as< IR::Vector<IR::SwitchCase>* > ())); }
#line 5426 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 360:
#line 1218 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::SwitchCase>* > () = new IR::Vector<IR::SwitchCase>(); }
#line 5432 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 361:
#line 1219 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::SwitchCase>* > () = yystack_[1].value.as< IR::Vector<IR::SwitchCase>* > (); yylhs.value.as< IR::Vector<IR::SwitchCase>* > ()->push_back(yystack_[0].value.as< IR::SwitchCase* > ()); }
#line 5438 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 362:
#line 1223 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::SwitchCase* > () = new IR::SwitchCase(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::BlockStatement* > ()); }
#line 5444 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 363:
#line 1224 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::SwitchCase* > () = new IR::SwitchCase(yystack_[1].location, yystack_[1].value.as< IR::Expression* > (), nullptr); }
#line 5450 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 364:
#line 1228 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::DefaultExpression(yystack_[0].location); }
#line 5456 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 365:
#line 1229 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = yystack_[0].value.as< IR::Expression* > (); }
#line 5462 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 366:
#line 1233 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::StatOrDecl* > () = yystack_[0].value.as< IR::Declaration* > (); }
#line 5468 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 367:
#line 1234 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::StatOrDecl* > () = yystack_[0].value.as< IR::Declaration* > (); }
#line 5474 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 368:
#line 1235 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::StatOrDecl* > () = yystack_[0].value.as< IR::Statement* > (); }
#line 5480 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 369:
#line 1236 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::StatOrDecl* > () = yystack_[0].value.as< IR::Declaration* > (); }
#line 5486 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 370:
#line 1244 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Declaration* > () = new IR::P4Table(yystack_[3].location, *yystack_[3].value.as< IR::ID* > (), yystack_[5].value.as< IR::Annotations* > (), new IR::TableProperties(yystack_[1].location, *yystack_[1].value.as< IR::IndexedVector<IR::Property>* > ())); }
#line 5492 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 371:
#line 1248 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::Property>* > () = new IR::IndexedVector<IR::Property>();
                                           yylhs.value.as< IR::IndexedVector<IR::Property>* > ()->push_back(yystack_[0].value.as< IR::Property* > ()); }
#line 5499 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 372:
#line 1250 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::Property>* > () = yystack_[1].value.as< IR::IndexedVector<IR::Property>* > (); yylhs.value.as< IR::IndexedVector<IR::Property>* > ()->push_back(yystack_[0].value.as< IR::Property* > ()); }
#line 5505 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 373:
#line 1255 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { auto v = new IR::Key(yystack_[1].location, *yystack_[1].value.as< IR::Vector<IR::KeyElement>* > ());
          auto id = IR::ID(yystack_[4].location, "key");
          yylhs.value.as< IR::Property* > () = new IR::Property( yystack_[4].location + yystack_[0].location, id, v, false); }
#line 5513 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 374:
#line 1259 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { auto v = new IR::ActionList(yystack_[1].location, *yystack_[1].value.as< IR::IndexedVector<IR::ActionListElement>* > ());
          auto id = IR::ID(yystack_[4].location, "actions");
          yylhs.value.as< IR::Property* > () = new IR::Property(yystack_[4].location + yystack_[0].location, id, v, false); }
#line 5521 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 375:
#line 1263 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { auto l = new IR::EntriesList(yystack_[4].location, *yystack_[1].value.as< IR::Vector<IR::Entry>* > ());
          auto id = IR::ID(yystack_[4].location+yystack_[0].location, "entries");
          yylhs.value.as< IR::Property* > () = new IR::Property(yystack_[4].location, id, yystack_[6].value.as< IR::Annotations* > (), l, yystack_[5].value.as< OptionalConst > ().isConst); }
#line 5529 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 376:
#line 1267 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { auto v = new IR::ExpressionValue(yystack_[1].location, yystack_[1].value.as< IR::Expression* > ());
          auto id = *yystack_[3].value.as< IR::ID* > ();
          yylhs.value.as< IR::Property* > () = new IR::Property(yystack_[3].value.as< IR::ID* > ()->srcInfo, id, yystack_[5].value.as< IR::Annotations* > (), v, yystack_[4].value.as< OptionalConst > ().isConst); }
#line 5537 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 377:
#line 1273 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::KeyElement>* > () = new IR::Vector<IR::KeyElement>(); }
#line 5543 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 378:
#line 1274 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::KeyElement>* > () = yystack_[1].value.as< IR::Vector<IR::KeyElement>* > (); yylhs.value.as< IR::Vector<IR::KeyElement>* > ()->push_back(yystack_[0].value.as< IR::KeyElement* > ()); }
#line 5549 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 379:
#line 1279 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { auto expr = new IR::PathExpression(*yystack_[2].value.as< IR::ID* > ());
                                           yylhs.value.as< IR::KeyElement* > () = new IR::KeyElement(yystack_[4].location, yystack_[1].value.as< IR::Annotations* > (), yystack_[4].value.as< IR::Expression* > (), expr); }
#line 5556 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 380:
#line 1284 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::ActionListElement>* > () = new IR::IndexedVector<IR::ActionListElement>(); }
#line 5562 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 381:
#line 1286 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::IndexedVector<IR::ActionListElement>* > () = yystack_[3].value.as< IR::IndexedVector<IR::ActionListElement>* > (); yylhs.value.as< IR::IndexedVector<IR::ActionListElement>* > ()->push_back(new IR::ActionListElement(yystack_[1].location, yystack_[2].value.as< IR::Annotations* > (), yystack_[1].value.as< IR::Expression* > ())); }
#line 5568 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 382:
#line 1291 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::PathExpression(yystack_[0].value.as< IR::Path* > ()); }
#line 5574 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 383:
#line 1293 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::MethodCallExpression(yystack_[3].location+yystack_[1].location, new IR::PathExpression(yystack_[3].value.as< IR::Path* > ()), yystack_[1].value.as< IR::Vector<IR::Argument>* > ()); }
#line 5580 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 384:
#line 1298 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { if (auto l = yystack_[4].value.as< IR::Expression* > ()->to<IR::ListExpression>())
            yylhs.value.as< IR::Entry* > () = new IR::Entry(yystack_[4].location+yystack_[1].location, yystack_[1].value.as< IR::Annotations* > (), l, yystack_[2].value.as< IR::Expression* > ());
          else {  // if not a tuple, make it a list of 1
            IR::Vector<IR::Expression> le(yystack_[4].value.as< IR::Expression* > ());
            yylhs.value.as< IR::Entry* > () = new IR::Entry(yystack_[4].location+yystack_[1].location, yystack_[1].value.as< IR::Annotations* > (),
                   new IR::ListExpression(yystack_[4].location, le),
                   yystack_[2].value.as< IR::Expression* > ());
          }
        }
#line 5594 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 385:
#line 1310 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Entry>* > () = new IR::Vector<IR::Entry>(); yylhs.value.as< IR::Vector<IR::Entry>* > ()->push_back(yystack_[0].value.as< IR::Entry* > ()); }
#line 5600 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 386:
#line 1311 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Entry>* > () = yystack_[1].value.as< IR::Vector<IR::Entry>* > (); yylhs.value.as< IR::Vector<IR::Entry>* > ()->push_back(yystack_[0].value.as< IR::Entry* > ()); }
#line 5606 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 387:
#line 1318 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { auto pl = new IR::ParameterList(yystack_[2].location, *yystack_[2].value.as< IR::IndexedVector<IR::Parameter>* > ());
          yylhs.value.as< IR::Declaration* > () = new IR::P4Action(yystack_[4].location, *yystack_[4].value.as< IR::ID* > (), yystack_[6].value.as< IR::Annotations* > (), pl, yystack_[0].value.as< IR::BlockStatement* > ()); }
#line 5613 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 388:
#line 1326 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { auto ann = new IR::Annotations(yystack_[4].location, *yystack_[4].value.as< IR::Vector<IR::Annotation>* > ());
                                       yylhs.value.as< IR::Declaration* > () = new IR::Declaration_Variable(yystack_[4].location+yystack_[1].location, *yystack_[2].value.as< IR::ID* > (), ann, yystack_[3].value.as< ConstType* > (), yystack_[1].value.as< IR::Expression* > ());
                                       driver.structure->declareObject(*yystack_[2].value.as< IR::ID* > (), yystack_[3].value.as< ConstType* > ()->toString()); }
#line 5621 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 389:
#line 1330 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Declaration* > () = new IR::Declaration_Variable(yystack_[3].location+yystack_[0].location, *yystack_[2].value.as< IR::ID* > (), yystack_[3].value.as< ConstType* > (), yystack_[1].value.as< IR::Expression* > ());
                                       driver.structure->declareObject(*yystack_[2].value.as< IR::ID* > (), yystack_[3].value.as< ConstType* > ()->toString()); }
#line 5628 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 390:
#line 1336 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Declaration* > () = new IR::Declaration_Constant(yystack_[3].location, *yystack_[3].value.as< IR::ID* > (), yystack_[6].value.as< IR::Annotations* > (), yystack_[4].value.as< ConstType* > (), yystack_[1].value.as< IR::Expression* > ());
                                       driver.structure->declareObject(*yystack_[3].value.as< IR::ID* > (), yystack_[4].value.as< ConstType* > ()->toString()); }
#line 5635 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 391:
#line 1341 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = nullptr; }
#line 5641 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 392:
#line 1342 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = yystack_[0].value.as< IR::Expression* > (); }
#line 5647 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 393:
#line 1346 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = yystack_[0].value.as< IR::Expression* > (); }
#line 5653 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 394:
#line 1352 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    {
            driver.structure->pop();
            yylhs.value.as< IR::Declaration* > () = new IR::Function(yystack_[1].value.as< IR::Method* > ()->srcInfo, yystack_[1].value.as< IR::Method* > ()->name, yystack_[1].value.as< IR::Method* > ()->type, yystack_[0].value.as< IR::BlockStatement* > ()); }
#line 5661 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 395:
#line 1358 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Argument>* > () = new IR::Vector<IR::Argument>(); }
#line 5667 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 396:
#line 1359 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Argument>* > () = yystack_[0].value.as< IR::Vector<IR::Argument>* > (); }
#line 5673 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 397:
#line 1363 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Argument>* > () = new IR::Vector<IR::Argument>();
                                           yylhs.value.as< IR::Vector<IR::Argument>* > ()->push_back(yystack_[0].value.as< IR::Argument* > ()); }
#line 5680 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 398:
#line 1365 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Argument>* > () = yystack_[2].value.as< IR::Vector<IR::Argument>* > (); yylhs.value.as< IR::Vector<IR::Argument>* > ()->push_back(yystack_[0].value.as< IR::Argument* > ()); }
#line 5686 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 399:
#line 1369 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Argument* > () = new IR::Argument(yystack_[0].location, yystack_[0].value.as< IR::Expression* > ()); }
#line 5692 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 400:
#line 1370 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Argument* > () = new IR::Argument(yystack_[2].location, *yystack_[2].value.as< IR::ID* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 5698 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 401:
#line 1371 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Argument* > () = new IR::Argument(yystack_[0].location, new IR::DefaultExpression(yystack_[0].location)); }
#line 5704 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 402:
#line 1375 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = new IR::Vector<IR::Expression>(); }
#line 5710 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 403:
#line 1376 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = new IR::Vector<IR::Expression>();
                                           yylhs.value.as< IR::Vector<IR::Expression>* > ()->push_back(yystack_[0].value.as< IR::Expression* > ()); }
#line 5717 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 404:
#line 1378 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = yystack_[2].value.as< IR::Vector<IR::Expression>* > (); yylhs.value.as< IR::Vector<IR::Expression>* > ()->push_back(yystack_[0].value.as< IR::Expression* > ()); }
#line 5723 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 405:
#line 1382 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Path* > () = new IR::Path(*yystack_[0].value.as< IR::ID* > ()); }
#line 5729 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 406:
#line 1383 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Path* > () = new IR::Path(*yystack_[0].value.as< IR::ID* > (), true);
                                           driver.structure->clearPath(); }
#line 5736 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 407:
#line 1388 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { driver.structure->relativePathFromLastSymbol(); }
#line 5742 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 408:
#line 1388 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    {
          driver.structure->clearPath(); yylhs.value.as< IR::ID* > () = yystack_[0].value.as< IR::ID* > (); }
#line 5749 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 409:
#line 1392 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::PathExpression(yystack_[0].value.as< IR::Path* > ()); }
#line 5755 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 410:
#line 1393 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::This(yystack_[0].location); }
#line 5761 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 411:
#line 1394 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Member(yystack_[1].location + yystack_[0].location, yystack_[1].value.as< IR::Expression* > (), *yystack_[0].value.as< IR::ID* > ()); }
#line 5767 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 412:
#line 1395 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::ArrayIndex(yystack_[3].location + yystack_[0].location, yystack_[3].value.as< IR::Expression* > (), yystack_[1].value.as< IR::Expression* > ()); }
#line 5773 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 413:
#line 1396 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Slice(yystack_[5].location + yystack_[0].location, yystack_[5].value.as< IR::Expression* > (), yystack_[3].value.as< IR::Expression* > (), yystack_[1].value.as< IR::Expression* > ()); }
#line 5779 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 414:
#line 1400 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = parseConstant(yystack_[0].location, yystack_[0].value.as< UnparsedConstant > (), 0); }
#line 5785 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 415:
#line 1401 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::StringLiteral(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 5791 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 416:
#line 1402 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::BoolLiteral(yystack_[0].location, true); }
#line 5797 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 417:
#line 1403 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::BoolLiteral(yystack_[0].location, false); }
#line 5803 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 418:
#line 1404 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::This(yystack_[0].location); }
#line 5809 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 419:
#line 1405 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::PathExpression(*yystack_[0].value.as< IR::ID* > ()); }
#line 5815 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 420:
#line 1406 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::PathExpression(new IR::Path(*yystack_[0].value.as< IR::ID* > (), true)); driver.structure->clearPath(); }
#line 5821 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 421:
#line 1407 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::ArrayIndex(yystack_[3].location + yystack_[0].location, yystack_[3].value.as< IR::Expression* > (), yystack_[1].value.as< IR::Expression* > ()); }
#line 5827 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 422:
#line 1408 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Slice(yystack_[5].location + yystack_[0].location, yystack_[5].value.as< IR::Expression* > (), yystack_[3].value.as< IR::Expression* > (), yystack_[1].value.as< IR::Expression* > ()); }
#line 5833 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 423:
#line 1409 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::ListExpression(yystack_[2].location + yystack_[0].location, *yystack_[1].value.as< IR::Vector<IR::Expression>* > ()); }
#line 5839 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 424:
#line 1410 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::StructExpression(
                                                  yystack_[2].location + yystack_[0].location, IR::Type::Unknown::get(), (IR::Type_Name*)nullptr, *yystack_[1].value.as< IR::IndexedVector<IR::NamedExpression>* > ()); }
#line 5846 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 425:
#line 1412 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = yystack_[1].value.as< IR::Expression* > (); }
#line 5852 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 426:
#line 1413 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::LNot(yystack_[1].location + yystack_[0].location, yystack_[0].value.as< IR::Expression* > ()); }
#line 5858 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 427:
#line 1414 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Cmpl(yystack_[1].location + yystack_[0].location, yystack_[0].value.as< IR::Expression* > ()); }
#line 5864 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 428:
#line 1415 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Neg(yystack_[1].location + yystack_[0].location, yystack_[0].value.as< IR::Expression* > ()); }
#line 5870 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 429:
#line 1416 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = yystack_[0].value.as< IR::Expression* > (); }
#line 5876 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 430:
#line 1418 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Member(yystack_[1].location + yystack_[0].location, new IR::TypeNameExpression(yystack_[1].location, yystack_[1].value.as< IR::Type_Name* > ()), *yystack_[0].value.as< IR::ID* > ()); }
#line 5882 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 431:
#line 1420 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { auto typeName = new IR::Type_Name(yystack_[2].location, new IR::Path(IR::ID(yystack_[2].location, "error")));
          yylhs.value.as< IR::Expression* > () = new IR::Member(yystack_[2].location+yystack_[0].location, new IR::TypeNameExpression(yystack_[2].location+yystack_[0].location, typeName), *yystack_[0].value.as< IR::ID* > ()); }
#line 5889 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 432:
#line 1422 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Member(yystack_[1].location + yystack_[0].location, yystack_[1].value.as< IR::Expression* > (), *yystack_[0].value.as< IR::ID* > ()); }
#line 5895 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 433:
#line 1423 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Mul(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 5901 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 434:
#line 1424 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Div(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 5907 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 435:
#line 1425 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Mod(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 5913 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 436:
#line 1426 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Add(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 5919 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 437:
#line 1427 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Sub(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 5925 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 438:
#line 1428 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::AddSat(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 5931 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 439:
#line 1429 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::SubSat(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 5937 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 440:
#line 1430 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Shl(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 5943 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 441:
#line 1432 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Shr(yystack_[3].location + yystack_[0].location, yystack_[3].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 5949 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 442:
#line 1433 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Leq(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 5955 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 443:
#line 1434 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Geq(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 5961 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 444:
#line 1436 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Lss(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 5967 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 445:
#line 1437 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Grt(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 5973 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 446:
#line 1438 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Neq(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 5979 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 447:
#line 1439 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Equ(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 5985 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 448:
#line 1440 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::BAnd(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 5991 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 449:
#line 1441 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::BXor(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 5997 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 450:
#line 1442 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::BOr(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6003 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 451:
#line 1443 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Concat(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6009 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 452:
#line 1444 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::LAnd(yystack_[2].location + yystack_[1].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6015 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 453:
#line 1445 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::LOr(yystack_[2].location + yystack_[1].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6021 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 454:
#line 1446 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Mux(yystack_[4].location + yystack_[0].location, yystack_[4].value.as< IR::Expression* > (), yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6027 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 455:
#line 1448 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::MethodCallExpression(yystack_[6].location + yystack_[3].location, yystack_[6].value.as< IR::Expression* > (), yystack_[4].value.as< IR::Vector<IR::Type>* > (), yystack_[1].value.as< IR::Vector<IR::Argument>* > ()); }
#line 6033 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 456:
#line 1450 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::MethodCallExpression(yystack_[3].location + yystack_[0].location, yystack_[3].value.as< IR::Expression* > (), yystack_[1].value.as< IR::Vector<IR::Argument>* > ()); }
#line 6039 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 457:
#line 1452 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::ConstructorCallExpression(yystack_[3].location + yystack_[0].location, yystack_[3].value.as< ConstType* > (), yystack_[1].value.as< IR::Vector<IR::Argument>* > ()); }
#line 6045 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 458:
#line 1453 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Cast(yystack_[3].location + yystack_[0].location, yystack_[2].value.as< ConstType* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6051 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 459:
#line 1457 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = parseConstant(yystack_[0].location, yystack_[0].value.as< UnparsedConstant > (), 0); }
#line 6057 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 460:
#line 1458 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::StringLiteral(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 6063 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 461:
#line 1459 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::BoolLiteral(yystack_[0].location, true); }
#line 6069 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 462:
#line 1460 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::BoolLiteral(yystack_[0].location, false); }
#line 6075 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 463:
#line 1461 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::This(yystack_[0].location); }
#line 6081 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 464:
#line 1462 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::PathExpression(*yystack_[0].value.as< IR::ID* > ()); }
#line 6087 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 465:
#line 1463 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::PathExpression(new IR::Path(*yystack_[0].value.as< IR::ID* > (), true)); driver.structure->clearPath(); }
#line 6093 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 466:
#line 1464 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::ArrayIndex(yystack_[3].location + yystack_[0].location, yystack_[3].value.as< IR::Expression* > (), yystack_[1].value.as< IR::Expression* > ()); }
#line 6099 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 467:
#line 1465 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Slice(yystack_[5].location + yystack_[0].location, yystack_[5].value.as< IR::Expression* > (), yystack_[3].value.as< IR::Expression* > (), yystack_[1].value.as< IR::Expression* > ()); }
#line 6105 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 468:
#line 1466 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = yystack_[1].value.as< IR::Expression* > (); }
#line 6111 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 469:
#line 1467 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::LNot(yystack_[1].location + yystack_[0].location, yystack_[0].value.as< IR::Expression* > ()); }
#line 6117 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 470:
#line 1468 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Cmpl(yystack_[1].location + yystack_[0].location, yystack_[0].value.as< IR::Expression* > ()); }
#line 6123 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 471:
#line 1469 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Neg(yystack_[1].location + yystack_[0].location, yystack_[0].value.as< IR::Expression* > ()); }
#line 6129 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 472:
#line 1470 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = yystack_[0].value.as< IR::Expression* > (); }
#line 6135 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 473:
#line 1472 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Member(yystack_[1].location + yystack_[0].location, new IR::TypeNameExpression(yystack_[1].location, yystack_[1].value.as< IR::Type_Name* > ()), *yystack_[0].value.as< IR::ID* > ()); }
#line 6141 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 474:
#line 1474 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { auto typeName = new IR::Type_Name(yystack_[2].location, new IR::Path(IR::ID(yystack_[2].location, "error")));
          yylhs.value.as< IR::Expression* > () = new IR::Member(yystack_[2].location+yystack_[0].location, new IR::TypeNameExpression(yystack_[2].location+yystack_[0].location, typeName), *yystack_[0].value.as< IR::ID* > ()); }
#line 6148 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 475:
#line 1476 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Member(yystack_[1].location + yystack_[0].location, yystack_[1].value.as< IR::Expression* > (), *yystack_[0].value.as< IR::ID* > ()); }
#line 6154 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 476:
#line 1477 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Mul(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6160 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 477:
#line 1478 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Div(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6166 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 478:
#line 1479 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Mod(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6172 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 479:
#line 1480 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Add(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6178 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 480:
#line 1481 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Sub(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6184 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 481:
#line 1482 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::AddSat(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6190 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 482:
#line 1483 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::SubSat(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6196 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 483:
#line 1484 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Shl(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6202 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 484:
#line 1486 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Shr(yystack_[3].location + yystack_[0].location, yystack_[3].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6208 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 485:
#line 1487 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Leq(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6214 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 486:
#line 1488 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Geq(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6220 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 487:
#line 1490 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Lss(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6226 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 488:
#line 1491 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Grt(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6232 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 489:
#line 1492 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Neq(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6238 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 490:
#line 1493 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Equ(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6244 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 491:
#line 1494 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::BAnd(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6250 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 492:
#line 1495 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::BXor(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6256 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 493:
#line 1496 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::BOr(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6262 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 494:
#line 1497 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Concat(yystack_[2].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6268 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 495:
#line 1498 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::LAnd(yystack_[2].location + yystack_[1].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6274 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 496:
#line 1499 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::LOr(yystack_[2].location + yystack_[1].location + yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6280 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 497:
#line 1500 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Mux(yystack_[4].location + yystack_[0].location, yystack_[4].value.as< IR::Expression* > (), yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6286 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 498:
#line 1502 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::MethodCallExpression(yystack_[6].location + yystack_[3].location, yystack_[6].value.as< IR::Expression* > (), yystack_[4].value.as< IR::Vector<IR::Type>* > (), yystack_[1].value.as< IR::Vector<IR::Argument>* > ()); }
#line 6292 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 499:
#line 1504 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::MethodCallExpression(yystack_[3].location + yystack_[0].location, yystack_[3].value.as< IR::Expression* > (), yystack_[1].value.as< IR::Vector<IR::Argument>* > ()); }
#line 6298 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 500:
#line 1506 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::ConstructorCallExpression(yystack_[3].location + yystack_[0].location, yystack_[3].value.as< ConstType* > (), yystack_[1].value.as< IR::Vector<IR::Argument>* > ()); }
#line 6304 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 501:
#line 1507 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Cast(yystack_[3].location + yystack_[0].location, yystack_[2].value.as< ConstType* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 6310 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 502:
#line 1511 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = parseConstant(yystack_[0].location, yystack_[0].value.as< UnparsedConstant > (), 0); }
#line 6316 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 503:
#line 1512 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::StringLiteral(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 6322 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 504:
#line 1516 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = new IR::Vector<IR::Expression>();
                                   yylhs.value.as< IR::Vector<IR::Expression>* > ()->push_back(parseConstant(yystack_[0].location, yystack_[0].value.as< UnparsedConstant > (), 0)); }
#line 6329 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 505:
#line 1518 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = yystack_[2].value.as< IR::Vector<IR::Expression>* > ();
                                   yylhs.value.as< IR::Vector<IR::Expression>* > ()->push_back(parseConstant(yystack_[0].location, yystack_[0].value.as< UnparsedConstant > (), 0)); }
#line 6336 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 506:
#line 1523 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = new IR::Vector<IR::Expression>();
                                   yylhs.value.as< IR::Vector<IR::Expression>* > ()->push_back(yystack_[0].value.as< IR::Expression* > ()); }
#line 6343 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 507:
#line 1525 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = yystack_[2].value.as< IR::Vector<IR::Expression>* > ();
                                   yylhs.value.as< IR::Vector<IR::Expression>* > ()->push_back(yystack_[0].value.as< IR::Expression* > ()); }
#line 6350 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 508:
#line 1530 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = new IR::Vector<IR::Expression>();
                                   yylhs.value.as< IR::Vector<IR::Expression>* > ()->push_back(new IR::StringLiteral(yystack_[0].location, yystack_[0].value.as< cstring > ())); }
#line 6357 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;

  case 509:
#line 1532 "parsers/p4/p4parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = yystack_[2].value.as< IR::Vector<IR::Expression>* > ();
                                   yylhs.value.as< IR::Vector<IR::Expression>* > ()->push_back(new IR::StringLiteral(yystack_[0].location, yystack_[0].value.as< cstring > ())); }
#line 6364 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
    break;


#line 6368 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  P4Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  P4Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short int P4Parser::yypact_ninf_ = -846;

  const short int P4Parser::yytable_ninf_ = -263;

  const short int
  P4Parser::yypact_[] =
  {
    4152,  -846,  2308,   378,   -83,   209,   -61,  2308,   -31,   209,
      22,  2308,    72,    75,  2308,    88,    99,   120,   117,   229,
    -846,   329,  2308,  2308,  2308,  2357,  1016,  2308,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,   184,  -846,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,   458,   202,  -846,   219,  -846,   218,
    3736,  -846,  -846,   211,   224,  -846,  -846,   233,  -846,  -846,
    -846,   237,  -846,   245,  3736,  -846,  -846,  -846,  2811,   260,
     267,  2848,   270,   275,   279,  -846,  -846,  -846,  -846,   378,
    -846,   107,   292,   107,   294,   378,  -846,   107,   107,  -846,
    -846,  -846,  3897,  1236,  -846,   285,  -846,   252,  -846,     6,
    -846,   129,  -846,   -34,   304,   320,  -846,  -846,   326,  -846,
     378,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,   315,
    -846,  -846,  -846,   168,   168,   168,    93,   319,   -14,    47,
     184,   321,   214,   139,  2885,   168,   378,  -846,  -846,  2112,
    -846,  -846,  -846,  -846,  2495,  2308,  2308,  2308,  2308,  2308,
    2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,
    2308,  2308,  2308,  2308,  2308,   330,  2112,  2308,  2308,  -846,
    1415,  2308,   378,   268,   209,   274,  2308,   269,   280,  2308,
     278,   281,    44,   204,   -26,   378,   -21,   378,  -846,  2495,
     -20,   378,   176,   378,  1088,   908,   378,   378,  1236,   378,
     378,   378,  1236,  -846,  -846,   336,  -846,    24,  -846,   348,
    -846,   350,   351,   -34,  -846,  2112,  2308,  2308,   107,  -846,
    -846,  -846,  2308,  -846,  -846,  -846,   340,   352,   345,  -846,
    3736,   378,  -846,  -846,  -846,  -846,  -846,   157,  3736,  3971,
    3971,  4094,  3880,  3847,  3913,  3913,   166,   166,   166,   166,
     168,   168,   168,  4002,  4064,  4033,  2700,  3971,  2308,   359,
    2922,   166,  -846,  -846,  -846,  -846,   296,  3971,  3736,  -846,
    -846,  -846,  -846,  3736,  -846,  -846,  2959,   357,   358,   107,
    -846,  -846,  -846,  2357,  -846,  2308,   298,  -846,    68,  2308,
     298,   113,  1572,   157,  2308,   298,   365,   378,  -846,  -846,
     378,   173,   362,   363,   364,  -846,  -846,  -846,    62,   378,
     378,  -846,  -846,  -846,   378,   378,  2112,    43,   366,   369,
    -846,  -846,  -846,  -846,   374,  2996,  3033,  -846,  -846,   378,
     168,  2308,  -846,  2112,  -846,  -846,  -846,  2495,  -846,  -846,
    2308,  4094,  -846,  2308,  2495,   376,  2308,   317,   323,   324,
      -6,   105,  1662,  3070,  -846,  -846,   378,  3107,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,
    -846,  3144,  -846,    24,   373,   107,   395,  -846,   107,  -846,
    -846,   107,   107,  -846,  -846,   107,   107,   107,  -846,  -846,
     389,  -846,  -846,  -846,   176,  -846,   -34,  1236,  1178,  -846,
     378,  -846,  -846,   391,  -846,   311,  3736,  -846,  -846,  3181,
    3810,  -846,  2112,  3736,  -846,  -846,   298,  -846,  -846,  -846,
     298,  -846,   298,  1752,   298,   392,  2308,  -846,   378,   398,
    -846,  -846,  -846,  -846,  -846,  -846,   378,   378,  -846,    74,
    1236,  -846,  -846,     9,  -846,  -846,   207,  -846,  -846,   -34,
     -30,  -846,  -846,  -846,  -846,  -846,  -846,  1474,   306,    24,
     378,  -846,  -846,   393,  -846,  -846,  -846,  -846,  -846,   -34,
     387,  3736,   396,   150,   378,   406,   408,   409,   418,   420,
     412,   312,   416,   378,   107,   305,  -846,   377,  -846,   419,
     433,  -846,   378,  -846,  -846,  -846,   422,   431,  2161,   432,
    -846,     8,  -846,   458,   276,  -846,  -846,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,   246,   439,
    -846,   434,  -846,  -846,  -846,  -846,    24,  -846,   435,   213,
    -846,  -846,  -846,  -846,    24,    24,  -846,   439,  -846,  2308,
    -846,   176,   419,  2308,   436,  -846,   451,  -846,  2308,  -846,
    3218,  2308,  -846,   426,  2308,  2112,  2308,  -846,  2495,  -846,
     440,  -846,   446,  2308,  -846,   378,    10,    13,    14,   449,
     450,    20,   444,  3736,   460,   298,   298,   298,   457,  -846,
    -846,    61,  3255,  -846,  3292,   468,  2737,   456,  3329,   157,
    -846,  -846,  -846,  -846,  -846,  -846,  1321,  -846,  -846,   176,
    -846,  -846,  -846,  -846,  -846,  -846,  -846,   469,   480,   481,
    -846,   476,   479,   465,    15,  -846,   515,   495,  2112,  -846,
    2308,   489,  -846,   498,    -9,  2534,   502,   496,   378,  2404,
    2308,  2308,  2308,   509,   512,  -846,   192,  -846,  -846,   501,
     487,  -846,   513,  3366,  -846,  2112,  -846,  1236,  -846,  -846,
    -846,   507,    24,  -846,   514,   402,    70,  1236,  -846,  -846,
     525,   378,  -846,  -846,  -846,  -846,  -846,  -846,  3403,  3440,
    3477,  -846,  -846,  -846,   519,  -846,  -846,  -846,  -846,   520,
     515,  2210,   517,  -846,   528,  -846,   535,  -846,   537,   530,
    -846,  -846,  -846,   378,  -846,   378,   378,   378,    67,  2259,
     546,  2308,  -846,  2308,  2308,  2308,  -846,  1016,  2308,  -846,
    -846,  -846,  -846,   538,  -846,  -846,  -846,   458,   541,   219,
    -846,   540,  3773,  -846,   539,   542,  2308,  -846,  -846,   543,
     550,   555,  -846,    69,  -846,  -846,  3514,  2010,   559,   168,
     168,   168,   547,  3551,   168,   378,  -846,  2112,  -846,     7,
    2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,
    2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,  2308,   556,
    2112,  2308,  2308,  -846,  1415,  -846,  -846,    80,  2452,  -846,
    -846,  -846,   240,   560,   570,   378,  1833,  -846,  -846,   568,
    -846,  -846,  -846,  1908,  2660,  -846,  2308,  -846,  -846,   576,
    -846,  3971,  3971,  4094,  3880,  3847,  3913,  3913,   166,   166,
     166,   166,   168,   168,   168,  4002,  4064,  4033,  2774,  3971,
    2308,   577,  3588,   166,   296,  3971,   589,  -846,  -846,  2112,
     -34,   580,   582,   586,   585,  2620,    69,  -846,  -846,  2308,
    2308,   168,  -846,  -846,  2308,  4094,  -846,  2308,   590,  -846,
     592,   583,  -846,  2061,  2308,  2308,   -34,  3736,  3736,  3625,
    3810,  2112,  1959,  -846,  -846,   172,  -846,  3662,  3699,   587,
    -846,   593,  -846,  -846,   594,  -846,  2061,  -846,  -846,   378,
    -846,   588,  -846
  };

  const unsigned short int
  P4Parser::yydefact_[] =
  {
       0,    24,   402,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,    53,     0,     0,     0,   402,     0,     0,   180,   416,
     417,   418,    40,    38,    42,     0,    39,    43,    41,    37,
     263,   415,   414,   419,     0,     0,   265,   261,   262,     4,
     403,    45,    44,     0,     5,   152,   504,     6,   503,   502,
     506,     7,   508,     8,     9,    10,    11,    12,     0,     0,
       0,     0,     0,     0,     0,     1,     2,    23,    26,     0,
     270,   272,   271,   274,     0,     0,   273,     0,     0,   282,
     283,    25,     0,    54,    55,     0,    33,     0,    30,   178,
      32,   178,    28,    53,   281,   257,   260,   259,   258,   256,
       0,    31,   301,   306,   308,   307,   309,    34,    35,     0,
      29,    27,    36,   429,   428,   427,   263,   419,     0,     0,
     271,     0,   257,   258,     0,   426,     0,   264,   420,   395,
     510,   511,   407,   430,   293,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   395,     0,     0,   432,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    57,     0,     0,     0,     0,    62,   293,
       0,     0,     0,     0,     0,     0,     0,     0,    53,     0,
       0,     0,    53,   271,    56,     0,   305,    53,   303,     0,
     304,     0,     0,    54,   394,   395,     0,     0,   284,   302,
     424,   423,     0,   425,   431,   401,     0,     0,   396,   397,
     399,     0,   292,   291,   290,   289,   294,     0,   404,   442,
     443,   440,   452,   453,   446,   447,   436,   437,   438,   439,
     433,   434,   435,   450,   448,   449,     0,   445,     0,     0,
       0,   451,   298,   297,   296,   299,     0,   444,   154,   153,
     505,   507,   509,    13,    14,    15,     0,     0,     0,     0,
      20,    22,    19,   402,    62,     0,     0,   331,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,   322,
       0,   283,   244,     0,     0,   281,   310,   316,     0,     0,
       0,   165,   188,   313,     0,     0,   395,   164,     0,   156,
     157,   182,   236,   355,     0,     0,     0,   251,   285,     0,
     458,     0,   457,     0,   408,   512,   513,     0,   269,   421,
       0,   441,   456,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   275,   329,     0,     0,   276,   330,
      65,    61,   123,   122,   117,   118,   119,   121,   120,   125,
     127,   126,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    62,   144,
     145,   146,   147,   148,   149,   150,   151,   124,   110,   115,
     116,   104,    81,   102,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    82,
      83,    84,    85,    86,    87,    88,    96,    89,    90,    91,
      93,    92,    94,    95,    97,    98,    99,   100,   101,   103,
     105,   106,   107,   108,   109,   111,   112,   113,   114,    64,
     266,     0,   277,    53,     0,   284,     0,   324,   284,   248,
     247,   284,   284,   335,   336,   284,   284,   284,   333,   334,
       0,   161,   163,   162,     0,   179,    53,    53,    53,   357,
       0,   267,   268,     0,   287,     0,   400,   398,   295,     0,
     454,   300,   395,    16,    17,    18,     0,    60,    59,    58,
       0,   332,     0,     0,     0,     0,     0,   234,     0,     0,
     245,   311,   317,   166,   189,   314,     0,     0,   158,     0,
      54,   185,   183,    53,   191,   187,     0,   186,   184,    53,
       0,   241,   237,   240,   239,   242,   238,    53,     0,    53,
       0,   286,   422,     0,    21,   278,   279,    63,   280,    53,
       0,   393,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   159,     0,     0,     0,   181,     0,   192,   391,
       0,   243,     0,   356,   340,   410,     0,     0,     0,     0,
     405,     0,   369,     0,   257,   347,   350,   353,   352,   349,
     348,   368,   351,   354,   358,   366,   367,   409,     0,     0,
     169,     0,   288,   455,   387,   390,    53,   323,     0,     0,
     326,   249,   319,   319,    53,    53,   319,     0,   168,     0,
     193,     0,   391,     0,     0,   232,     0,   341,     0,   342,
       0,     0,   406,     0,     0,   395,     0,   411,   293,   172,
       0,   252,     0,     0,   325,     0,    53,    53,    53,     0,
       0,    53,     0,   160,     0,     0,     0,     0,     0,   392,
     389,    53,     0,   343,     0,     0,     0,     0,     0,     0,
     174,   171,   235,   328,   327,   246,     0,   250,   312,     0,
     320,   318,   167,   190,   315,   170,   195,     0,     0,     0,
     388,     0,     0,    51,    53,   371,    53,     0,   395,   412,
       0,     0,   339,     0,     0,     0,   263,     0,     0,    53,
       0,     0,     0,     0,     0,    52,     0,   370,   372,     0,
     344,   360,     0,     0,   337,   395,   173,     0,   177,   175,
     176,     0,    53,   253,     0,     0,     0,    54,   196,   202,
       0,     0,   197,   199,   203,   198,   200,   201,     0,     0,
       0,   380,   377,    48,     0,    50,    49,    46,    47,     0,
      53,     0,     0,   413,     0,   254,     0,   321,     0,     0,
     207,   209,   204,     0,   194,     0,     0,     0,    53,     0,
       0,     0,   345,     0,     0,     0,   359,     0,     0,   461,
     462,   463,   364,     0,   460,   459,   464,     0,     0,   261,
     361,     0,   365,   346,     0,     0,   402,   208,   195,     0,
       0,     0,   374,     0,   373,   378,     0,     0,     0,   472,
     471,   470,     0,     0,   469,     0,   465,   395,   473,   363,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     395,     0,     0,   475,     0,   338,   255,     0,    53,   231,
     230,   229,     0,     0,   382,     0,     0,   228,   227,     0,
     214,   215,   385,     0,   224,   376,     0,   468,   474,     0,
     362,   485,   486,   483,   495,   496,   489,   490,   479,   480,
     481,   482,   476,   477,   478,   493,   491,   492,     0,   488,
       0,     0,     0,   494,     0,   487,     0,   205,   381,   395,
      53,   223,   222,     0,     0,   224,     0,   375,   386,     0,
       0,   501,   500,   466,     0,   484,   499,     0,     0,   211,
       0,     0,   217,     0,     0,     0,    53,   225,   226,     0,
     497,   395,     0,   383,   379,     0,   218,   220,   221,     0,
     467,     0,   210,   212,     0,   216,     0,   384,   498,     0,
     219,     0,   213
  };

  const short int
  P4Parser::yypgoto_[] =
  {
    -846,  -846,  -846,  -846,  -846,  -846,  -846,    -3,    42,  -846,
    -846,   179,   -13,   -89,  -270,  -846,   -12,   477,  -442,  -846,
     178,  -846,  -846,  -846,  -846,  -460,    35,  -846,  -846,  -846,
     554,   265,  -846,  -846,  -846,  -846,  -846,  -846,  -846,   136,
    -846,  -148,  -846,  -846,  -846,  -846,  -846,  -846,  -846,  -846,
    -281,  -846,  -846,  -846,  -845,  -846,  -846,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,  -846,  -188,  -846,  -846,
     727,   -99,  -846,   314,    63,  -846,   557,    71,  -846,   164,
    -846,  -846,  -291,  -187,  -846,  -171,  -846,    23,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,  -846,  -846,  -308,  -846,  -846,
    -846,  -846,  -846,    45,  -846,  -846,  -181,  -846,  -693,  -690,
    -846,  -846,  -683,  -682,  -673,  -100,  -846,  -846,  -846,  -846,
    -846,  -846,  -846,  -846,  -846,     4,  -846,  -846,  -846,  -217,
    -173,  -846,   225,  -444,   -16,    82,  -611,     3,  -109,  -846,
     379,   -24,  -793,   -37,  -846,  -846,   518,  -846,     0,  -846,
    -846,  -846,   748,  -251
  };

  const short int
  P4Parser::yydefgoto_[] =
  {
      -1,    18,    19,   282,    20,    21,    91,    43,   226,   759,
     716,   317,   213,    94,   292,   449,    54,    55,   318,   319,
     320,   474,    95,   465,   558,    96,   640,   670,   704,   729,
     209,    44,    98,   477,   522,    99,   466,   559,   523,   524,
     654,   709,   738,   739,   808,   740,   770,   771,   942,   953,
     869,   870,   945,   913,   871,   525,   100,   101,   455,   552,
     478,   532,   570,   102,   458,   555,   646,   103,   483,   677,
     235,    45,    46,    47,   106,   107,    48,   109,   110,   327,
     328,   485,   236,   237,   265,   266,   111,   112,   113,   461,
     556,   114,   467,   560,   115,   462,   557,   647,   680,   116,
     456,   509,   609,   610,   117,   118,   288,   119,   585,   586,
     587,   588,   589,   590,   591,   592,   479,   537,   593,   761,
     800,   801,   594,   533,   694,   695,   779,   815,   778,   863,
     872,   873,   120,   746,   747,   624,   550,   122,   227,   228,
     229,    49,   597,   169,   231,   598,   230,   802,    60,    57,
      61,    63,   170,   338
  };

  const short int
  P4Parser::yytable_[] =
  {
      52,   129,   293,   214,   204,   121,   291,   304,    93,    66,
     143,   505,   659,   128,   352,   345,   742,   521,   531,   743,
     864,   914,   127,   720,   285,    79,   744,   745,    56,   289,
     294,   220,   673,   527,   535,   354,   726,   497,   191,   358,
     172,   138,   450,   192,   452,    53,   488,    28,   172,    62,
      79,   -53,   323,   491,   566,   675,   207,   259,   678,   681,
     717,    85,    80,    81,   208,   684,    79,    53,    79,    79,
     203,   572,    79,    79,    79,  -155,    52,   582,    83,    79,
      65,   192,    52,    79,   691,   286,    85,   782,   946,    86,
     290,   295,   221,   595,    87,   143,    88,   601,    89,    90,
      40,   145,    85,   692,    85,    85,   324,    52,    85,    85,
      85,   960,   812,   355,   772,    85,   279,    75,   503,    85,
      79,   183,   356,   864,   204,    28,    79,   188,   471,   472,
     691,   906,    67,    52,   145,   473,   127,   -45,    32,    33,
     194,   234,   280,   192,   196,   197,    34,   192,   498,   692,
     -45,   -45,   218,   140,   141,   281,    85,    36,   359,   145,
      37,   201,    85,   127,   642,   742,    38,   356,   743,    52,
     818,   563,   649,   650,   271,   744,   745,    39,   224,   207,
     564,   217,    52,    69,    52,    70,   234,   210,    52,  -262,
      52,    52,   302,    52,    52,   607,    52,    52,    52,    72,
      92,   157,   158,   159,   356,   335,   336,   470,   163,    73,
     163,   337,   127,   141,    53,   141,   166,   -37,   166,   -37,
     -37,   310,   142,   955,   142,   315,   956,   287,    52,   287,
      74,   -37,    28,   296,   541,   298,   299,   303,   306,   307,
     136,   311,   312,   313,   728,   544,   283,    80,    81,   545,
      76,   546,   139,   548,   284,   203,   216,   215,   644,   351,
     140,   141,   753,    83,  -261,   140,   141,   645,   171,   754,
     142,   350,   145,   334,    86,   142,    32,    33,   172,    87,
     127,    88,   212,   755,    34,    40,    97,   173,   634,   756,
     766,   174,   140,   141,    52,    36,   635,    52,    37,   175,
     757,   758,   142,   636,    38,   648,    52,    52,   651,    32,
      33,    52,    52,   127,   177,    39,    51,    34,   216,    58,
      59,   178,   140,   141,   180,    53,    52,   553,    36,   181,
     127,    37,   633,   182,   234,   105,   185,    38,   187,   454,
     132,   234,   457,   206,   335,   336,   335,   336,    39,    77,
     344,   463,   464,    52,   215,   316,   468,   469,    97,   335,
     336,   137,   216,   599,   600,   540,   140,   141,   217,   617,
     618,   484,   222,   219,    32,    33,   -44,   308,   258,   270,
     274,   308,    34,   543,   272,    28,   316,    78,    79,   277,
     275,   278,   321,    36,   322,   323,    37,   331,   501,   333,
      80,    81,    38,   332,   687,   688,   689,   105,    82,    97,
     342,   347,   348,    39,    51,   453,    83,   475,   703,    84,
     -44,   459,   460,   476,    85,   480,   492,    86,   494,   571,
     506,   204,    87,   495,    88,   496,    89,    90,    40,   508,
     516,   539,   554,   549,   603,   605,   606,    32,    33,   604,
     611,   669,   612,   613,    97,    34,   616,    97,   105,    97,
      97,   528,   536,    97,   520,   520,    36,    97,   614,    37,
     615,    32,    33,   619,   563,    38,   623,    52,   625,    34,
     627,   628,   631,   639,   132,   641,    39,    51,   707,   127,
      36,   768,   643,    37,   660,   661,   665,   672,   671,    38,
     682,   683,   685,   105,   686,    52,   105,   701,   105,   105,
      39,    51,   105,    52,    52,   690,   105,   731,   698,   710,
      50,   596,   538,    52,   520,    64,   667,    32,    33,    68,
     711,   712,    71,   713,   580,    34,   714,    52,   715,   721,
     123,   124,   125,    50,   134,   135,    36,   724,   725,    37,
     287,    52,   732,   751,   733,    38,   752,   633,   561,   562,
      52,   637,    52,   760,   762,   765,    39,   137,   569,    52,
     774,    28,   767,   574,    79,   803,   780,   781,   108,   804,
     632,   575,   602,   133,    32,    33,   805,   806,   807,   722,
     817,   827,    34,   829,   825,   576,   608,   855,   876,   577,
     856,   859,    97,    36,   900,   620,    37,   622,   860,    97,
      85,   578,    38,   861,   626,   579,   764,   875,   908,   507,
     909,   916,   510,    39,    40,   511,   512,   922,   926,   513,
     514,   515,   127,   929,  -228,   234,  -227,   932,   204,   933,
     941,   944,    52,   943,   958,   957,   962,   959,   204,   269,
     108,   105,   652,   928,   518,   211,   519,   530,   105,   568,
     858,   954,   798,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   904,   656,   260,   261,   608,   267,   268,
     674,   727,   657,   580,   273,   127,   737,   276,   718,   936,
     918,   108,   567,   534,   658,    52,   580,   730,   212,     0,
       0,     0,   487,     0,     0,     0,   581,     0,   879,     0,
       0,     0,   127,     0,     0,     0,     0,   133,   212,   880,
       0,     0,    52,     0,   325,   326,     0,     0,    52,    97,
     330,   901,    97,    97,     0,     0,   108,     0,   104,   108,
     734,   108,   108,   131,     0,   108,     0,   580,   796,   108,
       0,     0,   828,     0,     0,   853,     0,     0,     0,     0,
      52,     0,    52,    52,    52,     0,   341,   769,     0,     0,
       0,     0,   857,   569,     0,    97,     0,     0,   105,     0,
       0,   105,   105,     0,   826,   144,     0,     0,     0,     0,
     930,    50,   583,   353,     0,     0,     0,   357,     0,     0,
     580,     0,   451,     0,     0,   622,     0,   809,   810,   811,
     205,     0,    52,     0,   127,   676,   679,   679,     0,   184,
     679,   186,   951,     0,   105,   189,   190,     0,     0,     0,
     693,     0,     0,     0,     0,   737,     0,   127,     0,   486,
       0,   584,     0,   144,     0,   580,     0,     0,   489,   632,
       0,   490,    52,     0,   493,     0,     0,   878,     0,     0,
       0,     0,     0,   693,     0,   212,     0,     0,     0,     0,
     144,     0,     0,     0,     0,     0,    97,     0,   736,     0,
       0,     0,     0,     0,   108,     0,     0,   264,     0,     0,
       0,   108,     0,    97,     0,     0,   127,   910,     0,     0,
       0,     0,     0,   580,     0,     0,     0,     0,     0,   297,
       0,   300,   305,     0,     0,   309,     0,     0,     0,   314,
       0,     0,     0,     0,     0,   655,     0,     0,   127,   212,
       0,    97,     0,     0,    97,     0,     0,     0,     0,     0,
       0,     0,   105,     0,     0,     0,    52,   813,     0,     0,
       0,   583,     0,     0,    28,     0,   329,     0,     0,    97,
      97,     0,     0,     0,   583,     0,     0,    32,    33,    80,
      81,     0,     0,     0,     0,    34,     0,   203,     0,     0,
     105,     0,    97,   105,     0,    83,    36,     0,     0,    37,
       0,   961,    97,     0,     0,    38,    86,     0,   212,     0,
     719,    87,     0,    88,     0,    89,   301,   126,   105,   105,
       0,     0,     0,   584,   551,   583,   797,   349,     0,     0,
       0,   108,     0,     0,   108,   108,     0,   736,     0,     0,
       0,   105,     0,     0,     0,     0,     0,    22,    23,     0,
       0,   105,     0,     0,     0,     0,     0,    24,     0,     0,
      25,     0,     0,     0,     0,     0,    26,     0,    27,     0,
       0,     0,    28,     0,   719,   799,     0,   108,   862,     0,
      29,    30,    31,     0,     0,    32,    33,    80,    81,   931,
       0,     0,     0,    34,   108,   130,   630,     0,     0,     0,
       0,   132,     0,    83,    36,     0,     0,    37,     0,     0,
       0,     0,     0,    38,    86,   949,     0,     0,     0,    87,
       0,    88,     0,   583,    39,    40,    41,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   653,     0,     0,
       0,   551,     0,     0,    28,     0,   662,     0,     0,   664,
       0,     0,   666,     0,   668,     0,     0,    32,    33,    80,
      81,   551,     0,     0,     0,    34,     0,   203,   132,     0,
       0,     0,   584,     0,     0,    83,    36,     0,     0,    37,
     132,   862,     0,     0,     0,    38,    86,     0,     0,     0,
       0,    87,     0,    88,     0,   108,    39,   126,     0,     0,
       0,   517,     0,   329,   526,   526,   329,     0,     0,   329,
     329,     0,     0,   329,   329,   329,     0,     0,   723,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   748,   749,
     750,     0,     0,   108,    28,     0,   108,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   565,   529,    80,
      81,     0,     0,     0,     0,     0,     0,   203,     0,     0,
       0,   108,   108,     0,   526,    83,   108,     0,     0,     0,
       0,     0,     0,    85,     0,     0,    86,     0,     0,     0,
       0,    87,     0,    88,   108,     0,     0,    40,     0,     0,
       0,     0,    28,     0,   108,    79,     0,   816,     0,   551,
       0,   819,   820,   821,     0,   823,   824,    80,    81,     0,
       0,     0,   621,     0,     0,   203,     0,     0,     0,     0,
       0,     0,     0,    83,    50,     0,     0,     0,     0,     0,
       0,    85,   144,     0,    86,   874,     0,     0,     0,    87,
       0,    88,     0,     0,   133,    40,   638,     0,   881,   882,
     883,   884,   885,   886,   887,   888,   889,   890,   891,   892,
     893,   894,   895,   896,   897,   898,   899,     0,     0,   902,
     903,     0,   905,     0,     0,     0,     0,    28,     0,     0,
       0,     0,     0,     0,   915,     0,     0,     0,   705,     0,
       0,   874,    80,    81,   921,     0,     0,     0,     0,     0,
     203,     0,     0,   305,     0,     0,   708,     0,    83,     0,
       0,   133,     0,     0,     0,   108,     0,     0,   925,    86,
       0,     0,     0,   133,    87,     0,    88,     0,    89,    90,
     706,   104,   305,     0,     0,     0,   741,   937,   938,     0,
       0,     0,   939,     0,     0,   940,    22,    23,     0,     0,
       0,   874,   947,   948,   205,     0,    24,     0,     0,    25,
     874,     0,     0,     0,   773,    26,     0,    27,     0,     0,
       0,    28,     0,     0,   874,     0,   262,     0,     0,    29,
      30,    31,     0,     0,    32,    33,    80,    81,     0,     0,
       0,     0,    34,     0,   130,     0,     0,     0,     0,     0,
       0,     0,    83,    36,     0,     0,    37,     0,     0,     0,
       0,     0,    38,    86,   822,     0,     0,     0,    87,   573,
      88,     0,   263,    39,    40,    41,    42,     0,     0,     0,
      28,     0,   574,    79,     0,     0,     0,     0,     0,     0,
     575,     0,     0,    32,    33,    80,    81,   144,     0,     0,
     854,    34,     0,   203,   576,     0,     0,     0,   577,     0,
       0,    83,    36,     0,     0,    37,     0,     0,     0,    85,
     578,    38,    86,     0,   579,     0,     0,    87,     0,    88,
       0,   264,    39,    40,     0,   741,     0,     0,     0,     0,
       0,     0,     0,   131,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,     0,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   360,     0,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   499,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   360,     0,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   547,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,    22,    23,     0,     0,     0,     0,
       0,     0,     0,     0,    24,     0,     0,    25,     0,     0,
       0,     0,     0,    26,     0,    27,     0,     0,     0,    28,
       0,     0,     0,     0,   911,     0,     0,    29,    30,    31,
       0,     0,    32,    33,    80,    81,     0,     0,   912,     0,
      34,     0,   130,     0,     0,     0,     0,     0,     0,     0,
      83,    36,     0,     0,    37,     0,     0,     0,     0,     0,
      38,    86,     0,     0,     0,     0,    87,     0,    88,    22,
      23,    39,    40,    41,    42,     0,     0,     0,     0,    24,
       0,     0,    25,   917,     0,     0,     0,     0,   866,     0,
      27,     0,     0,     0,    28,     0,     0,     0,     0,   867,
       0,     0,    29,    30,    31,     0,     0,    32,    33,     0,
       0,     0,     0,   868,     0,    34,     0,    35,     0,     0,
      22,    23,     0,     0,     0,     0,    36,     0,     0,    37,
      24,     0,     0,    25,   952,    38,     0,     0,     0,   866,
       0,    27,     0,     0,     0,    28,    39,    40,    41,    42,
     867,     0,     0,    29,    30,    31,     0,     0,    32,    33,
       0,     0,     0,     0,   868,     0,    34,     0,    35,     0,
       0,    22,    23,     0,     0,     0,     0,    36,     0,     0,
      37,    24,     0,     0,    25,     0,    38,     0,     0,     0,
     866,     0,    27,     0,     0,     0,    28,    39,    40,    41,
      42,   867,     0,     0,    29,    30,    31,     0,     0,    32,
      33,     0,     0,     0,     0,   868,     0,    34,     0,    35,
       0,     0,    22,    23,     0,     0,     0,     0,    36,     0,
       0,    37,    24,     0,     0,    25,     0,    38,     0,     0,
       0,    26,     0,    27,     0,     0,     0,    28,    39,    40,
      41,    42,   867,     0,     0,    29,    30,    31,     0,     0,
      32,    33,     0,     0,     0,     0,   868,     0,    34,     0,
      35,     0,     0,    22,    23,     0,     0,     0,     0,    36,
       0,     0,    37,    24,     0,     0,    25,     0,    38,     0,
       0,     0,    26,     0,    27,     0,     0,     0,    28,    39,
      40,    41,    42,   225,     0,     0,    29,    30,    31,     0,
       0,    32,    33,     0,     0,     0,     0,     0,     0,    34,
       0,    35,    22,    23,     0,     0,     0,     0,     0,     0,
      36,     0,    24,    37,     0,    25,     0,     0,     0,    38,
       0,    26,     0,    27,     0,     0,     0,    28,     0,   629,
      39,   126,    41,    42,     0,    29,    30,    31,     0,     0,
      32,    33,     0,     0,     0,     0,     0,     0,    34,     0,
      35,   783,   784,     0,     0,     0,     0,     0,     0,    36,
       0,   785,    37,     0,     0,   786,     0,     0,    38,     0,
     787,     0,   788,     0,     0,     0,    28,     0,     0,    39,
      40,    41,    42,     0,   789,   790,   791,     0,     0,    32,
      33,     0,     0,     0,     0,   792,     0,    34,     0,   793,
      22,    23,     0,     0,     0,     0,     0,     0,    36,     0,
      24,    37,     0,    25,   814,     0,     0,    38,     0,    26,
       0,    27,     0,     0,     0,    28,     0,     0,    39,    40,
     794,   795,     0,    29,    30,    31,     0,     0,    32,    33,
       0,     0,     0,     0,     0,     0,    34,     0,    35,    22,
      23,     0,     0,     0,     0,     0,     0,    36,     0,    24,
      37,     0,    25,     0,     0,     0,    38,     0,    26,     0,
      27,     0,     0,     0,    28,     0,     0,    39,    40,    41,
      42,     0,    29,    30,    31,     0,     0,    32,    33,     0,
       0,     0,     0,     0,     0,    34,     0,    35,    22,    23,
       0,     0,     0,     0,     0,     0,    36,     0,    24,    37,
       0,    25,     0,     0,     0,    38,     0,    26,     0,    27,
       0,     0,     0,    28,     0,     0,    39,    40,    41,    42,
       0,    29,    30,    31,     0,     0,    32,    33,     0,     0,
       0,     0,     0,     0,    34,     0,    35,     0,     0,     0,
       0,     0,     0,     0,     0,    36,     0,     0,    37,  -206,
       0,     0,     0,     0,    38,     0,     0,     0,     0,     0,
      28,     0,   574,    79,     0,    39,   126,    41,    42,     0,
     575,     0,     0,    32,    33,    80,    81,     0,     0,     0,
       0,    34,     0,   203,     0,     0,     0,     0,   577,     0,
       0,    83,    36,     0,     0,    37,     0,   907,     0,    85,
       0,    38,    86,     0,     0,     0,   735,    87,    28,    88,
     574,    79,    39,    40,     0,     0,     0,     0,   575,     0,
       0,    32,    33,    80,    81,     0,     0,     0,     0,    34,
       0,   203,     0,     0,     0,     0,   577,     0,     0,    83,
      36,     0,     0,    37,     0,     0,     0,    85,     0,    38,
      86,    28,     0,     0,     0,    87,   232,    88,     0,     0,
      39,    40,     0,     0,    32,    33,    80,    81,     0,     0,
       0,     0,    34,     0,   203,     0,     0,     0,     0,     0,
       0,     0,    83,    36,     0,     0,    37,     0,     0,     0,
      28,     0,    38,    86,     0,     0,     0,     0,    87,     0,
      88,     0,   233,    39,    40,    80,    81,     0,     0,     0,
       0,     0,     0,   203,     0,     0,     0,     0,     0,     0,
       0,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,     0,     0,     0,     0,    87,     0,    88,
       0,    89,    90,    40,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,     0,   163,     0,     0,     0,   140,   141,   164,   165,
     166,   223,     0,     0,     0,   167,   142,     0,     0,     0,
     168,     0,   934,   935,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,     0,   163,     0,     0,     0,   140,   141,   164,   165,
     166,     0,     0,     0,     0,   167,   142,     0,     0,     0,
     168,     0,   919,   920,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,     0,   163,   339,     0,     0,   140,   141,   164,   165,
     166,     0,     0,   340,     0,   167,   142,     0,     0,     0,
     168,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,     0,   163,
     699,     0,     0,   140,   141,   164,   165,   166,     0,     0,
     700,     0,   167,   142,     0,     0,     0,   168,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,     0,   163,   923,     0,     0,
     140,   141,   164,   165,   166,     0,     0,   924,     0,   167,
     142,     0,     0,     0,   168,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,     0,   163,     0,     0,     0,   140,   141,   164,
     165,   166,     0,     0,     0,   176,   167,   142,     0,     0,
       0,   168,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,     0,
     163,     0,     0,     0,   140,   141,   164,   165,   166,     0,
       0,     0,   179,   167,   142,     0,     0,     0,   168,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,     0,   163,     0,     0,
       0,   140,   141,   164,   165,   166,   223,     0,     0,     0,
     167,   142,     0,     0,     0,   168,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,     0,   163,     0,     0,     0,   140,   141,
     164,   165,   166,     0,     0,   343,     0,   167,   142,     0,
       0,     0,   168,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
       0,   163,     0,     0,     0,   140,   141,   164,   165,   166,
       0,     0,     0,   346,   167,   142,     0,     0,     0,   168,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,     0,   163,   481,
       0,     0,   140,   141,   164,   165,   166,     0,     0,     0,
       0,   167,   142,     0,     0,     0,   168,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,     0,   163,   482,     0,     0,   140,
     141,   164,   165,   166,     0,     0,     0,     0,   167,   142,
       0,     0,     0,   168,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,     0,   163,     0,     0,     0,   140,   141,   164,   165,
     166,   500,     0,     0,     0,   167,   142,     0,     0,     0,
     168,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,     0,   163,
       0,     0,     0,   140,   141,   164,   165,   166,   502,     0,
       0,     0,   167,   142,     0,     0,     0,   168,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,     0,   163,     0,     0,     0,
     140,   141,   164,   165,   166,   504,     0,     0,     0,   167,
     142,     0,     0,     0,   168,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,     0,   163,   542,     0,     0,   140,   141,   164,
     165,   166,     0,     0,     0,     0,   167,   142,     0,     0,
       0,   168,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,     0,
     163,     0,     0,     0,   140,   141,   164,   165,   166,     0,
       0,     0,     0,   167,   142,     0,   663,     0,   168,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,     0,   163,     0,     0,
       0,   140,   141,   164,   165,   166,   696,     0,     0,     0,
     167,   142,     0,     0,     0,   168,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,     0,   163,     0,     0,     0,   140,   141,
     164,   165,   166,   697,     0,     0,     0,   167,   142,     0,
       0,     0,   168,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
       0,   163,     0,     0,     0,   140,   141,   164,   165,   166,
       0,     0,     0,     0,   167,   142,     0,   702,     0,   168,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,     0,   163,   763,
       0,     0,   140,   141,   164,   165,   166,     0,     0,     0,
       0,   167,   142,     0,     0,     0,   168,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,     0,   163,     0,     0,     0,   140,
     141,   164,   165,   166,   775,     0,     0,     0,   167,   142,
       0,     0,     0,   168,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,     0,   163,     0,     0,     0,   140,   141,   164,   165,
     166,   776,     0,     0,     0,   167,   142,     0,     0,     0,
     168,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,     0,   163,
       0,     0,     0,   140,   141,   164,   165,   166,   777,     0,
       0,     0,   167,   142,     0,     0,     0,   168,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,     0,   163,     0,     0,     0,
     140,   141,   164,   165,   166,     0,     0,   865,     0,   167,
     142,     0,     0,     0,   168,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,     0,   163,     0,     0,     0,   140,   141,   164,
     165,   166,   877,     0,     0,     0,   167,   142,     0,     0,
       0,   168,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,     0,
     163,     0,     0,     0,   140,   141,   164,   165,   166,     0,
       0,   927,     0,   167,   142,     0,     0,     0,   168,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,     0,   163,   950,     0,
       0,   140,   141,   164,   165,   166,     0,     0,     0,     0,
     167,   142,     0,     0,     0,   168,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,     0,   163,     0,     0,     0,   140,   141,
     164,   165,   166,     0,     0,     0,  -225,   167,   142,     0,
       0,     0,   168,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
       0,   163,     0,     0,     0,   140,   141,   164,   165,   166,
       0,     0,     0,  -226,   167,   142,     0,     0,     0,   168,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,     0,   163,     0,
       0,     0,   140,   141,   164,   165,   166,     0,     0,     0,
       0,   167,   142,     0,     0,     0,   168,   830,   831,   832,
     833,   834,   835,   836,   837,   838,   839,   840,   841,   842,
     843,   844,   845,   846,     0,   847,     0,     0,     0,   140,
     141,   848,   849,   850,     0,     0,     0,     0,   851,   142,
       0,     0,     0,   852,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,     0,   163,     0,     0,     0,   140,   141,   164,   165,
     166,     0,     0,     0,     0,     0,   142,     0,     0,     0,
     168,   146,   147,   148,   149,     0,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,     0,   163,
       0,     0,     0,   140,   141,   164,   165,   166,     0,     0,
       0,     0,     0,   142,   146,   147,   148,   168,     0,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,     0,   163,     0,     0,     0,   140,   141,   164,   165,
     166,     0,     0,     0,     0,     0,   142,   146,   147,   148,
     168,     0,     0,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,     0,   163,     0,     0,     0,   140,
     141,   164,   165,   166,     0,   191,     0,     0,     0,   142,
     192,   193,     0,   168,     0,   194,     0,     0,   195,   196,
     197,     0,     0,     0,     0,     0,     0,     0,   198,     0,
     199,   200,     0,     0,     0,     0,   201,   148,     0,     0,
       0,   202,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,     0,   163,     0,     0,     0,     0,   141,     0,
     165,   166,     0,     0,     0,     0,     0,   142,   148,     0,
       0,   168,     0,   153,   154,   155,   156,   157,   158,   159,
       0,   161,   162,     0,   163,     0,     0,     0,     0,   141,
       0,   165,   166,     0,     0,     0,     0,     0,   142,   148,
       0,     0,   168,     0,   153,   154,   155,   156,   157,   158,
     159,     0,   161,     0,     0,   163,     0,     0,     0,     0,
     141,     0,   165,   166,     0,     0,     0,     0,     0,   142,
     148,     0,     0,   168,     0,   153,   154,   155,   156,   157,
     158,   159,     0,     0,     0,     0,   163,     0,     0,     0,
       0,   141,     0,   165,   166,     0,     0,     0,     0,     0,
     142,     0,     0,     0,   168,   153,   154,   155,   156,   157,
     158,   159,     0,     0,     0,     0,   163,     0,     0,     0,
       0,   141,     0,     0,   166,     0,     0,     0,     0,     0,
     142,     0,     0,     0,   168,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17
  };

  const short int
  P4Parser::yycheck_[] =
  {
       3,    25,   189,   103,    93,    21,   187,   195,    21,     9,
      47,   453,   623,    25,   284,   266,   709,   477,   478,   709,
     813,   866,    25,   696,    50,    59,   709,   709,   111,    50,
      50,    45,   643,   477,   478,   286,    45,    43,    68,   290,
      54,    44,   293,    73,   295,     3,   337,    56,    54,   110,
      59,    44,    44,   344,    45,    45,    50,   166,    45,    45,
      45,    95,    71,    72,    58,    45,    59,    25,    59,    59,
      79,   101,    59,    59,    59,    51,    79,   537,    87,    59,
     111,    73,    85,    59,    69,   111,    95,   760,   933,    98,
     111,   111,    45,   537,   103,   132,   105,   539,   107,   108,
     109,    54,    95,    88,    95,    95,   215,   110,    95,    95,
      95,   956,    45,    45,    44,    95,    72,     0,   388,    95,
      59,    79,    54,   916,   213,    56,    59,    85,    85,    86,
      69,    51,   110,   136,    54,    92,   139,    44,    69,    70,
      78,   144,    98,    73,    82,    83,    77,    73,    43,    88,
      57,    58,   110,    46,    47,   111,    95,    88,    45,    54,
      91,    99,    95,   166,   606,   858,    97,    54,   858,   172,
     781,    97,   614,   615,   174,   858,   858,   108,   136,    50,
     106,    42,   185,   111,   187,   110,   189,    58,   191,    50,
     193,   194,   195,   196,   197,    45,   199,   200,   201,   111,
      21,    35,    36,    37,    54,    48,    49,   316,    42,   110,
      42,    54,   215,    47,   172,    47,    50,    44,    50,    46,
      47,   198,    56,    51,    56,   202,    54,   185,   231,   187,
     110,    58,    56,   191,   485,   193,   194,   195,   196,   197,
      56,   199,   200,   201,   704,   496,    42,    71,    72,   500,
      21,   502,    50,   504,    50,    79,    42,    50,    45,   283,
      46,    47,    70,    87,    50,    46,    47,    54,    57,    77,
      56,   283,    54,   231,    98,    56,    69,    70,    54,   103,
     283,   105,   103,    91,    77,   109,    21,    54,    42,    97,
     732,    54,    46,    47,   297,    88,    50,   300,    91,    54,
     108,   109,    56,    57,    97,   613,   309,   310,   616,    69,
      70,   314,   315,   316,    54,   108,   109,    77,    42,   110,
     111,    54,    46,    47,    54,   283,   329,   508,    88,    54,
     333,    91,    56,    54,   337,    21,    44,    97,    44,   297,
      26,   344,   300,    58,    48,    49,    48,    49,   108,    20,
      54,   309,   310,   356,    50,    50,   314,   315,    93,    48,
      49,   109,    42,    57,    58,    54,    46,    47,    42,    57,
      58,   329,    51,    58,    69,    70,    57,   198,    48,   111,
     111,   202,    77,   492,   110,    56,    50,    58,    59,   111,
     110,   110,    44,    88,    44,    44,    91,    57,   356,    54,
      71,    72,    97,    51,   655,   656,   657,    93,    79,   144,
      51,    54,    54,   108,   109,    50,    87,    51,   669,    90,
      58,    58,    58,    54,    95,    51,    50,    98,   111,   529,
      57,   520,   103,   110,   105,   111,   107,   108,   109,    44,
      51,    50,    44,    51,    51,    58,    50,    69,    70,   549,
      44,   638,    44,    44,   189,    77,    44,   192,   144,   194,
     195,   477,   478,   198,   477,   478,    88,   202,    50,    91,
      50,    69,    70,    57,    97,    97,    57,   480,    45,    77,
      58,    50,    50,    44,   170,    51,   108,   109,   676,   492,
      88,    89,    57,    91,    58,    44,    70,    51,    58,    97,
      51,    51,    58,   189,    44,   508,   192,    51,   194,   195,
     108,   109,   198,   516,   517,    58,   202,   705,    50,    50,
       2,   537,   480,   526,   537,     7,   635,    69,    70,    11,
      50,    50,    14,    57,   537,    77,    57,   540,    73,    44,
      22,    23,    24,    25,    26,    27,    88,    58,    50,    91,
     508,   554,    50,    44,    58,    97,    44,    56,   516,   517,
     563,   598,   565,    76,    51,    58,   108,   109,   526,   572,
      45,    56,    58,    58,    59,    58,    57,    57,    21,    51,
     583,    66,   540,    26,    69,    70,    51,    50,    58,   698,
      44,    50,    77,    53,    56,    80,   554,    58,    51,    84,
      58,    58,   337,    88,    48,   563,    91,   565,    58,   344,
      95,    96,    97,    58,   572,   100,   725,    58,    58,   455,
      50,    53,   458,   108,   109,   461,   462,    51,    51,   465,
     466,   467,   635,    44,    54,   638,    54,    51,   727,    54,
      50,    58,   645,    51,    51,    58,    58,    53,   737,   172,
      93,   337,   617,   904,   476,   101,   477,   478,   344,   523,
     808,   942,   761,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   854,   621,   167,   168,   645,   170,   171,
     645,   704,   621,   696,   176,   698,   709,   179,   694,   916,
     873,   144,   523,   478,   622,   708,   709,   704,   529,    -1,
      -1,    -1,   333,    -1,    -1,    -1,   537,    -1,   827,    -1,
      -1,    -1,   725,    -1,    -1,    -1,    -1,   170,   549,   829,
      -1,    -1,   735,    -1,   216,   217,    -1,    -1,   741,   474,
     222,   850,   477,   478,    -1,    -1,   189,    -1,    21,   192,
     708,   194,   195,    26,    -1,   198,    -1,   760,   761,   202,
      -1,    -1,   799,    -1,    -1,   802,    -1,    -1,    -1,    -1,
     773,    -1,   775,   776,   777,    -1,   258,   735,    -1,    -1,
      -1,    -1,   806,   741,    -1,   520,    -1,    -1,   474,    -1,
      -1,   477,   478,    -1,   797,    47,    -1,    -1,    -1,    -1,
     909,   283,   537,   285,    -1,    -1,    -1,   289,    -1,    -1,
     813,    -1,   294,    -1,    -1,   773,    -1,   775,   776,   777,
      93,    -1,   825,    -1,   827,   646,   647,   648,    -1,    81,
     651,    83,   941,    -1,   520,    87,    88,    -1,    -1,    -1,
     661,    -1,    -1,    -1,    -1,   858,    -1,   850,    -1,   331,
      -1,   537,    -1,   105,    -1,   858,    -1,    -1,   340,   862,
      -1,   343,   865,    -1,   346,    -1,    -1,   825,    -1,    -1,
      -1,    -1,    -1,   694,    -1,   696,    -1,    -1,    -1,    -1,
     132,    -1,    -1,    -1,    -1,    -1,   621,    -1,   709,    -1,
      -1,    -1,    -1,    -1,   337,    -1,    -1,   170,    -1,    -1,
      -1,   344,    -1,   638,    -1,    -1,   909,   865,    -1,    -1,
      -1,    -1,    -1,   916,    -1,    -1,    -1,    -1,    -1,   192,
      -1,   194,   195,    -1,    -1,   198,    -1,    -1,    -1,   202,
      -1,    -1,    -1,    -1,    -1,   621,    -1,    -1,   941,   760,
      -1,   676,    -1,    -1,   679,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   638,    -1,    -1,    -1,   959,   778,    -1,    -1,
      -1,   696,    -1,    -1,    56,    -1,   218,    -1,    -1,   704,
     705,    -1,    -1,    -1,   709,    -1,    -1,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    77,    -1,    79,    -1,    -1,
     676,    -1,   727,   679,    -1,    87,    88,    -1,    -1,    91,
      -1,   959,   737,    -1,    -1,    97,    98,    -1,   829,    -1,
     696,   103,    -1,   105,    -1,   107,   108,   109,   704,   705,
      -1,    -1,    -1,   709,   506,   760,   761,   279,    -1,    -1,
      -1,   474,    -1,    -1,   477,   478,    -1,   858,    -1,    -1,
      -1,   727,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,   737,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    50,    -1,    52,    -1,
      -1,    -1,    56,    -1,   760,   761,    -1,   520,   813,    -1,
      64,    65,    66,    -1,    -1,    69,    70,    71,    72,   910,
      -1,    -1,    -1,    77,   537,    79,   578,    -1,    -1,    -1,
      -1,   787,    -1,    87,    88,    -1,    -1,    91,    -1,    -1,
      -1,    -1,    -1,    97,    98,   936,    -1,    -1,    -1,   103,
      -1,   105,    -1,   858,   108,   109,   110,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   619,    -1,    -1,
      -1,   623,    -1,    -1,    56,    -1,   628,    -1,    -1,   631,
      -1,    -1,   634,    -1,   636,    -1,    -1,    69,    70,    71,
      72,   643,    -1,    -1,    -1,    77,    -1,    79,   854,    -1,
      -1,    -1,   858,    -1,    -1,    87,    88,    -1,    -1,    91,
     866,   916,    -1,    -1,    -1,    97,    98,    -1,    -1,    -1,
      -1,   103,    -1,   105,    -1,   638,   108,   109,    -1,    -1,
      -1,   474,    -1,   455,   477,   478,   458,    -1,    -1,   461,
     462,    -1,    -1,   465,   466,   467,    -1,    -1,   700,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   710,   711,
     712,    -1,    -1,   676,    56,    -1,   679,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   520,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,
      -1,   704,   705,    -1,   537,    87,   709,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    -1,    -1,    98,    -1,    -1,    -1,
      -1,   103,    -1,   105,   727,    -1,    -1,   109,    -1,    -1,
      -1,    -1,    56,    -1,   737,    59,    -1,   779,    -1,   781,
      -1,   783,   784,   785,    -1,   787,   788,    71,    72,    -1,
      -1,    -1,   564,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,   806,    -1,    -1,    -1,    -1,    -1,
      -1,    95,   584,    -1,    98,   817,    -1,    -1,    -1,   103,
      -1,   105,    -1,    -1,   787,   109,   598,    -1,   830,   831,
     832,   833,   834,   835,   836,   837,   838,   839,   840,   841,
     842,   843,   844,   845,   846,   847,   848,    -1,    -1,   851,
     852,    -1,   854,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,   866,    -1,    -1,    -1,    67,    -1,
      -1,   873,    71,    72,   876,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    -1,   676,    -1,    -1,   679,    -1,    87,    -1,
      -1,   854,    -1,    -1,    -1,   858,    -1,    -1,   900,    98,
      -1,    -1,    -1,   866,   103,    -1,   105,    -1,   107,   108,
     109,   704,   705,    -1,    -1,    -1,   709,   919,   920,    -1,
      -1,    -1,   924,    -1,    -1,   927,    31,    32,    -1,    -1,
      -1,   933,   934,   935,   727,    -1,    41,    -1,    -1,    44,
     942,    -1,    -1,    -1,   737,    50,    -1,    52,    -1,    -1,
      -1,    56,    -1,    -1,   956,    -1,    61,    -1,    -1,    64,
      65,    66,    -1,    -1,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    77,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    -1,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    97,    98,   787,    -1,    -1,    -1,   103,    45,
     105,    -1,   107,   108,   109,   110,   111,    -1,    -1,    -1,
      56,    -1,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    69,    70,    71,    72,   799,    -1,    -1,
     802,    77,    -1,    79,    80,    -1,    -1,    -1,    84,    -1,
      -1,    87,    88,    -1,    -1,    91,    -1,    -1,    -1,    95,
      96,    97,    98,    -1,   100,    -1,    -1,   103,    -1,   105,
      -1,   854,   108,   109,    -1,   858,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   866,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    22,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    22,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    52,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    64,    65,    66,
      -1,    -1,    69,    70,    71,    72,    -1,    -1,    75,    -1,
      77,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      97,    98,    -1,    -1,    -1,    -1,   103,    -1,   105,    31,
      32,   108,   109,   110,   111,    -1,    -1,    -1,    -1,    41,
      -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,    -1,
      52,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    64,    65,    66,    -1,    -1,    69,    70,    -1,
      -1,    -1,    -1,    75,    -1,    77,    -1,    79,    -1,    -1,
      31,    32,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,
      41,    -1,    -1,    44,    45,    97,    -1,    -1,    -1,    50,
      -1,    52,    -1,    -1,    -1,    56,   108,   109,   110,   111,
      61,    -1,    -1,    64,    65,    66,    -1,    -1,    69,    70,
      -1,    -1,    -1,    -1,    75,    -1,    77,    -1,    79,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    88,    -1,    -1,
      91,    41,    -1,    -1,    44,    -1,    97,    -1,    -1,    -1,
      50,    -1,    52,    -1,    -1,    -1,    56,   108,   109,   110,
     111,    61,    -1,    -1,    64,    65,    66,    -1,    -1,    69,
      70,    -1,    -1,    -1,    -1,    75,    -1,    77,    -1,    79,
      -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    88,    -1,
      -1,    91,    41,    -1,    -1,    44,    -1,    97,    -1,    -1,
      -1,    50,    -1,    52,    -1,    -1,    -1,    56,   108,   109,
     110,   111,    61,    -1,    -1,    64,    65,    66,    -1,    -1,
      69,    70,    -1,    -1,    -1,    -1,    75,    -1,    77,    -1,
      79,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    91,    41,    -1,    -1,    44,    -1,    97,    -1,
      -1,    -1,    50,    -1,    52,    -1,    -1,    -1,    56,   108,
     109,   110,   111,    61,    -1,    -1,    64,    65,    66,    -1,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      -1,    79,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    41,    91,    -1,    44,    -1,    -1,    -1,    97,
      -1,    50,    -1,    52,    -1,    -1,    -1,    56,    -1,    58,
     108,   109,   110,   111,    -1,    64,    65,    66,    -1,    -1,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,
      79,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    41,    91,    -1,    -1,    45,    -1,    -1,    97,    -1,
      50,    -1,    52,    -1,    -1,    -1,    56,    -1,    -1,   108,
     109,   110,   111,    -1,    64,    65,    66,    -1,    -1,    69,
      70,    -1,    -1,    -1,    -1,    75,    -1,    77,    -1,    79,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,
      41,    91,    -1,    44,    45,    -1,    -1,    97,    -1,    50,
      -1,    52,    -1,    -1,    -1,    56,    -1,    -1,   108,   109,
     110,   111,    -1,    64,    65,    66,    -1,    -1,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    79,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    41,
      91,    -1,    44,    -1,    -1,    -1,    97,    -1,    50,    -1,
      52,    -1,    -1,    -1,    56,    -1,    -1,   108,   109,   110,
     111,    -1,    64,    65,    66,    -1,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    -1,    79,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    41,    91,
      -1,    44,    -1,    -1,    -1,    97,    -1,    50,    -1,    52,
      -1,    -1,    -1,    56,    -1,    -1,   108,   109,   110,   111,
      -1,    64,    65,    66,    -1,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    45,
      -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    58,    59,    -1,   108,   109,   110,   111,    -1,
      66,    -1,    -1,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    77,    -1,    79,    -1,    -1,    -1,    -1,    84,    -1,
      -1,    87,    88,    -1,    -1,    91,    -1,    45,    -1,    95,
      -1,    97,    98,    -1,    -1,    -1,   102,   103,    56,   105,
      58,    59,   108,   109,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    77,
      -1,    79,    -1,    -1,    -1,    -1,    84,    -1,    -1,    87,
      88,    -1,    -1,    91,    -1,    -1,    -1,    95,    -1,    97,
      98,    56,    -1,    -1,    -1,   103,    61,   105,    -1,    -1,
     108,   109,    -1,    -1,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    77,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    -1,    -1,    91,    -1,    -1,    -1,
      56,    -1,    97,    98,    -1,    -1,    -1,    -1,   103,    -1,
     105,    -1,   107,   108,   109,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,   103,    -1,   105,
      -1,   107,   108,   109,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    -1,    -1,    -1,    55,    56,    -1,    -1,    -1,
      60,    -1,    62,    63,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    55,    56,    -1,    -1,    -1,
      60,    -1,    62,    63,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    43,    -1,    -1,    46,    47,    48,    49,
      50,    -1,    -1,    53,    -1,    55,    56,    -1,    -1,    -1,
      60,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      43,    -1,    -1,    46,    47,    48,    49,    50,    -1,    -1,
      53,    -1,    55,    56,    -1,    -1,    -1,    60,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    43,    -1,    -1,
      46,    47,    48,    49,    50,    -1,    -1,    53,    -1,    55,
      56,    -1,    -1,    -1,    60,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    54,    55,    56,    -1,    -1,
      -1,    60,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    54,    55,    56,    -1,    -1,    -1,    60,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    -1,    -1,    -1,
      55,    56,    -1,    -1,    -1,    60,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    -1,    -1,    53,    -1,    55,    56,    -1,
      -1,    -1,    60,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      -1,    -1,    -1,    54,    55,    56,    -1,    -1,    -1,    60,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    43,
      -1,    -1,    46,    47,    48,    49,    50,    -1,    -1,    -1,
      -1,    55,    56,    -1,    -1,    -1,    60,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    -1,    -1,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    -1,    55,    56,
      -1,    -1,    -1,    60,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    -1,    -1,    -1,    55,    56,    -1,    -1,    -1,
      60,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    -1,
      -1,    -1,    55,    56,    -1,    -1,    -1,    60,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    -1,    -1,    -1,    55,
      56,    -1,    -1,    -1,    60,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    43,    -1,    -1,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    -1,    55,    56,    -1,    -1,
      -1,    60,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    -1,    55,    56,    -1,    58,    -1,    60,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    -1,    -1,    -1,
      55,    56,    -1,    -1,    -1,    60,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    -1,    -1,    -1,    55,    56,    -1,
      -1,    -1,    60,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      -1,    -1,    -1,    -1,    55,    56,    -1,    58,    -1,    60,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    43,
      -1,    -1,    46,    47,    48,    49,    50,    -1,    -1,    -1,
      -1,    55,    56,    -1,    -1,    -1,    60,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    51,    -1,    -1,    -1,    55,    56,
      -1,    -1,    -1,    60,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    -1,    -1,    -1,    55,    56,    -1,    -1,    -1,
      60,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    -1,
      -1,    -1,    55,    56,    -1,    -1,    -1,    60,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    -1,    -1,    53,    -1,    55,
      56,    -1,    -1,    -1,    60,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    -1,    -1,    -1,    55,    56,    -1,    -1,
      -1,    60,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,
      -1,    53,    -1,    55,    56,    -1,    -1,    -1,    60,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    42,    43,    -1,
      -1,    46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,
      55,    56,    -1,    -1,    -1,    60,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    54,    55,    56,    -1,
      -1,    -1,    60,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      -1,    -1,    -1,    54,    55,    56,    -1,    -1,    -1,    60,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    42,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    -1,    -1,    -1,
      -1,    55,    56,    -1,    -1,    -1,    60,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    -1,    55,    56,
      -1,    -1,    -1,    60,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,
      60,    24,    25,    26,    27,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    -1,    -1,    56,    24,    25,    26,    60,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    56,    24,    25,    26,
      60,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    -1,    68,    -1,    -1,    -1,    56,
      73,    74,    -1,    60,    -1,    78,    -1,    -1,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    -1,    -1,    -1,    -1,    99,    26,    -1,    -1,
      -1,   104,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,
      49,    50,    -1,    -1,    -1,    -1,    -1,    56,    26,    -1,
      -1,    60,    -1,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,    47,
      -1,    49,    50,    -1,    -1,    -1,    -1,    -1,    56,    26,
      -1,    -1,    60,    -1,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      47,    -1,    49,    50,    -1,    -1,    -1,    -1,    -1,    56,
      26,    -1,    -1,    60,    -1,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    47,    -1,    49,    50,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    -1,    60,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    -1,    60,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19
  };

  const unsigned short int
  P4Parser::yystos_[] =
  {
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,   115,   116,
     118,   119,    31,    32,    41,    44,    50,    52,    56,    64,
      65,    66,    69,    70,    77,    79,    88,    91,    97,   108,
     109,   110,   111,   121,   145,   185,   186,   187,   190,   255,
     260,   109,   121,   122,   130,   131,   111,   263,   110,   111,
     262,   264,   110,   265,   260,   111,   262,   110,   260,   111,
     110,   260,   111,   110,   110,     0,    21,    20,    58,    59,
      71,    72,    79,    87,    90,    95,    98,   103,   105,   107,
     108,   120,   125,   126,   127,   136,   139,   145,   146,   149,
     170,   171,   177,   181,   184,   187,   188,   189,   190,   191,
     192,   200,   201,   202,   205,   208,   213,   218,   219,   221,
     246,   248,   251,   260,   260,   260,   109,   121,   130,   255,
      79,   184,   187,   190,   260,   260,    56,   109,   121,    50,
      46,    47,    56,   257,   266,    54,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    42,    48,    49,    50,    55,    60,   257,
     266,    57,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,   122,   266,    44,   266,    44,   122,   266,
     266,    68,    73,    74,    78,    81,    82,    83,    91,    93,
      94,    99,   104,    79,   127,   184,    58,    50,    58,   144,
      58,   144,   125,   126,   229,    50,    42,    42,   122,    58,
      45,    45,    51,    51,   122,    61,   122,   252,   253,   254,
     260,   258,    61,   107,   121,   184,   196,   197,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,    48,   252,
     260,   260,    61,   107,   184,   198,   199,   260,   260,   131,
     111,   262,   110,   260,   111,   110,   260,   111,   110,    72,
      98,   111,   117,    42,    50,    50,   111,   122,   220,    50,
     111,   220,   128,   197,    50,   111,   122,   184,   122,   122,
     184,   108,   121,   122,   181,   184,   122,   122,   125,   184,
     201,   122,   122,   122,   184,   201,    50,   125,   132,   133,
     134,    44,    44,    44,   252,   260,   260,   193,   194,   266,
     260,    57,    51,    54,   122,    48,    49,    54,   267,    43,
      53,   260,    51,    53,    54,   267,    54,    54,    54,   266,
     130,   255,   128,   260,   267,    45,    54,   260,   267,    45,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   129,
     267,   260,   267,    50,   122,   172,   214,   122,   178,    58,
      58,   203,   209,   122,   122,   137,   150,   206,   122,   122,
     252,    85,    86,    92,   135,    51,    54,   147,   174,   230,
      51,    43,    43,   182,   122,   195,   260,   254,   196,   260,
     260,   196,    50,   260,   111,   110,   111,    43,    43,    51,
      51,   122,    51,   128,    51,   132,    57,   193,    44,   215,
     193,   193,   193,   193,   193,   193,    51,   184,   134,   125,
     126,   139,   148,   152,   153,   169,   184,   247,   248,    70,
     125,   139,   175,   237,   246,   247,   248,   231,   122,    50,
      54,   267,    43,   252,   267,   267,   267,    51,   267,    51,
     250,   260,   173,   220,    44,   179,   204,   210,   138,   151,
     207,   122,   122,    97,   106,   184,    45,   125,   153,   122,
     176,   229,   101,    45,    58,    66,    80,    84,    96,   100,
     121,   125,   139,   145,   187,   222,   223,   224,   225,   226,
     227,   228,   229,   232,   236,   247,   248,   256,   259,    57,
      58,   132,   122,    51,   229,    58,    50,    45,   122,   216,
     217,    44,    44,    44,    50,    50,    44,    57,    58,    57,
     122,   266,   122,    57,   249,    45,   122,    58,    50,    58,
     260,    50,   121,    56,    42,    50,    57,   257,   266,    44,
     140,    51,   132,    57,    45,    54,   180,   211,   211,   132,
     132,   211,   140,   260,   154,   187,   188,   191,   249,   250,
      58,    44,   260,    58,   260,    70,   260,   252,   260,   197,
     141,    58,    51,   250,   217,    45,   125,   183,    45,   125,
     212,    45,    51,    51,    45,    58,    44,   267,   267,   267,
      58,    69,    88,   125,   238,   239,    51,    51,    50,    43,
      53,    51,    58,   267,   142,    67,   109,   181,   184,   155,
      50,    50,    50,    57,    57,    73,   124,    45,   239,   187,
     228,    44,   252,   260,    58,    50,    45,   126,   139,   143,
     251,   181,    50,    58,   122,   102,   125,   126,   156,   157,
     159,   184,   222,   223,   226,   227,   247,   248,   260,   260,
     260,    44,    44,    70,    77,    91,    97,   108,   109,   123,
      76,   233,    51,    43,   252,    58,   132,    58,    89,   122,
     160,   161,    44,   184,    45,    51,    51,    51,   242,   240,
      57,    57,   228,    31,    32,    41,    45,    50,    52,    64,
      65,    66,    75,    79,   110,   111,   121,   145,   185,   187,
     234,   235,   261,    58,    51,    51,    50,    58,   158,   122,
     122,   122,    45,   125,    45,   241,   260,    44,   250,   260,
     260,   260,   184,   260,   260,    56,   121,    50,   257,    53,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    42,    48,    49,
      50,    55,    60,   257,   266,    58,    58,   255,   155,    58,
      58,    58,   145,   243,   256,    53,    50,    61,    75,   164,
     165,   168,   244,   245,   260,    58,    51,    51,   122,   252,
     229,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
      48,   252,   260,   260,   199,   260,    51,    45,    58,    50,
     122,    61,    75,   167,   168,   260,    53,    45,   244,    62,
      63,   260,    51,    43,    53,   260,    51,    53,   267,    44,
     252,   125,    51,    54,    62,    63,   243,   260,   260,   260,
     260,    50,   162,    51,    58,   166,   168,   260,   260,   125,
      43,   252,    45,   163,   164,    51,    54,    58,    51,    53,
     168,   122,    58
  };

  const unsigned short int
  P4Parser::yyr1_[] =
  {
       0,   114,   115,   115,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     117,   117,   117,   118,   119,   119,   119,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   121,   121,   121,
     121,   121,   121,   121,   122,   122,   123,   123,   123,   123,
     123,   124,   124,   125,   125,   126,   126,   127,   127,   127,
     127,   127,   128,   128,   128,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   130,   130,   131,   132,   132,   133,   133,   134,
     134,   135,   135,   135,   135,   137,   138,   136,   139,   139,
     139,   139,   141,   140,   142,   142,   143,   143,   144,   144,
     145,   146,   147,   147,   148,   148,   148,   148,   150,   151,
     149,   152,   152,   154,   153,   155,   155,   156,   156,   156,
     156,   156,   156,   156,   158,   157,   159,   159,   160,   160,
     161,   162,   162,   163,   164,   164,   165,   165,   166,   166,
     167,   167,   167,   167,   168,   168,   168,   168,   168,   169,
     169,   169,   170,   172,   173,   171,   174,   174,   175,   175,
     175,   175,   175,   176,   178,   179,   177,   177,   177,   180,
     180,   182,   181,   183,   183,   183,   184,   184,   184,   184,
     184,   185,   185,   186,   186,   187,   188,   189,   189,   190,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   192,   192,   192,   193,   193,   194,   195,   195,   196,
     196,   196,   196,   197,   197,   197,   198,   198,   198,   199,
     199,   200,   200,   200,   200,   200,   201,   201,   201,   201,
     203,   204,   202,   206,   207,   205,   209,   210,   208,   211,
     211,   212,   214,   213,   215,   213,   216,   216,   217,   218,
     219,   220,   220,   221,   221,   221,   221,   222,   222,   222,
     223,   224,   225,   225,   226,   226,   227,   228,   228,   228,
     228,   228,   228,   228,   228,   230,   229,   231,   231,   232,
     233,   233,   234,   234,   235,   235,   236,   236,   236,   236,
     237,   238,   238,   239,   239,   239,   239,   240,   240,   241,
     242,   242,   243,   243,   244,   245,   245,   246,   247,   247,
     248,   249,   249,   250,   251,   252,   252,   253,   253,   254,
     254,   254,   255,   255,   255,   256,   256,   258,   257,   259,
     259,   259,   259,   259,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   262,   262,   263,   263,   264,   264,   265,   265,
     266,   266,   267,   267
  };

  const unsigned char
  P4Parser::yyr2_[] =
  {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     4,     4,     4,     6,     6,     6,     4,
       1,     4,     1,     2,     0,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     0,     1,     1,     2,     2,     5,     5,
       5,     4,     0,     4,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     0,     1,     1,     3,     4,
       6,     1,     1,     1,     0,     0,     0,     9,     7,     6,
       9,     8,     0,     4,     0,     2,     1,     1,     0,     3,
       1,     6,     0,     2,     1,     1,     1,     1,     0,     0,
       9,     1,     2,     0,     8,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     0,     5,     0,     2,     2,     1,
       7,     0,     2,     4,     1,     1,     5,     3,     1,     3,
       3,     3,     1,     1,     1,     3,     3,     1,     1,    10,
      10,    10,     7,     0,     0,     9,     0,     2,     1,     1,
       1,     1,     1,     1,     0,     0,     9,     4,     4,     0,
       2,     0,     7,     3,     4,     6,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     4,     4,     4,     4,
       1,     1,     1,     1,     1,     4,     4,     4,     6,     6,
       6,     1,     1,     1,     0,     1,     3,     1,     3,     1,
       1,     1,     1,     0,     1,     3,     1,     1,     1,     1,
       3,     1,     2,     2,     2,     2,     1,     1,     1,     1,
       0,     0,     9,     0,     0,     9,     0,     0,     9,     0,
       2,     4,     0,     7,     0,     8,     1,     3,     3,     4,
       4,     1,     3,     4,     4,     4,     4,     5,     8,     4,
       1,     2,     2,     3,     5,     7,     7,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     5,     0,     2,     7,
       0,     2,     3,     2,     1,     1,     1,     1,     1,     1,
       6,     1,     2,     5,     5,     7,     6,     0,     2,     5,
       0,     4,     1,     4,     5,     1,     2,     7,     5,     4,
       7,     0,     2,     1,     2,     0,     1,     1,     3,     1,
       3,     1,     0,     1,     3,     1,     2,     0,     3,     1,
       1,     2,     4,     6,     1,     1,     1,     1,     1,     1,
       2,     4,     6,     3,     3,     3,     2,     2,     2,     2,
       2,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     5,     7,     4,     4,     4,     1,
       1,     1,     1,     1,     1,     2,     4,     6,     3,     2,
       2,     2,     2,     2,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     5,     7,     4,
       4,     4,     1,     1,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const P4Parser::yytname_[] =
  {
  "$end", "error", "$undefined", "START_PROGRAM", "START_EXPRESSION_LIST",
  "START_KV_LIST", "START_INTEGER_LIST",
  "START_INTEGER_OR_STRING_LITERAL_LIST", "START_STRING_LITERAL_LIST",
  "START_EXPRESSION", "START_INTEGER", "START_INTEGER_OR_STRING_LITERAL",
  "START_STRING_LITERAL", "START_EXPRESSION_PAIR", "START_INTEGER_PAIR",
  "START_STRING_LITERAL_PAIR", "START_EXPRESSION_TRIPLE",
  "START_INTEGER_TRIPLE", "START_STRING_LITERAL_TRIPLE",
  "START_P4RT_TRANSLATION_ANNOTATION", "END", "END_ANNOTATION",
  "UNEXPECTED_TOKEN", "END_PRAGMA", "\"<=\"", "\">=\"", "\"<<\"", "\"&&\"",
  "\"||\"", "\"!=\"", "\"==\"", "\"+\"", "\"-\"", "\"|+|\"", "\"|-|\"",
  "\"*\"", "\"/\"", "\"%\"", "\"|\"", "\"&\"", "\"^\"", "\"~\"", "\"[\"",
  "\"]\"", "\"{\"", "\"}\"", "\"<\"", "L_ANGLE_ARGS", "\">\"",
  "R_ANGLE_SHIFT", "\"(\"", "\")\"", "\"!\"", "\":\"", "\",\"", "\"?\"",
  "\".\"", "\"=\"", "\";\"", "\"@\"", "\"++\"", "\"_\"", "\"&&&\"",
  "\"..\"", "TRUE", "FALSE", "THIS", "ABSTRACT", "ACTION", "ACTIONS",
  "APPLY", "BOOL", "BIT", "CONST", "CONTROL", "DEFAULT", "ELSE", "ENTRIES",
  "ENUM", "ERROR", "EXIT", "EXTERN", "HEADER", "HEADER_UNION", "IF", "IN",
  "INOUT", "INT", "KEY", "SELECT", "MATCH_KIND", "TYPE", "OUT", "PACKAGE",
  "PARSER", "PRAGMA", "RETURN", "STATE", "STRING", "STRUCT", "SWITCH",
  "TABLE", "TRANSITION", "TUPLE", "TYPEDEF", "VARBIT", "VALUESET", "VOID",
  "IDENTIFIER", "TYPE_IDENTIFIER", "STRING_LITERAL", "INTEGER", "PREFIX",
  "THEN", "$accept", "start", "fragment", "p4rtControllerType", "program",
  "input", "declaration", "nonTypeName", "name", "nonTableKwName",
  "optCONST", "optAnnotations", "annotations", "annotation",
  "annotationBody", "annotationToken", "kvList", "kvPair", "parameterList",
  "nonEmptyParameterList", "parameter", "direction",
  "packageTypeDeclaration", "$@1", "$@2", "instantiation",
  "objInitializer", "$@3", "objDeclarations", "objDeclaration",
  "optConstructorParameters", "dotPrefix", "parserDeclaration",
  "parserLocalElements", "parserLocalElement", "parserTypeDeclaration",
  "$@4", "$@5", "parserStates", "parserState", "$@6", "parserStatements",
  "parserStatement", "parserBlockStatement", "$@7", "transitionStatement",
  "stateExpression", "selectExpression", "selectCaseList", "selectCase",
  "keysetExpression", "tupleKeysetExpression", "simpleExpressionList",
  "reducedSimpleKeysetExpression", "simpleKeysetExpression",
  "valueSetDeclaration", "controlDeclaration", "controlTypeDeclaration",
  "$@8", "$@9", "controlLocalDeclarations", "controlLocalDeclaration",
  "controlBody", "externDeclaration", "$@10", "$@11", "methodPrototypes",
  "functionPrototype", "$@12", "methodPrototype", "typeRef", "namedType",
  "prefixedType", "typeName", "tupleType", "headerStackType",
  "specializedType", "baseType", "typeOrVoid", "optTypeParameters",
  "typeParameters", "typeParameterList", "typeArg", "typeArgumentList",
  "realTypeArg", "realTypeArgumentList", "typeDeclaration",
  "derivedTypeDeclaration", "headerTypeDeclaration", "$@13", "$@14",
  "structTypeDeclaration", "$@15", "$@16", "headerUnionDeclaration",
  "$@17", "$@18", "structFieldList", "structField", "enumDeclaration",
  "$@19", "$@20", "specifiedIdentifierList", "specifiedIdentifier",
  "errorDeclaration", "matchKindDeclaration", "identifierList",
  "typedefDeclaration", "assignmentOrMethodCallStatement",
  "emptyStatement", "exitStatement", "returnStatement",
  "conditionalStatement", "directApplication", "statement",
  "blockStatement", "$@21", "statOrDeclList", "switchStatement",
  "switchCases", "switchCase", "switchLabel", "statementOrDeclaration",
  "tableDeclaration", "tablePropertyList", "tableProperty",
  "keyElementList", "keyElement", "actionList", "actionRef", "entry",
  "entriesList", "actionDeclaration", "variableDeclaration",
  "constantDeclaration", "optInitializer", "initializer",
  "functionDeclaration", "argumentList", "nonEmptyArgList", "argument",
  "expressionList", "prefixedNonTypeName", "dot_name", "$@22", "lvalue",
  "expression", "nonBraceExpression", "intOrStr", "intList",
  "intOrStrList", "strList", "l_angle", "r_angle", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  P4Parser::yyrline_[] =
  {
       0,   348,   348,   349,   354,   355,   356,   357,   358,   361,
     362,   363,   364,   367,   372,   377,   384,   390,   396,   405,
     417,   419,   422,   426,   429,   430,   431,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   448,   449,   450,
     451,   452,   453,   454,   458,   459,   463,   464,   465,   466,
     467,   471,   472,   476,   477,   481,   485,   492,   497,   499,
     501,   505,   510,   511,   516,   522,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   569,   570,   571,   572,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   585,   586,   587,   588,   589,
     590,   591,   593,   594,   595,   596,   603,   604,   605,   606,
     607,   608,   609,   610,   612,   613,   614,   615,   616,   617,
     618,   619,   623,   624,   628,   632,   633,   637,   639,   643,
     644,   648,   649,   650,   651,   655,   656,   655,   666,   670,
     674,   679,   686,   686,   692,   693,   697,   698,   702,   703,
     707,   713,   722,   723,   727,   728,   729,   730,   735,   736,
     734,   744,   746,   750,   750,   757,   758,   762,   763,   764,
     765,   766,   767,   768,   772,   772,   777,   778,   782,   783,
     787,   793,   794,   798,   804,   805,   809,   811,   815,   816,
     821,   822,   823,   824,   828,   829,   830,   831,   832,   836,
     839,   842,   850,   859,   860,   858,   868,   869,   873,   874,
     875,   876,   877,   881,   888,   889,   887,   893,   897,   905,
     906,   911,   910,   923,   926,   930,   939,   940,   941,   942,
     943,   947,   948,   952,   953,   958,   962,   966,   967,   971,
     975,   976,   977,   978,   979,   980,   982,   984,   987,   989,
     991,   996,   997,   998,  1003,  1004,  1008,  1012,  1014,  1018,
    1019,  1021,  1022,  1026,  1027,  1028,  1032,  1033,  1034,  1040,
    1041,  1045,  1046,  1047,  1048,  1049,  1053,  1054,  1055,  1056,
    1060,  1060,  1060,  1069,  1069,  1069,  1078,  1078,  1078,  1087,
    1088,  1092,  1097,  1096,  1099,  1099,  1107,  1108,  1112,  1116,
    1121,  1126,  1128,  1132,  1134,  1136,  1138,  1146,  1151,  1156,
    1162,  1166,  1170,  1171,  1175,  1177,  1183,  1191,  1192,  1193,
    1194,  1195,  1196,  1197,  1198,  1202,  1202,  1208,  1209,  1213,
    1218,  1219,  1223,  1224,  1228,  1229,  1233,  1234,  1235,  1236,
    1242,  1248,  1250,  1254,  1258,  1262,  1266,  1273,  1274,  1278,
    1284,  1285,  1290,  1292,  1297,  1310,  1311,  1317,  1325,  1329,
    1335,  1341,  1342,  1346,  1352,  1358,  1359,  1363,  1365,  1369,
    1370,  1371,  1375,  1376,  1378,  1382,  1383,  1388,  1388,  1392,
    1393,  1394,  1395,  1396,  1400,  1401,  1402,  1403,  1404,  1405,
    1406,  1407,  1408,  1409,  1410,  1412,  1413,  1414,  1415,  1416,
    1417,  1419,  1422,  1423,  1424,  1425,  1426,  1427,  1428,  1429,
    1430,  1431,  1433,  1434,  1435,  1437,  1438,  1439,  1440,  1441,
    1442,  1443,  1444,  1445,  1446,  1447,  1449,  1451,  1453,  1457,
    1458,  1459,  1460,  1461,  1462,  1463,  1464,  1465,  1466,  1467,
    1468,  1469,  1470,  1471,  1473,  1476,  1477,  1478,  1479,  1480,
    1481,  1482,  1483,  1484,  1485,  1487,  1488,  1489,  1491,  1492,
    1493,  1494,  1495,  1496,  1497,  1498,  1499,  1500,  1501,  1503,
    1505,  1507,  1511,  1512,  1516,  1518,  1523,  1525,  1530,  1532,
    1536,  1536,  1537,  1537
  };

  // Print the state stack on the debug stream.
  void
  P4Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  P4Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 23 "parsers/p4/p4parser.ypp" // lalr1.cc:1167
} // P4
#line 8095 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/p4/p4parser.cpp" // lalr1.cc:1167
#line 1541 "parsers/p4/p4parser.ypp" // lalr1.cc:1168


void P4::P4Parser::error(const Util::SourceInfo& location,
                         const std::string& message) {
    driver.onParseError(location, message);
}
