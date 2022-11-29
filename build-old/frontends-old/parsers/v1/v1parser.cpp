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
#line 112 "parsers/v1/v1parser.ypp" // lalr1.cc:404
 /* -*-C++-*- */
#include <iostream>  // NOLINT(build/include_order)

#include "frontends/parsers/parserDriver.h"
#include "frontends/parsers/v1/v1lexer.hpp"
#include "frontends/parsers/v1/v1parser.hpp"
#include "ir/ir.h"

#define YYLLOC_DEFAULT(Cur, Rhs, N)                                             \
    ((Cur) = (N) ? YYRHSLOC(Rhs, 1) + YYRHSLOC(Rhs, N)                          \
                 : Util::SourceInfo(driver.sources, YYRHSLOC(Rhs, 0).getEnd()))

#undef yylex
#define yylex lexer.yylex
static const IR::Expression *removeRedundantValid(const IR::Expression *e);

#line 53 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "v1parser.hpp"

// User implementation prologue.

#line 67 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:412


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

#line 23 "parsers/v1/v1parser.ypp" // lalr1.cc:479
namespace V1 {
#line 153 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  V1Parser::yytnamerr_ (const char *yystr)
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
  V1Parser::V1Parser (V1::V1ParserDriver& driver_yyarg, V1::V1Lexer& lexer_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg),
      lexer (lexer_yyarg)
  {}

  V1Parser::~V1Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  V1Parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  V1Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  V1Parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  V1Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  V1Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  V1Parser::symbol_number_type
  V1Parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  V1Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  V1Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 133: // opt_field_modifiers
      case 134: // attributes
      case 135: // attrib
        value.move< Attributes > (that.value);
        break;

      case 184: // blackbox_body
        value.move< BBoxType > (that.value);
        break;

      case 156: // case_value
        value.move< CaseValue > (that.value);
        break;

      case 132: // bit_width
      case 138: // type
        value.move< ConstType* > (that.value);
        break;

      case 130: // header_dec_body
      case 131: // field_declarations
        value.move< HeaderType > (that.value);
        break;

      case 168: // action_function_body
      case 169: // action_statement_list
        value.move< IR::ActionFunction* > (that.value);
        break;

      case 171: // action_profile_body
        value.move< IR::ActionProfile* > (that.value);
        break;

      case 173: // action_selector_body
        value.move< IR::ActionSelector* > (that.value);
        break;

      case 186: // blackbox_method
        value.move< IR::Annotations* > (that.value);
        break;

      case 182: // apply_case_list
        value.move< IR::Apply* > (that.value);
        break;

      case 193: // local_var
        value.move< IR::AttribLocal* > (that.value);
        break;

      case 191: // opt_locals_list
      case 192: // locals_list
        value.move< IR::AttribLocals* > (that.value);
        break;

      case 185: // blackbox_attribute
        value.move< IR::Attribute* > (that.value);
        break;

      case 149: // update_verify_spec_list
        value.move< IR::CalculatedField* > (that.value);
        break;

      case 155: // case_value_list
        value.move< IR::CaseEntry* > (that.value);
        break;

      case 203: // const_expression
        value.move< IR::Constant* > (that.value);
        break;

      case 159: // counter_spec_list
        value.move< IR::Counter* > (that.value);
        break;

      case 190: // inout
        value.move< IR::Direction > (that.value);
        break;

      case 150: // opt_condition
      case 177: // field_or_masked_ref
      case 198: // pragma_operand
      case 199: // expression
      case 200: // header_or_field_ref
      case 201: // header_ref
        value.move< IR::Expression* > (that.value);
        break;

      case 144: // field_list_entries
        value.move< IR::FieldList* > (that.value);
        break;

      case 146: // field_list_calculation_body
        value.move< IR::FieldListCalculation* > (that.value);
        break;

      case 206: // name
        value.move< IR::ID > (that.value);
        break;

      case 202: // field_ref
        value.move< IR::Member* > (that.value);
        break;

      case 161: // meter_spec_list
        value.move< IR::Meter* > (that.value);
        break;

      case 147: // field_list_list
      case 165: // name_list
      case 166: // opt_name_list
      case 178: // action_list
        value.move< IR::NameList* > (that.value);
        break;

      case 195: // blackbox_config
        value.move< IR::NameMap<IR::Property>* > (that.value);
        break;

      case 189: // argument
        value.move< IR::Parameter* > (that.value);
        break;

      case 187: // opt_argument_list
      case 188: // argument_list
        value.move< IR::ParameterList* > (that.value);
        break;

      case 163: // register_spec_list
        value.move< IR::Register* > (that.value);
        break;

      case 153: // parser_statement_list
        value.move< IR::V1Parser* > (that.value);
        break;

      case 175: // table_body
        value.move< IR::V1Table* > (that.value);
        break;

      case 154: // case_entry_list
        value.move< IR::Vector<IR::CaseEntry>* > (that.value);
        break;

      case 176: // field_match_list
      case 180: // control_statement_list
      case 181: // control_statement
      case 196: // expressions
      case 197: // pragma_operands
      case 204: // expression_list
      case 205: // opt_expression_list
        value.move< IR::Vector<IR::Expression>* > (that.value);
        break;

      case 124: // INTEGER
        value.move< UnparsedConstant > (that.value);
        break;

      case 37: // ACTION
      case 38: // ACTIONS
      case 39: // ACTION_PROFILE
      case 40: // ACTION_SELECTOR
      case 41: // ALGORITHM
      case 42: // APPLY
      case 43: // ATTRIBUTE
      case 44: // ATTRIBUTES
      case 45: // BIT
      case 46: // BLACKBOX
      case 47: // BLACKBOX_TYPE
      case 48: // BLOCK
      case 49: // BOOL
      case 50: // CALCULATED_FIELD
      case 51: // CONTROL
      case 52: // COUNTER
      case 53: // CONST
      case 54: // CURRENT
      case 55: // DEFAULT
      case 56: // DEFAULT_ACTION
      case 57: // DIRECT
      case 58: // DROP
      case 59: // DYNAMIC_ACTION_SELECTION
      case 60: // ELSE
      case 61: // EXTRACT
      case 62: // EXPRESSION
      case 63: // EXPRESSION_LOCAL_VARIABLES
      case 64: // FALSE
      case 65: // FIELD_LIST
      case 66: // FIELD_LIST_CALCULATION
      case 67: // FIELDS
      case 68: // HEADER
      case 69: // HEADER_TYPE
      case 70: // IF
      case 71: // IMPLEMENTATION
      case 72: // IN
      case 73: // INPUT
      case 74: // INSTANCE_COUNT
      case 75: // INT
      case 76: // LATEST
      case 77: // LAYOUT
      case 78: // LENGTH
      case 79: // MASK
      case 80: // MAX_LENGTH
      case 81: // MAX_SIZE
      case 82: // MAX_WIDTH
      case 83: // METADATA
      case 84: // METER
      case 85: // METHOD
      case 86: // MIN_SIZE
      case 87: // MIN_WIDTH
      case 88: // OPTIONAL
      case 89: // OUT
      case 90: // OUTPUT_WIDTH
      case 91: // PARSE_ERROR
      case 92: // PARSER
      case 93: // PARSER_VALUE_SET
      case 94: // PARSER_EXCEPTION
      case 95: // PAYLOAD
      case 96: // PRAGMA
      case 97: // PREFIX
      case 98: // PRE_COLOR
      case 99: // PRIMITIVE_ACTION
      case 100: // READS
      case 101: // REGISTER
      case 102: // RESULT
      case 103: // RETURN
      case 104: // SATURATING
      case 105: // SELECT
      case 106: // SELECTION_KEY
      case 107: // SELECTION_MODE
      case 108: // SELECTION_TYPE
      case 109: // SET_METADATA
      case 110: // SIGNED
      case 111: // SIZE
      case 112: // STATIC
      case 113: // STRING
      case 114: // TABLE
      case 115: // TRUE
      case 116: // TYPE
      case 117: // UPDATE
      case 118: // VALID
      case 119: // VERIFY
      case 120: // WIDTH
      case 121: // WRITES
      case 122: // IDENTIFIER
      case 123: // STRING_LITERAL
        value.move< cstring > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  V1Parser::stack_symbol_type&
  V1Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 133: // opt_field_modifiers
      case 134: // attributes
      case 135: // attrib
        value.copy< Attributes > (that.value);
        break;

      case 184: // blackbox_body
        value.copy< BBoxType > (that.value);
        break;

      case 156: // case_value
        value.copy< CaseValue > (that.value);
        break;

      case 132: // bit_width
      case 138: // type
        value.copy< ConstType* > (that.value);
        break;

      case 130: // header_dec_body
      case 131: // field_declarations
        value.copy< HeaderType > (that.value);
        break;

      case 168: // action_function_body
      case 169: // action_statement_list
        value.copy< IR::ActionFunction* > (that.value);
        break;

      case 171: // action_profile_body
        value.copy< IR::ActionProfile* > (that.value);
        break;

      case 173: // action_selector_body
        value.copy< IR::ActionSelector* > (that.value);
        break;

      case 186: // blackbox_method
        value.copy< IR::Annotations* > (that.value);
        break;

      case 182: // apply_case_list
        value.copy< IR::Apply* > (that.value);
        break;

      case 193: // local_var
        value.copy< IR::AttribLocal* > (that.value);
        break;

      case 191: // opt_locals_list
      case 192: // locals_list
        value.copy< IR::AttribLocals* > (that.value);
        break;

      case 185: // blackbox_attribute
        value.copy< IR::Attribute* > (that.value);
        break;

      case 149: // update_verify_spec_list
        value.copy< IR::CalculatedField* > (that.value);
        break;

      case 155: // case_value_list
        value.copy< IR::CaseEntry* > (that.value);
        break;

      case 203: // const_expression
        value.copy< IR::Constant* > (that.value);
        break;

      case 159: // counter_spec_list
        value.copy< IR::Counter* > (that.value);
        break;

      case 190: // inout
        value.copy< IR::Direction > (that.value);
        break;

      case 150: // opt_condition
      case 177: // field_or_masked_ref
      case 198: // pragma_operand
      case 199: // expression
      case 200: // header_or_field_ref
      case 201: // header_ref
        value.copy< IR::Expression* > (that.value);
        break;

      case 144: // field_list_entries
        value.copy< IR::FieldList* > (that.value);
        break;

      case 146: // field_list_calculation_body
        value.copy< IR::FieldListCalculation* > (that.value);
        break;

      case 206: // name
        value.copy< IR::ID > (that.value);
        break;

      case 202: // field_ref
        value.copy< IR::Member* > (that.value);
        break;

      case 161: // meter_spec_list
        value.copy< IR::Meter* > (that.value);
        break;

      case 147: // field_list_list
      case 165: // name_list
      case 166: // opt_name_list
      case 178: // action_list
        value.copy< IR::NameList* > (that.value);
        break;

      case 195: // blackbox_config
        value.copy< IR::NameMap<IR::Property>* > (that.value);
        break;

      case 189: // argument
        value.copy< IR::Parameter* > (that.value);
        break;

      case 187: // opt_argument_list
      case 188: // argument_list
        value.copy< IR::ParameterList* > (that.value);
        break;

      case 163: // register_spec_list
        value.copy< IR::Register* > (that.value);
        break;

      case 153: // parser_statement_list
        value.copy< IR::V1Parser* > (that.value);
        break;

      case 175: // table_body
        value.copy< IR::V1Table* > (that.value);
        break;

      case 154: // case_entry_list
        value.copy< IR::Vector<IR::CaseEntry>* > (that.value);
        break;

      case 176: // field_match_list
      case 180: // control_statement_list
      case 181: // control_statement
      case 196: // expressions
      case 197: // pragma_operands
      case 204: // expression_list
      case 205: // opt_expression_list
        value.copy< IR::Vector<IR::Expression>* > (that.value);
        break;

      case 124: // INTEGER
        value.copy< UnparsedConstant > (that.value);
        break;

      case 37: // ACTION
      case 38: // ACTIONS
      case 39: // ACTION_PROFILE
      case 40: // ACTION_SELECTOR
      case 41: // ALGORITHM
      case 42: // APPLY
      case 43: // ATTRIBUTE
      case 44: // ATTRIBUTES
      case 45: // BIT
      case 46: // BLACKBOX
      case 47: // BLACKBOX_TYPE
      case 48: // BLOCK
      case 49: // BOOL
      case 50: // CALCULATED_FIELD
      case 51: // CONTROL
      case 52: // COUNTER
      case 53: // CONST
      case 54: // CURRENT
      case 55: // DEFAULT
      case 56: // DEFAULT_ACTION
      case 57: // DIRECT
      case 58: // DROP
      case 59: // DYNAMIC_ACTION_SELECTION
      case 60: // ELSE
      case 61: // EXTRACT
      case 62: // EXPRESSION
      case 63: // EXPRESSION_LOCAL_VARIABLES
      case 64: // FALSE
      case 65: // FIELD_LIST
      case 66: // FIELD_LIST_CALCULATION
      case 67: // FIELDS
      case 68: // HEADER
      case 69: // HEADER_TYPE
      case 70: // IF
      case 71: // IMPLEMENTATION
      case 72: // IN
      case 73: // INPUT
      case 74: // INSTANCE_COUNT
      case 75: // INT
      case 76: // LATEST
      case 77: // LAYOUT
      case 78: // LENGTH
      case 79: // MASK
      case 80: // MAX_LENGTH
      case 81: // MAX_SIZE
      case 82: // MAX_WIDTH
      case 83: // METADATA
      case 84: // METER
      case 85: // METHOD
      case 86: // MIN_SIZE
      case 87: // MIN_WIDTH
      case 88: // OPTIONAL
      case 89: // OUT
      case 90: // OUTPUT_WIDTH
      case 91: // PARSE_ERROR
      case 92: // PARSER
      case 93: // PARSER_VALUE_SET
      case 94: // PARSER_EXCEPTION
      case 95: // PAYLOAD
      case 96: // PRAGMA
      case 97: // PREFIX
      case 98: // PRE_COLOR
      case 99: // PRIMITIVE_ACTION
      case 100: // READS
      case 101: // REGISTER
      case 102: // RESULT
      case 103: // RETURN
      case 104: // SATURATING
      case 105: // SELECT
      case 106: // SELECTION_KEY
      case 107: // SELECTION_MODE
      case 108: // SELECTION_TYPE
      case 109: // SET_METADATA
      case 110: // SIGNED
      case 111: // SIZE
      case 112: // STATIC
      case 113: // STRING
      case 114: // TABLE
      case 115: // TRUE
      case 116: // TYPE
      case 117: // UPDATE
      case 118: // VALID
      case 119: // VERIFY
      case 120: // WIDTH
      case 121: // WRITES
      case 122: // IDENTIFIER
      case 123: // STRING_LITERAL
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
  V1Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  V1Parser::yy_print_ (std::ostream& yyo,
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
            case 37: // ACTION

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 815 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 38: // ACTIONS

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 822 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 39: // ACTION_PROFILE

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 829 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 40: // ACTION_SELECTOR

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 836 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 41: // ALGORITHM

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 843 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 42: // APPLY

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 850 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 43: // ATTRIBUTE

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 857 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 44: // ATTRIBUTES

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 864 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 45: // BIT

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 871 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 46: // BLACKBOX

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 878 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 47: // BLACKBOX_TYPE

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 885 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 48: // BLOCK

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 892 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 49: // BOOL

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 899 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 50: // CALCULATED_FIELD

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 906 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 51: // CONTROL

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 913 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 52: // COUNTER

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 920 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 53: // CONST

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 927 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 54: // CURRENT

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 934 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 55: // DEFAULT

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 941 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 56: // DEFAULT_ACTION

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 948 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 57: // DIRECT

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 955 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 58: // DROP

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 962 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 59: // DYNAMIC_ACTION_SELECTION

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 969 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 60: // ELSE

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 976 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 61: // EXTRACT

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 983 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 62: // EXPRESSION

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 990 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 63: // EXPRESSION_LOCAL_VARIABLES

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 997 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 64: // FALSE

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1004 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 65: // FIELD_LIST

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1011 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 66: // FIELD_LIST_CALCULATION

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1018 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 67: // FIELDS

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1025 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 68: // HEADER

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1032 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 69: // HEADER_TYPE

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1039 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 70: // IF

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1046 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 71: // IMPLEMENTATION

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1053 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 72: // IN

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1060 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 73: // INPUT

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1067 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 74: // INSTANCE_COUNT

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1074 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 75: // INT

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1081 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 76: // LATEST

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1088 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 77: // LAYOUT

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1095 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 78: // LENGTH

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1102 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 79: // MASK

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1109 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 80: // MAX_LENGTH

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1116 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 81: // MAX_SIZE

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1123 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 82: // MAX_WIDTH

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1130 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 83: // METADATA

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1137 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 84: // METER

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1144 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 85: // METHOD

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1151 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 86: // MIN_SIZE

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1158 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 87: // MIN_WIDTH

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1165 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 88: // OPTIONAL

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1172 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 89: // OUT

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1179 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 90: // OUTPUT_WIDTH

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1186 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 91: // PARSE_ERROR

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1193 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 92: // PARSER

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1200 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 93: // PARSER_VALUE_SET

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1207 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 94: // PARSER_EXCEPTION

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1214 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 95: // PAYLOAD

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1221 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 96: // PRAGMA

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1228 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 97: // PREFIX

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1235 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 98: // PRE_COLOR

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1242 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 99: // PRIMITIVE_ACTION

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1249 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 100: // READS

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1256 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 101: // REGISTER

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1263 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 102: // RESULT

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1270 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 103: // RETURN

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1277 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 104: // SATURATING

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1284 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 105: // SELECT

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1291 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 106: // SELECTION_KEY

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1298 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 107: // SELECTION_MODE

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1305 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 108: // SELECTION_TYPE

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1312 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 109: // SET_METADATA

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1319 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 110: // SIGNED

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1326 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 111: // SIZE

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1333 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 112: // STATIC

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1340 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 113: // STRING

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1347 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 114: // TABLE

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1354 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 115: // TRUE

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1361 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 116: // TYPE

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1368 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 117: // UPDATE

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1375 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 118: // VALID

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1382 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 119: // VERIFY

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1389 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 120: // WIDTH

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1396 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 121: // WRITES

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1403 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 122: // IDENTIFIER

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1410 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 123: // STRING_LITERAL

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< cstring > (); }
#line 1417 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 124: // INTEGER

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< UnparsedConstant > (); }
#line 1424 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 130: // header_dec_body

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< HeaderType > (); }
#line 1431 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 131: // field_declarations

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< HeaderType > (); }
#line 1438 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 132: // bit_width

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< ConstType* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1452 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 133: // opt_field_modifiers

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Attributes > (); }
#line 1459 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 134: // attributes

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Attributes > (); }
#line 1466 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 135: // attrib

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< Attributes > (); }
#line 1473 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 138: // type

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< ConstType* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1487 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 144: // field_list_entries

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::FieldList* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1501 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 146: // field_list_calculation_body

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::FieldListCalculation* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1515 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 147: // field_list_list

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::NameList* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1529 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 149: // update_verify_spec_list

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::CalculatedField* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1543 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 150: // opt_condition

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1557 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 153: // parser_statement_list

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::V1Parser* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1571 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 154: // case_entry_list

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::Vector<IR::CaseEntry>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1585 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 155: // case_value_list

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::CaseEntry* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1599 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 156: // case_value

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< CaseValue > (); }
#line 1606 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 159: // counter_spec_list

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::Counter* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1620 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 161: // meter_spec_list

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::Meter* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1634 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 163: // register_spec_list

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::Register* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1648 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 165: // name_list

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::NameList* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1662 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 166: // opt_name_list

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::NameList* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1676 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 168: // action_function_body

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::ActionFunction* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1690 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 169: // action_statement_list

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::ActionFunction* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1704 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 171: // action_profile_body

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::ActionProfile* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1718 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 173: // action_selector_body

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::ActionSelector* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1732 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 175: // table_body

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::V1Table* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1746 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 176: // field_match_list

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::Vector<IR::Expression>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1760 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 177: // field_or_masked_ref

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1774 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 178: // action_list

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::NameList* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1788 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 180: // control_statement_list

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::Vector<IR::Expression>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1802 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 181: // control_statement

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::Vector<IR::Expression>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1816 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 182: // apply_case_list

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::Apply* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1830 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 184: // blackbox_body

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< BBoxType > (); }
#line 1837 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 185: // blackbox_attribute

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::Attribute* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1851 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 186: // blackbox_method

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::Annotations* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1865 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 187: // opt_argument_list

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::ParameterList* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1879 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 188: // argument_list

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::ParameterList* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1893 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 189: // argument

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::Parameter* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1907 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 190: // inout

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::Direction > (); }
#line 1914 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 191: // opt_locals_list

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::AttribLocals* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1928 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 192: // locals_list

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::AttribLocals* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1942 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 193: // local_var

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::AttribLocal* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1956 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 195: // blackbox_config

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::NameMap<IR::Property>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1970 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 196: // expressions

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::Vector<IR::Expression>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1984 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 197: // pragma_operands

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::Vector<IR::Expression>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 1998 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 198: // pragma_operand

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2012 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 199: // expression

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2026 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 200: // header_or_field_ref

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2040 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 201: // header_ref

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::Expression* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2054 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 202: // field_ref

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::Member* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2068 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 203: // const_expression

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::Constant* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2082 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 204: // expression_list

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::Vector<IR::Expression>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2096 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 205: // opt_expression_list

