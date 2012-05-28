/* A Bison parser, made by GNU Bison 2.5.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2011 Free Software Foundation, Inc.
   
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


/* First part of user declarations.  */


/* Line 293 of lalr1.cc  */
#line 39 "Loader.tab.cpp"


#include "Loader.tab.hpp"

/* User implementation prologue.  */


/* Line 299 of lalr1.cc  */
#line 48 "Loader.tab.cpp"
/* Unqualified %code blocks.  */

/* Line 300 of lalr1.cc  */
#line 35 "Loader.ypp"

  static int yylex(Serializer::Loader::semantic_type* yylval,
		   Serializer::Loader::location_type* yylloc,
		   Serializer::Scanner &scanner);



/* Line 300 of lalr1.cc  */
#line 61 "Loader.tab.cpp"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                               \
 do                                                                    \
   if (N)                                                              \
     {                                                                 \
       (Current).begin = YYRHSLOC (Rhs, 1).begin;                      \
       (Current).end   = YYRHSLOC (Rhs, N).end;                        \
     }                                                                 \
   else                                                                \
     {                                                                 \
       (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;        \
     }                                                                 \
 while (false)
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


/* Line 382 of lalr1.cc  */
#line 11 "Loader.ypp"
namespace Serializer {

/* Line 382 of lalr1.cc  */
#line 149 "Loader.tab.cpp"

  /// Build a parser object.
  Loader::Loader (Serializer::Scanner &scanner_yyarg, Serializer::Unpackman &up_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      up (up_yyarg)
  {
  }

  Loader::~Loader ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  Loader::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  Loader::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  Loader::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
        case 3: /* "\"identifier\"" */

/* Line 480 of lalr1.cc  */
#line 16 "Loader.ypp"
	{ delete (*yyvaluep).sval; };

/* Line 480 of lalr1.cc  */
#line 217 "Loader.tab.cpp"
	break;

	default:
	  break;
      }
  }

  void
  Loader::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Loader::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Loader::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Loader::debug_level_type
  Loader::debug_level () const
  {
    return yydebug_;
  }

  void
  Loader::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  Loader::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Loader::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Loader::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc, scanner);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yy_table_value_is_error_ (yyn))
	  goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 4:

