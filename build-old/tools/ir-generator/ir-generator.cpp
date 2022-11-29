/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 17 "ir-generator.ypp" /* yacc.c:339  */
 /* -*-C++-*- */
// some of these includes are needed by lex-generated file

#include <assert.h>
#include <limits.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include <iostream>
#include <cerrno>
#include <vector>

#include "lib/cstring.h"
#include "lib/stringref.h"
#include "lib/source_file.h"
#include "lib/error.h"
#include "tools/ir-generator/irclass.h"

#ifndef YYDEBUG
#define YYDEBUG 1
#endif

#define YYLTYPE Util::SourceInfo
#define YYLLOC_DEFAULT(Cur, Rhs, N)                                     \
    ((Cur) = (N) ? YYRHSLOC(Rhs, 1) + YYRHSLOC(Rhs, N)                  \
                 : Util::SourceInfo(sources, YYRHSLOC(Rhs, 0).getEnd()))

static void yyerror(const char *fmt, ...);
static std::vector<IrElement*> global;
static CommentBlock *currCommentBlock = nullptr;

namespace {  // anonymous namespace
static int yylex();

static Util::InputSources *sources = new Util::InputSources;
static IrNamespace *current_namespace = LookupScope().resolve(0);


#line 106 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "ir-generator.hpp".  */
#ifndef YY_YY_MEDIA_YEC_WORK_PROGRAMS_P4_VERIFICATION_P4B_TRANSLATOR_BUILD_TOOLS_IR_GENERATOR_IR_GENERATOR_HPP_INCLUDED
# define YY_YY_MEDIA_YEC_WORK_PROGRAMS_P4_VERIFICATION_P4B_TRANSLATOR_BUILD_TOOLS_IR_GENERATOR_IR_GENERATOR_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ABSTRACT = 258,
    APPLY = 259,
    CLASS = 260,
    CONST = 261,
    DBLCOL = 262,
    DEFAULT = 263,
    DELETE = 264,
    INLINE = 265,
    INTERFACE = 266,
    NAMESPACE = 267,
    NEW = 268,
    NULLOK = 269,
    OPERATOR = 270,
    OPTIONAL = 271,
    PRIVATE = 272,
    PROTECTED = 273,
    PUBLIC = 274,
    STATIC = 275,
    VIRTUAL = 276,
    BLOCK = 277,
    COMMENTBLOCK = 278,
    IDENTIFIER = 279,
    INTEGER = 280,
    NO = 281,
    STRING = 282,
    ZERO = 283,
    EMITBLOCK = 284
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 57 "ir-generator.ypp" /* yacc.c:355  */