#line 134 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        {
    auto val = yysym.value.template as< IR::Vector<IR::Expression>* > ();
    if (val != nullptr) {
        yyoutput << val;
    } else {
        yyoutput << "(null)";
    }
}
#line 2110 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;

      case 206: // name

#line 132 "parsers/v1/v1parser.ypp" // lalr1.cc:636
        { yyoutput << yysym.value.template as< IR::ID > (); }
#line 2117 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:636
        break;


      default:
        break;
    }
    yyo << ')';
  }
#endif

  inline
  void
  V1Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  V1Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  V1Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  V1Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  V1Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  V1Parser::debug_level_type
  V1Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  V1Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline V1Parser::state_type
  V1Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  V1Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  V1Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  V1Parser::parse ()
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
      case 133: // opt_field_modifiers
      case 134: // attributes
      case 135: // attrib
        yylhs.value.build< Attributes > ();
        break;

      case 184: // blackbox_body
        yylhs.value.build< BBoxType > ();
        break;

      case 156: // case_value
        yylhs.value.build< CaseValue > ();
        break;

      case 132: // bit_width
      case 138: // type
        yylhs.value.build< ConstType* > ();
        break;

      case 130: // header_dec_body
      case 131: // field_declarations
        yylhs.value.build< HeaderType > ();
        break;

      case 168: // action_function_body
      case 169: // action_statement_list
        yylhs.value.build< IR::ActionFunction* > ();
        break;

      case 171: // action_profile_body
        yylhs.value.build< IR::ActionProfile* > ();
        break;

      case 173: // action_selector_body
        yylhs.value.build< IR::ActionSelector* > ();
        break;

      case 186: // blackbox_method
        yylhs.value.build< IR::Annotations* > ();
        break;

      case 182: // apply_case_list
        yylhs.value.build< IR::Apply* > ();
        break;

      case 193: // local_var
        yylhs.value.build< IR::AttribLocal* > ();
        break;

      case 191: // opt_locals_list
      case 192: // locals_list
        yylhs.value.build< IR::AttribLocals* > ();
        break;

      case 185: // blackbox_attribute
        yylhs.value.build< IR::Attribute* > ();
        break;

      case 149: // update_verify_spec_list
        yylhs.value.build< IR::CalculatedField* > ();
        break;

      case 155: // case_value_list
        yylhs.value.build< IR::CaseEntry* > ();
        break;

      case 203: // const_expression
        yylhs.value.build< IR::Constant* > ();
        break;

      case 159: // counter_spec_list
        yylhs.value.build< IR::Counter* > ();
        break;

      case 190: // inout
        yylhs.value.build< IR::Direction > ();
        break;

      case 150: // opt_condition
      case 177: // field_or_masked_ref
      case 198: // pragma_operand
      case 199: // expression
      case 200: // header_or_field_ref
      case 201: // header_ref
        yylhs.value.build< IR::Expression* > ();
        break;

      case 144: // field_list_entries
        yylhs.value.build< IR::FieldList* > ();
        break;

      case 146: // field_list_calculation_body
        yylhs.value.build< IR::FieldListCalculation* > ();
        break;

      case 206: // name
        yylhs.value.build< IR::ID > ();
        break;

      case 202: // field_ref
        yylhs.value.build< IR::Member* > ();
        break;

      case 161: // meter_spec_list
        yylhs.value.build< IR::Meter* > ();
        break;

      case 147: // field_list_list
      case 165: // name_list
      case 166: // opt_name_list
      case 178: // action_list
        yylhs.value.build< IR::NameList* > ();
        break;

      case 195: // blackbox_config
        yylhs.value.build< IR::NameMap<IR::Property>* > ();
        break;

      case 189: // argument
        yylhs.value.build< IR::Parameter* > ();
        break;

      case 187: // opt_argument_list
      case 188: // argument_list
        yylhs.value.build< IR::ParameterList* > ();
        break;

      case 163: // register_spec_list
        yylhs.value.build< IR::Register* > ();
        break;

      case 153: // parser_statement_list
        yylhs.value.build< IR::V1Parser* > ();
        break;

      case 175: // table_body
        yylhs.value.build< IR::V1Table* > ();
        break;

      case 154: // case_entry_list
        yylhs.value.build< IR::Vector<IR::CaseEntry>* > ();
        break;

      case 176: // field_match_list
      case 180: // control_statement_list
      case 181: // control_statement
      case 196: // expressions
      case 197: // pragma_operands
      case 204: // expression_list
      case 205: // opt_expression_list
        yylhs.value.build< IR::Vector<IR::Expression>* > ();
        break;

      case 124: // INTEGER
        yylhs.value.build< UnparsedConstant > ();
        break;

      case 37: // ACTION
      case 38: // ACTIONS
      case 39: // ACTION_PROFILE
      case 40: // ACTION_SELECTOR
      case 41: // ALGORITHM
      case 42: // APPLY
      case 43: // ATTRIBUTE
      case 44: // ATTRIBUTES
      case 45: // BIT
      case 46: // BLACKBOX
      case 47: // BLACKBOX_TYPE
      case 48: // BLOCK
      case 49: // BOOL
      case 50: // CALCULATED_FIELD
      case 51: // CONTROL
      case 52: // COUNTER
      case 53: // CONST
      case 54: // CURRENT
      case 55: // DEFAULT
      case 56: // DEFAULT_ACTION
      case 57: // DIRECT
      case 58: // DROP
      case 59: // DYNAMIC_ACTION_SELECTION
      case 60: // ELSE
      case 61: // EXTRACT
      case 62: // EXPRESSION
      case 63: // EXPRESSION_LOCAL_VARIABLES
      case 64: // FALSE
      case 65: // FIELD_LIST
      case 66: // FIELD_LIST_CALCULATION
      case 67: // FIELDS
      case 68: // HEADER
      case 69: // HEADER_TYPE
      case 70: // IF
      case 71: // IMPLEMENTATION
      case 72: // IN
      case 73: // INPUT
      case 74: // INSTANCE_COUNT
      case 75: // INT
      case 76: // LATEST
      case 77: // LAYOUT
      case 78: // LENGTH
      case 79: // MASK
      case 80: // MAX_LENGTH
      case 81: // MAX_SIZE
      case 82: // MAX_WIDTH
      case 83: // METADATA
      case 84: // METER
      case 85: // METHOD
      case 86: // MIN_SIZE
      case 87: // MIN_WIDTH
      case 88: // OPTIONAL
      case 89: // OUT
      case 90: // OUTPUT_WIDTH
      case 91: // PARSE_ERROR
      case 92: // PARSER
      case 93: // PARSER_VALUE_SET
      case 94: // PARSER_EXCEPTION
      case 95: // PAYLOAD
      case 96: // PRAGMA
      case 97: // PREFIX
      case 98: // PRE_COLOR
      case 99: // PRIMITIVE_ACTION
      case 100: // READS
      case 101: // REGISTER
      case 102: // RESULT
      case 103: // RETURN
      case 104: // SATURATING
      case 105: // SELECT
      case 106: // SELECTION_KEY
      case 107: // SELECTION_MODE
      case 108: // SELECTION_TYPE
      case 109: // SET_METADATA
      case 110: // SIGNED
      case 111: // SIZE
      case 112: // STATIC
      case 113: // STRING
      case 114: // TABLE
      case 115: // TRUE
      case 116: // TYPE
      case 117: // UPDATE
      case 118: // VALID
      case 119: // VERIFY
      case 120: // WIDTH
      case 121: // WRITES
      case 122: // IDENTIFIER
      case 123: // STRING_LITERAL
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
#line 249 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { YYACCEPT; }
#line 2584 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 24:
#line 273 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { driver.addPragma(new IR::Annotation(yystack_[2].location, yystack_[2].value.as< cstring > (), *yystack_[1].value.as< IR::Vector<IR::Expression>* > ())); }
#line 2590 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 25:
#line 275 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { driver.clearPragmas(); }
#line 2596 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 26:
#line 283 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yystack_[1].value.as< HeaderType > ().annotations->append(driver.takePragmasAsVector());
        driver.global->add(yystack_[3].value.as< IR::ID > (), new IR::v1HeaderType(yystack_[4].location+yystack_[0].location, yystack_[3].value.as< IR::ID > (),
            new IR::Type_Struct(yystack_[4].location+yystack_[0].location, IR::ID(yystack_[3].location, yystack_[3].value.as< IR::ID > ()),
                                new IR::Annotations(*yystack_[1].value.as< HeaderType > ().annotations), *yystack_[1].value.as< HeaderType > ().fields),
            new IR::Type_Header(yystack_[4].location+yystack_[0].location, IR::ID(yystack_[3].location, yystack_[3].value.as< IR::ID > ()),
                                new IR::Annotations(*yystack_[1].value.as< HeaderType > ().annotations), *yystack_[1].value.as< HeaderType > ().fields))); }
#line 2607 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 27:
#line 290 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { driver.clearPragmas(); }
#line 2613 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 28:
#line 294 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< HeaderType > () = yystack_[3].value.as< HeaderType > (); }
#line 2619 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 29:
#line 295 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< HeaderType > () = yystack_[2].value.as< HeaderType > (); }
#line 2625 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 30:
#line 299 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< HeaderType > ().annotations = new IR::Vector<IR::Annotation>;
        yylhs.value.as< HeaderType > ().fields = new IR::IndexedVector<IR::StructField>; }
#line 2632 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 31:
#line 301 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    {
        auto *type = yystack_[2].value.as< ConstType* > ();
        if (yystack_[1].value.as< Attributes > ().signed_ && type->is<IR::Type::Bits>())
            type = IR::Type::Bits::get(type->to<IR::Type::Bits>()->size, true);
        (yylhs.value.as< HeaderType > ()=yystack_[5].value.as< HeaderType > ()).fields->push_back(new IR::StructField(yystack_[4].location+yystack_[2].location, IR::ID(yystack_[4].location, yystack_[4].value.as< IR::ID > ()),
                new IR::Annotations(yystack_[1].value.as< Attributes > ().annotations), type)); }
#line 2643 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 32:
#line 308 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< HeaderType > ()=yystack_[3].value.as< HeaderType > ()).fields->push_back(new IR::StructField(yystack_[2].location+yystack_[0].location, IR::ID(yystack_[1].location, yystack_[1].value.as< IR::ID > ()), yystack_[2].value.as< ConstType* > ())); }
#line 2649 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 33:
#line 313 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { if (yystack_[0].value.as< IR::Constant* > ())
            yylhs.value.as< ConstType* > () = IR::Type::Bits::get(yystack_[0].location, yystack_[0].value.as< IR::Constant* > ()->asInt());
        else
            yylhs.value.as< ConstType* > () = IR::Type::Unknown::get(); }
#line 2658 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 34:
#line 318 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = IR::Type::Varbits::get(); }
#line 2664 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 35:
#line 321 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Attributes > () = Attributes(); }
#line 2670 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 36:
#line 322 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Attributes > () = yystack_[1].value.as< Attributes > (); }
#line 2676 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 37:
#line 326 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Attributes > () = yystack_[0].value.as< Attributes > (); }
#line 2682 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 38:
#line 327 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< Attributes > () = yystack_[2].value.as< Attributes > ()).merge(yystack_[0].value.as< Attributes > ()); }
#line 2688 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 39:
#line 331 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Attributes > ().signed_ = true; }
#line 2694 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 40:
#line 332 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< Attributes > ().annotations.push_back(new IR::Annotation(yystack_[0].location, IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()), {}));
                   yylhs.value.as< Attributes > ().saturating = true; }
#line 2701 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 42:
#line 338 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yystack_[(4) - (-1)].value.as< HeaderType > ().annotations->emplace_back(
          IR::Annotation(yystack_[3].location+yystack_[0].location, "length", IR::Vector<IR::Expression>(yystack_[1].value.as< IR::Expression* > ()))); }
#line 2708 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 44:
#line 344 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yystack_[(4) - (-2)].value.as< HeaderType > ().annotations->emplace_back(
          IR::Annotation(yystack_[3].location+yystack_[0].location, "max_length", IR::Vector<IR::Expression>(yystack_[1].value.as< IR::Constant* > ()))); }
#line 2715 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 45:
#line 348 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = IR::Type::Bits::get(yystack_[0].location, 1); }
#line 2721 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 46:
#line 350 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = IR::Type::Bits::get(yystack_[1].location, parseConstant(yystack_[1].location, yystack_[1].value.as< UnparsedConstant > (), 0)->asInt()); }
#line 2727 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 47:
#line 351 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = IR::Type_Block::get(); }
#line 2733 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 48:
#line 352 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = IR::Type_Boolean::get(); }
#line 2739 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 49:
#line 353 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = IR::Type_Counter::get(); }
#line 2745 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 50:
#line 354 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = IR::Type_Expression::get(); }
#line 2751 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 51:
#line 355 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = IR::Type_FieldListCalculation::get(); }
#line 2757 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 52:
#line 356 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = new IR::Type_InfInt; }
#line 2763 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 53:
#line 358 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = IR::Type::Bits::get(yystack_[1].location, parseConstant(yystack_[1].location, yystack_[1].value.as< UnparsedConstant > (), 0)->asInt(), true); }
#line 2769 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 54:
#line 359 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = IR::Type_Meter::get(); }
#line 2775 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 55:
#line 360 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = IR::Type_String::get(); }
#line 2781 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 56:
#line 361 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = IR::Type_Register::get(); }
#line 2787 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 57:
#line 362 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< ConstType* > () = IR::Type_AnyTable::get(); }
#line 2793 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 58:
#line 371 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { driver.global->add(yystack_[1].value.as< IR::ID > (), new IR::Header(yystack_[3].location+yystack_[0].location, IR::ID(yystack_[2].location, yystack_[2].value.as< IR::ID > ()), IR::ID(yystack_[1].location, yystack_[1].value.as< IR::ID > ()),
                                              driver.takePragmasAsAnnotations())); }
#line 2800 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 59:
#line 374 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { driver.global->add(yystack_[4].value.as< IR::ID > (), new IR::HeaderStack(yystack_[6].location+yystack_[0].location, IR::ID(yystack_[5].location, yystack_[5].value.as< IR::ID > ()), IR::ID(yystack_[4].location, yystack_[4].value.as< IR::ID > ()),
                                                   driver.takePragmasAsAnnotations(),
                                                   yystack_[2].value.as< IR::Constant* > () ? yystack_[2].value.as< IR::Constant* > ()->asLong() : 0));
        yystack_[2].value.as< IR::Constant* > () = nullptr; }
#line 2809 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 60:
#line 382 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { driver.global->add(yystack_[2].value.as< IR::ID > (), new IR::Metadata(yystack_[4].location+yystack_[0].location, IR::ID(yystack_[3].location, yystack_[3].value.as< IR::ID > ()), IR::ID(yystack_[2].location, yystack_[2].value.as< IR::ID > ()),
                                                driver.takePragmasAsAnnotations())); }
#line 2816 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 64:
#line 392 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yystack_[1].value.as< IR::Constant* > () = nullptr; }
#line 2822 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 65:
#line 401 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yystack_[1].value.as< IR::FieldList* > ()->name = IR::ID(yystack_[3].location, yystack_[3].value.as< IR::ID > ()); yystack_[1].value.as< IR::FieldList* > ()->srcInfo = yystack_[4].location + yystack_[0].location; driver.global->add(yystack_[3].value.as< IR::ID > (), yystack_[1].value.as< IR::FieldList* > ()); }
#line 2828 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 67:
#line 407 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::FieldList* > () = new IR::FieldList(driver.takePragmasAsAnnotations()); }
#line 2834 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 68:
#line 409 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::FieldList* > ()=yystack_[2].value.as< IR::FieldList* > ())->fields.push_back(yystack_[1].value.as< IR::Expression* > ()); }
#line 2840 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 69:
#line 411 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::FieldList* > ()=yystack_[2].value.as< IR::FieldList* > ())->payload = true; }
#line 2846 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 70:
#line 420 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yystack_[1].value.as< IR::FieldListCalculation* > ()->name = IR::ID(yystack_[3].location, yystack_[3].value.as< IR::ID > ()); yystack_[1].value.as< IR::FieldListCalculation* > ()->srcInfo = yystack_[4].location + yystack_[0].location; driver.global->add(yystack_[3].value.as< IR::ID > (), yystack_[1].value.as< IR::FieldListCalculation* > ()); }
#line 2852 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 72:
#line 425 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::FieldListCalculation* > () = new IR::FieldListCalculation(driver.takePragmasAsAnnotations()); }
#line 2858 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 73:
#line 427 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { if (yystack_[4].value.as< IR::FieldListCalculation* > ()->input)
           ::error(ErrorType::ERR_INVALID, "%s: multiple 'input' in field_list_calculation", yystack_[3].location);
        (yylhs.value.as< IR::FieldListCalculation* > ()=yystack_[4].value.as< IR::FieldListCalculation* > ())->input = yystack_[1].value.as< IR::NameList* > (); }
