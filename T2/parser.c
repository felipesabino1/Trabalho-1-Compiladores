/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"
#include "semantico.h"
#include "codegen.h"

extern char *yytext;
extern int yylex();
extern FILE *yyin;
extern int yylineno;
void yyerror(char const *s);
int yylineno_aux;
Node* root;

#line 88 "parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "tokens.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_GLOBAL = 3,                     /* GLOBAL  */
  YYSYMBOL_FUNCAO = 4,                     /* FUNCAO  */
  YYSYMBOL_PRINCIPAL = 5,                  /* PRINCIPAL  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_CAR = 7,                        /* CAR  */
  YYSYMBOL_RETORNE = 8,                    /* RETORNE  */
  YYSYMBOL_LEIA = 9,                       /* LEIA  */
  YYSYMBOL_ESCREVA = 10,                   /* ESCREVA  */
  YYSYMBOL_NOVALINHA = 11,                 /* NOVALINHA  */
  YYSYMBOL_SE = 12,                        /* SE  */
  YYSYMBOL_ENTAO = 13,                     /* ENTAO  */
  YYSYMBOL_SENAO = 14,                     /* SENAO  */
  YYSYMBOL_FIMSE = 15,                     /* FIMSE  */
  YYSYMBOL_ENQUANTO = 16,                  /* ENQUANTO  */
  YYSYMBOL_IDENTIFICADOR = 17,             /* IDENTIFICADOR  */
  YYSYMBOL_CADEIACARACTERES = 18,          /* CADEIACARACTERES  */
  YYSYMBOL_CARCONST = 19,                  /* CARCONST  */
  YYSYMBOL_INTCONST = 20,                  /* INTCONST  */
  YYSYMBOL_ATRIBUICAO = 21,                /* ATRIBUICAO  */
  YYSYMBOL_OU = 22,                        /* OU  */
  YYSYMBOL_E = 23,                         /* E  */
  YYSYMBOL_IGUAL = 24,                     /* IGUAL  */
  YYSYMBOL_DIFERENTE = 25,                 /* DIFERENTE  */
  YYSYMBOL_MAIORIGUAL = 26,                /* MAIORIGUAL  */
  YYSYMBOL_MENORIGUAL = 27,                /* MENORIGUAL  */
  YYSYMBOL_28_ = 28,                       /* '['  */
  YYSYMBOL_29_ = 29,                       /* ']'  */
  YYSYMBOL_30_ = 30,                       /* '{'  */
  YYSYMBOL_31_ = 31,                       /* '}'  */
  YYSYMBOL_32_ = 32,                       /* ':'  */
  YYSYMBOL_33_ = 33,                       /* ';'  */
  YYSYMBOL_34_ = 34,                       /* ','  */
  YYSYMBOL_35_ = 35,                       /* '('  */
  YYSYMBOL_36_ = 36,                       /* ')'  */
  YYSYMBOL_37_ = 37,                       /* '<'  */
  YYSYMBOL_38_ = 38,                       /* '>'  */
  YYSYMBOL_39_ = 39,                       /* '+'  */
  YYSYMBOL_40_ = 40,                       /* '-'  */
  YYSYMBOL_41_ = 41,                       /* '*'  */
  YYSYMBOL_42_ = 42,                       /* '/'  */
  YYSYMBOL_43_ = 43,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_Programa = 45,                  /* Programa  */
  YYSYMBOL_DeclVarGlobais = 46,            /* DeclVarGlobais  */
  YYSYMBOL_VarSection = 47,                /* VarSection  */
  YYSYMBOL_ListaDeclVar = 48,              /* ListaDeclVar  */
  YYSYMBOL_ListVar = 49,                   /* ListVar  */
  YYSYMBOL_DeclFunc = 50,                  /* DeclFunc  */
  YYSYMBOL_ListaFuncoes = 51,              /* ListaFuncoes  */
  YYSYMBOL_ListaParametros = 52,           /* ListaParametros  */
  YYSYMBOL_ListaParametrosTail = 53,       /* ListaParametrosTail  */
  YYSYMBOL_DeclPrograma = 54,              /* DeclPrograma  */
  YYSYMBOL_Bloco = 55,                     /* Bloco  */
  YYSYMBOL_Tipo = 56,                      /* Tipo  */
  YYSYMBOL_ListaComando = 57,              /* ListaComando  */
  YYSYMBOL_Comando = 58,                   /* Comando  */
  YYSYMBOL_Expr = 59,                      /* Expr  */
  YYSYMBOL_LValueExpr = 60,                /* LValueExpr  */
  YYSYMBOL_OrExpr = 61,                    /* OrExpr  */
  YYSYMBOL_AndExpr = 62,                   /* AndExpr  */
  YYSYMBOL_EqExpr = 63,                    /* EqExpr  */
  YYSYMBOL_DesigExpr = 64,                 /* DesigExpr  */
  YYSYMBOL_AddExpr = 65,                   /* AddExpr  */
  YYSYMBOL_MulExpr = 66,                   /* MulExpr  */
  YYSYMBOL_UnExpr = 67,                    /* UnExpr  */
  YYSYMBOL_PrimExpr = 68,                  /* PrimExpr  */
  YYSYMBOL_ListExpr = 69                   /* ListExpr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   199

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,     2,     2,     2,     2,     2,
      35,    36,    41,    39,    34,    40,     2,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    32,    33,
      37,     2,    38,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    28,     2,    29,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    35,    35,    38,    39,    42,    43,    46,    47,    50,
      54,    60,    64,    72,    77,    80,    85,    88,    89,    92,
      97,   102,   107,   114,   117,   118,   121,   122,   125,   126,
     129,   130,   131,   132,   133,   134,   138,   139,   140,   141,
     142,   145,   146,   149,   153,   156,   157,   160,   161,   164,
     165,   166,   169,   170,   171,   172,   173,   176,   177,   178,
     181,   182,   183,   186,   187,   188,   191,   195,   199,   203,
     204,   205,   206,   209,   210
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "GLOBAL", "FUNCAO",
  "PRINCIPAL", "INT", "CAR", "RETORNE", "LEIA", "ESCREVA", "NOVALINHA",
  "SE", "ENTAO", "SENAO", "FIMSE", "ENQUANTO", "IDENTIFICADOR",
  "CADEIACARACTERES", "CARCONST", "INTCONST", "ATRIBUICAO", "OU", "E",
  "IGUAL", "DIFERENTE", "MAIORIGUAL", "MENORIGUAL", "'['", "']'", "'{'",
  "'}'", "':'", "';'", "','", "'('", "')'", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'!'", "$accept", "Programa", "DeclVarGlobais",
  "VarSection", "ListaDeclVar", "ListVar", "DeclFunc", "ListaFuncoes",
  "ListaParametros", "ListaParametrosTail", "DeclPrograma", "Bloco",
  "Tipo", "ListaComando", "Comando", "Expr", "LValueExpr", "OrExpr",
  "AndExpr", "EqExpr", "DesigExpr", "AddExpr", "MulExpr", "UnExpr",
  "PrimExpr", "ListExpr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-133)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-45)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      20,    18,    61,    60,    51,    51,  -133,  -133,    45,    73,
      16,    71,    65,    75,    92,    39,  -133,   116,    51,  -133,
      19,  -133,    88,    46,    96,  -133,   123,  -133,  -133,  -133,
     124,   139,    68,   141,   -11,   126,   125,   127,   103,  -133,
    -133,  -133,    68,    -1,    -1,  -133,   130,    82,   131,   142,
     143,   144,    12,   106,    43,    54,  -133,  -133,    82,   132,
      51,    21,   133,  -133,    24,   135,   145,   137,   138,   146,
    -133,    68,    68,    99,    -5,   136,    -8,  -133,  -133,  -133,
    -133,  -133,    68,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   147,    51,  -133,   148,    19,
     149,    68,  -133,    68,  -133,  -133,  -133,   140,   150,   123,
     151,  -133,  -133,    41,  -133,    68,  -133,   144,    12,   106,
     106,    43,    43,    43,    43,    54,    54,  -133,  -133,  -133,
    -133,   152,   153,    19,   154,   161,    82,   164,    68,  -133,
     159,    19,   139,    39,  -133,    82,  -133,  -133,  -133,   155,
    -133,   158,    90,   139,   156,   163,    82,  -133,  -133,   139,
    -133,   167,   157,  -133,   162,    19,    39,   158,  -133
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,    14,     0,     0,     3,     1,     0,     0,
      11,     0,     0,     0,     0,     0,     2,     0,     0,     5,
       0,     6,     0,     0,     0,    23,     0,     9,    26,    27,
       0,    18,     0,     0,     0,     0,     0,     0,    69,    70,
      71,    30,     0,     0,     0,    40,     0,    28,     0,     0,
      42,    46,    48,    51,    56,    59,    62,    65,     0,    12,
       8,     0,     0,    17,    69,     0,    44,     0,     0,     0,
      36,     0,     0,     0,     0,     0,    69,    63,    64,    24,
      29,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     0,     0,
       0,     0,    32,     0,    33,    35,    34,     0,     0,    71,
       0,    67,    73,     0,    72,     0,    41,    45,    47,    49,
      50,    54,    55,    52,    53,    57,    58,    60,    61,    25,
      10,     0,    19,     0,     0,     0,     0,    68,     0,    66,
       0,     0,     0,     0,    43,     0,    39,    74,    68,    20,
      21,    16,     0,     0,     0,     0,     0,    37,    22,    18,
      13,     0,     0,    38,     0,     0,     0,    16,    15
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,  -133,  -133,   189,     0,   -16,  -133,    30,    36,  -132,
    -133,   -15,   -94,   -30,  -123,   -31,   165,  -133,   113,   115,
      28,    59,    29,    47,   111,  -133
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    24,    13,    12,     9,   155,    62,    63,
      16,    45,    30,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,   113
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    65,    27,    69,    11,   132,    64,    68,    39,    40,
     150,    75,    64,   146,    39,    40,    76,    80,    39,    40,
     115,   158,   152,     1,    42,    28,    29,    74,    95,    43,
      42,   111,    44,   161,    42,    43,    85,    86,    44,   143,
     107,   108,   110,   112,    17,   -44,     4,   149,     5,    98,
      18,   116,   101,    99,    32,    33,    34,    35,    36,    74,
      97,     7,    37,    38,     8,    39,    40,     4,    10,    23,
     110,   166,   134,    14,     4,   138,    23,   139,    15,    41,
     130,    42,    91,    92,   140,    64,    43,    39,    40,    44,
      32,    33,    34,    35,    36,    93,    94,    20,    37,    64,
      19,    39,    40,    42,   156,   157,    21,   147,    43,    22,
       4,    44,    23,   119,   120,    41,    64,    42,    39,   109,
     125,   126,    43,    31,   -44,    44,    58,    76,   151,    39,
      40,    73,    87,    88,    42,   -11,    26,    18,    74,    43,
     127,   128,    44,    89,    90,    42,   121,   122,   123,   124,
      43,   167,    59,    44,    77,    78,    61,    60,    66,    70,
      71,    79,    72,    82,    81,    83,    96,    84,   102,   100,
     104,   105,   114,   103,   145,   154,   135,   131,   129,   106,
     137,   133,   163,   144,   141,   -43,   136,   142,   148,   153,
       6,   159,   160,   164,   165,   162,   117,   168,    67,   118
};

static const yytype_uint8 yycheck[] =
{
      15,    32,    18,    34,     4,    99,    17,    18,    19,    20,
     142,    42,    17,   136,    19,    20,    17,    47,    19,    20,
      28,   153,   145,     3,    35,     6,     7,    35,    58,    40,
      35,    36,    43,   156,    35,    40,    24,    25,    43,   133,
      71,    72,    73,    74,    28,    21,    28,   141,    30,    28,
      34,    82,    28,    32,     8,     9,    10,    11,    12,    35,
      60,     0,    16,    17,     4,    19,    20,    28,    17,    30,
     101,   165,   103,    28,    28,    34,    30,    36,     5,    33,
      96,    35,    39,    40,   115,    17,    40,    19,    20,    43,
       8,     9,    10,    11,    12,    41,    42,    32,    16,    17,
      29,    19,    20,    35,    14,    15,    31,   138,    40,    17,
      28,    43,    30,    85,    86,    33,    17,    35,    19,    20,
      91,    92,    40,    35,    21,    43,    30,    17,   143,    19,
      20,    28,    26,    27,    35,    32,    20,    34,    35,    40,
      93,    94,    43,    37,    38,    35,    87,    88,    89,    90,
      40,   166,    29,    43,    43,    44,    17,    33,    17,    33,
      35,    31,    35,    21,    33,    22,    34,    23,    33,    36,
      33,    33,    36,    28,    13,    17,    36,    29,    31,    33,
      29,    32,    15,    29,    32,    21,    36,    34,    29,    34,
       1,    35,    29,    36,    32,   159,    83,   167,    33,    84
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    45,    46,    28,    30,    47,     0,     4,    50,
      17,    48,    49,    48,    28,     5,    54,    28,    34,    29,
      32,    31,    17,    30,    47,    55,    20,    49,     6,     7,
      56,    35,     8,     9,    10,    11,    12,    16,    17,    19,
      20,    33,    35,    40,    43,    55,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    30,    29,
      33,    17,    52,    53,    17,    59,    17,    60,    18,    59,
      33,    35,    35,    28,    35,    59,    17,    68,    68,    31,
      57,    33,    21,    22,    23,    24,    25,    26,    27,    37,
      38,    39,    40,    41,    42,    57,    34,    48,    28,    32,
      36,    28,    33,    28,    33,    33,    33,    59,    59,    20,
      59,    36,    59,    69,    36,    28,    59,    62,    63,    64,
      64,    65,    65,    65,    65,    66,    66,    67,    67,    31,
      49,    29,    56,    32,    59,    36,    36,    29,    34,    36,
      59,    32,    34,    56,    29,    13,    58,    59,    29,    56,
      53,    55,    58,    34,    17,    51,    14,    15,    53,    35,
      29,    58,    52,    15,    36,    32,    56,    55,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    48,    48,    49,
      49,    49,    49,    50,    50,    51,    51,    52,    52,    53,
      53,    53,    53,    54,    55,    55,    56,    56,    57,    57,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    59,    59,    60,    60,    61,    61,    62,    62,    63,
      63,    63,    64,    64,    64,    64,    64,    65,    65,    65,
      66,    66,    66,    67,    67,    67,    68,    68,    68,    68,
      68,    68,    68,    69,    69
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     0,     3,     3,     5,     4,     3,
       6,     1,     4,    11,     0,     8,     0,     1,     0,     3,
       5,     5,     7,     2,     3,     4,     1,     1,     1,     2,
       1,     2,     3,     3,     3,     3,     2,     7,     9,     5,
       1,     3,     1,     4,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     2,     2,     1,     4,     3,     4,     1,
       1,     1,     3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Programa: DeclVarGlobais DeclFunc DeclPrograma  */
