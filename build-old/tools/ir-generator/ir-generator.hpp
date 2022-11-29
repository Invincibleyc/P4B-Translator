/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 57 "ir-generator.ypp" /* yacc.c:1909  */

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

#line 104 "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/ir-generator.hpp" /* yacc.c:1909  */
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