#line 2866 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 74:
#line 431 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { if (yystack_[4].value.as< IR::FieldListCalculation* > ()->algorithm)
            ::error(ErrorType::ERR_INVALID,
                    "%s: multiple 'algorithm' in field_list_calculation", yystack_[3].location);
        (yylhs.value.as< IR::FieldListCalculation* > ()=yystack_[4].value.as< IR::FieldListCalculation* > ())->algorithm = new IR::NameList(yystack_[1].location, IR::ID(yystack_[1].location, yystack_[1].value.as< IR::ID > ())); }
#line 2875 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 75:
#line 436 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { if (yystack_[4].value.as< IR::FieldListCalculation* > ()->algorithm)
            ::error(ErrorType::ERR_INVALID,
                    "%s: multiple 'algorithm' in field_list_calculation", yystack_[3].location);
        (yylhs.value.as< IR::FieldListCalculation* > ()=yystack_[4].value.as< IR::FieldListCalculation* > ())->algorithm = yystack_[1].value.as< IR::NameList* > (); }
#line 2884 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 76:
#line 441 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { if (yystack_[4].value.as< IR::FieldListCalculation* > ()->output_width)
            ::error(ErrorType::ERR_INVALID,
                    "%s: multiple 'output_width' in field_list_calculation", yystack_[3].location);
        (yylhs.value.as< IR::FieldListCalculation* > ()=yystack_[4].value.as< IR::FieldListCalculation* > ())->output_width = yystack_[1].value.as< IR::Constant* > () ? yystack_[1].value.as< IR::Constant* > ()->asInt() : 0; }
#line 2893 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 77:
#line 445 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::FieldListCalculation* > () = yystack_[2].value.as< IR::FieldListCalculation* > (); }
#line 2899 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 78:
#line 446 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::FieldListCalculation* > () = yystack_[1].value.as< IR::FieldListCalculation* > (); }
#line 2905 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 79:
#line 450 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::NameList* > () = new IR::NameList; }
#line 2911 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 80:
#line 452 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::NameList* > ()=yystack_[2].value.as< IR::NameList* > ())->names.emplace_back(yystack_[1].location, yystack_[1].value.as< IR::ID > ()); }
#line 2917 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 81:
#line 457 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yystack_[1].value.as< IR::CalculatedField* > ()->field = yystack_[3].value.as< IR::Member* > (); yystack_[1].value.as< IR::CalculatedField* > ()->srcInfo = yystack_[4].location + yystack_[0].location; driver.global->add(yystack_[3].value.as< IR::Member* > ()->toString(), yystack_[1].value.as< IR::CalculatedField* > ()); }
#line 2923 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 83:
#line 462 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::CalculatedField* > () = new IR::CalculatedField(driver.takePragmasAsAnnotations()); }
#line 2929 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 84:
#line 464 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::CalculatedField* > ()=yystack_[4].value.as< IR::CalculatedField* > ())->specs.emplace_back(yystack_[4].location+yystack_[2].location, true, IR::ID(yystack_[2].location, yystack_[2].value.as< IR::ID > ()), yystack_[1].value.as< IR::Expression* > ()); }
#line 2935 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 85:
#line 466 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::CalculatedField* > ()=yystack_[4].value.as< IR::CalculatedField* > ())->specs.emplace_back(yystack_[4].location+yystack_[2].location, false, IR::ID(yystack_[2].location, yystack_[2].value.as< IR::ID > ()), yystack_[1].value.as< IR::Expression* > ()); }
#line 2941 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 86:
#line 467 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::CalculatedField* > () = yystack_[2].value.as< IR::CalculatedField* > (); }
#line 2947 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 87:
#line 468 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::CalculatedField* > () = yystack_[1].value.as< IR::CalculatedField* > (); }
#line 2953 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 88:
#line 471 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = nullptr; }
#line 2959 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 89:
#line 472 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = yystack_[1].value.as< IR::Expression* > (); }
#line 2965 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 90:
#line 481 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { driver.global->add(yystack_[1].value.as< IR::ID > (), new IR::ParserValueSet(yystack_[2].location, IR::ID(yystack_[1].location, yystack_[1].value.as< IR::ID > ()), driver.takePragmasAsAnnotations())); }
#line 2971 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 91:
#line 489 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yystack_[1].value.as< IR::V1Parser* > ()->name = IR::ID(yystack_[3].location, yystack_[3].value.as< IR::ID > ()); yystack_[1].value.as< IR::V1Parser* > ()->srcInfo = yystack_[4].location + yystack_[0].location; driver.global->add(yystack_[3].value.as< IR::ID > (), yystack_[1].value.as< IR::V1Parser* > ()); }
#line 2977 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 93:
#line 494 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::V1Parser* > () = new IR::V1Parser(driver.takePragmasAsAnnotations()); }
#line 2983 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 94:
#line 496 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::V1Parser* > ()=yystack_[5].value.as< IR::V1Parser* > ())->stmts.push_back(new IR::Primitive(yystack_[4].location+yystack_[1].location, yystack_[4].value.as< cstring > (), yystack_[2].value.as< IR::Expression* > ())); }
#line 2989 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 95:
#line 498 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::V1Parser* > ()=yystack_[7].value.as< IR::V1Parser* > ())->stmts.push_back(new IR::Primitive(yystack_[6].location+yystack_[1].location, yystack_[6].value.as< cstring > (), yystack_[4].value.as< IR::Expression* > (), yystack_[2].value.as< IR::Expression* > ())); }
#line 2995 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 96:
#line 500 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::V1Parser* > ()=yystack_[4].value.as< IR::V1Parser* > ())->stmts.push_back(new IR::Primitive(yystack_[2].location, "set_metadata", yystack_[3].value.as< IR::Expression* > (), yystack_[1].value.as< IR::Expression* > ())); }
#line 3001 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 97:
#line 502 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::V1Parser* > ()=yystack_[3].value.as< IR::V1Parser* > ())->default_return = IR::ID(yystack_[1].location, yystack_[1].value.as< IR::ID > ()); }
#line 3007 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 98:
#line 504 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::V1Parser* > ()=yystack_[8].value.as< IR::V1Parser* > ())->select = yystack_[4].value.as< IR::Vector<IR::Expression>* > (); yylhs.value.as< IR::V1Parser* > ()->cases = yystack_[1].value.as< IR::Vector<IR::CaseEntry>* > (); }
#line 3013 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 99:
#line 506 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::V1Parser* > ()=yystack_[3].value.as< IR::V1Parser* > ())->parse_error = IR::ID(yystack_[1].location, yystack_[1].value.as< IR::ID > ()); }
#line 3019 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 100:
#line 508 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::V1Parser* > ()=yystack_[2].value.as< IR::V1Parser* > ())->drop = true; }
#line 3025 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 101:
#line 509 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::V1Parser* > () = yystack_[2].value.as< IR::V1Parser* > (); }
#line 3031 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 102:
#line 510 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::V1Parser* > () = yystack_[1].value.as< IR::V1Parser* > (); }
#line 3037 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 103:
#line 513 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::CaseEntry>* > () = new IR::Vector<IR::CaseEntry>; }
#line 3043 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 104:
#line 515 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yystack_[3].value.as< IR::CaseEntry* > ()->action = IR::ID(yystack_[1].location, yystack_[1].value.as< IR::ID > ()); yystack_[4].value.as< IR::Vector<IR::CaseEntry>* > ()->srcInfo += yystack_[3].location + yystack_[1].location; (yylhs.value.as< IR::Vector<IR::CaseEntry>* > ()=yystack_[4].value.as< IR::Vector<IR::CaseEntry>* > ())->push_back(yystack_[3].value.as< IR::CaseEntry* > ()); }
#line 3049 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 105:
#line 517 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yystack_[3].value.as< IR::CaseEntry* > ()->action = IR::ID(yystack_[1].location, yystack_[1].value.as< cstring > ()); yystack_[4].value.as< IR::Vector<IR::CaseEntry>* > ()->srcInfo += yystack_[3].location + yystack_[1].location; (yylhs.value.as< IR::Vector<IR::CaseEntry>* > ()=yystack_[4].value.as< IR::Vector<IR::CaseEntry>* > ())->push_back(yystack_[3].value.as< IR::CaseEntry* > ()); }
#line 3055 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 106:
#line 521 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::CaseEntry* > () = new IR::CaseEntry(yystack_[0].location);
                   yylhs.value.as< IR::CaseEntry* > ()->values.emplace_back(yystack_[0].value.as< CaseValue > ()); }
#line 3062 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 107:
#line 523 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::CaseEntry* > ()=yystack_[2].value.as< IR::CaseEntry* > ())->values.emplace_back(yystack_[0].value.as< CaseValue > ());
                                       yylhs.value.as< IR::CaseEntry* > ()->srcInfo += yystack_[0].location; }
#line 3069 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 108:
#line 529 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< CaseValue > () = CaseValue(yystack_[0].value.as< IR::Expression* > () ? yystack_[0].value.as< IR::Expression* > () : new IR::Constant(-1), new IR::Constant(-1)); }
#line 3075 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 109:
#line 531 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< CaseValue > () = CaseValue(yystack_[2].value.as< IR::Expression* > () ? yystack_[2].value.as< IR::Expression* > () : new IR::Constant(-1), yystack_[0].value.as< IR::Constant* > () ? yystack_[0].value.as< IR::Constant* > () : new IR::Constant(0)); }
#line 3081 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 110:
#line 533 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< CaseValue > () = CaseValue(new IR::Constant(0), new IR::Constant(0)); }
#line 3087 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 111:
#line 541 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    {
          driver.clearPragmas();
          ::warning(ErrorType::WARN_UNSUPPORTED,
                    "%1%: parser exception is not translated to P4-16", yystack_[4].value.as< cstring > ());
      }
#line 3097 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 113:
#line 554 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yystack_[1].value.as< IR::Counter* > ()->name = IR::ID(yystack_[3].location, yystack_[3].value.as< IR::ID > ()); yystack_[1].value.as< IR::Counter* > ()->srcInfo = yystack_[4].location + yystack_[0].location; driver.global->add(yystack_[3].value.as< IR::ID > (), yystack_[1].value.as< IR::Counter* > ()); }
#line 3103 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 115:
#line 560 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Counter* > () = new IR::Counter(driver.takePragmasAsAnnotations()))->settype(yystack_[1].value.as< IR::ID > ()); }
#line 3109 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 116:
#line 562 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { if ((yylhs.value.as< IR::Counter* > ()=yystack_[4].value.as< IR::Counter* > ())->table)
            ::error(ErrorType::ERR_INVALID, "%s: Can't attach counter to two tables", yystack_[3].location+yystack_[1].location);
        yylhs.value.as< IR::Counter* > ()->table = IR::ID(yystack_[1].location, yystack_[1].value.as< IR::ID > ());
        yylhs.value.as< IR::Counter* > ()->direct = true; }
#line 3118 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 117:
#line 567 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { if ((yylhs.value.as< IR::Counter* > ()=yystack_[4].value.as< IR::Counter* > ())->table)
            ::error(ErrorType::ERR_INVALID, "%s: Can't attach counter to two tables", yystack_[3].location+yystack_[1].location);
        yylhs.value.as< IR::Counter* > ()->table = IR::ID(yystack_[1].location, yystack_[1].value.as< IR::ID > ());
        yylhs.value.as< IR::Counter* > ()->direct = false; }
#line 3127 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 118:
#line 572 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Counter* > ()=yystack_[4].value.as< IR::Counter* > ())->instance_count = yystack_[1].value.as< IR::Constant* > () ? yystack_[1].value.as< IR::Constant* > ()->asLong() : 0; yystack_[1].value.as< IR::Constant* > () = nullptr; }
#line 3133 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 119:
#line 574 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Counter* > ()=yystack_[4].value.as< IR::Counter* > ())->max_width = yystack_[1].value.as< IR::Constant* > () ? yystack_[1].value.as< IR::Constant* > ()->asLong() : 0; yystack_[1].value.as< IR::Constant* > () = nullptr; }
#line 3139 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 120:
#line 576 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Counter* > ()=yystack_[4].value.as< IR::Counter* > ())->min_width = yystack_[1].value.as< IR::Constant* > () ? yystack_[1].value.as< IR::Constant* > ()->asLong() : 0; yystack_[1].value.as< IR::Constant* > () = nullptr; }
#line 3145 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 121:
#line 578 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Counter* > ()=yystack_[2].value.as< IR::Counter* > ())->saturating = true; }
#line 3151 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 122:
#line 579 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Counter* > () = yystack_[2].value.as< IR::Counter* > (); }
#line 3157 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 123:
#line 580 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Counter* > () = yystack_[1].value.as< IR::Counter* > (); }
#line 3163 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 124:
#line 588 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yystack_[1].value.as< IR::Meter* > ()->name = IR::ID(yystack_[3].location, yystack_[3].value.as< IR::ID > ()); yystack_[1].value.as< IR::Meter* > ()->srcInfo = yystack_[4].location + yystack_[0].location;
        driver.global->add(yystack_[3].value.as< IR::ID > (), yystack_[1].value.as< IR::Meter* > ()); }
#line 3170 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 126:
#line 595 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Meter* > () = new IR::Meter(driver.takePragmasAsAnnotations()))->settype(yystack_[1].value.as< IR::ID > ()); }
#line 3176 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 127:
#line 597 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Meter* > ()=yystack_[4].value.as< IR::Meter* > ())->result = yystack_[1].value.as< IR::Member* > (); }
#line 3182 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 128:
#line 599 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Meter* > ()=yystack_[4].value.as< IR::Meter* > ())->pre_color = yystack_[1].value.as< IR::Member* > (); }
#line 3188 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 129:
#line 601 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { if ((yylhs.value.as< IR::Meter* > ()=yystack_[4].value.as< IR::Meter* > ())->table)
            ::error(ErrorType::ERR_INVALID, "%s: Can't attach meter to two tables", yystack_[3].location+yystack_[1].location);
        yylhs.value.as< IR::Meter* > ()->table = IR::ID(yystack_[1].location, yystack_[1].value.as< IR::ID > ());
        yylhs.value.as< IR::Meter* > ()->direct = true; }
#line 3197 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 130:
#line 606 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { if ((yylhs.value.as< IR::Meter* > ()=yystack_[4].value.as< IR::Meter* > ())->table)
            ::error(ErrorType::ERR_INVALID, "%s: Can't attach meter to two tables", yystack_[3].location+yystack_[1].location);
        yylhs.value.as< IR::Meter* > ()->table = IR::ID(yystack_[1].location, yystack_[1].value.as< IR::ID > ());
        yylhs.value.as< IR::Meter* > ()->direct = false; }
#line 3206 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 131:
#line 611 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Meter* > ()=yystack_[4].value.as< IR::Meter* > ())->instance_count = yystack_[1].value.as< IR::Constant* > () ? yystack_[1].value.as< IR::Constant* > ()->asLong() : 0; yystack_[1].value.as< IR::Constant* > () = nullptr; }
#line 3212 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 132:
#line 613 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Meter* > ()=yystack_[4].value.as< IR::Meter* > ())->implementation = IR::ID(yystack_[1].location, yystack_[1].value.as< IR::ID > ()); }
#line 3218 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 133:
#line 614 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Meter* > () = yystack_[2].value.as< IR::Meter* > (); }
#line 3224 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 134:
#line 615 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Meter* > () = yystack_[1].value.as< IR::Meter* > (); }
#line 3230 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 135:
#line 623 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yystack_[1].value.as< IR::Register* > ()->name = IR::ID(yystack_[3].location, yystack_[3].value.as< IR::ID > ());
        yystack_[1].value.as< IR::Register* > ()->srcInfo = yystack_[4].location + yystack_[0].location;
        driver.global->add(yystack_[3].value.as< IR::ID > (), yystack_[1].value.as< IR::Register* > ()); }
#line 3238 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 137:
#line 631 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Register* > () = new IR::Register(driver.takePragmasAsAnnotations());
        yylhs.value.as< IR::Register* > ()->width = yystack_[1].value.as< IR::Constant* > () ? yystack_[1].value.as< IR::Constant* > ()->asLong() : 0;
        yystack_[1].value.as< IR::Constant* > () = nullptr; }
#line 3246 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 138:
#line 635 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Register* > () = new IR::Register(driver.takePragmasAsAnnotations());
        yylhs.value.as< IR::Register* > ()->layout = IR::ID(yystack_[1].location, yystack_[1].value.as< IR::ID > ()); }
#line 3253 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 139:
#line 638 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { if ((yylhs.value.as< IR::Register* > ()=yystack_[4].value.as< IR::Register* > ())->table)
            ::error(ErrorType::ERR_INVALID, "%s: Can't attach register to two tables", yystack_[3].location+yystack_[1].location);
        yylhs.value.as< IR::Register* > ()->table = IR::ID(yystack_[1].location, yystack_[1].value.as< IR::ID > ());
        yylhs.value.as< IR::Register* > ()->direct = true; }
#line 3262 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 140:
#line 643 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { if ((yylhs.value.as< IR::Register* > ()=yystack_[4].value.as< IR::Register* > ())->table)
            ::error(ErrorType::ERR_INVALID, "%s: Can't attach register to two tables", yystack_[3].location+yystack_[1].location);
        yylhs.value.as< IR::Register* > ()->table = IR::ID(yystack_[1].location, yystack_[1].value.as< IR::ID > ());
        yylhs.value.as< IR::Register* > ()->direct = false; }
#line 3271 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 141:
#line 648 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Register* > ()=yystack_[4].value.as< IR::Register* > ())->instance_count = yystack_[1].value.as< IR::Constant* > () ? yystack_[1].value.as< IR::Constant* > ()->asLong() : 0; yystack_[1].value.as< IR::Constant* > () = nullptr; }
#line 3277 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 142:
#line 650 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Register* > ()=yystack_[4].value.as< IR::Register* > ())->signed_ = yystack_[1].value.as< Attributes > ().signed_;
        yystack_[4].value.as< IR::Register* > ()->saturating = yystack_[1].value.as< Attributes > ().saturating; }