    YYSTYPE() {}
    int                         i;
    cstring                     str;
    IrClass                     *irClass;
    IrElement                   *irElement;
    IrField                     *irField;
    IrMethod                    *irMethod;
    IrNamespace                 *irNamespace;
    ConstFieldInitializer       *constFieldInit;
    LookupScope                 *lookup;
    std::vector<const Type *>   *types;
    Type                        *type;
    NodeKind                    kind;
    struct {
        bool                    impl;
        cstring                 block;
    }                           emit;

#line 196 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_MEDIA_YEC_WORK_PROGRAMS_P4_VERIFICATION_P4B_TRANSLATOR_BUILD_TOOLS_IR_GENERATOR_IR_GENERATOR_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */
#line 101 "ir-generator.ypp" /* yacc.c:358  */

static void
symbol_print(FILE* file, int type, YYSTYPE value)
{
    switch (type)
    {
    case EMITBLOCK:
        fprintf(file, "%s%s", value.emit.impl ? "/*impl*/ " : "", value.emit.block.c_str());
        break;
    case BLOCK:
    case COMMENTBLOCK:
    case IDENTIFIER:
    case STRING:
    case NO:
    case INTEGER:
    case ZERO:
        fprintf(file, "%s", value.str.c_str());
        break;
    default:
        break;
    }
}

#define YYPRINT(file, type, value)   symbol_print(file, type, value)

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-function"
#include "ir-generator-lex.c"
#pragma GCC diagnostic pop

static cstring canon_name(cstring name) {
    /* canonical method names for backwards compatibility */
    if (name == "visitchildren") return "visit_children";
    return name;
}

static void pushCurrentComment() {
    if (currCommentBlock) {
        global.push_back(currCommentBlock);
        currCommentBlock = nullptr;
    }
}


#line 272 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
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


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   189

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  177

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,     2,     2,     2,    43,     2,
      35,    36,    44,    45,    34,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,    32,
      39,    37,    40,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,    31,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   149,   149,   151,   155,   161,   167,   170,   171,   170,
     176,   180,   181,   182,   187,   186,   193,   194,   198,   199,
     203,   204,   205,   209,   210,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   227,   230,   234,   236,
     239,   245,   238,   250,   249,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   280,   280,   283,   287,   293,   293,
     296,   297,   300,   301,   302,   303,   304,   308,   312,   319,
     320,   321,   322,   323,   326,   326,   328,   328,   331,   332,
     333,   337,   338,   339,   342,   343,   344,   345,   346,   349,
     350,   351,   352,   353,   354,   355,   359,   360,   364,   365,
     369,   370,   374,   375,   378,   384,   384,   384,   384,   385,
     386,   387,   390,   391,   392
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ABSTRACT", "APPLY", "CLASS", "CONST",
  "DBLCOL", "DEFAULT", "DELETE", "INLINE", "INTERFACE", "NAMESPACE", "NEW",
  "NULLOK", "OPERATOR", "OPTIONAL", "PRIVATE", "PROTECTED", "PUBLIC",
  "STATIC", "VIRTUAL", "BLOCK", "COMMENTBLOCK", "IDENTIFIER", "INTEGER",
  "NO", "STRING", "ZERO", "EMITBLOCK", "'{'", "'}'", "';'", "':'", "','",
  "'('", "')'", "'='", "'!'", "'<'", "'>'", "'['", "']'", "'&'", "'*'",
  "'+'", "$accept", "input", "element", "$@1", "$@2", "scope", "irclass",
  "@3", "parentList", "nonEmptyParentList", "kind", "partList", "part",
  "$@4", "@5", "method", "@6", "$@7", "@8", "methodName", "optArgList",
  "argList", "optConst", "optOverride", "body", "irField", "modifier",
  "modifiers", "fieldName", "optInitializer", "lookup_scope", "nonRefType",
  "type", "type_args", "type_arg", "optTypeList", "typeList",
  "constFieldInit", "expression", "name", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     123,   125,    59,    58,    44,    40,    41,    61,    33,    60,
      62,    91,    93,    38,    42,    43
};
# endif

#define YYPACT_NINF -116

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-116)))

