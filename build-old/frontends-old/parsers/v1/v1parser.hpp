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
 ** \file /media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.hpp
 ** Define the V1::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_YY_MEDIA_YEC_WORK_PROGRAMS_P4_VERIFICATION_P4B_TRANSLATOR_BUILD_FRONTENDS_PARSERS_V1_V1PARSER_HPP_INCLUDED
# define YY_YY_MEDIA_YEC_WORK_PROGRAMS_P4_VERIFICATION_P4B_TRANSLATOR_BUILD_FRONTENDS_PARSERS_V1_V1PARSER_HPP_INCLUDED
// //                    "%code requires" blocks.
#line 37 "parsers/v1/v1parser.ypp" // lalr1.cc:377

namespace V1 {
class V1Lexer;
class V1ParserDriver;

struct BBoxType {
    IR::Vector<IR::Method>* methods;
    IR::NameMap<IR::Attribute, ordered_map>* attribs;
};

struct HeaderType {
    IR::Vector<IR::Annotation>* annotations;
    IR::IndexedVector<IR::StructField>* fields;
};

struct Attributes {
    bool signed_ = false;
    bool saturating = false;
    IR::Vector<IR::Annotation> annotations;
    Attributes &merge(const Attributes &a) {
        signed_ |= a.signed_;
        saturating |= a.saturating;
        annotations.append(a.annotations);
        return *this; }
};

}  // namespace V1

inline std::ostream& operator<<(std::ostream& out, const V1::BBoxType& bboxType) {
    out << "BBoxType(" << bboxType.methods << ',' << bboxType.attribs << ')';
    return out;
}

inline std::ostream& operator<<(std::ostream& out, const V1::HeaderType& headerType) {
    out << "HeaderType(" << headerType.annotations << ',' << headerType.fields << ')';
    return out;
}

inline std::ostream& operator<<(std::ostream& out, const V1::Attributes& a) {
    return out << "Attributes(" << (a.signed_ ? "signed," : "") <<
                  (a.saturating ? "saturating," : "") << a.annotations << ')'; }

typedef std::pair<const IR::Expression*, const IR::Constant*> CaseValue;