#line 3284 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 143:
#line 652 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Register* > () = yystack_[2].value.as< IR::Register* > (); }
#line 3290 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 144:
#line 653 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Register* > () = yystack_[1].value.as< IR::Register* > (); }
#line 3296 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 145:
#line 662 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { driver.clearPragmas(); yystack_[2].value.as< IR::NameList* > () = nullptr; }
#line 3302 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 146:
#line 665 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::NameList* > () = new IR::NameList(yystack_[0].location, yystack_[0].value.as< IR::ID > ()); }
#line 3308 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 147:
#line 666 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::NameList* > ()=yystack_[2].value.as< IR::NameList* > ())->names.emplace_back(yystack_[0].location, yystack_[0].value.as< IR::ID > ());
                           yylhs.value.as< IR::NameList* > ()->srcInfo = yystack_[2].location + yystack_[0].location; }
#line 3315 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 148:
#line 670 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::NameList* > () = nullptr; }
#line 3321 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 149:
#line 671 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::NameList* > () = yystack_[0].value.as< IR::NameList* > (); }
#line 3327 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 150:
#line 680 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yystack_[0].value.as< IR::ActionFunction* > ()->name = IR::ID(yystack_[4].location, yystack_[4].value.as< IR::ID > ());
        if (yystack_[2].value.as< IR::NameList* > ()) for (auto &arg : yystack_[2].value.as< IR::NameList* > ()->names)
            yystack_[0].value.as< IR::ActionFunction* > ()->args.push_back(new IR::ActionArg(yystack_[4].value.as< IR::ID > (), arg));
        yystack_[2].value.as< IR::NameList* > () = nullptr;
        yystack_[0].value.as< IR::ActionFunction* > ()->srcInfo = yystack_[5].location + yystack_[0].location;
        driver.global->add(yystack_[4].value.as< IR::ID > (), yystack_[0].value.as< IR::ActionFunction* > ()); }
#line 3338 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 151:
#line 689 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ActionFunction* > () = yystack_[1].value.as< IR::ActionFunction* > (); }
#line 3344 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 152:
#line 690 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ActionFunction* > () = yystack_[2].value.as< IR::ActionFunction* > (); }
#line 3350 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 153:
#line 694 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ActionFunction* > () = new IR::ActionFunction(driver.takePragmasAsAnnotations()); }
#line 3356 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 154:
#line 696 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::ActionFunction* > () = yystack_[5].value.as< IR::ActionFunction* > ())->action.push_back(new IR::Primitive(yystack_[4].location+yystack_[1].location, yystack_[4].value.as< IR::ID > (), yystack_[2].value.as< IR::Vector<IR::Expression>* > ())); }
#line 3362 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 155:
#line 698 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::ActionFunction* > () = yystack_[4].value.as< IR::ActionFunction* > ())->action.push_back(new IR::Primitive(yystack_[2].location, "modify_field", yystack_[3].value.as< IR::Member* > (), yystack_[1].value.as< IR::Expression* > ())); }
#line 3368 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 156:
#line 700 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::ActionFunction* > () = yystack_[5].value.as< IR::ActionFunction* > ())->action.push_back(new IR::Primitive(yystack_[4].location+yystack_[1].location, yystack_[4].value.as< IR::Member* > ()->member, yystack_[4].value.as< IR::Member* > ()->expr, yystack_[2].value.as< IR::Vector<IR::Expression>* > ())); }
#line 3374 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 157:
#line 702 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ActionFunction* > () = yystack_[2].value.as< IR::ActionFunction* > (); }
#line 3380 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 158:
#line 704 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ActionFunction* > () = yystack_[1].value.as< IR::ActionFunction* > (); }
#line 3386 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 159:
#line 712 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yystack_[1].value.as< IR::ActionProfile* > ()->name = IR::ID(yystack_[3].location, yystack_[3].value.as< IR::ID > ()); yystack_[1].value.as< IR::ActionProfile* > ()->srcInfo = yystack_[4].location + yystack_[0].location; driver.global->add(yystack_[3].value.as< IR::ID > (), yystack_[1].value.as< IR::ActionProfile* > ()); }
#line 3392 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 160:
#line 716 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ActionProfile* > () = new IR::ActionProfile(driver.takePragmasAsAnnotations()); }
#line 3398 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 161:
#line 718 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::ActionProfile* > ()=yystack_[4].value.as< IR::ActionProfile* > ())->actions = yystack_[1].value.as< IR::NameList* > ()->names; yystack_[1].value.as< IR::NameList* > () = nullptr; }
#line 3404 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 162:
#line 720 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::ActionProfile* > ()=yystack_[4].value.as< IR::ActionProfile* > ())->size = yystack_[1].value.as< IR::Constant* > () ? yystack_[1].value.as< IR::Constant* > ()->asLong() : 0; yystack_[1].value.as< IR::Constant* > () = nullptr; }
#line 3410 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 163:
#line 722 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::ActionProfile* > ()=yystack_[4].value.as< IR::ActionProfile* > ())->selector = IR::ID(yystack_[1].location, yystack_[1].value.as< IR::ID > ()); }
#line 3416 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 164:
#line 726 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yystack_[1].value.as< IR::ActionSelector* > ()->name = IR::ID(yystack_[3].location, yystack_[3].value.as< IR::ID > ()); yystack_[1].value.as< IR::ActionSelector* > ()->srcInfo = yystack_[4].location + yystack_[0].location; driver.global->add(yystack_[3].value.as< IR::ID > (), yystack_[1].value.as< IR::ActionSelector* > ()); }
#line 3422 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 165:
#line 730 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ActionSelector* > () = new IR::ActionSelector(driver.takePragmasAsAnnotations()); }
#line 3428 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 166:
#line 731 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::ActionSelector* > ()=yystack_[4].value.as< IR::ActionSelector* > ())->key = IR::ID(yystack_[1].location, yystack_[1].value.as< IR::ID > ()); }
#line 3434 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 167:
#line 732 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::ActionSelector* > ()=yystack_[4].value.as< IR::ActionSelector* > ())->mode = IR::ID(yystack_[1].location, yystack_[1].value.as< IR::ID > ()); }
#line 3440 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 168:
#line 733 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::ActionSelector* > ()=yystack_[4].value.as< IR::ActionSelector* > ())->type = IR::ID(yystack_[1].location, yystack_[1].value.as< IR::ID > ()); }
#line 3446 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 169:
#line 741 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yystack_[1].value.as< IR::V1Table* > ()->name = IR::ID(yystack_[3].location, yystack_[3].value.as< IR::ID > ());
        yystack_[1].value.as< IR::V1Table* > ()->srcInfo = yystack_[4].location + yystack_[0].location;
        driver.global->add(yystack_[3].value.as< IR::ID > (), yystack_[1].value.as< IR::V1Table* > ()); }
#line 3454 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 171:
#line 748 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::V1Table* > () = new IR::V1Table(driver.takePragmasAsAnnotations()); }
#line 3460 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 172:
#line 750 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::V1Table* > ()=yystack_[4].value.as< IR::V1Table* > ())->reads = yystack_[1].value.as< IR::Vector<IR::Expression>* > (); }
#line 3466 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 173:
#line 752 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::V1Table* > ()=yystack_[5].value.as< IR::V1Table* > ())->reads = yystack_[2].value.as< IR::Vector<IR::Expression>* > (); }
#line 3472 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 174:
#line 754 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::V1Table* > ()=yystack_[4].value.as< IR::V1Table* > ())->actions = yystack_[1].value.as< IR::NameList* > ()->names; yystack_[1].value.as< IR::NameList* > () = nullptr; }
#line 3478 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 175:
#line 756 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::V1Table* > ()=yystack_[4].value.as< IR::V1Table* > ())->action_profile = IR::ID(yystack_[1].location, yystack_[1].value.as< IR::ID > ()); }
#line 3484 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 176:
#line 758 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::V1Table* > ()=yystack_[4].value.as< IR::V1Table* > ())->min_size = yystack_[1].value.as< IR::Constant* > () ? yystack_[1].value.as< IR::Constant* > ()->asLong() : 0; yystack_[1].value.as< IR::Constant* > () = nullptr; }
#line 3490 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 177:
#line 760 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::V1Table* > ()=yystack_[4].value.as< IR::V1Table* > ())->max_size = yystack_[1].value.as< IR::Constant* > () ? yystack_[1].value.as< IR::Constant* > ()->asLong() : 0; yystack_[1].value.as< IR::Constant* > () = nullptr; }
#line 3496 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 178:
#line 762 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::V1Table* > ()=yystack_[4].value.as< IR::V1Table* > ())->size = yystack_[1].value.as< IR::Constant* > () ? yystack_[1].value.as< IR::Constant* > ()->asLong() : 0; yystack_[1].value.as< IR::Constant* > () = nullptr; }
#line 3502 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 179:
#line 764 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::V1Table* > ()=yystack_[4].value.as< IR::V1Table* > ())->default_action = IR::ID(yystack_[1].location, yystack_[1].value.as< IR::ID > ()); }
#line 3508 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 180:
#line 766 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::V1Table* > ()=yystack_[7].value.as< IR::V1Table* > ())->default_action = IR::ID(yystack_[4].location, yystack_[4].value.as< IR::ID > ());
          if (yystack_[2].value.as< IR::Vector<IR::Expression>* > () == nullptr) yylhs.value.as< IR::V1Table* > ()->default_action_is_const = true;
          yylhs.value.as< IR::V1Table* > ()->default_action_args = yystack_[2].value.as< IR::Vector<IR::Expression>* > (); }
#line 3516 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 181:
#line 770 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::V1Table* > ()=yystack_[5].value.as< IR::V1Table* > ())->default_action = IR::ID(yystack_[1].location, yystack_[1].value.as< IR::ID > ());
          yylhs.value.as< IR::V1Table* > ()->default_action_is_const = true; }
#line 3523 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 182:
#line 773 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::V1Table* > ()=yystack_[8].value.as< IR::V1Table* > ())->default_action = IR::ID(yystack_[4].location, yystack_[4].value.as< IR::ID > ());
          yylhs.value.as< IR::V1Table* > ()->default_action_args = yystack_[2].value.as< IR::Vector<IR::Expression>* > ();
	  yylhs.value.as< IR::V1Table* > ()->default_action_is_const = true; }
#line 3531 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 183:
#line 777 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { auto exp = new IR::ExpressionValue(yystack_[1].location, yystack_[1].value.as< IR::Expression* > ());
        auto prop = new IR::Property(yystack_[3].location, IR::ID(yystack_[3].location, yystack_[3].value.as< cstring > ()), exp, false);
        yystack_[4].value.as< IR::V1Table* > ()->addProperty(prop);
        yylhs.value.as< IR::V1Table* > () = yystack_[4].value.as< IR::V1Table* > (); }
#line 3540 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 184:
#line 781 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::V1Table* > ()=yystack_[2].value.as< IR::V1Table* > (); }
#line 3546 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 185:
#line 782 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::V1Table* > ()=yystack_[1].value.as< IR::V1Table* > (); }
#line 3552 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 186:
#line 785 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = new IR::Vector<IR::Expression>(); }
#line 3558 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 187:
#line 787 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Vector<IR::Expression>* > ()=yystack_[4].value.as< IR::Vector<IR::Expression>* > ())->push_back(yystack_[3].value.as< IR::Expression* > ());
        yylhs.value.as< IR::Vector<IR::Expression>* > ()->srcInfo += yystack_[3].location + yystack_[1].location;
        yystack_[(5) - (-2)].value.as< IR::V1Table* > ()->reads_types.push_back(IR::ID(yystack_[1].location, yystack_[1].value.as< IR::ID > ())); }
#line 3566 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 188:
#line 791 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Vector<IR::Expression>* > ()=yystack_[4].value.as< IR::Vector<IR::Expression>* > ())->push_back(new IR::Primitive(yystack_[3].location+yystack_[1].location, yystack_[1].value.as< cstring > (), yystack_[3].value.as< IR::Expression* > ()));
        yylhs.value.as< IR::Vector<IR::Expression>* > ()->srcInfo += yystack_[3].location + yystack_[1].location;
        yystack_[(5) - (-2)].value.as< IR::V1Table* > ()->reads_types.push_back(IR::ID(yystack_[1].location, yystack_[1].value.as< cstring > ())); }
#line 3574 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 189:
#line 795 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Vector<IR::Expression>* > ()=yystack_[4].value.as< IR::Vector<IR::Expression>* > ())->push_back(new IR::Primitive(yystack_[3].location+yystack_[1].location, yystack_[1].value.as< cstring > (), removeRedundantValid(yystack_[3].value.as< IR::Expression* > ())));
        yylhs.value.as< IR::Vector<IR::Expression>* > ()->srcInfo += yystack_[3].location + yystack_[1].location;
        yystack_[(5) - (-2)].value.as< IR::V1Table* > ()->reads_types.push_back(IR::ID(yystack_[1].location, yystack_[1].value.as< cstring > ())); }
#line 3582 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 190:
#line 798 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = yystack_[2].value.as< IR::Vector<IR::Expression>* > (); }
#line 3588 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 191:
#line 799 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = yystack_[1].value.as< IR::Vector<IR::Expression>* > (); }
#line 3594 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 192:
#line 803 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = yystack_[0].value.as< IR::Member* > (); }
#line 3600 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 193:
#line 805 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Mask(yystack_[1].location, yystack_[2].value.as< IR::Member* > (), yystack_[0].value.as< IR::Constant* > ()); }
#line 3606 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 194:
#line 807 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Primitive(yystack_[2].location+yystack_[0].location, yystack_[0].value.as< cstring > (), yystack_[2].value.as< IR::Expression* > ()); }
#line 3612 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 195:
#line 809 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Mask(yystack_[1].location, new IR::Primitive(yystack_[4].location+yystack_[2].location, yystack_[2].value.as< cstring > (), yystack_[4].value.as< IR::Expression* > ()), yystack_[0].value.as< IR::Constant* > ()); }
#line 3618 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 196:
#line 812 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::NameList* > () = new IR::NameList(); }
#line 3624 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 197:
#line 813 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::NameList* > ()=yystack_[2].value.as< IR::NameList* > ())->names.emplace_back(yystack_[1].location, yystack_[1].value.as< IR::ID > ()); }
#line 3630 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 198:
#line 821 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { driver.global->add(yystack_[3].value.as< IR::ID > (), new IR::V1Control(yystack_[4].location+yystack_[0].location, IR::ID(yystack_[3].location, yystack_[3].value.as< IR::ID > ()), yystack_[1].value.as< IR::Vector<IR::Expression>* > (),
                                                 driver.takePragmasAsAnnotations())); }
#line 3637 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 200:
#line 826 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = new IR::Vector<IR::Expression>; }
#line 3643 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 201:
#line 827 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Vector<IR::Expression>* > ()=yystack_[1].value.as< IR::Vector<IR::Expression>* > ())->append(*yystack_[0].value.as< IR::Vector<IR::Expression>* > ()); }
#line 3649 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 202:
#line 828 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = yystack_[2].value.as< IR::Vector<IR::Expression>* > (); }
#line 3655 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 203:
#line 829 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = yystack_[1].value.as< IR::Vector<IR::Expression>* > (); }
#line 3661 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 204:
#line 834 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = new IR::Vector<IR::Expression>(new IR::Apply(yystack_[4].location+yystack_[1].location, IR::ID(yystack_[2].location, yystack_[2].value.as< IR::ID > ()))); }
#line 3667 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 205:
#line 836 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yystack_[1].value.as< IR::Apply* > ()->name = IR::ID(yystack_[4].location, yystack_[4].value.as< IR::ID > ()); yystack_[1].value.as< IR::Apply* > ()->srcInfo = yystack_[6].location+yystack_[3].location; yylhs.value.as< IR::Vector<IR::Expression>* > () = new IR::Vector<IR::Expression>(yystack_[1].value.as< IR::Apply* > ()); }
#line 3673 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 206:
#line 838 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = new IR::Vector<IR::Expression>(new IR::If(yystack_[4].location+yystack_[2].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Vector<IR::Expression>* > (), nullptr)); }
#line 3679 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 207:
#line 840 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = new IR::Vector<IR::Expression>(new IR::If(yystack_[6].location+yystack_[4].location, yystack_[4].value.as< IR::Expression* > (), yystack_[2].value.as< IR::Vector<IR::Expression>* > (), yystack_[0].value.as< IR::Vector<IR::Expression>* > ())); }
#line 3685 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 208:
#line 842 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = new IR::Vector<IR::Expression>(new IR::Primitive(yystack_[3].location+yystack_[1].location, yystack_[3].value.as< IR::ID > ())); }
#line 3691 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 209:
#line 844 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = yystack_[1].value.as< IR::Vector<IR::Expression>* > (); }
#line 3697 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 210:
#line 847 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Apply* > () = new IR::Apply; }
#line 3703 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 211:
#line 849 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { for (auto name : yystack_[1].value.as< IR::NameList* > ()->names)
              yystack_[2].value.as< IR::Apply* > ()->actions[name] = yystack_[0].value.as< IR::Vector<IR::Expression>* > ();
          yylhs.value.as< IR::Apply* > () = yystack_[2].value.as< IR::Apply* > (); }
#line 3711 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 212:
#line 853 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Apply* > ()=yystack_[2].value.as< IR::Apply* > ())->actions["default"] = yystack_[0].value.as< IR::Vector<IR::Expression>* > (); }
#line 3717 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 213:
#line 861 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { driver.global->add(yystack_[3].value.as< IR::ID > (),
          new IR::Type_Extern(yystack_[4].location+yystack_[0].location, IR::ID(yystack_[3].location, yystack_[3].value.as< IR::ID > ()), *yystack_[1].value.as< BBoxType > ().methods,
                              *yystack_[1].value.as< BBoxType > ().attribs, driver.takePragmasAsAnnotations())); }
#line 3725 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 214:
#line 866 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    {
            yylhs.value.as< BBoxType > ().methods = new IR::Vector<IR::Method>;
            yylhs.value.as< BBoxType > ().attribs = new IR::NameMap<IR::Attribute, ordered_map>; }
#line 3733 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 215:
#line 870 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< BBoxType > ()=yystack_[5].value.as< BBoxType > ()).attribs->addUnique(yystack_[3].value.as< IR::ID > (), yystack_[1].value.as< IR::Attribute* > ()); }
#line 3739 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 216:
#line 872 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< BBoxType > ()=yystack_[6].value.as< BBoxType > ()).methods->push_back(new IR::Method(yystack_[5].location+yystack_[4].location, yystack_[4].value.as< IR::ID > (),
                new IR::Type_Method(yystack_[3].location+yystack_[1].location, IR::Type::Void::get(), yystack_[2].value.as< IR::ParameterList* > (), yystack_[4].value.as< IR::ID > ()))); }
#line 3746 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 217:
#line 875 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< BBoxType > ()=yystack_[8].value.as< BBoxType > ()).methods->push_back(new IR::Method(yystack_[7].location+yystack_[6].location, yystack_[6].value.as< IR::ID > (),
                new IR::Type_Method(yystack_[5].location+yystack_[3].location, IR::Type::Void::get(), yystack_[4].value.as< IR::ParameterList* > (), yystack_[6].value.as< IR::ID > ()), yystack_[1].value.as< IR::Annotations* > ())); }