#define YYTABLE_NINF -46

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -116,    57,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,    19,   -14,  -116,    -9,  -116,    21,    49,  -116,
      95,    70,  -116,    59,  -116,    31,    47,     7,   -33,     5,
    -116,    53,   129,  -116,    95,  -116,    99,    95,    82,    60,
    -116,  -116,  -116,  -116,  -116,  -116,     5,  -116,    -1,    65,
    -116,    66,  -116,  -116,    92,    95,    95,  -116,  -116,  -116,
    -116,    79,    80,    81,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,   130,  -116,     5,    86,    90,  -116,   101,  -116,  -116,
    -116,    59,  -116,  -116,   137,  -116,  -116,  -116,    56,    39,
    -116,    -3,  -116,    95,    96,    51,    91,    97,    33,    -7,
    -116,   139,  -116,  -116,  -116,    98,   104,   105,     5,  -116,
    -116,   105,  -116,  -116,  -116,  -116,  -116,  -116,    95,   108,
    -116,  -116,  -116,  -116,    42,    11,  -116,   134,   116,  -116,
     117,  -116,   119,     1,    11,  -116,   121,   110,   136,   108,
      95,  -116,   -16,  -116,   112,  -116,   133,    95,   105,  -116,
    -116,  -116,    13,   135,  -116,     0,     3,  -116,  -116,   159,
    -116,  -116,     8,  -116,   105,  -116,   154,   147,   148,   149,
    -116,  -116,     0,  -116,  -116,  -116,  -116
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    21,    22,    20,     7,     5,     6,    10,
       3,     4,    11,     0,    12,     0,     8,    16,     0,    13,
       0,     0,     2,     0,    81,    84,    17,     0,    89,    18,
      14,     0,     0,    82,     0,    86,    85,     0,     0,     0,
      90,    93,    23,     9,    92,    95,    19,    83,    98,     0,
      96,     0,    91,    94,    74,   100,     0,    87,    88,    33,
      34,     0,     0,     0,    37,    26,    25,    15,    24,    31,
      30,     0,    32,   102,     0,   101,    97,     0,    27,    28,
      29,     0,    70,    69,     0,    71,    72,    73,    84,     0,
      75,     0,    99,     0,     0,     0,     0,     0,    50,    52,
      40,     0,    38,    39,    77,    76,     0,    78,   103,    35,
      76,    78,    46,    47,    48,    51,    49,    53,    55,     0,
     112,   107,   106,   108,     0,   105,    43,     0,     0,    23,
       0,    41,    54,     0,   111,   104,     0,     0,     0,     0,
      55,    80,    79,    67,    74,    68,     0,     0,    78,   109,
     110,   113,     0,     0,    36,     0,     0,    56,   114,    58,
      62,    66,     0,    42,    78,    59,    60,     0,     0,     0,
      57,    61,     0,    64,    65,    63,    44
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,   160,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,    54,  -116,  -116,  -116,  -116,  -116,  -116,  -116,    93,
      45,  -116,  -116,  -116,    14,  -116,  -116,  -116,    94,  -109,
    -116,   -22,   -20,  -116,   131,  -116,  -116,  -116,    61,  -115
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    10,    13,    18,    15,    11,    42,    21,    26,
      12,    54,    68,    77,   129,    69,   118,   146,   140,    89,
     131,   132,   166,   172,   163,    70,    90,    71,   107,   128,
      27,    28,    48,    49,    50,    74,    75,    72,   124,   125
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,    32,   130,    39,   134,    39,    37,    39,    38,    39,
      16,    39,    84,   104,    46,    17,   167,   168,   138,   136,
     138,   105,   160,    35,   152,   148,    14,   164,    19,   137,
     116,    36,   161,   117,    55,    73,   169,   162,    33,   157,
      40,    41,    40,    41,    40,    41,    40,    41,    40,    41,
     139,    91,   139,   158,    20,   170,     3,     2,     4,    95,
       3,   102,     4,    33,     5,     6,    24,   104,     5,     6,
     114,   103,   115,   108,   135,   110,     7,   136,   -45,    22,
       7,    34,     8,    25,    43,     9,     8,   137,   -45,     9,
      37,   100,    38,   101,    44,    45,    59,    60,   133,    56,
      30,    23,    24,    52,    53,    57,    47,    51,    58,    61,
      62,    63,    78,    79,    80,    64,    59,    60,    65,    25,
     133,    66,    92,    67,    93,    94,   109,   156,   112,    61,
      62,    63,   120,   -45,   113,    64,    81,    24,    65,   126,
      82,    66,   127,   154,    83,    84,    85,   119,   143,   145,
      86,    87,   119,   147,    88,   150,   141,   149,   120,   121,
     151,   122,   123,   120,   121,   165,   122,   123,    37,   155,
      38,   159,    44,    45,    96,    97,    98,    99,   171,   173,
     174,   175,    31,   144,   106,   153,   176,    76,   142,   111
};