inline std::ostream& operator<<(std::ostream& out, const CaseValue& caseValue) {
    out << "CaseValue(" << caseValue.first << ',' << caseValue.second << ')';
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

#include "frontends/common/constantParsing.h"
#include "lib/cstring.h"
#include "lib/error.h"
#include "lib/source_file.h"

#line 112 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.hpp" // lalr1.cc:377

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

#line 23 "parsers/v1/v1parser.ypp" // lalr1.cc:377
namespace V1 {
#line 189 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.hpp" // lalr1.cc:377



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
  class V1Parser
  {
  public:
#ifndef YYSTYPE
    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // opt_field_modifiers
      // attributes
      // attrib
      char dummy1[sizeof(Attributes)];

      // blackbox_body
      char dummy2[sizeof(BBoxType)];

      // case_value
      char dummy3[sizeof(CaseValue)];

      // bit_width
      // type
      char dummy4[sizeof(ConstType*)];

      // header_dec_body
      // field_declarations
      char dummy5[sizeof(HeaderType)];

      // action_function_body
      // action_statement_list
      char dummy6[sizeof(IR::ActionFunction*)];

      // action_profile_body
      char dummy7[sizeof(IR::ActionProfile*)];

      // action_selector_body
      char dummy8[sizeof(IR::ActionSelector*)];

      // blackbox_method
      char dummy9[sizeof(IR::Annotations*)];

      // apply_case_list
      char dummy10[sizeof(IR::Apply*)];

      // local_var
      char dummy11[sizeof(IR::AttribLocal*)];

      // opt_locals_list
      // locals_list
      char dummy12[sizeof(IR::AttribLocals*)];

      // blackbox_attribute
      char dummy13[sizeof(IR::Attribute*)];

      // update_verify_spec_list
      char dummy14[sizeof(IR::CalculatedField*)];

      // case_value_list
      char dummy15[sizeof(IR::CaseEntry*)];

      // const_expression
      char dummy16[sizeof(IR::Constant*)];

      // counter_spec_list
      char dummy17[sizeof(IR::Counter*)];

      // inout
      char dummy18[sizeof(IR::Direction)];

      // opt_condition
      // field_or_masked_ref
      // pragma_operand
      // expression
      // header_or_field_ref
      // header_ref
      char dummy19[sizeof(IR::Expression*)];

      // field_list_entries
      char dummy20[sizeof(IR::FieldList*)];

      // field_list_calculation_body
      char dummy21[sizeof(IR::FieldListCalculation*)];

      // name
      char dummy22[sizeof(IR::ID)];

      // field_ref
      char dummy23[sizeof(IR::Member*)];

      // meter_spec_list
      char dummy24[sizeof(IR::Meter*)];

      // field_list_list
      // name_list
      // opt_name_list
      // action_list
      char dummy25[sizeof(IR::NameList*)];

      // blackbox_config
      char dummy26[sizeof(IR::NameMap<IR::Property>*)];

      // argument
      char dummy27[sizeof(IR::Parameter*)];

      // opt_argument_list
      // argument_list
      char dummy28[sizeof(IR::ParameterList*)];

      // register_spec_list
      char dummy29[sizeof(IR::Register*)];

      // parser_statement_list
      char dummy30[sizeof(IR::V1Parser*)];

      // table_body
      char dummy31[sizeof(IR::V1Table*)];

      // case_entry_list
      char dummy32[sizeof(IR::Vector<IR::CaseEntry>*)];

      // field_match_list
      // control_statement_list
      // control_statement
      // expressions
      // pragma_operands
      // expression_list
      // opt_expression_list
      char dummy33[sizeof(IR::Vector<IR::Expression>*)];

      // INTEGER
      char dummy34[sizeof(UnparsedConstant)];

      // ACTION
      // ACTIONS
      // ACTION_PROFILE
      // ACTION_SELECTOR
      // ALGORITHM
      // APPLY
      // ATTRIBUTE
      // ATTRIBUTES
      // BIT
      // BLACKBOX
      // BLACKBOX_TYPE
      // BLOCK
      // BOOL
      // CALCULATED_FIELD
      // CONTROL
      // COUNTER
      // CONST
      // CURRENT
      // DEFAULT
      // DEFAULT_ACTION
      // DIRECT
      // DROP
      // DYNAMIC_ACTION_SELECTION
      // ELSE
      // EXTRACT
      // EXPRESSION
      // EXPRESSION_LOCAL_VARIABLES
      // FALSE
      // FIELD_LIST
      // FIELD_LIST_CALCULATION
      // FIELDS
      // HEADER
      // HEADER_TYPE
      // IF
      // IMPLEMENTATION
      // IN
      // INPUT
      // INSTANCE_COUNT
      // INT
      // LATEST
      // LAYOUT
      // LENGTH
      // MASK
      // MAX_LENGTH
      // MAX_SIZE
      // MAX_WIDTH
      // METADATA
      // METER
      // METHOD
      // MIN_SIZE
      // MIN_WIDTH
      // OPTIONAL
      // OUT
      // OUTPUT_WIDTH
      // PARSE_ERROR
      // PARSER
      // PARSER_VALUE_SET
      // PARSER_EXCEPTION
      // PAYLOAD
      // PRAGMA
      // PREFIX
      // PRE_COLOR
      // PRIMITIVE_ACTION
      // READS
      // REGISTER
      // RESULT
      // RETURN
      // SATURATING
      // SELECT
      // SELECTION_KEY
      // SELECTION_MODE
      // SELECTION_TYPE
      // SET_METADATA
      // SIGNED
      // SIZE
      // STATIC
      // STRING
      // TABLE
      // TRUE
      // TYPE
      // UPDATE
      // VALID
      // VERIFY
      // WIDTH
      // WRITES
      // IDENTIFIER
      // STRING_LITERAL
      char dummy35[sizeof(cstring)];
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
        TOK_END = 258,
        TOK_UNEXPECTED_TOKEN = 259,
        TOK_LE = 260,
        TOK_GE = 261,
        TOK_SHL = 262,
        TOK_SHR = 263,
        TOK_AND = 264,
        TOK_OR = 265,
        TOK_NE = 266,
        TOK_EQ = 267,
        TOK_PLUS = 268,
        TOK_MINUS = 269,
        TOK_MUL = 270,
        TOK_DIV = 271,
        TOK_MOD = 272,
        TOK_BIT_OR = 273,
        TOK_BIT_AND = 274,
        TOK_BIT_XOR = 275,
        TOK_COMPLEMENT = 276,
        TOK_L_BRACKET = 277,
        TOK_R_BRACKET = 278,
        TOK_L_BRACE = 279,
        TOK_R_BRACE = 280,
        TOK_L_ANGLE = 281,
        TOK_R_ANGLE = 282,
        TOK_L_PAREN = 283,
        TOK_R_PAREN = 284,
        TOK_NOT = 285,
        TOK_COLON = 286,
        TOK_COMMA = 287,
        TOK_DOT = 288,
        TOK_ASSIGN = 289,
        TOK_SEMICOLON = 290,
        TOK_NEWLINE = 291,
        TOK_ACTION = 292,
        TOK_ACTIONS = 293,
        TOK_ACTION_PROFILE = 294,
        TOK_ACTION_SELECTOR = 295,
        TOK_ALGORITHM = 296,
        TOK_APPLY = 297,
        TOK_ATTRIBUTE = 298,
        TOK_ATTRIBUTES = 299,
        TOK_BIT = 300,
        TOK_BLACKBOX = 301,
        TOK_BLACKBOX_TYPE = 302,
        TOK_BLOCK = 303,
        TOK_BOOL = 304,
        TOK_CALCULATED_FIELD = 305,
        TOK_CONTROL = 306,
        TOK_COUNTER = 307,
        TOK_CONST = 308,
        TOK_CURRENT = 309,
        TOK_DEFAULT = 310,
        TOK_DEFAULT_ACTION = 311,
        TOK_DIRECT = 312,
        TOK_DROP = 313,
        TOK_DYNAMIC_ACTION_SELECTION = 314,
        TOK_ELSE = 315,
        TOK_EXTRACT = 316,
        TOK_EXPRESSION = 317,
        TOK_EXPRESSION_LOCAL_VARIABLES = 318,
        TOK_FALSE = 319,
        TOK_FIELD_LIST = 320,
        TOK_FIELD_LIST_CALCULATION = 321,
        TOK_FIELDS = 322,
        TOK_HEADER = 323,
        TOK_HEADER_TYPE = 324,
        TOK_IF = 325,
        TOK_IMPLEMENTATION = 326,
        TOK_IN = 327,
        TOK_INPUT = 328,
        TOK_INSTANCE_COUNT = 329,
        TOK_INT = 330,
        TOK_LATEST = 331,
        TOK_LAYOUT = 332,
        TOK_LENGTH = 333,
        TOK_MASK = 334,
        TOK_MAX_LENGTH = 335,
        TOK_MAX_SIZE = 336,
        TOK_MAX_WIDTH = 337,
        TOK_METADATA = 338,
        TOK_METER = 339,
        TOK_METHOD = 340,
        TOK_MIN_SIZE = 341,
        TOK_MIN_WIDTH = 342,
        TOK_OPTIONAL = 343,
        TOK_OUT = 344,
        TOK_OUTPUT_WIDTH = 345,
        TOK_PARSE_ERROR = 346,
        TOK_PARSER = 347,
        TOK_PARSER_VALUE_SET = 348,
        TOK_PARSER_EXCEPTION = 349,
        TOK_PAYLOAD = 350,
        TOK_PRAGMA = 351,
        TOK_PREFIX = 352,
        TOK_PRE_COLOR = 353,
        TOK_PRIMITIVE_ACTION = 354,
        TOK_READS = 355,
        TOK_REGISTER = 356,
        TOK_RESULT = 357,
        TOK_RETURN = 358,
        TOK_SATURATING = 359,
        TOK_SELECT = 360,
        TOK_SELECTION_KEY = 361,
        TOK_SELECTION_MODE = 362,
        TOK_SELECTION_TYPE = 363,
        TOK_SET_METADATA = 364,
        TOK_SIGNED = 365,
        TOK_SIZE = 366,
        TOK_STATIC = 367,
        TOK_STRING = 368,
        TOK_TABLE = 369,
        TOK_TRUE = 370,
        TOK_TYPE = 371,
        TOK_UPDATE = 372,
        TOK_VALID = 373,
        TOK_VERIFY = 374,
        TOK_WIDTH = 375,
        TOK_WRITES = 376,
        TOK_IDENTIFIER = 377,
        TOK_STRING_LITERAL = 378,
        TOK_INTEGER = 379,
        TOK_EXPRLIST = 380
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

  basic_symbol (typename Base::kind_type t, const Attributes v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const BBoxType v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const CaseValue v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ConstType* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const HeaderType v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::ActionFunction* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::ActionProfile* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::ActionSelector* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Annotations* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Apply* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::AttribLocal* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::AttribLocals* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Attribute* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::CalculatedField* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::CaseEntry* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Constant* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Counter* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Direction v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Expression* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::FieldList* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::FieldListCalculation* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::ID v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Member* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Meter* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::NameList* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::NameMap<IR::Property>* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Parameter* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::ParameterList* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Register* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::V1Parser* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::V1Table* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Vector<IR::CaseEntry>* v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const IR::Vector<IR::Expression>* v, const location_type& l);

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
    make_END (const location_type& l);

    static inline
    symbol_type
    make_UNEXPECTED_TOKEN (const location_type& l);

    static inline
    symbol_type
    make_LE (const location_type& l);

    static inline
    symbol_type
    make_GE (const location_type& l);

    static inline
    symbol_type
    make_SHL (const location_type& l);

    static inline
    symbol_type
    make_SHR (const location_type& l);

    static inline
    symbol_type
    make_AND (const location_type& l);

    static inline
    symbol_type
    make_OR (const location_type& l);

    static inline
    symbol_type
    make_NE (const location_type& l);

    static inline
    symbol_type
    make_EQ (const location_type& l);

    static inline
    symbol_type
    make_PLUS (const location_type& l);

    static inline
    symbol_type
    make_MINUS (const location_type& l);

    static inline
    symbol_type
    make_MUL (const location_type& l);

    static inline
    symbol_type
    make_DIV (const location_type& l);

    static inline
    symbol_type
    make_MOD (const location_type& l);

    static inline
    symbol_type
    make_BIT_OR (const location_type& l);

    static inline
    symbol_type
    make_BIT_AND (const location_type& l);

    static inline
    symbol_type
    make_BIT_XOR (const location_type& l);

    static inline
    symbol_type
    make_COMPLEMENT (const location_type& l);

    static inline
    symbol_type
    make_L_BRACKET (const location_type& l);

    static inline
    symbol_type
    make_R_BRACKET (const location_type& l);

    static inline
    symbol_type
    make_L_BRACE (const location_type& l);

    static inline
    symbol_type
    make_R_BRACE (const location_type& l);

    static inline
    symbol_type
    make_L_ANGLE (const location_type& l);

    static inline
    symbol_type
    make_R_ANGLE (const location_type& l);

    static inline
    symbol_type
    make_L_PAREN (const location_type& l);

    static inline
    symbol_type
    make_R_PAREN (const location_type& l);

    static inline
    symbol_type
    make_NOT (const location_type& l);

    static inline
    symbol_type
    make_COLON (const location_type& l);

    static inline
    symbol_type
    make_COMMA (const location_type& l);

    static inline
    symbol_type
    make_DOT (const location_type& l);

    static inline
    symbol_type
    make_ASSIGN (const location_type& l);

    static inline
    symbol_type
    make_SEMICOLON (const location_type& l);

    static inline
    symbol_type
    make_NEWLINE (const location_type& l);

    static inline
    symbol_type
    make_ACTION (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_ACTIONS (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_ACTION_PROFILE (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_ACTION_SELECTOR (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_ALGORITHM (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_APPLY (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_ATTRIBUTE (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_ATTRIBUTES (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_BIT (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_BLACKBOX (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_BLACKBOX_TYPE (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_BLOCK (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_BOOL (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_CALCULATED_FIELD (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_CONTROL (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_COUNTER (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_CONST (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_CURRENT (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_DEFAULT (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_DEFAULT_ACTION (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_DIRECT (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_DROP (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_DYNAMIC_ACTION_SELECTION (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_ELSE (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_EXTRACT (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_EXPRESSION (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_EXPRESSION_LOCAL_VARIABLES (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_FALSE (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_FIELD_LIST (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_FIELD_LIST_CALCULATION (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_FIELDS (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_HEADER (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_HEADER_TYPE (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_IF (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_IMPLEMENTATION (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_IN (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_INPUT (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_INSTANCE_COUNT (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_INT (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_LATEST (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_LAYOUT (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_LENGTH (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_MASK (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_MAX_LENGTH (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_MAX_SIZE (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_MAX_WIDTH (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_METADATA (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_METER (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_METHOD (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_MIN_SIZE (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_MIN_WIDTH (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_OPTIONAL (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_OUT (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_OUTPUT_WIDTH (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_PARSE_ERROR (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_PARSER (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_PARSER_VALUE_SET (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_PARSER_EXCEPTION (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_PAYLOAD (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_PRAGMA (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_PREFIX (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_PRE_COLOR (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_PRIMITIVE_ACTION (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_READS (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_REGISTER (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_RESULT (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_RETURN (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_SATURATING (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_SELECT (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_SELECTION_KEY (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_SELECTION_MODE (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_SELECTION_TYPE (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_SET_METADATA (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_SIGNED (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_SIZE (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_STATIC (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_STRING (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_TABLE (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_TRUE (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_TYPE (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_UPDATE (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_VALID (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_VERIFY (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_WIDTH (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_WRITES (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_IDENTIFIER (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_STRING_LITERAL (const cstring& v, const location_type& l);

    static inline
    symbol_type
    make_INTEGER (const UnparsedConstant& v, const location_type& l);

    static inline
    symbol_type
    make_EXPRLIST (const location_type& l);


    /// Build a parser object.
    V1Parser (V1::V1ParserDriver& driver_yyarg, V1::V1Lexer& lexer_yyarg);
    virtual ~V1Parser ();

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
    V1Parser (const V1Parser&);
    V1Parser& operator= (const V1Parser&);

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
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

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
      yylast_ = 4234,     ///< Last index in yytable_.
      yynnts_ = 81,  ///< Number of nonterminal symbols.
      yyfinal_ = 3, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 126  ///< Number of tokens.
    };


    // User arguments.
    V1::V1ParserDriver& driver;
    V1::V1Lexer& lexer;
  };

  // Symbol number corresponding to token number t.
  inline
  V1Parser::token_number_type
  V1Parser::yytranslate_ (token_type t)
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
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125
    };
    const unsigned int user_token_number_max_ = 380;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

  inline
  V1Parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  V1Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  V1Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      case 133: // opt_field_modifiers
      case 134: // attributes
      case 135: // attrib
        value.copy< Attributes > (other.value);
        break;

      case 184: // blackbox_body
        value.copy< BBoxType > (other.value);
        break;

      case 156: // case_value
        value.copy< CaseValue > (other.value);
        break;

      case 132: // bit_width
      case 138: // type
        value.copy< ConstType* > (other.value);
        break;

      case 130: // header_dec_body
      case 131: // field_declarations
        value.copy< HeaderType > (other.value);
        break;

      case 168: // action_function_body
      case 169: // action_statement_list
        value.copy< IR::ActionFunction* > (other.value);
        break;

      case 171: // action_profile_body
        value.copy< IR::ActionProfile* > (other.value);
        break;

      case 173: // action_selector_body
        value.copy< IR::ActionSelector* > (other.value);
        break;

      case 186: // blackbox_method
        value.copy< IR::Annotations* > (other.value);
        break;

      case 182: // apply_case_list
        value.copy< IR::Apply* > (other.value);
        break;

      case 193: // local_var
        value.copy< IR::AttribLocal* > (other.value);
        break;

      case 191: // opt_locals_list
      case 192: // locals_list
        value.copy< IR::AttribLocals* > (other.value);
        break;

      case 185: // blackbox_attribute
        value.copy< IR::Attribute* > (other.value);
        break;

      case 149: // update_verify_spec_list
        value.copy< IR::CalculatedField* > (other.value);
        break;

      case 155: // case_value_list
        value.copy< IR::CaseEntry* > (other.value);
        break;

      case 203: // const_expression
        value.copy< IR::Constant* > (other.value);
        break;

      case 159: // counter_spec_list
        value.copy< IR::Counter* > (other.value);
        break;

      case 190: // inout
        value.copy< IR::Direction > (other.value);
        break;

      case 150: // opt_condition
      case 177: // field_or_masked_ref
      case 198: // pragma_operand
      case 199: // expression
      case 200: // header_or_field_ref
      case 201: // header_ref
        value.copy< IR::Expression* > (other.value);
        break;

      case 144: // field_list_entries
        value.copy< IR::FieldList* > (other.value);
        break;

      case 146: // field_list_calculation_body
        value.copy< IR::FieldListCalculation* > (other.value);
        break;

      case 206: // name
        value.copy< IR::ID > (other.value);
        break;

      case 202: // field_ref
        value.copy< IR::Member* > (other.value);
        break;

      case 161: // meter_spec_list
        value.copy< IR::Meter* > (other.value);
        break;

      case 147: // field_list_list
      case 165: // name_list
      case 166: // opt_name_list
      case 178: // action_list
        value.copy< IR::NameList* > (other.value);
        break;

      case 195: // blackbox_config
        value.copy< IR::NameMap<IR::Property>* > (other.value);
        break;

      case 189: // argument
        value.copy< IR::Parameter* > (other.value);
        break;

      case 187: // opt_argument_list
      case 188: // argument_list
        value.copy< IR::ParameterList* > (other.value);
        break;

      case 163: // register_spec_list
        value.copy< IR::Register* > (other.value);
        break;

      case 153: // parser_statement_list
        value.copy< IR::V1Parser* > (other.value);
        break;

      case 175: // table_body
        value.copy< IR::V1Table* > (other.value);
        break;

      case 154: // case_entry_list
        value.copy< IR::Vector<IR::CaseEntry>* > (other.value);
        break;

      case 176: // field_match_list
      case 180: // control_statement_list
      case 181: // control_statement
      case 196: // expressions
      case 197: // pragma_operands
      case 204: // expression_list
      case 205: // opt_expression_list
        value.copy< IR::Vector<IR::Expression>* > (other.value);
        break;

      case 124: // INTEGER
        value.copy< UnparsedConstant > (other.value);
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
        value.copy< cstring > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      case 133: // opt_field_modifiers
      case 134: // attributes
      case 135: // attrib
        value.copy< Attributes > (v);
        break;

      case 184: // blackbox_body
        value.copy< BBoxType > (v);
        break;

      case 156: // case_value
        value.copy< CaseValue > (v);
        break;

      case 132: // bit_width
      case 138: // type
        value.copy< ConstType* > (v);
        break;

      case 130: // header_dec_body
      case 131: // field_declarations
        value.copy< HeaderType > (v);
        break;

      case 168: // action_function_body
      case 169: // action_statement_list
        value.copy< IR::ActionFunction* > (v);
        break;

      case 171: // action_profile_body
        value.copy< IR::ActionProfile* > (v);
        break;

      case 173: // action_selector_body
        value.copy< IR::ActionSelector* > (v);
        break;

      case 186: // blackbox_method
        value.copy< IR::Annotations* > (v);
        break;

      case 182: // apply_case_list
        value.copy< IR::Apply* > (v);
        break;

      case 193: // local_var
        value.copy< IR::AttribLocal* > (v);
        break;

      case 191: // opt_locals_list
      case 192: // locals_list
        value.copy< IR::AttribLocals* > (v);
        break;

      case 185: // blackbox_attribute
        value.copy< IR::Attribute* > (v);
        break;

      case 149: // update_verify_spec_list
        value.copy< IR::CalculatedField* > (v);
        break;

      case 155: // case_value_list
        value.copy< IR::CaseEntry* > (v);
        break;

      case 203: // const_expression
        value.copy< IR::Constant* > (v);
        break;

      case 159: // counter_spec_list
        value.copy< IR::Counter* > (v);
        break;

      case 190: // inout
        value.copy< IR::Direction > (v);
        break;

      case 150: // opt_condition
      case 177: // field_or_masked_ref
      case 198: // pragma_operand
      case 199: // expression
      case 200: // header_or_field_ref
      case 201: // header_ref
        value.copy< IR::Expression* > (v);
        break;

      case 144: // field_list_entries
        value.copy< IR::FieldList* > (v);
        break;

      case 146: // field_list_calculation_body
        value.copy< IR::FieldListCalculation* > (v);
        break;

      case 206: // name
        value.copy< IR::ID > (v);
        break;

      case 202: // field_ref
        value.copy< IR::Member* > (v);
        break;

      case 161: // meter_spec_list
        value.copy< IR::Meter* > (v);
        break;

      case 147: // field_list_list
      case 165: // name_list
      case 166: // opt_name_list
      case 178: // action_list
        value.copy< IR::NameList* > (v);
        break;

      case 195: // blackbox_config
        value.copy< IR::NameMap<IR::Property>* > (v);
        break;

      case 189: // argument
        value.copy< IR::Parameter* > (v);
        break;

      case 187: // opt_argument_list
      case 188: // argument_list
        value.copy< IR::ParameterList* > (v);
        break;

      case 163: // register_spec_list
        value.copy< IR::Register* > (v);
        break;

      case 153: // parser_statement_list
        value.copy< IR::V1Parser* > (v);
        break;

      case 175: // table_body
        value.copy< IR::V1Table* > (v);
        break;

      case 154: // case_entry_list
        value.copy< IR::Vector<IR::CaseEntry>* > (v);
        break;

      case 176: // field_match_list
      case 180: // control_statement_list
      case 181: // control_statement
      case 196: // expressions
      case 197: // pragma_operands
      case 204: // expression_list
      case 205: // opt_expression_list
        value.copy< IR::Vector<IR::Expression>* > (v);
        break;

      case 124: // INTEGER
        value.copy< UnparsedConstant > (v);
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
        value.copy< cstring > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const Attributes v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const BBoxType v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const CaseValue v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ConstType* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const HeaderType v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::ActionFunction* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::ActionProfile* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::ActionSelector* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Annotations* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Apply* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::AttribLocal* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::AttribLocals* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Attribute* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::CalculatedField* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::CaseEntry* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Constant* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Counter* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Direction v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Expression* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::FieldList* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::FieldListCalculation* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::ID v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Member* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Meter* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::NameList* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::NameMap<IR::Property>* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Parameter* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::ParameterList* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Register* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::V1Parser* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::V1Table* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Vector<IR::CaseEntry>* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const IR::Vector<IR::Expression>* v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const UnparsedConstant v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  V1Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const cstring v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  inline
  V1Parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  V1Parser::basic_symbol<Base>::clear ()
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
      case 133: // opt_field_modifiers
      case 134: // attributes
      case 135: // attrib
        value.template destroy< Attributes > ();
        break;

      case 184: // blackbox_body
        value.template destroy< BBoxType > ();
        break;

      case 156: // case_value
        value.template destroy< CaseValue > ();
        break;

      case 132: // bit_width
      case 138: // type
        value.template destroy< ConstType* > ();
        break;

      case 130: // header_dec_body
      case 131: // field_declarations
        value.template destroy< HeaderType > ();
        break;

      case 168: // action_function_body
      case 169: // action_statement_list
        value.template destroy< IR::ActionFunction* > ();
        break;

      case 171: // action_profile_body
        value.template destroy< IR::ActionProfile* > ();
        break;

      case 173: // action_selector_body
        value.template destroy< IR::ActionSelector* > ();
        break;

      case 186: // blackbox_method
        value.template destroy< IR::Annotations* > ();
        break;

      case 182: // apply_case_list
        value.template destroy< IR::Apply* > ();
        break;

      case 193: // local_var
        value.template destroy< IR::AttribLocal* > ();
        break;

      case 191: // opt_locals_list
      case 192: // locals_list
        value.template destroy< IR::AttribLocals* > ();
        break;

      case 185: // blackbox_attribute
        value.template destroy< IR::Attribute* > ();
        break;

      case 149: // update_verify_spec_list
        value.template destroy< IR::CalculatedField* > ();
        break;

      case 155: // case_value_list
        value.template destroy< IR::CaseEntry* > ();
        break;

      case 203: // const_expression
        value.template destroy< IR::Constant* > ();
        break;

      case 159: // counter_spec_list
        value.template destroy< IR::Counter* > ();
        break;

      case 190: // inout
        value.template destroy< IR::Direction > ();
        break;

      case 150: // opt_condition
      case 177: // field_or_masked_ref
      case 198: // pragma_operand
      case 199: // expression
      case 200: // header_or_field_ref
      case 201: // header_ref
        value.template destroy< IR::Expression* > ();
        break;

      case 144: // field_list_entries
        value.template destroy< IR::FieldList* > ();
        break;

      case 146: // field_list_calculation_body
        value.template destroy< IR::FieldListCalculation* > ();
        break;

      case 206: // name
        value.template destroy< IR::ID > ();
        break;

      case 202: // field_ref
        value.template destroy< IR::Member* > ();
        break;

      case 161: // meter_spec_list
        value.template destroy< IR::Meter* > ();
        break;

      case 147: // field_list_list
      case 165: // name_list
      case 166: // opt_name_list
      case 178: // action_list
        value.template destroy< IR::NameList* > ();
        break;

      case 195: // blackbox_config
        value.template destroy< IR::NameMap<IR::Property>* > ();
        break;

      case 189: // argument
        value.template destroy< IR::Parameter* > ();
        break;

      case 187: // opt_argument_list
      case 188: // argument_list
        value.template destroy< IR::ParameterList* > ();
        break;

      case 163: // register_spec_list
        value.template destroy< IR::Register* > ();
        break;

      case 153: // parser_statement_list
        value.template destroy< IR::V1Parser* > ();
        break;

      case 175: // table_body
        value.template destroy< IR::V1Table* > ();
        break;

      case 154: // case_entry_list
        value.template destroy< IR::Vector<IR::CaseEntry>* > ();
        break;

      case 176: // field_match_list
      case 180: // control_statement_list
      case 181: // control_statement
      case 196: // expressions
      case 197: // pragma_operands
      case 204: // expression_list
      case 205: // opt_expression_list
        value.template destroy< IR::Vector<IR::Expression>* > ();
        break;

      case 124: // INTEGER
        value.template destroy< UnparsedConstant > ();
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
  V1Parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  V1Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 133: // opt_field_modifiers
      case 134: // attributes
      case 135: // attrib
        value.move< Attributes > (s.value);
        break;

      case 184: // blackbox_body
        value.move< BBoxType > (s.value);
        break;

      case 156: // case_value
        value.move< CaseValue > (s.value);
        break;

      case 132: // bit_width
      case 138: // type
        value.move< ConstType* > (s.value);
        break;

      case 130: // header_dec_body
      case 131: // field_declarations
        value.move< HeaderType > (s.value);
        break;

      case 168: // action_function_body
      case 169: // action_statement_list
        value.move< IR::ActionFunction* > (s.value);
        break;

      case 171: // action_profile_body
        value.move< IR::ActionProfile* > (s.value);
        break;

      case 173: // action_selector_body
        value.move< IR::ActionSelector* > (s.value);
        break;

      case 186: // blackbox_method
        value.move< IR::Annotations* > (s.value);
        break;

      case 182: // apply_case_list
        value.move< IR::Apply* > (s.value);
        break;

      case 193: // local_var
        value.move< IR::AttribLocal* > (s.value);
        break;

      case 191: // opt_locals_list
      case 192: // locals_list
        value.move< IR::AttribLocals* > (s.value);
        break;

      case 185: // blackbox_attribute
        value.move< IR::Attribute* > (s.value);
        break;

      case 149: // update_verify_spec_list
        value.move< IR::CalculatedField* > (s.value);
        break;

      case 155: // case_value_list
        value.move< IR::CaseEntry* > (s.value);
        break;

      case 203: // const_expression
        value.move< IR::Constant* > (s.value);
        break;

      case 159: // counter_spec_list
        value.move< IR::Counter* > (s.value);
        break;

      case 190: // inout
        value.move< IR::Direction > (s.value);
        break;

      case 150: // opt_condition
      case 177: // field_or_masked_ref
      case 198: // pragma_operand
      case 199: // expression
      case 200: // header_or_field_ref
      case 201: // header_ref
        value.move< IR::Expression* > (s.value);
        break;

      case 144: // field_list_entries
        value.move< IR::FieldList* > (s.value);
        break;

      case 146: // field_list_calculation_body
        value.move< IR::FieldListCalculation* > (s.value);
        break;

      case 206: // name
        value.move< IR::ID > (s.value);
        break;

      case 202: // field_ref
        value.move< IR::Member* > (s.value);
        break;

      case 161: // meter_spec_list
        value.move< IR::Meter* > (s.value);
        break;

      case 147: // field_list_list
      case 165: // name_list
      case 166: // opt_name_list
      case 178: // action_list
        value.move< IR::NameList* > (s.value);
        break;

      case 195: // blackbox_config
        value.move< IR::NameMap<IR::Property>* > (s.value);
        break;

      case 189: // argument
        value.move< IR::Parameter* > (s.value);
        break;

      case 187: // opt_argument_list
      case 188: // argument_list
        value.move< IR::ParameterList* > (s.value);
        break;

      case 163: // register_spec_list
        value.move< IR::Register* > (s.value);
        break;

      case 153: // parser_statement_list
        value.move< IR::V1Parser* > (s.value);
        break;

      case 175: // table_body
        value.move< IR::V1Table* > (s.value);
        break;

      case 154: // case_entry_list
        value.move< IR::Vector<IR::CaseEntry>* > (s.value);
        break;

      case 176: // field_match_list
      case 180: // control_statement_list
      case 181: // control_statement
      case 196: // expressions
      case 197: // pragma_operands
      case 204: // expression_list
      case 205: // opt_expression_list
        value.move< IR::Vector<IR::Expression>* > (s.value);
        break;

      case 124: // INTEGER
        value.move< UnparsedConstant > (s.value);
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
        value.move< cstring > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
  V1Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  V1Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  V1Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  V1Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  V1Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  V1Parser::by_type::type_get () const
  {
    return type;
  }

  inline
  V1Parser::token_type
  V1Parser::by_type::token () const
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
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380
    };
    return static_cast<token_type> (yytoken_number_[type]);
  }
  // Implementation of make_symbol for each symbol type.
  V1Parser::symbol_type
  V1Parser::make_END (const location_type& l)
  {
    return symbol_type (token::TOK_END, l);
  }

  V1Parser::symbol_type
  V1Parser::make_UNEXPECTED_TOKEN (const location_type& l)
  {
    return symbol_type (token::TOK_UNEXPECTED_TOKEN, l);
  }

  V1Parser::symbol_type
  V1Parser::make_LE (const location_type& l)
  {
    return symbol_type (token::TOK_LE, l);
  }

  V1Parser::symbol_type
  V1Parser::make_GE (const location_type& l)
  {
    return symbol_type (token::TOK_GE, l);
  }

  V1Parser::symbol_type
  V1Parser::make_SHL (const location_type& l)
  {
    return symbol_type (token::TOK_SHL, l);
  }

  V1Parser::symbol_type
  V1Parser::make_SHR (const location_type& l)
  {
    return symbol_type (token::TOK_SHR, l);
  }

  V1Parser::symbol_type
  V1Parser::make_AND (const location_type& l)
  {
    return symbol_type (token::TOK_AND, l);
  }

  V1Parser::symbol_type
  V1Parser::make_OR (const location_type& l)
  {
    return symbol_type (token::TOK_OR, l);
  }

  V1Parser::symbol_type
  V1Parser::make_NE (const location_type& l)
  {
    return symbol_type (token::TOK_NE, l);
  }

  V1Parser::symbol_type
  V1Parser::make_EQ (const location_type& l)
  {
    return symbol_type (token::TOK_EQ, l);
  }

  V1Parser::symbol_type
  V1Parser::make_PLUS (const location_type& l)
  {
    return symbol_type (token::TOK_PLUS, l);
  }

  V1Parser::symbol_type
  V1Parser::make_MINUS (const location_type& l)
  {
    return symbol_type (token::TOK_MINUS, l);
  }

  V1Parser::symbol_type
  V1Parser::make_MUL (const location_type& l)
  {
    return symbol_type (token::TOK_MUL, l);
  }

  V1Parser::symbol_type
  V1Parser::make_DIV (const location_type& l)
  {
    return symbol_type (token::TOK_DIV, l);
  }

  V1Parser::symbol_type
  V1Parser::make_MOD (const location_type& l)
  {
    return symbol_type (token::TOK_MOD, l);
  }

  V1Parser::symbol_type
  V1Parser::make_BIT_OR (const location_type& l)
  {
    return symbol_type (token::TOK_BIT_OR, l);
  }

  V1Parser::symbol_type
  V1Parser::make_BIT_AND (const location_type& l)
  {
    return symbol_type (token::TOK_BIT_AND, l);
  }

  V1Parser::symbol_type
  V1Parser::make_BIT_XOR (const location_type& l)
  {
    return symbol_type (token::TOK_BIT_XOR, l);
  }

  V1Parser::symbol_type
  V1Parser::make_COMPLEMENT (const location_type& l)
  {
    return symbol_type (token::TOK_COMPLEMENT, l);
  }

  V1Parser::symbol_type
  V1Parser::make_L_BRACKET (const location_type& l)
  {
    return symbol_type (token::TOK_L_BRACKET, l);
  }

  V1Parser::symbol_type
  V1Parser::make_R_BRACKET (const location_type& l)
  {
    return symbol_type (token::TOK_R_BRACKET, l);
  }

  V1Parser::symbol_type
  V1Parser::make_L_BRACE (const location_type& l)
  {
    return symbol_type (token::TOK_L_BRACE, l);
  }

  V1Parser::symbol_type
  V1Parser::make_R_BRACE (const location_type& l)
  {
    return symbol_type (token::TOK_R_BRACE, l);
  }

  V1Parser::symbol_type
  V1Parser::make_L_ANGLE (const location_type& l)
  {
    return symbol_type (token::TOK_L_ANGLE, l);
  }

  V1Parser::symbol_type
  V1Parser::make_R_ANGLE (const location_type& l)
  {
    return symbol_type (token::TOK_R_ANGLE, l);
  }

  V1Parser::symbol_type
  V1Parser::make_L_PAREN (const location_type& l)
  {
    return symbol_type (token::TOK_L_PAREN, l);
  }

  V1Parser::symbol_type
  V1Parser::make_R_PAREN (const location_type& l)
  {
    return symbol_type (token::TOK_R_PAREN, l);
  }

  V1Parser::symbol_type
  V1Parser::make_NOT (const location_type& l)
  {
    return symbol_type (token::TOK_NOT, l);
  }

  V1Parser::symbol_type
  V1Parser::make_COLON (const location_type& l)
  {
    return symbol_type (token::TOK_COLON, l);
  }

  V1Parser::symbol_type
  V1Parser::make_COMMA (const location_type& l)
  {
    return symbol_type (token::TOK_COMMA, l);
  }

  V1Parser::symbol_type
  V1Parser::make_DOT (const location_type& l)
  {
    return symbol_type (token::TOK_DOT, l);
  }

  V1Parser::symbol_type
  V1Parser::make_ASSIGN (const location_type& l)
  {
    return symbol_type (token::TOK_ASSIGN, l);
  }

  V1Parser::symbol_type
  V1Parser::make_SEMICOLON (const location_type& l)
  {
    return symbol_type (token::TOK_SEMICOLON, l);
  }

  V1Parser::symbol_type
  V1Parser::make_NEWLINE (const location_type& l)
  {
    return symbol_type (token::TOK_NEWLINE, l);
  }

  V1Parser::symbol_type
  V1Parser::make_ACTION (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_ACTION, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_ACTIONS (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_ACTIONS, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_ACTION_PROFILE (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_ACTION_PROFILE, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_ACTION_SELECTOR (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_ACTION_SELECTOR, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_ALGORITHM (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_ALGORITHM, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_APPLY (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_APPLY, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_ATTRIBUTE (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_ATTRIBUTE, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_ATTRIBUTES (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_ATTRIBUTES, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_BIT (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_BIT, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_BLACKBOX (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_BLACKBOX, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_BLACKBOX_TYPE (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_BLACKBOX_TYPE, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_BLOCK (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_BLOCK, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_BOOL (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_BOOL, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_CALCULATED_FIELD (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_CALCULATED_FIELD, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_CONTROL (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_CONTROL, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_COUNTER (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_COUNTER, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_CONST (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_CONST, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_CURRENT (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_CURRENT, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_DEFAULT (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_DEFAULT, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_DEFAULT_ACTION (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_DEFAULT_ACTION, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_DIRECT (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_DIRECT, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_DROP (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_DROP, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_DYNAMIC_ACTION_SELECTION (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_DYNAMIC_ACTION_SELECTION, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_ELSE (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_ELSE, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_EXTRACT (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_EXTRACT, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_EXPRESSION (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_EXPRESSION, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_EXPRESSION_LOCAL_VARIABLES (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_EXPRESSION_LOCAL_VARIABLES, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_FALSE (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_FALSE, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_FIELD_LIST (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_FIELD_LIST, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_FIELD_LIST_CALCULATION (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_FIELD_LIST_CALCULATION, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_FIELDS (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_FIELDS, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_HEADER (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_HEADER, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_HEADER_TYPE (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_HEADER_TYPE, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_IF (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_IF, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_IMPLEMENTATION (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_IMPLEMENTATION, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_IN (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_IN, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_INPUT (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_INPUT, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_INSTANCE_COUNT (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_INSTANCE_COUNT, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_INT (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_INT, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_LATEST (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_LATEST, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_LAYOUT (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_LAYOUT, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_LENGTH (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_LENGTH, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_MASK (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_MASK, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_MAX_LENGTH (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_MAX_LENGTH, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_MAX_SIZE (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_MAX_SIZE, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_MAX_WIDTH (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_MAX_WIDTH, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_METADATA (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_METADATA, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_METER (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_METER, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_METHOD (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_METHOD, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_MIN_SIZE (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_MIN_SIZE, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_MIN_WIDTH (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_MIN_WIDTH, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_OPTIONAL (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_OPTIONAL, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_OUT (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_OUT, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_OUTPUT_WIDTH (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_OUTPUT_WIDTH, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_PARSE_ERROR (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_PARSE_ERROR, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_PARSER (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_PARSER, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_PARSER_VALUE_SET (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_PARSER_VALUE_SET, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_PARSER_EXCEPTION (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_PARSER_EXCEPTION, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_PAYLOAD (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_PAYLOAD, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_PRAGMA (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_PRAGMA, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_PREFIX (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_PREFIX, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_PRE_COLOR (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_PRE_COLOR, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_PRIMITIVE_ACTION (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_PRIMITIVE_ACTION, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_READS (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_READS, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_REGISTER (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_REGISTER, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_RESULT (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_RESULT, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_RETURN (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_RETURN, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_SATURATING (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_SATURATING, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_SELECT (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_SELECT, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_SELECTION_KEY (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_SELECTION_KEY, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_SELECTION_MODE (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_SELECTION_MODE, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_SELECTION_TYPE (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_SELECTION_TYPE, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_SET_METADATA (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_SET_METADATA, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_SIGNED (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_SIGNED, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_SIZE (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_SIZE, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_STATIC (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_STATIC, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_STRING (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_STRING, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_TABLE (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_TABLE, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_TRUE (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_TRUE, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_TYPE (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_TYPE, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_UPDATE (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_UPDATE, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_VALID (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_VALID, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_VERIFY (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_VERIFY, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_WIDTH (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_WIDTH, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_WRITES (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_WRITES, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_IDENTIFIER (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_IDENTIFIER, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_STRING_LITERAL (const cstring& v, const location_type& l)
  {
    return symbol_type (token::TOK_STRING_LITERAL, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_INTEGER (const UnparsedConstant& v, const location_type& l)
  {
    return symbol_type (token::TOK_INTEGER, v, l);
  }

  V1Parser::symbol_type
  V1Parser::make_EXPRLIST (const location_type& l)
  {
    return symbol_type (token::TOK_EXPRLIST, l);
  }


#line 23 "parsers/v1/v1parser.ypp" // lalr1.cc:377
} // V1
#line 3806 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/parsers/v1/v1parser.hpp" // lalr1.cc:377




#endif // !YY_YY_MEDIA_YEC_WORK_PROGRAMS_P4_VERIFICATION_P4B_TRANSLATOR_BUILD_FRONTENDS_PARSERS_V1_V1PARSER_HPP_INCLUDED