/* Line 690 of lalr1.cc  */
#line 61 "Loader.ypp"
    {}
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 67 "Loader.ypp"
    {
  up.pf.setId((yysemantic_stack_[(12) - (3)].ival));
  up.pf.setName(*(yysemantic_stack_[(12) - (5)].sval));
  up.pf.setXp((yysemantic_stack_[(12) - (7)].ival));
  up.pf.setTuto((yysemantic_stack_[(12) - (9)].ival));
  up.pf.setSkin(static_cast<Skin::eSkin>((yysemantic_stack_[(12) - (11)].ival)));
}
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 75 "Loader.ypp"
    {
  up.pf.addStat((yysemantic_stack_[(14) - (3)].ival));
  up.pf.addStat((yysemantic_stack_[(14) - (5)].ival));
  up.pf.addStat((yysemantic_stack_[(14) - (7)].ival));
  up.pf.addStat((yysemantic_stack_[(14) - (9)].ival));
  up.pf.addStat((yysemantic_stack_[(14) - (11)].ival));
  up.pf.addStat((yysemantic_stack_[(14) - (13)].ival));
}
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 84 "Loader.ypp"
    {
  up.pf.addSkill((yysemantic_stack_[(8) - (3)].ival));
  up.pf.addSkill((yysemantic_stack_[(8) - (5)].ival));
  up.pf.addSkill((yysemantic_stack_[(8) - (7)].ival));
}
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 90 "Loader.ypp"
    {
  up.pf.addAchievement((yysemantic_stack_[(8) - (3)].ival));
  up.pf.addAchievement((yysemantic_stack_[(8) - (5)].ival));
  up.pf.addAchievement((yysemantic_stack_[(8) - (7)].ival));
}
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 96 "Loader.ypp"
    {
  up.ma.setGameMode(static_cast<GameMode::eGameMode>((yysemantic_stack_[(6) - (3)].ival)));
  up.ma.setCheat((yysemantic_stack_[(6) - (5)].ival));
}
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 101 "Loader.ypp"
    {
  Map*		m = new Map((yysemantic_stack_[(9) - (3)].ival), (yysemantic_stack_[(9) - (5)].ival), *(yysemantic_stack_[(9) - (7)].sval));

  up.ma.setMap(m);
}
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 114 "Loader.ypp"
    {
  up.pf.addSave((yysemantic_stack_[(3) - (2)].ival));
}
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 121 "Loader.ypp"
    {
  assert(up.ma._map != 0);

  APlayer*	p = 0;

  if ((yysemantic_stack_[(27) - (11)].ival) > 0)
    p = new Human(*up.ma._map, Config()); //TODO CONFIG
  else
    p = new Human(*up.ma._map, Config()); //TODO:AI

  p->setId((yysemantic_stack_[(27) - (1)].ival));
  p->setTeamId((yysemantic_stack_[(27) - (3)].ival));
  p->setName(*(yysemantic_stack_[(27) - (5)].sval));
  p->setTeamName(*(yysemantic_stack_[(27) - (7)].sval));
  p->setColor((yysemantic_stack_[(27) - (11)].ival));
  p->setSkin(static_cast<Skin::eSkin>((yysemantic_stack_[(27) - (13)].ival)));
  p->setState(static_cast<State::eState>((yysemantic_stack_[(27) - (15)].ival)));
  p->setDir(static_cast<Dir::eDir>((yysemantic_stack_[(27) - (17)].ival)));
  p->setWeapon(static_cast<BombType::eBomb>((yysemantic_stack_[(27) - (19)].ival)));
  p->setPv((yysemantic_stack_[(27) - (25)].ival));
  p->setType((yysemantic_stack_[(27) - (9)].ival));
  p->setPos((yysemantic_stack_[(27) - (21)].ival), (yysemantic_stack_[(27) - (23)].ival));

  up.ma._players.push_back(p);
  std::cout << "- Player: "
  	    //<< "\n-> id player " << $1
  	    //<< "\n-> id team: " << $3
  	    //<< "\n-> nick: " << *$5
  	    //<< "\n-> team name: " << *$7
  	    //<< "\n-> type: " << ($9 > 0 ? "HUMAN" : "AI")
  	    //<< "\n-> color: " << $11
  	    //<< "\n-> skin: " << $13
  	    //<< "\n-> state: " << $15
  	    //<< "\n-> dir: " << $17
  	    //<< "\n-> weapon: " << $19
  	    //<< "\n-> x: " << $21
  	    //<< "\n-> y: " << $23
	    << std::endl << std::endl;
}
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 164 "Loader.ypp"
    {
  up.pf.addConfig(static_cast<HumGame::eAction>((yysemantic_stack_[(5) - (1)].ival)), static_cast<gdl::Keys::Key>((yysemantic_stack_[(5) - (3)].ival)));
}
    break;