static const yytype_uint8 yycheck[] =
{
      20,    23,   111,     6,   119,     6,    39,     6,    41,     6,
      24,     6,    15,    16,    34,    24,     8,     9,     7,    35,
       7,    24,    22,    16,   139,    24,     7,    24,     7,    45,
      37,    24,    32,    40,    35,    55,    28,    37,     7,   148,
      43,    44,    43,    44,    43,    44,    43,    44,    43,    44,
      39,    71,    39,    40,    33,   164,     3,     0,     5,    81,
       3,    22,     5,     7,    11,    12,     7,    16,    11,    12,
      37,    32,    39,    93,    32,    24,    23,    35,    22,    30,
      23,    34,    29,    24,    31,    32,    29,    45,    32,    32,
      39,    35,    41,    37,    43,    44,     4,     5,   118,    34,
      30,     6,     7,    43,    44,    40,     7,    25,    42,    17,
      18,    19,    33,    33,    33,    23,     4,     5,    26,    24,
     140,    29,    36,    31,    34,    24,    30,   147,    37,    17,
      18,    19,    24,    35,    37,    23,     6,     7,    26,    35,
      10,    29,    37,    31,    14,    15,    16,    13,    32,    32,
      20,    21,    13,    34,    24,    45,    22,    36,    24,    25,
      24,    27,    28,    24,    25,     6,    27,    28,    39,    36,
      41,    36,    43,    44,    37,    38,    39,    40,    24,    32,
      32,    32,    22,   129,    91,   140,   172,    56,   127,    95
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,     0,     3,     5,    11,    12,    23,    29,    32,
      48,    52,    56,    49,     7,    51,    24,    24,    50,     7,
      33,    54,    30,     6,     7,    24,    55,    76,    77,    78,
      30,    47,    77,     7,    34,    16,    24,    39,    41,     6,
      43,    44,    53,    31,    43,    44,    78,     7,    78,    79,
      80,    25,    43,    44,    57,    35,    34,    40,    42,     4,
       5,    17,    18,    19,    23,    26,    29,    31,    58,    61,
      71,    73,    83,    78,    81,    82,    80,    59,    33,    33,
      33,     6,    10,    14,    15,    16,    20,    21,    24,    65,
      72,    78,    36,    34,    24,    77,    37,    38,    39,    40,
      35,    37,    22,    32,    16,    24,    65,    74,    78,    30,
      24,    74,    37,    37,    37,    39,    37,    40,    62,    13,
      24,    25,    27,    28,    84,    85,    35,    37,    75,    60,
      75,    66,    67,    78,    85,    32,    35,    45,     7,    39,
      64,    22,    84,    32,    57,    32,    63,    34,    24,    36,
      45,    24,    85,    66,    31,    36,    78,    75,    40,    36,
      22,    32,    37,    70,    24,     6,    68,     8,     9,    28,
      75,    24,    69,    32,    32,    32,    70
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    48,    49,    50,    48,
      48,    51,    51,    51,    53,    52,    54,    54,    55,    55,
      56,    56,    56,    57,    57,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    59,    60,    58,    58,    61,    61,
      62,    63,    61,    64,    61,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    66,    66,    67,    67,    68,    68,
      69,    69,    70,    70,    70,    70,    70,    71,    71,    72,
      72,    72,    72,    72,    73,    73,    74,    74,    75,    75,
      75,    76,    76,    76,    77,    77,    77,    77,    77,    78,
      78,    78,    78,    78,    78,    78,    79,    79,    80,    80,
      81,    81,    82,    82,    83,    84,    84,    84,    84,    84,
      84,    84,    85,    85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     0,     0,     7,
       1,     0,     1,     3,     0,     8,     0,     2,     1,     3,
       1,     1,     1,     0,     2,     1,     1,     2,     2,     2,
       1,     1,     1,     1,     0,     0,     7,     1,     3,     3,
       0,     0,     8,     0,    10,     1,     3,     3,     3,     3,
       2,     3,     2,     3,     1,     0,     3,     5,     0,     1,
       0,     1,     1,     3,     3,     3,     1,     5,     6,     1,
       1,     1,     1,     1,     0,     2,     1,     1,     0,     2,
       2,     1,     2,     3,     1,     2,     2,     4,     4,     1,
       2,     3,     3,     2,     3,     3,     1,     3,     1,     4,
       0,     1,     1,     3,     5,     1,     1,     1,     1,     3,
       3,     2,     1,     3,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
#line 155 "ir-generator.ypp" /* yacc.c:1646  */
    {
        if (currCommentBlock) {
            (yyvsp[0].irClass)->comments.push_back(currCommentBlock);
            currCommentBlock = nullptr;
        }
        global.push_back((yyvsp[0].irClass)); }
#line 1581 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 161 "ir-generator.ypp" /* yacc.c:1646  */
    {
        if (!currCommentBlock) {
            currCommentBlock = new CommentBlock((yylsp[0]), (yyvsp[0].str));
        } else {
            currCommentBlock->append((yyvsp[0].str));
            currCommentBlock->srcInfo += (yylsp[0]); }}
#line 1592 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 167 "ir-generator.ypp" /* yacc.c:1646  */
    {
        pushCurrentComment();
        global.push_back(new EmitBlock((yylsp[0]), (yyvsp[0].emit).impl, (yyvsp[0].emit).block)); }
#line 1600 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 170 "ir-generator.ypp" /* yacc.c:1646  */
    { BEGIN(PARSE_BRACKET); }
#line 1606 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 171 "ir-generator.ypp" /* yacc.c:1646  */
    { current_namespace = IrNamespace::get(current_namespace, (yyvsp[0].str)); }
#line 1612 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 172 "ir-generator.ypp" /* yacc.c:1646  */
    {
        current_namespace = current_namespace->parent;
        pushCurrentComment();
        }
#line 1621 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 176 "ir-generator.ypp" /* yacc.c:1646  */
    { pushCurrentComment(); }
#line 1627 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 180 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.irNamespace) = current_namespace; }
#line 1633 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 181 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.irNamespace) = nullptr; }
#line 1639 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 182 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.irNamespace) = IrNamespace::get((yyvsp[-2].irNamespace), (yyvsp[-1].str)); }
#line 1645 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 187 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.irClass) = new IrClass((yylsp[-2]), (yyvsp[-3].irNamespace), (yyvsp[-4].kind), (yyvsp[-2].str), (yyvsp[-1].types)); }
#line 1651 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 189 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.irClass) = (yyvsp[-2].irClass); }
#line 1657 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 193 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.types) = nullptr; }
#line 1663 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 194 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.types) = (yyvsp[0].types); }
#line 1669 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 198 "ir-generator.ypp" /* yacc.c:1646  */
    { ((yyval.types) = new std::vector<const Type *>())->push_back((yyvsp[0].type)); }
#line 1675 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 199 "ir-generator.ypp" /* yacc.c:1646  */
    { ((yyval.types) = (yyvsp[-2].types))->push_back((yyvsp[0].type)); }
#line 1681 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 203 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.kind) = NodeKind::Interface; BEGIN(PARSE_BRACKET); }
#line 1687 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 204 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.kind) = NodeKind::Abstract; BEGIN(PARSE_BRACKET); }
#line 1693 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 205 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.kind) = NodeKind::Concrete; BEGIN(PARSE_BRACKET); }
#line 1699 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 209 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.irClass) = (yyvsp[0].irClass); }
#line 1705 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 210 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.irClass) = (yyvsp[-1].irClass);
                            if ((yyvsp[0].irElement)) {
                                (yyvsp[0].irElement)->access = (yyval.irClass)->current_access;
                                (yyvsp[0].irElement)->clss = (yyval.irClass);
                                (yyval.irClass)->elements.push_back((yyvsp[0].irElement)); } }