#line 3753 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 218:
#line 877 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< BBoxType > () = yystack_[1].value.as< BBoxType > (); }
#line 3759 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 219:
#line 880 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Attribute* > () = new IR::Attribute(yystack_[(0) - (-1)].value.as< IR::ID > ()); }
#line 3765 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 220:
#line 881 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Attribute* > ()=yystack_[4].value.as< IR::Attribute* > ())->type = yystack_[1].value.as< ConstType* > (); }
#line 3771 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 221:
#line 883 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Attribute* > ()=yystack_[4].value.as< IR::Attribute* > ())->locals = yystack_[1].value.as< IR::AttribLocals* > (); }
#line 3777 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 222:
#line 885 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Attribute* > ()=yystack_[2].value.as< IR::Attribute* > ())->optional = true; }
#line 3783 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 223:
#line 886 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Attribute* > () = yystack_[2].value.as< IR::Attribute* > (); }
#line 3789 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 224:
#line 887 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Attribute* > () = yystack_[1].value.as< IR::Attribute* > (); }
#line 3795 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 225:
#line 890 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Annotations* > () = new IR::Annotations; }
#line 3801 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 226:
#line 892 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Annotations* > ()=yystack_[4].value.as< IR::Annotations* > ())->add(new IR::Annotation(yystack_[3].location, yystack_[3].value.as< cstring > (), driver.makeExpressionList(yystack_[1].value.as< IR::NameList* > ()))); }
#line 3807 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 227:
#line 894 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Annotations* > ()=yystack_[4].value.as< IR::Annotations* > ())->add(new IR::Annotation(yystack_[3].location, yystack_[3].value.as< cstring > (), driver.makeExpressionList(yystack_[1].value.as< IR::NameList* > ()))); }
#line 3813 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 228:
#line 898 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ParameterList* > () = new IR::ParameterList; }
#line 3819 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 229:
#line 899 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ParameterList* > () = yystack_[0].value.as< IR::ParameterList* > (); }
#line 3825 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 230:
#line 903 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ParameterList* > () = new IR::ParameterList({yystack_[0].value.as< IR::Parameter* > ()}); }
#line 3831 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 231:
#line 904 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::ParameterList* > ()=yystack_[2].value.as< IR::ParameterList* > ())->push_back(yystack_[0].value.as< IR::Parameter* > ()); }
#line 3837 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 232:
#line 909 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Parameter* > () = new IR::Parameter(yystack_[0].location, yystack_[0].value.as< IR::ID > (), yystack_[2].value.as< IR::Direction > (), yystack_[1].value.as< ConstType* > ()); }
#line 3843 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 233:
#line 911 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Parameter* > () = yystack_[0].value.as< IR::Parameter* > ())->annotations = yystack_[0].value.as< IR::Parameter* > ()->annotations->add(new IR::Annotation(yystack_[1].location, yystack_[1].value.as< cstring > (), {})); }
#line 3849 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 234:
#line 914 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Direction > () = IR::Direction::In; }
#line 3855 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 235:
#line 914 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Direction > () = IR::Direction::Out; }
#line 3861 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 236:
#line 916 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::AttribLocals* > () = nullptr; }
#line 3867 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 238:
#line 918 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::AttribLocals* > () = new IR::AttribLocals())->locals[yystack_[0].value.as< IR::AttribLocal* > ()->name] = yystack_[0].value.as< IR::AttribLocal* > (); }
#line 3873 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 239:
#line 919 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::AttribLocals* > () = yystack_[2].value.as< IR::AttribLocals* > ())->locals[yystack_[0].value.as< IR::AttribLocal* > ()->name] = yystack_[0].value.as< IR::AttribLocal* > (); }
#line 3879 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 240:
#line 922 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::AttribLocal* > () = new IR::AttribLocal(yystack_[0].location, yystack_[0].value.as< IR::ID > ()); }
#line 3885 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 241:
#line 923 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::AttribLocal* > () = new IR::AttribLocal(yystack_[1].location+yystack_[0].location, yystack_[1].value.as< ConstType* > (), yystack_[0].value.as< IR::ID > ()); }
#line 3891 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 242:
#line 928 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { driver.global->add(yystack_[1].value.as< IR::ID > (),
            new IR::Declaration_Instance(yystack_[1].location, yystack_[1].value.as< IR::ID > (), driver.takePragmasAsAnnotations(),
                                         new IR::Type_Name(yystack_[2].value.as< IR::ID > ()),
                                         new IR::Vector<IR::Argument>)); }
#line 3900 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 243:
#line 933 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { auto instance =
            new IR::Declaration_Instance(yystack_[3].location, yystack_[3].value.as< IR::ID > (), driver.takePragmasAsAnnotations(),
                                         new IR::Type_Name(yystack_[4].value.as< IR::ID > ()),
                                         new IR::Vector<IR::Argument>);
          instance->properties = std::move(*yystack_[1].value.as< IR::NameMap<IR::Property>* > ());
          driver.global->add(yystack_[3].value.as< IR::ID > (), instance); }
#line 3911 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 244:
#line 941 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::NameMap<IR::Property>* > () = new IR::NameMap<IR::Property>; }
#line 3917 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 245:
#line 943 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { const IR::PropertyValue *pv;
            if (yystack_[1].value.as< IR::Vector<IR::Expression>* > ()->size() == 1)
                pv = new IR::ExpressionValue(yystack_[1].location, yystack_[1].value.as< IR::Vector<IR::Expression>* > ()->front());
            else
                pv = new IR::ExpressionListValue(yystack_[1].location, std::move(*yystack_[1].value.as< IR::Vector<IR::Expression>* > ()));
            (yylhs.value.as< IR::NameMap<IR::Property>* > ()=yystack_[4].value.as< IR::NameMap<IR::Property>* > ())->add(yystack_[3].value.as< IR::ID > (), new IR::Property(yystack_[3].location+yystack_[1].location, yystack_[3].value.as< IR::ID > (), pv, false)); }
#line 3928 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 246:
#line 950 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { auto *pv = new IR::ExpressionListValue(std::move(*yystack_[1].value.as< IR::Vector<IR::Expression>* > ()));
            (yylhs.value.as< IR::NameMap<IR::Property>* > ()=yystack_[4].value.as< IR::NameMap<IR::Property>* > ())->add(yystack_[3].value.as< IR::ID > (), new IR::Property(yystack_[3].location+yystack_[1].location, yystack_[3].value.as< IR::ID > (), pv, false)); }
#line 3935 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 247:
#line 955 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = new IR::Vector<IR::Expression>; }
#line 3941 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 248:
#line 957 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Vector<IR::Expression>* > ()=yystack_[1].value.as< IR::Vector<IR::Expression>* > ())->push_back(yystack_[0].value.as< IR::Expression* > ()); yylhs.value.as< IR::Vector<IR::Expression>* > ()->srcInfo += yystack_[0].location; }
#line 3947 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 249:
#line 959 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Vector<IR::Expression>* > ()=yystack_[2].value.as< IR::Vector<IR::Expression>* > ())->push_back(yystack_[0].value.as< IR::Expression* > ()); yylhs.value.as< IR::Vector<IR::Expression>* > ()->srcInfo += yystack_[0].location; }
#line 3953 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 250:
#line 961 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Vector<IR::Expression>* > ()=yystack_[4].value.as< IR::Vector<IR::Expression>* > ())->push_back(new IR::Primitive(yystack_[3].location, yystack_[3].value.as< cstring > (), yystack_[1].value.as< IR::Vector<IR::Expression>* > ())); yylhs.value.as< IR::Vector<IR::Expression>* > ()->srcInfo += yystack_[0].location; }
#line 3959 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 251:
#line 965 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = new IR::Vector<IR::Expression>; }
#line 3965 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 252:
#line 967 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Vector<IR::Expression>* > ()=yystack_[1].value.as< IR::Vector<IR::Expression>* > ())->push_back(yystack_[0].value.as< IR::Expression* > ()); yylhs.value.as< IR::Vector<IR::Expression>* > ()->srcInfo += yystack_[0].location; }
#line 3971 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 253:
#line 969 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Vector<IR::Expression>* > ()=yystack_[2].value.as< IR::Vector<IR::Expression>* > ())->push_back(yystack_[0].value.as< IR::Expression* > ()); yylhs.value.as< IR::Vector<IR::Expression>* > ()->srcInfo += yystack_[0].location; }
#line 3977 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 254:
#line 973 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = parseConstant(yystack_[0].location, yystack_[0].value.as< UnparsedConstant > (), 0); }
#line 3983 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 255:
#line 974 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::StringLiteral(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 3989 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 256:
#line 975 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::StringLiteral(yystack_[0].location, yystack_[0].value.as< IR::ID > ()); }
#line 3995 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 257:
#line 976 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::StringLiteral(yystack_[2].location+yystack_[0].location, yystack_[2].value.as< IR::ID > () + '.' + yystack_[0].value.as< IR::ID > ()); }
#line 4001 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 258:
#line 984 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Primitive(yystack_[3].location+yystack_[0].location, yystack_[3].value.as< cstring > (), yystack_[1].value.as< IR::Expression* > ()); }
#line 4007 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 259:
#line 986 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Primitive(yystack_[5].location+yystack_[0].location, yystack_[5].value.as< cstring > (), yystack_[3].value.as< IR::Constant* > (), yystack_[1].value.as< IR::Constant* > ()); }
#line 4013 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 260:
#line 987 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = yystack_[0].value.as< IR::Member* > (); }
#line 4019 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 261:
#line 988 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = yystack_[0].value.as< IR::Expression* > (); }
#line 4025 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 262:
#line 989 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Primitive(yystack_[2].location+yystack_[0].location, yystack_[0].value.as< cstring > (), yystack_[2].value.as< IR::Expression* > ()); }
#line 4031 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 263:
#line 990 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Member(yystack_[2].location+yystack_[0].location,
                                            new IR::PathExpression(IR::ID(yystack_[2].location, yystack_[2].value.as< cstring > ())),
                                            IR::ID(yystack_[0].location, yystack_[0].value.as< IR::ID > ())); }
#line 4039 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 264:
#line 993 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = parseConstant(yystack_[0].location, yystack_[0].value.as< UnparsedConstant > (), 0); }
#line 4045 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 265:
#line 994 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = yystack_[1].value.as< IR::Expression* > (); }
#line 4051 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 266:
#line 995 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::LNot(yystack_[1].location, yystack_[0].value.as< IR::Expression* > ()); }
#line 4057 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 267:
#line 996 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Cmpl(yystack_[1].location, yystack_[0].value.as< IR::Expression* > ()); }
#line 4063 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 268:
#line 997 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Neg(yystack_[1].location, yystack_[0].value.as< IR::Expression* > ()); }
#line 4069 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 269:
#line 998 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = yystack_[0].value.as< IR::Expression* > (); }
#line 4075 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 270:
#line 999 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Mul(yystack_[1].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 4081 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 271:
#line 1000 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Div(yystack_[1].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 4087 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 272:
#line 1001 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Mod(yystack_[1].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 4093 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 273:
#line 1002 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Add(yystack_[1].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 4099 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 274:
#line 1003 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Sub(yystack_[1].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 4105 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 275:
#line 1004 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Shl(yystack_[1].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 4111 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 276:
#line 1005 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Shr(yystack_[1].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 4117 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 277:
#line 1006 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Leq(yystack_[1].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 4123 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 278:
#line 1007 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Geq(yystack_[1].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 4129 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 279:
#line 1008 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Lss(yystack_[1].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 4135 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 280:
#line 1009 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Grt(yystack_[1].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 4141 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 281:
#line 1010 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Neq(yystack_[1].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 4147 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 282:
#line 1011 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::Equ(yystack_[1].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 4153 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 283:
#line 1012 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::BAnd(yystack_[1].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 4159 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 284:
#line 1013 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::BXor(yystack_[1].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 4165 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 285:
#line 1014 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::BOr(yystack_[1].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 4171 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 286:
#line 1015 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::LAnd(yystack_[1].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 4177 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 287:
#line 1016 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::LOr(yystack_[1].location, yystack_[2].value.as< IR::Expression* > (), yystack_[0].value.as< IR::Expression* > ()); }
#line 4183 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 288:
#line 1017 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::BoolLiteral(yystack_[0].location, true); }
#line 4189 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 289:
#line 1018 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::BoolLiteral(yystack_[0].location, false); }
#line 4195 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 290:
#line 1022 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = yystack_[0].value.as< IR::Expression* > (); }
#line 4201 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 291:
#line 1023 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = yystack_[0].value.as< IR::Member* > (); }
#line 4207 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 292:
#line 1027 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::PathExpression(IR::ID(yystack_[0].location, yystack_[0].value.as< IR::ID > ())); }
#line 4213 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 293:
#line 1028 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Expression* > () = new IR::HeaderStackItemRef(yystack_[3].location+yystack_[0].location, yystack_[3].value.as< IR::Expression* > (), yystack_[1].value.as< IR::Expression* > ()); }
#line 4219 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 294:
#line 1032 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Member* > () = new IR::Member(yystack_[2].location+yystack_[0].location, yystack_[2].value.as< IR::Expression* > (), IR::ID(yystack_[0].location, yystack_[0].value.as< IR::ID > ())); }
#line 4225 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 295:
#line 1036 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { if (!(yylhs.value.as< IR::Constant* > () = driver.constantFold(&*yystack_[0].value.as< IR::Expression* > ())))
                ::error(ErrorType::ERR_INVALID, "%s: Non constant expression", yystack_[0].location); }
#line 4232 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 296:
#line 1041 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = new IR::Vector<IR::Expression>(yystack_[0].value.as< IR::Expression* > ()); yylhs.value.as< IR::Vector<IR::Expression>* > ()->srcInfo = yystack_[0].location; }
#line 4238 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 297:
#line 1042 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { (yylhs.value.as< IR::Vector<IR::Expression>* > ()=yystack_[2].value.as< IR::Vector<IR::Expression>* > ())->push_back(yystack_[0].value.as< IR::Expression* > ()); yylhs.value.as< IR::Vector<IR::Expression>* > ()->srcInfo += yystack_[0].location; }
#line 4244 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 298:
#line 1045 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = nullptr; }
#line 4250 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 299:
#line 1045 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::Vector<IR::Expression>* > () = yystack_[0].value.as< IR::Vector<IR::Expression>* > (); }
#line 4256 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 300:
#line 1047 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4262 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 301:
#line 1048 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4268 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 302:
#line 1049 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4274 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 303:
#line 1050 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4280 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 304:
#line 1051 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4286 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 305:
#line 1052 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4292 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 306:
#line 1053 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4298 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 307:
#line 1054 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4304 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 308:
#line 1055 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4310 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 309:
#line 1056 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4316 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 310:
#line 1057 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4322 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 311:
#line 1058 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4328 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 312:
#line 1059 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4334 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 313:
#line 1060 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4340 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 314:
#line 1061 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4346 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 315:
#line 1062 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4352 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 316:
#line 1063 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4358 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 317:
#line 1064 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4364 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 318:
#line 1065 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4370 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 319:
#line 1066 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4376 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 320:
#line 1067 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4382 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 321:
#line 1068 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4388 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 322:
#line 1069 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4394 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 323:
#line 1070 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4400 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 324:
#line 1071 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4406 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 325:
#line 1072 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4412 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 326:
#line 1073 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4418 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 327:
#line 1074 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4424 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 328:
#line 1075 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4430 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 329:
#line 1076 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4436 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 330:
#line 1077 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4442 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 331:
#line 1078 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4448 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 332:
#line 1079 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4454 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 333:
#line 1080 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4460 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 334:
#line 1081 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4466 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 335:
#line 1082 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4472 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 336:
#line 1083 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4478 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 337:
#line 1084 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4484 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 338:
#line 1085 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4490 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 339:
#line 1086 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4496 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 340:
#line 1087 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4502 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 341:
#line 1088 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4508 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 342:
#line 1089 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4514 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 343:
#line 1090 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4520 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 344:
#line 1091 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4526 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 345:
#line 1092 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4532 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 346:
#line 1093 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4538 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 347:
#line 1094 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4544 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 348:
#line 1095 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4550 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 349:
#line 1096 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4556 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 350:
#line 1097 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4562 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 351:
#line 1098 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4568 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 352:
#line 1099 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4574 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 353:
#line 1100 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4580 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 354:
#line 1101 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4586 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 355:
#line 1102 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4592 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 356:
#line 1103 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4598 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 357:
#line 1104 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4604 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 358:
#line 1105 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4610 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 359:
#line 1106 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4616 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 360:
#line 1107 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4622 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 361:
#line 1108 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4628 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 362:
#line 1109 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4634 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 363:
#line 1110 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4640 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 364:
#line 1111 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4646 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 365:
#line 1112 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4652 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 366:
#line 1113 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4658 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 367:
#line 1114 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4664 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 368:
#line 1115 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4670 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 369:
#line 1116 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4676 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 370:
#line 1117 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4682 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;

  case 371:
#line 1118 "parsers/v1/v1parser.ypp" // lalr1.cc:859
    { yylhs.value.as< IR::ID > () = IR::ID(yystack_[0].location, yystack_[0].value.as< cstring > ()); }
#line 4688 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
    break;