#line 35 "parser.y"
                                                { root = newNode3(Programa_Node, NULL, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1254 "parser.c"
    break;

  case 3: /* DeclVarGlobais: GLOBAL VarSection  */
#line 38 "parser.y"
                                   { (yyval.node) = newNode1(DeclVarGlobais_Node, NULL, (yyvsp[0].node)); }
#line 1260 "parser.c"
    break;

  case 4: /* DeclVarGlobais: %empty  */
#line 39 "parser.y"
                             { (yyval.node) = NULL; }
#line 1266 "parser.c"
    break;

  case 5: /* VarSection: '[' ListaDeclVar ']'  */
#line 42 "parser.y"
                                  { (yyval.node) = newNode1(VarSection_Node, NULL, (yyvsp[-1].node)); }
#line 1272 "parser.c"
    break;

  case 6: /* VarSection: '{' ListaDeclVar '}'  */
#line 43 "parser.y"
                                  { (yyval.node) = newNode1(VarSection_Node, NULL, (yyvsp[-1].node)); }
#line 1278 "parser.c"
    break;

  case 7: /* ListaDeclVar: ListVar ':' Tipo ';' ListaDeclVar  */
#line 46 "parser.y"
                                                 { (yyval.node) = newNode3(LstDeclVar_Node, NULL, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1284 "parser.c"
    break;

  case 8: /* ListaDeclVar: ListVar ':' Tipo ';'  */
#line 47 "parser.y"
                                    { (yyval.node) = newNode2(LstDeclVar_Node, NULL, (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1290 "parser.c"
    break;

  case 9: /* ListVar: IDENTIFICADOR ',' ListVar  */
#line 50 "parser.y"
                                    { 
            Node* id = newNode0(Identificador_Node, (yyvsp[-2].lexema));
            (yyval.node) = newNode2(ListVar_Node, NULL, id, (yyvsp[0].node));
        }
#line 1299 "parser.c"
    break;

  case 10: /* ListVar: IDENTIFICADOR '[' INTCONST ']' ',' ListVar  */
#line 54 "parser.y"
                                                     {
            Node* id = newNode0(Identificador_Node, (yyvsp[-5].lexema));
            Node* tam = newNode0(IntConst_Node, (yyvsp[-3].lexema));
            Node* vetor = newNode2(DeclVetor_Node, NULL, id, tam);
            (yyval.node) = newNode2(ListVar_Node, NULL, vetor, (yyvsp[0].node));
        }
#line 1310 "parser.c"
    break;

  case 11: /* ListVar: IDENTIFICADOR  */
#line 60 "parser.y"
                        {
            Node* id = newNode0(Identificador_Node, (yyvsp[0].lexema));
            (yyval.node) = newNode1(ListVar_Node, NULL, id);
        }
#line 1319 "parser.c"
    break;

  case 12: /* ListVar: IDENTIFICADOR '[' INTCONST ']'  */
#line 64 "parser.y"
                                         {
            Node* id = newNode0(Identificador_Node, (yyvsp[-3].lexema));
            Node* tam = newNode0(IntConst_Node, (yyvsp[-1].lexema));
            Node* vetor = newNode2(DeclVetor_Node, NULL, id, tam);
            (yyval.node) = newNode1(ListVar_Node, NULL, vetor);
        }
#line 1330 "parser.c"
    break;

  case 13: /* DeclFunc: FUNCAO '[' IDENTIFICADOR '(' ListaParametros ')' ':' Tipo Bloco ListaFuncoes ']'  */
#line 72 "parser.y"
                                                                                            {
            Node* id = newNode0(Identificador_Node, (yyvsp[-8].lexema));
            Node* func = newNode4(DeclFunc_Node, NULL, id, (yyvsp[-6].node), (yyvsp[-3].node), (yyvsp[-2].node));
            (yyval.node) = newNode2(LstFunc_Node, NULL, func, (yyvsp[-1].node));
         }
#line 1340 "parser.c"
    break;

  case 14: /* DeclFunc: %empty  */
#line 77 "parser.y"
                       { (yyval.node) = NULL; }
#line 1346 "parser.c"
    break;

  case 15: /* ListaFuncoes: IDENTIFICADOR '(' ListaParametros ')' ':' Tipo Bloco ListaFuncoes  */
#line 80 "parser.y"
                                                                                 {
                Node* id = newNode0(Identificador_Node, (yyvsp[-7].lexema));
                Node* func = newNode4(DeclFunc_Node, NULL, id, (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[-1].node));
                (yyval.node) = newNode2(LstFunc_Node, NULL, func, (yyvsp[0].node));
             }
#line 1356 "parser.c"
    break;

  case 16: /* ListaFuncoes: %empty  */
#line 85 "parser.y"
                           { (yyval.node) = NULL; }
#line 1362 "parser.c"
    break;

  case 17: /* ListaParametros: ListaParametrosTail  */
#line 88 "parser.y"
                                      { (yyval.node) = (yyvsp[0].node); }
#line 1368 "parser.c"
    break;

  case 18: /* ListaParametros: %empty  */
#line 89 "parser.y"
                              { (yyval.node) = NULL; }
#line 1374 "parser.c"
    break;

  case 19: /* ListaParametrosTail: IDENTIFICADOR ':' Tipo  */
#line 92 "parser.y"
                                             {
                        Node* id = newNode0(Identificador_Node, (yyvsp[-2].lexema));
                        Node* param = newNode2(Param_Node, NULL, id, (yyvsp[0].node));
                        (yyval.node) = newNode1(LstParam_Node, NULL, param);
                    }
#line 1384 "parser.c"
    break;

  case 20: /* ListaParametrosTail: IDENTIFICADOR '[' ']' ':' Tipo  */
#line 97 "parser.y"
                                                     {
                        Node* id = newNode0(Identificador_Node, (yyvsp[-4].lexema));
                        Node* param = newNode2(ParamVetor_Node, NULL, id, (yyvsp[0].node));
                        (yyval.node) = newNode1(LstParam_Node, NULL, param);
                    }
#line 1394 "parser.c"
    break;

  case 21: /* ListaParametrosTail: IDENTIFICADOR ':' Tipo ',' ListaParametrosTail  */
#line 102 "parser.y"
                                                                     {
                        Node* id = newNode0(Identificador_Node, (yyvsp[-4].lexema));
                        Node* param = newNode2(Param_Node, NULL, id, (yyvsp[-2].node));
                        (yyval.node) = newNode2(LstParam_Node, NULL, param, (yyvsp[0].node));
                    }
#line 1404 "parser.c"
    break;

  case 22: /* ListaParametrosTail: IDENTIFICADOR '[' ']' ':' Tipo ',' ListaParametrosTail  */
#line 107 "parser.y"
                                                                             {
                        Node* id = newNode0(Identificador_Node, (yyvsp[-6].lexema));
                        Node* param = newNode2(ParamVetor_Node, NULL, id, (yyvsp[-2].node));
                        (yyval.node) = newNode2(LstParam_Node, NULL, param, (yyvsp[0].node));
                    }
#line 1414 "parser.c"
    break;

  case 23: /* DeclPrograma: PRINCIPAL Bloco  */
#line 114 "parser.y"
                               { (yyval.node) = newNode1(DeclPrograma_Node, NULL, (yyvsp[0].node)); }
#line 1420 "parser.c"
    break;

  case 24: /* Bloco: '{' ListaComando '}'  */
#line 117 "parser.y"
                             { (yyval.node) = newNode1(Bloco_Node, NULL, (yyvsp[-1].node)); }
#line 1426 "parser.c"
    break;

  case 25: /* Bloco: VarSection '{' ListaComando '}'  */
#line 118 "parser.y"
                                        { (yyval.node) = newNode2(BlocoVar_Node, NULL, (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1432 "parser.c"
    break;

  case 26: /* Tipo: INT  */
#line 121 "parser.y"
           { (yyval.node) = newNode0(TipoINT_Node, NULL); }
#line 1438 "parser.c"
    break;

  case 27: /* Tipo: CAR  */
#line 122 "parser.y"
           { (yyval.node) = newNode0(TipoCAR_Node, NULL); }
#line 1444 "parser.c"
    break;

  case 28: /* ListaComando: Comando  */
#line 125 "parser.y"
                       { (yyval.node) = newNode1(LstCmd_Node, NULL, (yyvsp[0].node)); }
#line 1450 "parser.c"
    break;

  case 29: /* ListaComando: Comando ListaComando  */
#line 126 "parser.y"
                                    { (yyval.node) = newNode2(LstCmd_Node, NULL, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1456 "parser.c"
    break;

  case 30: /* Comando: ';'  */
#line 129 "parser.y"
              { (yyval.node) = newNode0(CmdVazio_Node, NULL); }
#line 1462 "parser.c"
    break;

  case 31: /* Comando: Expr ';'  */
#line 130 "parser.y"
                   { (yyval.node) = newNode1(Expr_Node, NULL, (yyvsp[-1].node)); }
#line 1468 "parser.c"
    break;

  case 32: /* Comando: RETORNE Expr ';'  */
#line 131 "parser.y"
                           { (yyval.node) = newNode1(Retorne_Node, NULL, (yyvsp[-1].node)); }
#line 1474 "parser.c"
    break;

  case 33: /* Comando: LEIA LValueExpr ';'  */
#line 132 "parser.y"
                              { (yyval.node) = newNode1(Leia_Node, NULL, (yyvsp[-1].node)); }
#line 1480 "parser.c"
    break;

  case 34: /* Comando: ESCREVA Expr ';'  */
#line 133 "parser.y"
                           { (yyval.node) = newNode1(Escreva_Node, NULL, (yyvsp[-1].node)); }
#line 1486 "parser.c"
    break;

  case 35: /* Comando: ESCREVA CADEIACARACTERES ';'  */
#line 134 "parser.y"
                                       { 
            Node* cad = newNode0(CadeiaCar_Node, (yyvsp[-1].lexema));
            (yyval.node) = newNode1(EscrevaStr_Node, NULL, cad); 
        }
#line 1495 "parser.c"
    break;

  case 36: /* Comando: NOVALINHA ';'  */
#line 138 "parser.y"
                        { (yyval.node) = newNode0(NovaLinha_Node, NULL); }
#line 1501 "parser.c"
    break;

  case 37: /* Comando: SE '(' Expr ')' ENTAO Comando FIMSE  */
#line 139 "parser.y"
                                              { (yyval.node) = newNode2(Se_Node, NULL, (yyvsp[-4].node), (yyvsp[-1].node)); }
#line 1507 "parser.c"
    break;

  case 38: /* Comando: SE '(' Expr ')' ENTAO Comando SENAO Comando FIMSE  */
#line 140 "parser.y"
                                                            { (yyval.node) = newNode3(Se_Senao_Node, NULL, (yyvsp[-6].node), (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1513 "parser.c"
    break;

  case 39: /* Comando: ENQUANTO '(' Expr ')' Comando  */
#line 141 "parser.y"
                                        { (yyval.node) = newNode2(Enquanto_Node, NULL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1519 "parser.c"
    break;

  case 40: /* Comando: Bloco  */
#line 142 "parser.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1525 "parser.c"
    break;

  case 41: /* Expr: LValueExpr ATRIBUICAO Expr  */
#line 145 "parser.y"
                                  { (yyval.node) = newNode2(Expr_Atr_Node, NULL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1531 "parser.c"
    break;

  case 42: /* Expr: OrExpr  */
#line 146 "parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1537 "parser.c"
    break;

  case 43: /* LValueExpr: IDENTIFICADOR '[' Expr ']'  */
#line 149 "parser.y"
                                        {
                Node* id = newNode0(Identificador_Node, (yyvsp[-3].lexema));
                (yyval.node) = newNode2(AcessoVetor_Node, NULL, id, (yyvsp[-1].node));
           }
#line 1546 "parser.c"
    break;

  case 44: /* LValueExpr: IDENTIFICADOR  */
#line 153 "parser.y"
                           { (yyval.node) = newNode0(Identificador_Node, (yyvsp[0].lexema)); }
#line 1552 "parser.c"
    break;

  case 45: /* OrExpr: OrExpr OU AndExpr  */
#line 156 "parser.y"
                           { (yyval.node) = newNode2(Expr_Ou_Node, NULL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1558 "parser.c"
    break;

  case 46: /* OrExpr: AndExpr  */
#line 157 "parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1564 "parser.c"
    break;

  case 47: /* AndExpr: AndExpr E EqExpr  */
#line 160 "parser.y"
                           { (yyval.node) = newNode2(Expr_E_Node, NULL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1570 "parser.c"
    break;

  case 48: /* AndExpr: EqExpr  */
#line 161 "parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1576 "parser.c"
    break;

  case 49: /* EqExpr: EqExpr IGUAL DesigExpr  */
#line 164 "parser.y"
                                { (yyval.node) = newNode2(Expr_Igual_Node, NULL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1582 "parser.c"
    break;

  case 50: /* EqExpr: EqExpr DIFERENTE DesigExpr  */
#line 165 "parser.y"
                                    { (yyval.node) = newNode2(Expr_Dif_Node, NULL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1588 "parser.c"
    break;

  case 51: /* EqExpr: DesigExpr  */
#line 166 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1594 "parser.c"
    break;

  case 52: /* DesigExpr: DesigExpr '<' AddExpr  */
#line 169 "parser.y"
                                  { (yyval.node) = newNode2(Expr_Menor_Node, NULL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1600 "parser.c"
    break;

  case 53: /* DesigExpr: DesigExpr '>' AddExpr  */
#line 170 "parser.y"
                                  { (yyval.node) = newNode2(Expr_Maior_Node, NULL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1606 "parser.c"
    break;

  case 54: /* DesigExpr: DesigExpr MAIORIGUAL AddExpr  */
#line 171 "parser.y"
                                         { (yyval.node) = newNode2(Expr_MaiorIgual_Node, NULL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1612 "parser.c"
    break;

  case 55: /* DesigExpr: DesigExpr MENORIGUAL AddExpr  */
#line 172 "parser.y"
                                         { (yyval.node) = newNode2(Expr_MenorIgual_Node, NULL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1618 "parser.c"
    break;

  case 56: /* DesigExpr: AddExpr  */
#line 173 "parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1624 "parser.c"
    break;

  case 57: /* AddExpr: AddExpr '+' MulExpr  */
#line 176 "parser.y"
                              { (yyval.node) = newNode2(Expr_Add_Node, NULL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1630 "parser.c"
    break;

  case 58: /* AddExpr: AddExpr '-' MulExpr  */
#line 177 "parser.y"
                              { (yyval.node) = newNode2(Expr_Sub_Node, NULL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1636 "parser.c"
    break;

  case 59: /* AddExpr: MulExpr  */
#line 178 "parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1642 "parser.c"
    break;

  case 60: /* MulExpr: MulExpr '*' UnExpr  */
#line 181 "parser.y"
                             { (yyval.node) = newNode2(Expr_Mul_Node, NULL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1648 "parser.c"
    break;

  case 61: /* MulExpr: MulExpr '/' UnExpr  */
#line 182 "parser.y"
                             { (yyval.node) = newNode2(Expr_Div_Node, NULL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1654 "parser.c"
    break;

  case 62: /* MulExpr: UnExpr  */
#line 183 "parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1660 "parser.c"
    break;

  case 63: /* UnExpr: '-' PrimExpr  */
#line 186 "parser.y"
                      { (yyval.node) = newNode1(Expr_Minus_Node, NULL, (yyvsp[0].node)); }
#line 1666 "parser.c"
    break;

  case 64: /* UnExpr: '!' PrimExpr  */
#line 187 "parser.y"
                      { (yyval.node) = newNode1(Expr_Neg_Node, NULL, (yyvsp[0].node)); }
#line 1672 "parser.c"
    break;

  case 65: /* UnExpr: PrimExpr  */
#line 188 "parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1678 "parser.c"
    break;

  case 66: /* PrimExpr: IDENTIFICADOR '(' ListExpr ')'  */
#line 191 "parser.y"
                                          {
                Node* id = newNode0(Identificador_Node, (yyvsp[-3].lexema));
                (yyval.node) = newNode2(Call_Node, NULL, id, (yyvsp[-1].node));
         }
#line 1687 "parser.c"
    break;

  case 67: /* PrimExpr: IDENTIFICADOR '(' ')'  */
#line 195 "parser.y"
                                 {
                Node* id = newNode0(Identificador_Node, (yyvsp[-2].lexema));
                (yyval.node) = newNode1(CallEmpty_Node, NULL, id);
         }
#line 1696 "parser.c"
    break;

  case 68: /* PrimExpr: IDENTIFICADOR '[' Expr ']'  */
#line 199 "parser.y"
                                      {
                Node* id = newNode0(Identificador_Node, (yyvsp[-3].lexema));
                (yyval.node) = newNode2(AcessoVetor_Node, NULL, id, (yyvsp[-1].node));
         }
#line 1705 "parser.c"
    break;

  case 69: /* PrimExpr: IDENTIFICADOR  */
#line 203 "parser.y"
                         { (yyval.node) = newNode0(Identificador_Node, (yyvsp[0].lexema)); }
#line 1711 "parser.c"
    break;

  case 70: /* PrimExpr: CARCONST  */
#line 204 "parser.y"
                    { (yyval.node) = newNode0(CarConst_Node, (yyvsp[0].lexema)); }
#line 1717 "parser.c"
    break;

  case 71: /* PrimExpr: INTCONST  */
#line 205 "parser.y"
                    { (yyval.node) = newNode0(IntConst_Node, (yyvsp[0].lexema)); }
#line 1723 "parser.c"
    break;

  case 72: /* PrimExpr: '(' Expr ')'  */
#line 206 "parser.y"
                        { (yyval.node) = (yyvsp[-1].node); }
#line 1729 "parser.c"
    break;

  case 73: /* ListExpr: Expr  */
#line 209 "parser.y"
                { (yyval.node) = newNode1(LstExpr_Node, NULL, (yyvsp[0].node)); }
#line 1735 "parser.c"
    break;

  case 74: /* ListExpr: ListExpr ',' Expr  */
#line 210 "parser.y"
                             { (yyval.node) = newNode2(LstExpr_Node, NULL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1741 "parser.c"
    break;


#line 1745 "parser.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

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
                      yytoken, &yylval);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 213 "parser.y"


int main(int argc, char **argv){
    if(argc != 2) yyerror("Uso incorreto do compilador\nUso correto: ./g-v2 nome_arquivo\n");
    yyin = fopen(argv[1], "r");
    if(!yyin) yyerror("Arquivo nao pode ser aberto\n");
    int x = yyparse();
    if(x == 0) {
        if(semantic(root) == 0) {
            generate_code(root);
        }
    }
    limpa(root);
    return x;
}

void yyerror(char const *s){
    printf("ERRO: %s, na linha %d\n", s, yylineno);
    exit(1);
}