#line 1715 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 218 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.irElement) = new EmitBlock((yylsp[0]), (yyvsp[0].emit).impl, (yyvsp[0].emit).block); }
#line 1721 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 219 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.irElement) = new IrNo((yylsp[0]), (yyvsp[0].str)); }
#line 1727 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 220 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.irElement) = nullptr; (yyvsp[-2].irClass)->current_access = IrElement::Private; }
#line 1733 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 221 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.irElement) = nullptr; (yyvsp[-2].irClass)->current_access = IrElement::Protected; }
#line 1739 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 222 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.irElement) = nullptr; (yyvsp[-2].irClass)->current_access = IrElement::Public; }
#line 1745 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 223 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.irElement) = (yyvsp[0].irField); }
#line 1751 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 224 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.irElement) = (yyvsp[0].irMethod); }
#line 1757 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 225 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.irElement) = (yyvsp[0].constFieldInit); }
#line 1763 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 226 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.irElement) = new IrApply((yylsp[0])); }
#line 1769 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 227 "ir-generator.ypp" /* yacc.c:1646  */
    { BEGIN(PARSE_BRACKET); }
#line 1775 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 228 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.irClass) = new IrClass((yylsp[-2]), &(yyvsp[-4].irClass)->local, NodeKind::Nested, (yyvsp[-1].str)); }
#line 1781 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 229 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.irElement) = (yyvsp[-2].irClass); }
#line 1787 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 230 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.irElement) = new CommentBlock((yylsp[0]), (yyvsp[0].str)); }
#line 1793 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 235 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.irMethod) = new IrMethod((yylsp[-1]), canon_name((yyvsp[-1].str)), (yyvsp[0].str)); }
#line 1799 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 237 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.irMethod) = new IrMethod((yylsp[-1]), canon_name((yyvsp[-1].str))); }
#line 1805 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 239 "ir-generator.ypp" /* yacc.c:1646  */
    { if ((yyvsp[-1].str) != (yyvsp[-3].irClass)->name)
                yyerror("constructor name %s doesn't match class name %s", (yyvsp[-1].str), (yyvsp[-3].irClass)->name);
            if ((yyvsp[-2].i) & ~IrField::Inline)
                yyerror("%s invalid on constructor", IrElement::modifier((yyvsp[-2].i)));
            ((yyval.irMethod) = new IrMethod((yylsp[-1]), (yyvsp[-1].str)))->inImpl = !((yyvsp[-2].i) & IrField::Inline);
            (yyval.irMethod)->clss = (yyvsp[-3].irClass); }