#line 4692 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:859
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
  V1Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  V1Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
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


  const short int V1Parser::yypact_ninf_ = -669;

  const short int V1Parser::yytable_ninf_ = -367;

  const short int
  V1Parser::yypact_[] =
  {
    -669,    29,   230,  -669,  -669,  -669,  3713,  3713,  3713,  3713,
    3713,  3713,  3713,  3713,  3713,  3713,  3713,  3713,  3713,  3713,
    3713,  3713,  3713,  -669,  3713,  3713,  3713,  -669,  -669,  -669,
    -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,
    -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,
    -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,
    -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,
    -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,
    -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,
    -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,
    -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,
    -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,    31,
      52,    66,  3713,    86,    17,   127,  -669,   136,   236,    45,
     238,  3713,   239,  3713,   254,   255,    83,   264,  3107,   121,
     276,   277,  3713,  -669,  -669,    68,  -669,  2196,  3713,  -669,
    -669,   -59,  -669,  -669,  -669,    46,    10,   281,   114,  -669,
    -669,  -669,  3195,  -669,  -669,  -669,  -669,   250,  3713,   -42,
    -669,   207,   279,  -669,     6,    57,  -669,  -669,    36,  2196,
    2196,  2196,  2196,  2196,   278,  -669,   292,  -669,   299,  -669,
    4168,   108,  -669,  -669,    20,   928,   312,    41,  1412,    23,
    2196,  -669,   306,    35,  -669,   293,   327,   125,   702,   824,
    -669,  3713,   166,   333,   334,    26,    33,  3713,   342,  -669,
     343,   337,   340,  -669,   344,   346,   347,  2566,  -669,  -669,
    3713,  3713,  -669,  -669,  -669,  4068,  -669,  2196,  3713,  3713,
    2196,  2196,  2196,  2196,  2196,  2196,  2196,  2196,  2196,  2196,
    2196,  2196,  2196,  2196,  2196,  2196,  -669,  2196,  2196,  3283,
      49,  -669,  3713,  3713,    50,  -669,  -669,   348,   351,  -669,
     354,  3713,    53,  -669,   352,   353,   355,   356,   357,   358,
    -669,   359,   573,    59,  -669,   173,   364,   362,  4191,   367,
    -669,   393,  -669,  2656,  -669,  3713,    60,  -669,   366,   368,
     369,   370,   373,   374,    94,  -669,   371,   384,  3713,  3369,
     385,  4010,    96,  -669,  -669,   390,  3713,  2196,   158,  -669,
     398,   400,   406,   409,   182,  -669,   422,   418,   394,   420,
     421,   423,   429,   425,   426,  -669,  -669,  -669,  -669,  3713,
    2196,  3713,  3713,  3713,  -669,   220,   434,   431,  -669,   430,
    -669,   435,    17,  -669,   401,   401,   338,   338,   628,   598,
    4207,  4207,   345,   345,  -669,  -669,  -669,   428,   304,   193,
     401,   401,  -669,  -669,  -669,   399,   399,  -669,  -669,  1032,
    3713,  2196,   439,   437,  -669,  -669,  3713,  2196,  2196,  2196,
    -669,  3713,  -669,  -669,  -669,  -669,  -669,  3713,  -669,  2196,
     438,  1122,  -669,  -669,   443,   440,  -669,  -669,  3713,  3713,
    2196,  3713,  3713,  3713,  -669,  -669,  -669,  3713,   441,   442,
     444,  2196,  2196,  -669,  -669,   445,   447,  -669,  -669,    42,
    3713,  2196,  3713,  -669,  -669,  -669,  3713,   446,  3713,  2196,
    2196,  -669,  2196,  2196,  1212,  2746,   465,   466,   467,   468,
     472,  -669,  -669,  -669,   -34,  2196,  -669,   450,   474,   476,
     478,  -669,   486,  4093,   481,  -669,   482,   483,   484,   485,
     488,  2836,   489,  2926,   490,  -669,   518,   448,   215,   197,
     241,   243,   259,   261,   223,   284,   307,   309,   325,  3713,
     499,  2196,  -669,   498,   500,   501,   502,   503,   504,   242,
    -669,  2196,  -669,  4040,   667,  -669,  -669,  -669,  -669,   183,
    -669,   505,   506,   509,  3016,   510,  3713,   224,   511,   512,
    1302,   513,  3917,   185,  -669,   120,   522,  -669,   516,  -669,
    -669,  -669,  -669,  -669,  1524,  1636,    24,  -669,   -34,  -669,
     523,   521,  -669,   297,   525,  2196,  -669,  -669,   123,  2386,
    -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,   520,
    -669,  -669,   526,   454,   432,   436,   524,  1972,   528,  -669,
    -669,  -669,  -669,  -669,  -669,   529,  4191,   187,  2196,  -669,
      42,  -669,  -669,  -669,  -669,  -669,  -669,   269,  2196,  -669,
    -669,  -669,   191,  -669,   530,    71,   487,  -669,  -669,  -669,
    -669,  2196,  2196,  2196,  -669,  -669,  2196,   537,  4191,  -669,
     532,  -669,   544,   534,   539,  -669,   179,   -34,   545,  -669,
    -669,  -669,  -669,  -669,   546,  -669,  -669,  -669,  -669,  3713,
    -669,  4118,  -669,  -669,   515,  -669,  2196,   542,  -669,   549,
     567,  -669,  -669,   568,  -669,  -669,  -669,   571,  2196,  4143,
    -669,  2196,  -669,   565,   569,  -669,  -669,  3455,   508,  3541,
    2196,   572,  3948,   590,  4191,  -669,  -669,  3799,  -669,   297,
    -669,  -669,  -669,  -669,  -669,  2476,  2386,  3979,  2196,  -669,
    -669,    42,   585,  -669,  4191,   586,   599,   592,   594,   595,
     596,   553,  -669,   602,  -669,   614,  1748,  3713,   577,   618,
    -669,  -669,   617,     1,  -669,  2386,  2295,  -669,  -669,   621,
     206,  -669,  1860,  -669,   622,  -669,  -669,  -669,  -669,  2196,
    -669,  -669,  -669,  -669,  -669,  3799,  -669,  -669,   634,   635,
    -669,  -669,  -669,  -669,  -669,  -669,    15,  -669,   479,  -669,
    -669,  -669,  3713,  3713,  3627,  2084,  2196,   637,   638,   625,
     629,  -669,  -669,  -669,  -669,  -669,  -669
  };

  const unsigned short int
  V1Parser::yydefact_[] =
  {
       3,     0,     0,     1,    25,     2,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   251,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   317,   316,   318,   319,   320,   323,   321,   322,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   300,     0,
       0,     0,     0,     0,     0,     0,   292,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,   160,   165,     0,   214,     0,     0,    83,
     200,     0,    67,    66,    72,     0,     0,    61,     0,    93,
      90,    93,     0,    24,   255,   254,   252,   256,     0,     0,
     171,   149,     0,   146,     0,     0,   244,   242,     0,     0,
       0,     0,     0,     0,     0,   289,     0,   288,     0,   264,
       0,   261,   260,   294,     0,     0,     0,     0,     0,     0,
       0,    58,     0,     0,    63,     0,     0,     0,     0,     0,
     253,     0,     0,     0,     0,     0,     0,     0,     0,   159,
       0,     0,     0,   164,     0,     0,     0,     0,   218,   213,
       0,     0,   269,   268,   267,     0,   266,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   293,     0,     0,     0,
      87,    81,     0,     0,   203,   200,   198,     0,     0,   201,
       0,     0,   123,   113,     0,     0,     0,     0,     0,     0,
      65,     0,     0,    78,    70,     0,     0,     0,   295,     0,
      30,     0,    26,     0,    60,     0,   134,   124,     0,     0,
       0,     0,     0,     0,   102,    91,   319,   323,     0,   356,
     361,     0,   102,   111,   257,     0,     0,     0,   144,   135,
       0,     0,     0,     0,   185,   169,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   147,   153,   150,   196,     0,
       0,     0,     0,     0,   243,     0,     0,     0,   265,     0,
     263,     0,   290,   291,   277,   278,   275,   276,   286,   287,
     281,   282,   273,   274,   270,   271,   272,   285,   283,   284,
     279,   280,   262,    82,    86,    88,    88,   199,   202,     0,
       0,     0,     0,     0,   114,   122,     0,     0,     0,     0,
     121,     0,    69,    68,    71,    77,   196,     0,    79,     0,
       0,     0,    27,    62,     0,     0,   125,   133,     0,     0,
       0,     0,     0,     0,    92,   101,   100,     0,     0,     0,
       0,     0,     0,   112,   145,     0,     0,   136,   143,     0,
       0,     0,     0,   170,   184,   196,     0,     0,     0,     0,
       0,   186,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   247,   247,   219,   228,     0,   258,     0,     0,     0,
     203,   209,     0,     0,     0,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    59,     0,    41,    45,    47,
      48,    49,    50,    51,    52,    54,    56,    55,    57,     0,
       0,     0,   126,     0,     0,     0,     0,     0,     0,     0,
      99,     0,    97,     0,     0,   138,   137,    40,    39,     0,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   158,   151,     0,   292,   161,     0,   163,
     162,   166,   167,   168,     0,     0,     0,   234,     0,   235,
       0,   229,   230,     0,     0,     0,    84,    85,     0,     0,
     208,   116,   118,   119,   120,   117,    75,    74,    73,     0,
      76,    29,     0,    43,     0,     0,     0,     0,     0,   129,
     132,   131,   128,   127,   130,     0,   296,     0,     0,    96,
       0,   142,   139,   141,   140,   174,   175,     0,   298,   179,
     177,   176,   191,   172,     0,     0,   192,   178,   183,   152,
     157,   298,     0,   298,   197,   246,     0,   300,   248,   245,
     224,   215,     0,     0,     0,   233,     0,     0,    45,    47,
      48,    49,    50,    51,    52,    54,    56,    55,    57,     0,
     259,     0,   210,   204,   206,    80,     0,     0,    28,     0,
       0,    32,    34,    35,    33,    64,    94,     0,     0,     0,
      38,   298,   181,   299,     0,   173,   190,     0,     0,     0,
       0,     0,     0,     0,   249,   247,   223,   236,   222,     0,
     225,   216,   231,   232,    89,     0,     0,     0,     0,    46,
      53,     0,     0,   103,   297,     0,     0,     0,     0,     0,
       0,   194,   193,     0,   155,     0,     0,     0,     0,   237,
     238,   240,     0,     0,   205,     0,     0,   207,    42,     0,
       0,    31,     0,    95,     0,   180,   189,   187,   188,     0,
     156,   154,   250,   241,   221,     0,   220,   217,     0,     0,
     212,   211,    44,    36,    98,   110,     0,   106,   108,   182,
     195,   239,   148,   148,     0,     0,     0,     0,     0,     0,
       0,   107,   109,   226,   227,   105,   104
  };

  const short int
  V1Parser::yypgoto_[] =
  {
    -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,   -16,    87,
    -669,  -669,  -384,  -669,  -669,  -669,  -669,  -669,  -669,  -669,
    -669,  -669,  -669,  -669,   290,  -669,  -669,   507,  -669,  -669,
     -57,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -163,
    -668,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,  -669,
    -669,  -669,  -368,  -669,   424,  -519,  -669,  -669,  -669,  -669,
    -669,  -669,  -669,  -506,  -669,  -669,  -669,   -35,  -669,  -669,
    -429,  -669,   533,   -74,  -669,    11,    22,  -197,   195,  -560,
      -6
  };

  const short int
  V1Parser::yydefgoto_[] =
  {
      -1,     1,     2,    27,   203,   401,   643,   682,   509,   510,
     563,   638,   697,    28,    29,   205,   293,    30,   198,    31,
     199,   473,    32,   194,   458,    33,    34,   208,   712,   736,
     737,    35,    36,   197,    37,   207,    38,   215,    39,   171,
     172,    40,   337,   444,    41,   174,    42,   175,    43,   216,
     520,   594,   445,    44,   195,   269,   675,    45,   178,   536,
     703,   540,   541,   542,   543,   698,   699,   700,    46,   227,
     534,   138,   166,   288,   351,   191,   192,   289,   653,   654,
     126
  };

  const short int
  V1Parser::yytable_[] =
  {
     119,   120,   121,   122,   123,   212,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   489,   139,   140,
     141,   260,   124,   535,   283,   610,   727,   318,   471,     3,
     634,   219,   615,   125,   324,   213,   291,   228,   537,   147,
     349,   661,   272,   663,   220,   261,   744,   745,   284,   611,
     148,   319,   373,   377,   538,   539,   384,   196,   325,   142,
     292,   229,   394,   406,   285,   221,   273,   514,   200,   152,
     320,   326,   327,   190,   747,   748,   143,   202,   214,   230,
     153,   201,   223,   321,   374,   378,   328,   612,   385,   329,
     144,   686,   176,   147,   395,   407,   286,   414,   274,   423,
     322,   728,   658,   177,   659,   232,   233,   234,   235,   236,
     146,   672,   613,   287,   330,   275,   145,   222,   160,   331,
     426,   231,   729,   276,   282,   155,   296,   157,   277,   415,
     147,   415,   167,   332,   311,   311,   173,   262,   323,   263,
     614,   259,   193,   447,   333,   278,   507,   632,   601,   168,
     297,   149,   508,   279,   602,   334,   167,   707,   633,   629,
     150,   427,   173,   224,   225,   226,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   298,   370,   371,   433,   730,   731,   599,   270,
     467,   468,   469,   428,   655,   315,   299,   396,   217,   300,
     242,   243,   474,   670,   397,   314,   248,   249,   250,   251,
     252,   335,   254,   495,   671,   580,   647,   434,   581,   648,
     600,   345,  -311,   301,   346,   347,   656,   302,  -311,  -311,
     206,     4,   350,     5,   512,   733,   696,   303,   580,   217,
    -308,   564,   518,   519,   451,   521,  -308,  -308,  -333,   565,
     352,   452,   588,   193,  -333,  -333,   375,   376,   544,   589,
     151,   353,   154,   156,   147,   383,  -312,     6,  -315,     7,
       8,   575,  -312,  -312,  -315,  -315,     9,    10,   158,   159,
      11,    12,    13,   211,  -321,   702,  -325,   404,   161,   405,
    -321,  -321,  -325,  -325,   568,    14,    15,   651,    16,    17,
     169,   170,   418,   420,   652,   204,   237,   463,   218,  -341,
     425,   242,   243,    18,    19,  -341,  -341,   248,   249,   250,
     251,   252,    20,    21,    22,   238,    23,   239,   294,    24,
     290,    25,  -354,   446,  -365,   448,   449,   450,  -354,  -354,
    -365,  -365,   618,   271,    26,   619,   620,   503,   504,   621,
    -366,   248,   249,   250,   251,   252,  -366,  -366,   295,   622,
     250,   251,   252,   623,   316,   317,   336,   338,   339,   522,
     644,   340,   624,   270,   462,   341,   380,   342,   343,   381,
     466,   625,   382,   386,   387,   470,   388,   389,   398,   391,
     400,   472,   390,   399,   392,   490,   402,   408,   626,   409,
     410,   411,   493,   494,   412,   413,   416,   498,   242,   243,
     627,   628,   417,   421,   248,   249,   250,   251,   252,   253,
     254,   255,   124,   124,   511,   424,   513,   576,   499,   429,
     515,   430,   517,   496,   497,   242,   243,   431,   526,   528,
     432,   248,   249,   250,   251,   252,   435,   254,   255,   436,
     437,   438,   439,   441,   440,   124,   442,   443,   453,   454,
     608,   608,   455,   692,   456,   528,   525,   559,   464,   457,
     501,   631,   465,   475,   491,   492,   500,   516,   545,   502,
     505,   709,   506,   566,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     529,   530,   531,   532,   649,   257,   258,   533,   528,   546,
     587,   547,   706,   378,   576,   548,   550,   551,   552,   553,
     554,   561,   740,   555,   557,   560,   562,   576,   662,   576,
     567,   595,   664,   569,   637,   570,   571,   572,   573,   574,
     582,   583,   596,   270,   584,   586,   590,   591,   597,   752,
     603,   604,   616,   617,   630,   635,   639,   636,   746,   641,
     640,   657,   677,   645,   646,   665,   660,   666,   667,   668,
     669,   564,   565,   678,   684,   676,   679,   576,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   680,   683,   681,   648,   687,   257,
     258,   693,   724,   240,   241,   242,   243,   244,   393,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   695,
     711,   713,   608,   673,   257,   258,   690,   715,   714,   716,
     717,   718,   719,   240,   241,   242,   243,   720,   738,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   721,
     725,   689,   726,   193,   257,   258,   732,   739,   742,   743,
     755,   701,   753,   754,   756,   710,   459,   650,   209,   173,
     270,   738,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   751,   379,
     741,   723,     0,   257,   258,   210,   577,     0,     0,   270,
     270,     0,   579,   304,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   179,   180,     0,     0,   701,
       0,     0,     0,   181,     0,     0,     0,   305,     0,     0,
     182,     0,   183,     0,     0,     0,   173,   173,   750,    47,
      48,    49,    50,    51,     0,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,   184,     0,    63,    64,
     306,    66,     0,   307,    68,    69,   185,    70,    71,    72,
      73,    74,     0,    75,    76,    77,    78,    79,   186,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,   308,    94,    95,    96,     0,     0,     0,
      97,    98,    99,   100,   101,   309,   103,     0,   104,   105,
     106,   310,   108,   109,   110,   111,   112,   187,   113,   114,
     188,   115,   116,   117,   118,   312,   189,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   179,   180,     0,
       0,     0,     0,     0,     0,   181,     0,     0,     0,   313,
       0,     0,   182,     0,   183,     0,     0,     0,     0,     0,
       0,    47,    48,    49,    50,    51,     0,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,   184,     0,
      63,    64,   306,    66,     0,   307,    68,    69,   185,    70,
      71,    72,    73,    74,     0,    75,    76,    77,    78,    79,
     186,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,   308,    94,    95,    96,     0,
       0,     0,    97,    98,    99,   100,   101,   309,   103,   264,
     104,   105,   106,   310,   108,   109,   110,   111,   112,   187,
     113,   114,   188,   115,   116,   117,   118,     0,   189,     0,
       0,     0,   265,   266,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    47,    48,    49,    50,    51,
     267,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     0,     0,    63,    64,    65,    66,     0,    67,
      68,    69,     0,    70,    71,    72,    73,    74,   268,    75,
      76,    77,    78,    79,     0,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,     0,
      94,    95,    96,     0,     0,     0,    97,    98,    99,   100,
     101,   102,   103,   460,   104,   105,   106,   107,   108,   109,
     110,   111,   112,     0,   113,   114,     0,   115,   116,   117,
     118,     0,     0,     0,     0,     0,   265,   461,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
      48,    49,    50,    51,   267,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,     0,    63,    64,
      65,    66,     0,    67,    68,    69,     0,    70,    71,    72,
      73,    74,   268,    75,    76,    77,    78,    79,     0,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,   476,    94,    95,    96,     0,     0,     0,
      97,    98,    99,   100,   101,   102,   103,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   477,   113,   114,
       0,   115,   116,   117,   118,     0,     0,     0,     0,    47,
      48,    49,    50,    51,     0,    52,    53,   478,    55,    56,
     479,   480,    59,    60,   481,    62,     0,     0,    63,    64,
      65,    66,     0,    67,   482,    69,     0,    70,   483,    72,
      73,    74,     0,    75,    76,    77,    78,   484,     0,    80,
      81,    82,    83,    84,    85,    86,   485,    88,    89,    90,
      91,    92,    93,   523,    94,    95,    96,     0,     0,     0,
      97,    98,    99,   486,   101,   102,   103,     0,   104,   105,
     106,   107,   108,   109,   110,   487,   488,   524,   113,   114,
       0,   115,   116,   117,   118,     0,     0,     0,     0,    47,
      48,    49,    50,    51,     0,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,     0,    63,    64,
      65,    66,     0,    67,    68,    69,     0,    70,    71,    72,
      73,    74,     0,    75,    76,    77,    78,    79,     0,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,   592,    94,    95,    96,     0,     0,     0,
      97,    98,    99,   100,   101,   102,   103,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   593,   113,   114,
       0,   115,   116,   117,   118,     0,     0,     0,     0,    47,
      48,    49,    50,    51,     0,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,     0,    63,    64,
      65,    66,     0,    67,    68,    69,     0,    70,    71,    72,
      73,    74,     0,    75,    76,    77,    78,    79,     0,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,     0,    94,    95,    96,     0,     0,     0,
      97,    98,    99,   100,   101,   102,   103,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,   113,   114,
       0,   115,   116,   117,   118,   179,   180,     0,     0,     0,
       0,     0,     0,   181,     0,     0,     0,   280,     0,     0,
     182,     0,   183,     0,     0,     0,     0,     0,     0,    47,
      48,    49,    50,    51,     0,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,   184,     0,    63,    64,
      65,    66,     0,    67,    68,    69,   185,    70,    71,    72,
      73,    74,     0,    75,    76,    77,    78,    79,   186,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,     0,    94,    95,    96,   281,     0,     0,
      97,    98,    99,   100,   101,   102,   103,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   187,   113,   114,
     188,   115,   116,   117,   118,     0,   189,   179,   180,     0,
       0,     0,     0,     0,     0,   181,     0,     0,     0,   605,
       0,     0,   182,     0,   183,     0,   606,     0,     0,     0,
       0,    47,    48,    49,    50,    51,     0,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,   184,     0,
      63,    64,    65,    66,     0,    67,    68,    69,   185,    70,
      71,    72,    73,    74,     0,    75,    76,    77,    78,    79,
     186,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,     0,    94,    95,    96,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   103,     0,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   187,
     113,   114,   188,   115,   116,   117,   607,     0,   189,   179,
     180,     0,     0,     0,     0,     0,     0,   181,     0,     0,
       0,     0,     0,     0,   182,     0,   183,     0,   606,     0,
       0,   609,     0,    47,    48,    49,    50,    51,     0,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
     184,     0,    63,    64,    65,    66,     0,    67,    68,    69,
     185,    70,    71,    72,    73,    74,     0,    75,    76,    77,
      78,    79,   186,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,     0,    94,    95,
      96,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   187,   113,   114,   188,   115,   116,   117,   607,     0,
     189,   179,   180,     0,     0,     0,     0,     0,     0,   181,
       0,     0,     0,     0,     0,     0,   182,   722,   183,     0,
     606,     0,     0,     0,     0,    47,    48,    49,    50,    51,
       0,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,   184,     0,    63,    64,    65,    66,     0,    67,
      68,    69,   185,    70,    71,    72,    73,    74,     0,    75,
      76,    77,    78,    79,   186,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,     0,
      94,    95,    96,     0,     0,     0,    97,    98,    99,   100,
     101,   102,   103,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   187,   113,   114,   188,   115,   116,   117,
     607,     0,   189,   179,   180,     0,     0,     0,     0,     0,
       0,   181,     0,     0,     0,   734,     0,     0,   182,     0,
     183,     0,     0,     0,     0,     0,     0,    47,    48,    49,
      50,    51,     0,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,   184,   735,    63,    64,    65,    66,
       0,    67,    68,    69,   185,    70,    71,    72,    73,    74,
       0,    75,    76,    77,    78,    79,   186,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,     0,    94,    95,    96,     0,     0,     0,    97,    98,
      99,   100,   101,   102,   103,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   187,   113,   114,   188,   115,
     116,   117,   118,     0,   189,   179,   180,   642,     0,     0,
       0,     0,     0,   181,     0,     0,     0,     0,     0,     0,
     182,     0,   183,     0,     0,     0,     0,     0,     0,    47,
      48,    49,    50,    51,     0,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,   184,     0,    63,    64,
      65,    66,     0,    67,    68,    69,   185,    70,    71,    72,
      73,    74,     0,    75,    76,    77,    78,    79,   186,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,     0,    94,    95,    96,     0,     0,     0,
      97,    98,    99,   100,   101,   102,   103,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   187,   113,   114,
     188,   115,   116,   117,   118,     0,   189,   179,   180,     0,
       0,     0,     0,     0,     0,   181,     0,     0,     0,     0,
       0,     0,   182,     0,   183,     0,     0,     0,     0,     0,
       0,    47,    48,    49,    50,    51,     0,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,   184,   735,
      63,    64,    65,    66,     0,    67,    68,    69,   185,    70,
      71,    72,    73,    74,     0,    75,    76,    77,    78,    79,
     186,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,     0,    94,    95,    96,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   103,     0,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   187,
     113,   114,   188,   115,   116,   117,   118,     0,   189,   179,
     180,     0,     0,     0,     0,     0,     0,   181,     0,     0,
       0,     0,     0,     0,   182,     0,   183,     0,     0,     0,
       0,     0,     0,    47,    48,    49,    50,    51,     0,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
     184,     0,    63,    64,    65,    66,     0,    67,    68,    69,
     185,    70,    71,    72,    73,    74,     0,    75,    76,    77,
      78,    79,   186,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,     0,    94,    95,
      96,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   187,   113,   114,   188,   115,   116,   117,   118,   265,
     189,     0,     0,     0,     0,     0,     0,   217,     0,     0,
       0,     0,    47,    48,    49,    50,    51,   267,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
       0,    63,    64,    65,    66,     0,    67,    68,    69,     0,
      70,    71,    72,    73,    74,   268,    75,    76,    77,    78,
      79,     0,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     0,    94,    95,    96,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   103,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     265,   113,   114,     0,   115,   116,   117,   118,     0,     0,
       0,     0,     0,    47,    48,    49,    50,    51,   267,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,    63,    64,    65,    66,     0,    67,    68,    69,
       0,    70,    71,    72,    73,    74,   268,    75,    76,    77,
      78,    79,     0,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,     0,    94,    95,
      96,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   704,   113,   114,     0,   115,   116,   117,   118,     0,
       0,     0,     0,    47,    48,    49,    50,    51,     0,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,   705,    63,    64,    65,    66,     0,    67,    68,    69,
       0,    70,    71,    72,    73,    74,     0,    75,    76,    77,
      78,    79,     0,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,     0,    94,    95,
      96,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   344,   113,   114,     0,   115,   116,   117,   118,     0,
       0,     0,     0,    47,    48,    49,    50,    51,     0,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,    63,    64,    65,    66,     0,    67,    68,    69,
       0,    70,    71,    72,    73,    74,     0,    75,    76,    77,
      78,    79,     0,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,     0,    94,    95,
      96,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   403,   113,   114,     0,   115,   116,   117,   118,     0,
       0,     0,     0,    47,    48,    49,    50,    51,     0,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,    63,    64,    65,    66,     0,    67,    68,    69,
       0,    70,    71,    72,    73,    74,     0,    75,    76,    77,
      78,    79,     0,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,     0,    94,    95,
      96,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   527,   113,   114,     0,   115,   116,   117,   118,     0,
       0,     0,     0,    47,    48,    49,    50,    51,     0,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,    63,    64,    65,    66,     0,    67,    68,    69,
       0,    70,    71,    72,    73,    74,     0,    75,    76,    77,
      78,    79,     0,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,     0,    94,    95,
      96,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   556,   113,   114,     0,   115,   116,   117,   118,     0,
       0,     0,     0,    47,    48,    49,    50,    51,     0,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,    63,    64,    65,    66,     0,    67,    68,    69,
       0,    70,    71,    72,    73,    74,     0,    75,    76,    77,
      78,    79,     0,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,     0,    94,    95,
      96,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   558,   113,   114,     0,   115,   116,   117,   118,     0,
       0,     0,     0,    47,    48,    49,    50,    51,     0,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,    63,    64,    65,    66,     0,    67,    68,    69,
       0,    70,    71,    72,    73,    74,     0,    75,    76,    77,
      78,    79,     0,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,     0,    94,    95,
      96,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   585,   113,   114,     0,   115,   116,   117,   118,     0,
       0,     0,     0,    47,    48,    49,    50,    51,     0,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,    63,    64,    65,    66,     0,    67,    68,    69,
       0,    70,    71,    72,    73,    74,     0,    75,    76,    77,
      78,    79,     0,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,     0,    94,    95,
      96,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   113,   114,     0,   115,   116,   117,   118,   162,
       0,     0,     0,   163,    47,    48,    49,    50,    51,     0,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,     0,    63,    64,    65,    66,     0,    67,    68,
      69,     0,    70,    71,    72,    73,    74,     0,    75,    76,
      77,    78,    79,     0,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,    94,
      95,    96,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   103,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,     0,   113,   114,     0,   115,   116,   117,   118,
     164,   165,    47,    48,    49,    50,    51,     0,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
       0,    63,    64,    65,    66,     0,    67,    68,    69,     0,
      70,    71,    72,    73,    74,     0,    75,    76,    77,    78,
      79,     0,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     0,    94,    95,    96,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   103,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   112,
       0,   113,   114,     0,   115,   116,   117,   118,   164,   165,
      47,    48,    49,    50,    51,     0,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,     0,    63,
      64,    65,    66,     0,    67,    68,    69,     0,    70,    71,
      72,    73,    74,     0,    75,    76,    77,    78,    79,     0,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,     0,    94,    95,    96,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   103,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,     0,   113,
     114,   372,   115,   116,   117,   118,    47,    48,    49,    50,
      51,     0,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,     0,    63,    64,    65,    66,     0,
      67,    68,    69,     0,    70,    71,    72,    73,    74,     0,
      75,    76,    77,    78,    79,     0,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
       0,    94,    95,    96,     0,     0,     0,    97,    98,    99,
     100,   101,   102,   103,   419,   104,   105,   106,   107,   108,
     109,   110,   111,   112,     0,   113,   114,     0,   115,   116,
     117,   118,    47,    48,    49,    50,    51,     0,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
       0,    63,    64,    65,    66,     0,    67,    68,    69,     0,
      70,    71,    72,    73,    74,     0,    75,    76,    77,    78,
      79,     0,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     0,    94,    95,    96,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   103,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   112,
       0,   113,   114,   688,   115,   116,   117,   118,    47,    48,
      49,    50,    51,     0,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,     0,    63,    64,    65,
      66,     0,    67,    68,    69,     0,    70,    71,    72,    73,
      74,     0,    75,    76,    77,    78,    79,     0,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,     0,    94,    95,    96,     0,     0,     0,    97,
      98,    99,   100,   101,   102,   103,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,     0,   113,   114,   691,
     115,   116,   117,   118,    47,    48,    49,    50,    51,     0,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,     0,    63,    64,    65,    66,     0,    67,    68,
      69,     0,    70,    71,    72,    73,    74,     0,    75,    76,
      77,    78,    79,     0,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,   749,    94,
      95,    96,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   103,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,     0,   113,   114,     0,   115,   116,   117,   118,
      47,    48,    49,    50,    51,     0,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,     0,    63,
      64,    65,    66,     0,    67,    68,    69,     0,    70,    71,
      72,    73,    74,     0,    75,    76,    77,    78,    79,     0,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,     0,    94,    95,    96,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   103,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,     0,   113,
     114,     0,   115,   116,   117,   118,    47,    48,    49,    50,
      51,     0,    52,    53,   478,    55,    56,   479,   480,    59,
      60,   481,    62,     0,     0,    63,    64,    65,    66,     0,
      67,   482,    69,     0,    70,   483,    72,    73,    74,     0,
      75,    76,    77,    78,   484,     0,    80,    81,    82,    83,
      84,    85,    86,   485,    88,    89,    90,    91,    92,    93,
       0,    94,    95,    96,     0,     0,     0,    97,    98,    99,
     486,   101,   102,   103,     0,   104,   105,   106,   107,   108,
     109,   110,   487,   488,     0,   113,   114,     0,   115,   116,
     117,   118,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,     0,     0,
       0,     0,     0,   257,   258,     0,     0,     0,     0,     0,
       0,     0,   598,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,     0,
       0,     0,     0,     0,   257,   258,     0,     0,     0,     0,
       0,     0,     0,   694,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
       0,     0,     0,     0,     0,   257,   258,     0,     0,     0,
       0,     0,     0,     0,   708,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,     0,     0,     0,     0,     0,   257,   258,     0,     0,
       0,     0,     0,     0,   422,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,     0,     0,     0,     0,     0,   257,   258,     0,     0,
       0,     0,   578,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,     0,
       0,     0,     0,     0,   257,   258,     0,   348,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,     0,     0,     0,     0,     0,   257,
     258,     0,   549,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,     0,
       0,     0,     0,     0,   257,   258,     0,   674,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,     0,     0,     0,     0,     0,   257,
     258,     0,   685,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,     0,
       0,   256,     0,     0,   257,   258,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   240,   241,   242,   243,     0,   257,   258,     0,
     248,   249,   250,   251,   252,   253,   254,   255,     0,     0,
       0,     0,     0,   257,   258
  };

  const short int
  V1Parser::yycheck_[] =
  {
       6,     7,     8,     9,    10,   168,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,   401,    24,    25,
      26,     1,    11,   452,     1,     1,    25,     1,   396,     0,
     549,    25,   538,    11,     1,    77,     1,     1,    72,    22,
     237,   601,     1,   603,    38,    25,    31,    32,    25,    25,
      33,    25,     3,     3,    88,    89,     3,   116,    25,    28,
      25,    25,     3,     3,    41,    59,    25,   435,    22,    24,
      44,    38,    39,   147,   742,   743,    24,    67,   120,    43,
      35,    35,    25,    57,    35,    35,    53,    63,    35,    56,
      24,   651,    24,    22,    35,    35,    73,     3,    57,     3,
      74,   100,    31,    35,    33,   179,   180,   181,   182,   183,
      24,   617,    88,    90,    81,    74,   122,   111,    35,    86,
     317,    85,   121,    82,   198,   131,     1,   133,    87,    35,
      22,    35,   138,   100,   208,   209,   142,   117,   112,   119,
     116,    33,   148,   340,   111,   104,   104,    24,    28,    28,
      25,    24,   110,   112,    34,   122,   162,   676,    35,   543,
      24,     3,   168,   106,   107,   108,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    57,   257,   258,     3,   705,   706,     3,   195,
     387,   388,   389,    35,     3,    29,    71,    24,    32,    74,
       7,     8,   399,    24,    31,   211,    13,    14,    15,    16,
      17,   217,    19,   410,    35,    32,    29,    35,    35,    32,
      35,   227,    25,    98,   230,   231,    35,   102,    31,    32,
     116,     1,   238,     3,   431,    29,   665,   112,    32,    32,
      25,    26,   439,   440,    24,   442,    31,    32,    25,    26,
     239,    31,    28,   259,    31,    32,   262,   263,   455,    35,
      24,   239,    24,    24,    22,   271,    25,    37,    25,    39,
      40,    29,    31,    32,    31,    32,    46,    47,    24,    24,
      50,    51,    52,    33,    25,   669,    25,   293,    24,   295,
      31,    32,    31,    32,   491,    65,    66,    28,    68,    69,
      24,    24,   308,   309,    35,    24,    28,   381,    29,    25,
     316,     7,     8,    83,    84,    31,    32,    13,    14,    15,
      16,    17,    92,    93,    94,    33,    96,    28,    35,    99,
      24,   101,    25,   339,    25,   341,   342,   343,    31,    32,
      31,    32,    45,    31,   114,    48,    49,   421,   422,    52,
      25,    13,    14,    15,    16,    17,    31,    32,    31,    62,
      15,    16,    17,    66,    31,    31,    24,    24,    31,   443,
     567,    31,    75,   379,   380,    31,    28,    31,    31,    28,
     386,    84,    28,    31,    31,   391,    31,    31,    24,    31,
      23,   397,    35,    31,    35,   401,     3,    31,   101,    31,
      31,    31,   408,   409,    31,    31,    35,   413,     7,     8,
     113,   114,    28,    28,    13,    14,    15,    16,    17,    18,
      19,    20,   411,   412,   430,    35,   432,   501,   417,    31,
     436,    31,   438,   411,   412,     7,     8,    31,   444,   445,
      31,    13,    14,    15,    16,    17,    24,    19,    20,    31,
      56,    31,    31,    24,    31,   444,    31,    31,    24,    28,
     534,   535,    32,   660,    29,   471,   444,   473,    29,    70,
      28,   545,    35,    35,    31,    35,    35,    31,    28,    35,
      35,   678,    35,   489,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      35,    35,    35,    35,   578,    26,    27,    35,   514,    35,
     516,    35,   675,    35,   588,    29,    35,    35,    35,    35,
      35,     3,   719,    35,    35,    35,    78,   601,   602,   603,
      31,   520,   606,    35,    80,    35,    35,    35,    35,    35,
      35,    35,   520,   549,    35,    35,    35,    35,    35,   746,
      28,    35,    29,    32,    29,    35,   124,    31,    79,    35,
     124,    31,   636,    35,    35,    28,    79,    35,    24,    35,
      31,    26,    26,    31,   648,    60,    27,   651,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    27,    24,    28,    32,    29,    26,
      27,    29,    25,     5,     6,     7,     8,     9,    35,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    29,
      35,    35,   696,   629,    26,    27,   118,    35,    29,    35,
      35,    35,    79,     5,     6,     7,     8,    35,   712,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    35,
      32,   657,    35,   659,    26,    27,    35,    35,    24,    24,
      35,   667,    25,    25,    35,   681,   376,   580,   161,   675,
     676,   745,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,   745,   265,
     725,   697,    -1,    26,    27,   162,   501,    -1,    -1,   705,
     706,    -1,    35,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,   725,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    25,    -1,    -1,
      28,    -1,    30,    -1,    -1,    -1,   742,   743,   744,    37,
      38,    39,    40,    41,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,    -1,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,     1,   124,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    25,
      -1,    -1,    28,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    39,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,     1,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    -1,   124,    -1,
      -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    -1,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    -1,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      92,    93,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,     1,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    -1,   116,   117,    -1,   119,   120,   121,
     122,    -1,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    -1,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    -1,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     1,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,    -1,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    25,   116,   117,
      -1,   119,   120,   121,   122,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    -1,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    -1,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     1,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,    -1,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    25,   116,   117,
      -1,   119,   120,   121,   122,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    -1,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    -1,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     1,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,    -1,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    25,   116,   117,
      -1,   119,   120,   121,   122,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    -1,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    -1,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,    -1,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    -1,   116,   117,
      -1,   119,   120,   121,   122,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    25,    -1,    -1,
      28,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    95,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,    -1,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    -1,   124,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    25,
      -1,    -1,    28,    -1,    30,    -1,    32,    -1,    -1,    -1,
      -1,    37,    38,    39,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    -1,   124,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    30,    -1,    32,    -1,
      -1,    35,    -1,    37,    38,    39,    40,    41,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,    -1,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
     124,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    -1,
      32,    -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    -1,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      92,    93,    94,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,    -1,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,    -1,   124,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    25,    -1,    -1,    28,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    41,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    92,    93,    94,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,    -1,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    -1,   124,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,    -1,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    -1,   124,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    39,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    -1,   124,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,    -1,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    24,
     124,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    56,    57,    58,    59,    -1,    61,    62,    63,    -1,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    -1,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
      -1,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      24,   116,   117,    -1,   119,   120,   121,   122,    -1,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    -1,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    -1,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,    -1,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    25,   116,   117,    -1,   119,   120,   121,   122,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    -1,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,    -1,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    25,   116,   117,    -1,   119,   120,   121,   122,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    -1,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    -1,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,    -1,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    25,   116,   117,    -1,   119,   120,   121,   122,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    -1,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    -1,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,    -1,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    25,   116,   117,    -1,   119,   120,   121,   122,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    -1,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    -1,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,    -1,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    25,   116,   117,    -1,   119,   120,   121,   122,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    -1,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    -1,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,    -1,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    25,   116,   117,    -1,   119,   120,   121,   122,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    -1,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    -1,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,    -1,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    25,   116,   117,    -1,   119,   120,   121,   122,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    -1,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    -1,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    92,    93,
      94,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,    -1,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    -1,   116,   117,    -1,   119,   120,   121,   122,    32,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    41,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    56,    57,    58,    59,    -1,    61,    62,
      63,    -1,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    -1,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,    -1,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    -1,   116,   117,    -1,   119,   120,   121,   122,
     123,   124,    37,    38,    39,    40,    41,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    56,    57,    58,    59,    -1,    61,    62,    63,    -1,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      75,    -1,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
      -1,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      -1,   116,   117,    -1,   119,   120,   121,   122,   123,   124,
      37,    38,    39,    40,    41,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    56,
      57,    58,    59,    -1,    61,    62,    63,    -1,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    -1,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,    -1,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,   116,
     117,   118,   119,   120,   121,   122,    37,    38,    39,    40,
      41,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    56,    57,    58,    59,    -1,
      61,    62,    63,    -1,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    -1,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    92,    93,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    -1,   116,   117,    -1,   119,   120,
     121,   122,    37,    38,    39,    40,    41,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    56,    57,    58,    59,    -1,    61,    62,    63,    -1,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      75,    -1,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    94,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
      -1,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      -1,   116,   117,   118,   119,   120,   121,   122,    37,    38,
      39,    40,    41,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    56,    57,    58,
      59,    -1,    61,    62,    63,    -1,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    -1,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    92,    93,    94,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,    -1,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    -1,   116,   117,   118,
     119,   120,   121,   122,    37,    38,    39,    40,    41,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    56,    57,    58,    59,    -1,    61,    62,
      63,    -1,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    -1,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,    -1,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    -1,   116,   117,    -1,   119,   120,   121,   122,
      37,    38,    39,    40,    41,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    56,
      57,    58,    59,    -1,    61,    62,    63,    -1,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    -1,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,    -1,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,   116,
     117,    -1,   119,   120,   121,   122,    37,    38,    39,    40,
      41,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    56,    57,    58,    59,    -1,
      61,    62,    63,    -1,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    -1,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    92,    93,    94,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,    -1,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    -1,   116,   117,    -1,   119,   120,
     121,   122,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    34,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,
      -1,    -1,    32,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    26,    27,    -1,    29,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,
      27,    -1,    29,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    26,    27,    -1,    29,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,
      27,    -1,    29,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    23,    -1,    -1,    26,    27,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     5,     6,     7,     8,    -1,    26,    27,    -1,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27
  };

  const unsigned char
  V1Parser::yystos_[] =
  {
       0,   127,   128,     0,     1,     3,    37,    39,    40,    46,
      47,    50,    51,    52,    65,    66,    68,    69,    83,    84,
      92,    93,    94,    96,    99,   101,   114,   129,   139,   140,
     143,   145,   148,   151,   152,   157,   158,   160,   162,   164,
     167,   170,   172,   174,   179,   183,   194,    37,    38,    39,
      40,    41,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    56,    57,    58,    59,    61,    62,    63,
      65,    66,    67,    68,    69,    71,    72,    73,    74,    75,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    92,    93,    94,    98,    99,   100,
     101,   102,   103,   104,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   116,   117,   119,   120,   121,   122,   206,
     206,   206,   206,   206,   201,   202,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   197,   206,
     206,   206,    28,    24,    24,   206,    24,    22,    33,    24,
      24,    24,    24,    35,    24,   206,    24,   206,    24,    24,
      35,    24,    32,    36,   123,   124,   198,   206,    28,    24,
      24,   165,   166,   206,   171,   173,    24,    35,   184,    13,
      14,    21,    28,    30,    54,    64,    76,   115,   118,   124,
     199,   201,   202,   206,   149,   180,   116,   159,   144,   146,
      22,    35,    67,   130,    24,   141,   116,   161,   153,   153,
     198,    33,   165,    77,   120,   163,   175,    32,    29,    25,
      38,    59,   111,    25,   106,   107,   108,   195,     1,    25,
      43,    85,   199,   199,   199,   199,   199,    28,    33,    28,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    23,    26,    27,    33,
       1,    25,   117,   119,     1,    24,    25,    42,    70,   181,
     206,    31,     1,    25,    57,    74,    82,    87,   104,   112,
      25,    95,   199,     1,    25,    41,    73,    90,   199,   203,
      24,     1,    25,   142,    35,    31,     1,    25,    57,    71,
      74,    98,   102,   112,     1,    25,    58,    61,    91,   103,
     109,   199,     1,    25,   206,    29,    31,    31,     1,    25,
      44,    57,    74,   112,     1,    25,    38,    39,    53,    56,
      81,    86,   100,   111,   122,   206,    24,   168,    24,    31,
      31,    31,    31,    31,    25,   206,   206,   206,    29,   203,
     206,   200,   201,   202,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   118,     3,    35,   206,   206,     3,    35,   180,
      28,    28,    28,   206,     3,    35,    31,    31,    31,    31,
      35,    31,    35,    35,     3,    35,    24,    31,    24,    31,
      23,   131,     3,    25,   206,   206,     3,    35,    31,    31,
      31,    31,    31,    31,     3,    35,    35,    28,   206,   105,
     206,    28,    34,     3,    35,   206,   203,     3,    35,    31,
      31,    31,    31,     3,    35,    24,    31,    56,    31,    31,
      31,    24,    31,    31,   169,   178,   206,   203,   206,   206,
     206,    24,    31,    24,    28,    32,    29,    70,   150,   150,
       1,    25,   206,   199,    29,    35,   206,   203,   203,   203,
     206,   178,   206,   147,   203,    35,     1,    25,    45,    48,
      49,    52,    62,    66,    75,    84,   101,   113,   114,   138,
     206,    31,    35,   206,   206,   203,   202,   202,   206,   201,
      35,    28,    35,   199,   199,    35,    35,   104,   110,   134,
     135,   206,   203,   206,   178,   206,    31,   206,   203,   203,
     176,   203,   199,     1,    25,   202,   206,    25,   206,    35,
      35,    35,    35,    35,   196,   196,   185,    72,    88,    89,
     187,   188,   189,   190,   203,    28,    35,    35,    29,    29,
      35,    35,    35,    35,    35,    35,    25,    35,    25,   206,
      35,     3,    78,   136,    26,    26,   206,    31,   203,    35,
      35,    35,    35,    35,    35,    29,   199,   204,    32,    35,
      32,    35,    35,    35,    35,    25,    35,   206,    28,    35,
      35,    35,     1,    25,   177,   201,   202,    35,    35,     3,
      35,    28,    34,    28,    35,    25,    32,   122,   199,    35,
       1,    25,    63,    88,   116,   189,    29,    32,    45,    48,
      49,    52,    62,    66,    75,    84,   101,   113,   114,   138,
      29,   199,    24,    35,   181,    35,    31,    80,   137,   124,
     124,    35,    15,   132,   203,    35,    35,    29,    32,   199,
     135,    28,    35,   204,   205,     3,    35,    31,    31,    33,
      79,   205,   199,   205,   199,    28,    35,    24,    35,    31,
      24,    35,   189,   206,    29,   182,    60,   199,    31,    27,
      27,    28,   133,    24,   199,    29,   205,    29,   118,   206,
     118,   118,   203,    29,    35,    29,   196,   138,   191,   192,
     193,   206,   138,   186,    25,    55,   165,   181,    35,   203,
     134,    35,   154,    35,    29,    35,    35,    35,    35,    79,
      35,    35,    29,   206,    25,    32,    35,    25,   100,   121,
     181,   181,    35,    29,    25,    55,   155,   156,   199,    35,
     203,   193,    24,    24,    31,    32,    79,   166,   166,    91,
     206,   156,   203,    25,    25,    35,    35
  };

  const unsigned char
  V1Parser::yyr1_[] =
  {
       0,   126,   127,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   129,   129,   130,   130,
     131,   131,   131,   132,   132,   133,   133,   134,   134,   135,
     135,   136,   136,   137,   137,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   139,   139,
     140,   141,   141,   142,   142,   143,   143,   144,   144,   144,
     145,   145,   146,   146,   146,   146,   146,   146,   146,   147,
     147,   148,   148,   149,   149,   149,   149,   149,   150,   150,
     151,   152,   152,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   154,   154,   154,   155,   155,   156,   156,
     156,   157,   157,   158,   158,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   160,   160,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   162,   162,   163,   163,   163,
     163,   163,   163,   163,   163,   164,   165,   165,   166,   166,
     167,   168,   168,   169,   169,   169,   169,   169,   169,   170,
     171,   171,   171,   171,   172,   173,   173,   173,   173,   174,
     174,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   176,   176,   176,   176,
     176,   176,   177,   177,   177,   177,   178,   178,   179,   179,
     180,   180,   180,   180,   181,   181,   181,   181,   181,   181,
     182,   182,   182,   183,   184,   184,   184,   184,   184,   185,
     185,   185,   185,   185,   185,   186,   186,   186,   187,   187,
     188,   188,   189,   189,   190,   190,   191,   191,   192,   192,
     193,   193,   194,   194,   195,   195,   195,   196,   196,   196,
     196,   197,   197,   197,   198,   198,   198,   198,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     200,   200,   201,   201,   202,   203,   204,   204,   205,   205,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206
  };

  const unsigned char
  V1Parser::yyr2_[] =
  {
       0,     2,     2,     0,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     4,     2,     5,     6,     6,     5,
       0,     6,     4,     1,     1,     0,     3,     1,     3,     1,
       1,     0,     4,     0,     4,     1,     4,     1,     1,     1,
       1,     1,     1,     4,     1,     1,     1,     1,     4,     7,
       5,     0,     3,     0,     5,     5,     3,     0,     3,     3,
       5,     6,     0,     5,     5,     5,     5,     3,     2,     0,
       3,     5,     6,     0,     5,     5,     3,     2,     0,     4,
       3,     5,     6,     0,     6,     8,     5,     4,     9,     4,
       3,     3,     2,     0,     5,     5,     1,     3,     1,     3,
       1,     5,     6,     5,     6,     4,     5,     5,     5,     5,
       5,     3,     3,     2,     5,     6,     4,     5,     5,     5,
       5,     5,     5,     3,     2,     5,     6,     4,     4,     5,
       5,     5,     5,     3,     2,     6,     1,     3,     0,     1,
       6,     3,     4,     0,     6,     5,     6,     3,     2,     5,
       0,     5,     5,     5,     5,     0,     5,     5,     5,     5,
       6,     0,     5,     6,     5,     5,     5,     5,     5,     5,
       8,     6,     9,     5,     3,     2,     0,     5,     5,     5,
       3,     2,     1,     3,     3,     5,     0,     3,     5,     6,
       0,     2,     3,     2,     5,     7,     5,     7,     4,     3,
       0,     3,     3,     5,     0,     6,     7,     9,     2,     0,
       5,     5,     3,     3,     2,     0,     5,     5,     0,     1,
       1,     3,     3,     2,     1,     1,     0,     1,     1,     3,
       1,     2,     4,     6,     0,     5,     5,     0,     2,     3,
       5,     0,     2,     3,     1,     1,     1,     3,     4,     6,
       1,     1,     3,     3,     1,     3,     2,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     4,     3,     1,     1,     3,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const V1Parser::yytname_[] =
  {
  "$end", "error", "$undefined", "END", "UNEXPECTED_TOKEN", "\"<=\"",
  "\">=\"", "\"<<\"", "\">>\"", "\"&&\"", "\"||\"", "\"!=\"", "\"==\"",
  "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"%\"", "\"|\"", "\"&\"", "\"^\"",
  "\"~\"", "\"[\"", "\"]\"", "\"{\"", "\"}\"", "\"<\"", "\">\"", "\"(\"",
  "\")\"", "\"!\"", "\":\"", "\",\"", "\".\"", "\"=\"", "\";\"", "NEWLINE",
  "ACTION", "ACTIONS", "ACTION_PROFILE", "ACTION_SELECTOR", "ALGORITHM",
  "APPLY", "ATTRIBUTE", "ATTRIBUTES", "BIT", "BLACKBOX", "BLACKBOX_TYPE",
  "BLOCK", "BOOL", "CALCULATED_FIELD", "CONTROL", "COUNTER", "CONST",
  "CURRENT", "DEFAULT", "DEFAULT_ACTION", "DIRECT", "DROP",
  "DYNAMIC_ACTION_SELECTION", "ELSE", "EXTRACT", "EXPRESSION",
  "EXPRESSION_LOCAL_VARIABLES", "FALSE", "FIELD_LIST",
  "FIELD_LIST_CALCULATION", "FIELDS", "HEADER", "HEADER_TYPE", "IF",
  "IMPLEMENTATION", "IN", "INPUT", "INSTANCE_COUNT", "INT", "LATEST",
  "LAYOUT", "LENGTH", "MASK", "MAX_LENGTH", "MAX_SIZE", "MAX_WIDTH",
  "METADATA", "METER", "METHOD", "MIN_SIZE", "MIN_WIDTH", "OPTIONAL",
  "OUT", "OUTPUT_WIDTH", "PARSE_ERROR", "PARSER", "PARSER_VALUE_SET",
  "PARSER_EXCEPTION", "PAYLOAD", "PRAGMA", "PREFIX", "PRE_COLOR",
  "PRIMITIVE_ACTION", "READS", "REGISTER", "RESULT", "RETURN",
  "SATURATING", "SELECT", "SELECTION_KEY", "SELECTION_MODE",
  "SELECTION_TYPE", "SET_METADATA", "SIGNED", "SIZE", "STATIC", "STRING",
  "TABLE", "TRUE", "TYPE", "UPDATE", "VALID", "VERIFY", "WIDTH", "WRITES",
  "IDENTIFIER", "STRING_LITERAL", "INTEGER", "EXPRLIST", "$accept",
  "program", "input", "header_type_declaration", "header_dec_body",
  "field_declarations", "bit_width", "opt_field_modifiers", "attributes",
  "attrib", "opt_length", "opt_max_length", "type", "header_instance",
  "metadata_instance", "opt_metadata_initializer",
  "metadata_field_init_list", "field_list_declaration",
  "field_list_entries", "field_list_calculation_declaration",
  "field_list_calculation_body", "field_list_list",
  "calculated_field_declaration", "update_verify_spec_list",
  "opt_condition", "value_set_declaration", "parser_function_declaration",
  "parser_statement_list", "case_entry_list", "case_value_list",
  "case_value", "parser_exception_declaration", "counter_declaration",
  "counter_spec_list", "meter_declaration", "meter_spec_list",
  "register_declaration", "register_spec_list",
  "primitive_action_declaration", "name_list", "opt_name_list",
  "action_function_declaration", "action_function_body",
  "action_statement_list", "action_profile_declaration",
  "action_profile_body", "action_selector_declaration",
  "action_selector_body", "table_declaration", "table_body",
  "field_match_list", "field_or_masked_ref", "action_list",
  "control_function_declaration", "control_statement_list",
  "control_statement", "apply_case_list", "blackbox_type_declaration",
  "blackbox_body", "blackbox_attribute", "blackbox_method",
  "opt_argument_list", "argument_list", "argument", "inout",
  "opt_locals_list", "locals_list", "local_var", "blackbox_instantiation",
  "blackbox_config", "expressions", "pragma_operands", "pragma_operand",
  "expression", "header_or_field_ref", "header_ref", "field_ref",
  "const_expression", "expression_list", "opt_expression_list", "name", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  V1Parser::yyrline_[] =
  {
       0,   249,   249,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   274,   282,   289,   293,   295,
     299,   301,   307,   312,   317,   321,   322,   326,   327,   331,
     332,   336,   337,   342,   343,   348,   349,   351,   352,   353,
     354,   355,   356,   357,   359,   360,   361,   362,   370,   373,
     381,   386,   387,   390,   391,   400,   402,   407,   408,   410,
     419,   421,   425,   426,   430,   435,   440,   445,   446,   450,
     451,   456,   458,   462,   463,   465,   467,   468,   471,   472,
     480,   488,   490,   494,   495,   497,   499,   501,   503,   505,
     507,   509,   510,   513,   514,   516,   521,   523,   528,   530,
     532,   541,   546,   553,   555,   559,   561,   566,   571,   573,
     575,   577,   579,   580,   587,   590,   594,   596,   598,   600,
     605,   610,   612,   614,   615,   622,   626,   630,   634,   637,
     642,   647,   649,   652,   653,   661,   665,   666,   670,   671,
     679,   689,   690,   694,   695,   697,   699,   701,   703,   711,
     716,   717,   719,   721,   725,   730,   731,   732,   733,   740,
     744,   748,   749,   751,   753,   755,   757,   759,   761,   763,
     765,   769,   772,   776,   781,   782,   785,   786,   790,   794,
     798,   799,   803,   804,   806,   808,   812,   813,   820,   823,
     826,   827,   828,   829,   833,   835,   837,   839,   841,   843,
     847,   848,   852,   860,   866,   869,   871,   874,   877,   880,
     881,   882,   884,   886,   887,   890,   891,   893,   898,   899,
     903,   904,   908,   910,   914,   914,   916,   916,   918,   919,
     922,   923,   927,   932,   941,   942,   949,   954,   956,   958,
     960,   965,   966,   968,   973,   974,   975,   976,   984,   985,
     987,   988,   989,   990,   993,   994,   995,   996,   997,   998,
     999,  1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,  1008,
    1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,
    1022,  1023,  1027,  1028,  1031,  1035,  1041,  1042,  1045,  1045,
    1047,  1048,  1049,  1050,  1051,  1052,  1053,  1054,  1055,  1056,
    1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,  1065,  1066,
    1067,  1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,
    1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,  1106,
    1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,  1116,
    1117,  1118
  };

  // Print the state stack on the debug stream.
  void
  V1Parser::yystack_print_ ()
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
  V1Parser::yy_reduce_print_ (int yyrule)
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


#line 23 "parsers/v1/v1parser.ypp" // lalr1.cc:1167
} // V1
#line 6300 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.cpp" // lalr1.cc:1167
#line 1121 "parsers/v1/v1parser.ypp" // lalr1.cc:1168


void V1::V1Parser::error(const Util::SourceInfo& location,
                         const std::string& message) {
    driver.onParseError(location, message);
}

static const IR::Expression *removeRedundantValid(const IR::Expression *e) {
    if (auto *prim = e->to<IR::Primitive>()) {
        if (prim->name == "valid")
            return prim->operands.at(0); }
    return e;
}