/* Line 690 of lalr1.cc  */
#line 562 "Loader.tab.cpp"
	default:
          break;
      }
    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
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
    if (false)
      goto yyerrorlab;

    yyerror_range[1] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
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

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  Loader::yysyntax_error_ (int, int)
  {
    return YY_("syntax error");
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char Loader::yypact_ninf_ = -65;
  const signed char
  Loader::yypact_[] =
  {
        16,   -17,    -9,    -5,    -3,   -18,     7,    -1,    11,    13,
     -65,     0,   -65,   -65,    15,    19,    20,    21,   -65,    22,
     -65,    23,    18,    24,    -2,   -65,   -65,    14,    25,    26,
      27,   -18,    28,   -65,    29,   -65,    30,   -65,    31,   -65,
      35,    36,    37,    38,   -65,    39,    40,    41,    42,    33,
      43,    44,    45,    47,    48,    49,    50,    51,    53,    54,
      55,   -65,    18,    46,    57,    56,    58,    60,    61,   -65,
      62,    63,    59,    64,   -65,   -65,    71,    68,    66,    67,
     -65,    69,    70,    72,    73,    74,    75,    76,   -65,    79,
      80,    81,    82,   -65,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    -2,   -65
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  Loader::yydefact_[] =
  {
         0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     0,     3,     5,     0,     0,     0,     0,    15,     0,
      12,     0,     0,     0,     0,     1,     2,     0,     0,     0,
       0,     0,     0,    19,     0,    14,     0,    17,     0,    13,
       0,     0,     0,     0,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,     0,     0,     0,     0,     0,     0,     0,    20,
       0,     0,     0,     0,     8,     9,     0,     0,     0,     0,
      11,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       0,     0,     0,     7,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  Loader::yypgoto_[] =
  {
       -65,   -65,    32,   -65,    97,   -64,    65
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  Loader::yydefgoto_[] =
  {
        -1,    11,    12,    13,    20,    39,    35
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char Loader::yytable_ninf_ = -1;
  const unsigned char
  Loader::yytable_[] =
  {
        25,    18,    19,    14,     1,     2,     3,     4,     5,     6,
       7,    15,     8,    37,     9,    16,    38,    17,    22,    10,
       1,     2,     3,     4,     5,     6,     7,    21,     8,    33,
       9,    23,    24,    27,    40,    10,    34,    28,    29,    30,
      31,    32,    36,    26,   109,    41,    42,    43,    45,    46,
      47,    48,    49,    57,    50,    51,    52,    53,    54,    55,
      56,     0,    70,    58,    59,    60,    61,    62,    63,    65,
      64,    66,    67,    68,    71,     0,    72,    78,    73,    74,
      75,    76,    79,    77,    80,    81,    82,    83,    85,    84,
      86,    87,     0,    88,     0,    89,    90,    91,    92,     0,
      93,    95,    94,    97,    96,    99,    98,   101,   100,   103,
     102,   105,   104,   107,   106,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,    44
  };

  /* YYCHECK.  */
  const signed char
  Loader::yycheck_[] =
  {
         0,    19,    20,    20,     4,     5,     6,     7,     8,     9,
      10,    20,    12,    15,    14,    20,    18,    20,    19,    19,
       4,     5,     6,     7,     8,     9,    10,    20,    12,    11,
      14,    20,    19,    18,    20,    19,    18,    18,    18,    18,
      18,    18,    18,    11,   108,    20,    20,    20,    20,    20,
      20,    20,    17,    20,    18,    18,    18,    18,    18,    18,
      18,    -1,    16,    20,    20,    20,    19,    19,    19,    18,
      20,    18,    18,    18,    17,    -1,    20,    18,    20,    19,
      19,    19,    18,    20,    13,    17,    20,    20,    18,    20,
      18,    18,    -1,    19,    -1,    20,    20,    18,    18,    -1,
      19,    18,    20,    18,    20,    18,    20,    18,    20,    18,
      20,    18,    20,    18,    20,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    31
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Loader::yystos_[] =
  {
         0,     4,     5,     6,     7,     8,     9,    10,    12,    14,
      19,    22,    23,    24,    20,    20,    20,    20,    19,    20,
      25,    20,    19,    20,    19,     0,    23,    18,    18,    18,
      18,    18,    18,    11,    18,    27,    18,    15,    18,    26,
      20,    20,    20,    20,    25,    20,    20,    20,    20,    17,
      18,    18,    18,    18,    18,    18,    18,    20,    20,    20,
      20,    19,    19,    19,    20,    18,    18,    18,    18,    27,
      16,    17,    20,    20,    19,    19,    19,    20,    18,    18,
      13,    17,    20,    20,    20,    18,    18,    18,    19,    20,
      20,    18,    18,    19,    20,    18,    20,    18,    20,    18,
      20,    18,    20,    18,    20,    18,    20,    18,    19,    26
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Loader::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Loader::yyr1_[] =
  {
         0,    21,    22,    22,    23,    23,    24,    24,    24,    24,
      24,    24,    24,    24,    24,    25,    25,    26,    26,    27,
      27
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Loader::yyr2_[] =
  {
         0,     2,     2,     1,     1,     1,    12,    14,     8,     8,
       6,     9,     2,     3,     3,     1,     3,     1,    27,     1,
       5
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Loader::yytname_[] =
  {
    "$end", "error", "$undefined", "\"identifier\"", "INFO", "STAT",
  "SKILLS", "ACHIEVEMENTS", "SAVES", "HEADER", "CONFIG", "ENDCONFIG",
  "MAP", "ENDMAP", "PLAYERS", "ENDPLAYERS", "MIXTE", "WORD", "NUMBER",
  "EOL", "SEP", "$accept", "input", "line", "info", "sequence", "players",
  "config", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Loader::rhs_number_type
  Loader::yyrhs_[] =
  {
        22,     0,    -1,    22,    23,    -1,    23,    -1,    19,    -1,
      24,    -1,     4,    20,    18,    20,    17,    20,    18,    20,
      18,    20,    18,    19,    -1,     5,    20,    18,    20,    18,
      20,    18,    20,    18,    20,    18,    20,    18,    19,    -1,
       6,    20,    18,    20,    18,    20,    18,    19,    -1,     7,
      20,    18,    20,    18,    20,    18,    19,    -1,     9,    20,
      18,    20,    18,    19,    -1,    12,    20,    18,    20,    18,
      19,    16,    19,    13,    -1,     8,    25,    -1,    14,    19,
      26,    -1,    10,    19,    27,    -1,    19,    -1,    20,    18,
      25,    -1,    15,    -1,    18,    20,    18,    20,    17,    20,
      17,    20,    18,    20,    18,    20,    18,    20,    18,    20,
      18,    20,    18,    20,    18,    20,    18,    20,    18,    19,
      26,    -1,    11,    -1,    18,    20,    18,    19,    27,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  Loader::yyprhs_[] =
  {
         0,     0,     3,     6,     8,    10,    12,    25,    40,    49,
      58,    65,    75,    78,    82,    86,    88,    92,    94,   122,
     124
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned char
  Loader::yyrline_[] =
  {
         0,    56,    56,    57,    61,    62,    66,    74,    83,    89,
      95,   100,   106,   107,   108,   112,   113,   119,   120,   162,
     163
  };

  // Print the state stack on the debug stream.
  void
  Loader::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Loader::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  Loader::token_number_type
  Loader::yytranslate_ (int t)
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
      15,    16,    17,    18,    19,    20
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Loader::yyeof_ = 0;
  const int Loader::yylast_ = 128;
  const int Loader::yynnts_ = 7;
  const int Loader::yyempty_ = -2;
  const int Loader::yyfinal_ = 25;
  const int Loader::yyterror_ = 1;
  const int Loader::yyerrcode_ = 256;
  const int Loader::yyntokens_ = 21;

  const unsigned int Loader::yyuser_token_number_max_ = 275;
  const Loader::token_number_type Loader::yyundef_token_ = 2;


/* Line 1136 of lalr1.cc  */
#line 11 "Loader.ypp"
} // Serializer

/* Line 1136 of lalr1.cc  */
#line 1030 "Loader.tab.cpp"


/* Line 1138 of lalr1.cc  */
#line 169 "Loader.ypp"


namespace Serializer {
  void		Loader::error(Loader::location_type const& loc,
			      std::string const& msg) {
    std::ostringstream	ret;

    ret << "- Parse error at line " << loc.begin.line
	<< " column " << loc.begin.column << ":\n-- " << msg;
    throw std::runtime_error(ret.str());
  }
}

#include "Scanner.hpp"
static int	yylex(Serializer::Loader::semantic_type* yylval,
		      Serializer::Loader::location_type* yylloc,
		      Serializer::Scanner &scanner) {
  return scanner.yylex(yylval, yylloc);
}