#line 1816 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 245 "ir-generator.ypp" /* yacc.c:1646  */
    { BEGIN(PARSE_CTOR_INIT); }
#line 1822 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 246 "ir-generator.ypp" /* yacc.c:1646  */
    { ((yyval.irMethod) = (yyvsp[-4].irMethod))->body = (yyvsp[0].str);
            (yyval.irMethod)->isUser = true;
            BEGIN(NORMAL); }
#line 1830 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 250 "ir-generator.ypp" /* yacc.c:1646  */
    { ((yyval.irMethod) = new IrMethod((yylsp[-1]), (yyvsp[-1].str)))->rtype = (yyvsp[-2].type);
            (yyval.irMethod)->inImpl = !((yyvsp[-3].i) & IrField::Inline);
            (yyval.irMethod)->isStatic = ((yyvsp[-3].i) & IrField::Static);
            (yyval.irMethod)->isVirtual = ((yyvsp[-3].i) & IrField::Virtual);
            (yyval.irMethod)->clss = (yyvsp[-4].irClass);
            if ((yyvsp[-3].i) & !(IrField::Inline | IrField::Virtual))
                yyerror("%s invalid on method", IrElement::modifier((yyvsp[-3].i))); }
#line 1842 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 258 "ir-generator.ypp" /* yacc.c:1646  */
    { ((yyval.irMethod) = (yyvsp[-5].irMethod))->body = (yyvsp[0].str);
            if (!(yyvsp[0].str) || (yyvsp[0].str)[0] == '=') {
                if (!(yyval.irMethod)->inImpl)
                    yyerror("inline method %s with no body", (yyvsp[-7].str));
                (yyval.irMethod)->inImpl = false; }
            (yyval.irMethod)->isUser = true;
            (yyval.irMethod)->isConst = (yyvsp[-2].i);
            (yyval.irMethod)->isOverride = (yyvsp[-1].i); }
#line 1855 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 270 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.str) = "operator=="; }
#line 1861 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 271 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.str) = "operator!="; }
#line 1867 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 272 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.str) = "operator<="; }
#line 1873 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 273 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.str) = "operator>="; }
#line 1879 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 274 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.str) = "operator<"; }
#line 1885 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 275 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.str) = "operator<<"; }
#line 1891 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 276 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.str) = "operator>"; }
#line 1897 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 277 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.str) = "operator>>"; }
#line 1903 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 284 "ir-generator.ypp" /* yacc.c:1646  */
    { auto *field = new IrField((yylsp[-1]), (yyvsp[-2].type), (yyvsp[-1].str), (yyvsp[0].str));
              field->clss = (yyvsp[-3].irMethod)->clss;
              (yyvsp[-3].irMethod)->args.push_back(field); }
#line 1911 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 288 "ir-generator.ypp" /* yacc.c:1646  */
    { auto *field = new IrField((yylsp[-1]), (yyvsp[-2].type), (yyvsp[-1].str), (yyvsp[0].str));
              field->clss = (yyvsp[-5].irMethod)->clss;
              (yyvsp[-5].irMethod)->args.push_back(field); }
#line 1919 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 293 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.i) = false; }
#line 1925 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 293 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.i) = true; }
#line 1931 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 296 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.i) = false; }
#line 1937 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 297 "ir-generator.ypp" /* yacc.c:1646  */
    { if (!((yyval.i) = (yyvsp[0].str) == "override"))
                            yyerror("syntax error, expecting override or method body"); }
#line 1944 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 301 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.str) = "= 0;"; }
#line 1950 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 302 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.str) = "= default;"; }
#line 1956 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 303 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.str) = "= delete;"; }
#line 1962 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 304 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.str) = nullptr; }
#line 1968 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 309 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.irField) = new IrField((yylsp[-2]), (yyvsp[-3].type), (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[-4].i));
            if ((yyvsp[-4].i) & IrElement::Virtual)
                yyerror("virtual invalid on field %s", (yyvsp[-2].str)); }
#line 1976 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 313 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.irField) = new IrField((yylsp[-2]), (yyvsp[-3].type), (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[-5].i) | IrElement::Const);
            if ((yyvsp[-5].i) & IrElement::Virtual)
                yyerror("virtual invalid on field %s", (yyvsp[-2].str)); }
#line 1984 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 319 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.i) = IrElement::NullOK; }
#line 1990 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 320 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.i) = IrElement::Inline; }
#line 1996 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 321 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.i) = IrElement::Optional; }
#line 2002 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 322 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.i) = IrElement::Static; }
#line 2008 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 323 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.i) = IrElement::Virtual; }
#line 2014 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 326 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 2020 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 326 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[-1].i) | (yyvsp[0].i); }
#line 2026 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 328 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.str) = "optional"; }
#line 2032 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 331 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.str) = nullptr; }
#line 2038 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 332 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2044 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 333 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2050 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 337 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.lookup) = new LookupScope(); }
#line 2056 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 338 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.lookup) = new LookupScope(0, (yyvsp[-1].str)); }
#line 2062 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 339 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.lookup) = new LookupScope((yyvsp[-2].lookup), (yyvsp[-1].str)); }
#line 2068 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 342 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.type) = new NamedType((yylsp[0]), 0, (yyvsp[0].str)); }
#line 2074 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 343 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.type) = new NamedType((yylsp[0]), (yyvsp[-1].lookup), (yyvsp[0].str)); }
#line 2080 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 344 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.type) = new NamedType((yylsp[0]), (yyvsp[-1].lookup), "optional"); }
#line 2086 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 345 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.type) = new TemplateInstantiation((yylsp[-3])+(yylsp[0]), (yyvsp[-3].type), *(yyvsp[-1].types)); }
#line 2092 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 346 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.type) = new ArrayType((yylsp[-3])+(yylsp[0]), (yyvsp[-3].type), atoi((yyvsp[-1].str))); }
#line 2098 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 350 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.type) = new ReferenceType((yyvsp[-1].type)); }
#line 2104 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 351 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.type) = new ReferenceType((yyvsp[-2].type), true); }
#line 2110 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 352 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.type) = new ReferenceType((yyvsp[-1].type), true); }
#line 2116 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 353 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.type) = new PointerType((yyvsp[-1].type)); }
#line 2122 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 354 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.type) = new PointerType((yyvsp[-2].type), true); }
#line 2128 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 355 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.type) = new PointerType((yyvsp[-1].type), true); }
#line 2134 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 359 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.types) = new std::vector<const Type *>{(yyvsp[0].type)}; }
#line 2140 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 360 "ir-generator.ypp" /* yacc.c:1646  */
    { ((yyval.types) = (yyvsp[-2].types))->push_back((yyvsp[0].type)); }
#line 2146 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 364 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 2152 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 365 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.type) = new FunctionType((yyvsp[-3].type), *(yyvsp[-1].types)); }
#line 2158 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 369 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.types) = new std::vector<const Type *>(); }
#line 2164 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 370 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.types) = (yyvsp[0].types); }
#line 2170 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 374 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.types) = new std::vector<const Type *>{(yyvsp[0].type)}; }
#line 2176 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 375 "ir-generator.ypp" /* yacc.c:1646  */
    { ((yyval.types) = (yyvsp[-2].types))->push_back((yyvsp[0].type)); }
#line 2182 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 379 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.constFieldInit) = new ConstFieldInitializer((yylsp[-3]), (yyvsp[-3].str), (yyvsp[-1].str));
            if ((yyvsp[-4].i)) yyerror("%s invalid on constant", IrElement::modifier((yyvsp[-4].i))); }
#line 2189 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 385 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[-2].str) + "()"; }
#line 2195 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 386 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[-2].str) + "++"; }
#line 2201 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 387 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.str) = "new " + (yyvsp[0].str); }
#line 2207 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 391 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[-2].str) + "::" + (yyvsp[0].str); }
#line 2213 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 392 "ir-generator.ypp" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[-3].str) + "<" + (yyvsp[-1].str) + ">"; }
#line 2219 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
    break;


#line 2223 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 397 "ir-generator.ypp" /* yacc.c:1906  */

}  // end anonymous namespace

void yyerror(const char *fmt, ...) {
    auto& context = BaseCompileContext::get();
    if (!strcmp(fmt, "syntax error, unexpected IDENTIFIER")) {
        context.errorReporter().parser_error(sources,
                                             "syntax error, unexpected IDENTIFIER \"%s\"",
                                             yylval.str.c_str());
        return;
    }
    va_list args;
    va_start(args, fmt);
    context.errorReporter().parser_error(sources, fmt, args);
    va_end(args);
}

IrDefinitions *parse(char** files, int count) {
    int errors = 0;
    class IrgenCompileContext : public BaseCompileContext { } ctxt;
    AutoCompileContext ctxt_ctl(&ctxt);
#ifdef YYDEBUG
    if (const char *p = getenv("YYDEBUG"))
        yydebug = atoi(p);
#endif
    if (count <= 0) {
        ::error(ErrorType::ERR_EXPECTED, "No input files specified");
        errors = 1; }

    for (int i = 0; i < count; i++) {
        if (FILE *fp = fopen(files[i], "r")) {
            sources->mapLine(files[i], 1);
            yyrestart(fp);
            BEGIN(NORMAL);
            errors |= yyparse();
            fclose(fp);
            if (errors & 2) {
                error(ErrorType::ERR_OVERLIMIT, "out of memory");
                break; }
        } else {
            ::error(ErrorType::ERR_IO, "Cannot open file %s", files[i]);
            perror("");
            errors |= 1; } }

    return errors ? nullptr : new IrDefinitions(global);
}
