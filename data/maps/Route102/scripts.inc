
.set LOCALID_RIVAL_DEXNAV_MAY, 11
.set LOCALID_RIVAL_DEXNAV_BRENDAN, 12

Route102_MapScripts::
	.byte 0

Route102_EventScript_LittleBoy::
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
	end

Route102_EventScript_RouteSignOldale::
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
	end

Route102_EventScript_RouteSignPetalburg::
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

Route102_EventScript_Boy::
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
	end

Route102_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_CalvinRematch
	setvar VAR_0x8004, TRAINER_CALVIN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route102_EventScript_CalvinTryRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
	release
	end

Route102_EventScript_CalvinRegisterMatchCall::
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinTryRegister::
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegister::
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinRematch::
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Rick::
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Tiana::
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_Text_WatchMeCatchPokemon:
	.string "WALLY: {PLAYER}…\n"
	.string "POKéMON hide in tall grass like this,\l"
	.string "don't they?\p"
	.string "Please watch me and see if I can\n"
	.string "catch one properly.\p"
	.string "…Whoa!$"

Route102_Text_WallyIDidIt:
	.string "WALLY: I did it… It's my…\n"
	.string "My POKéMON!$"

Route102_Text_LetsGoBack:
	.string "{PLAYER}, thank you!\n"
	.string "Let's go back to the GYM!$"

Route102_Text_ImNotVeryTall:
	.string "I'm…not very tall, so I sink right\n"
	.string "into tall grass.\p"
	.string "The grass goes up my nose and…\n"
	.string "Fwafwafwafwafwa…\p"
	.string "Fwatchoo!$"

Route102_Text_CatchWholeBunchOfPokemon:
	.string "I'm going to catch a whole bunch of\n"
	.string "POKéMON!$"

Route102_Text_RouteSignOldale:
	.string "ROUTE 102\n"
	.string "{RIGHT_ARROW} OLDALE TOWN$"

Route102_Text_RouteSignPetalburg:
	.string "ROUTE 102\n"
	.string "{LEFT_ARROW} PETALBURG CITY$"

Route104_Trigger_RivalApproachPlayer_1::
	lock
	checkplayergender
	switch VAR_RESULT
	case MALE, Route104_Trigger_RivalApproachPlayer_1_3
	case FEMALE, Route104_Trigger_RivalApproachPlayer_1_4
Route104_Trigger_RivalApproachPlayer_1_1:
	release
	end

Route104_Trigger_RivalApproachPlayer_1_3:
	goto Route104_EventScript_RivalApproachPlayer_May_1
	goto Route104_Trigger_RivalApproachPlayer_1_1

Route104_Trigger_RivalApproachPlayer_1_4:
	goto Route104_EventScript_RivalApproachPlayer_Brendan_1
	goto Route104_Trigger_RivalApproachPlayer_1_1


Route104_Trigger_RivalApproachPlayer_2::
	lock
	checkplayergender
	switch VAR_RESULT
	case MALE, Route104_Trigger_RivalApproachPlayer_2_3
	case FEMALE, Route104_Trigger_RivalApproachPlayer_2_4
Route104_Trigger_RivalApproachPlayer_2_1:
	release
	end

Route104_Trigger_RivalApproachPlayer_2_3:
	goto Route104_EventScript_RivalApproachPlayer_May_2
	goto Route104_Trigger_RivalApproachPlayer_2_1

Route104_Trigger_RivalApproachPlayer_2_4:
	goto Route104_EventScript_RivalApproachPlayer_Brendan_2
	goto Route104_Trigger_RivalApproachPlayer_2_1


Route104_EventScript_RivalApproachPlayer_May_1::
	lock
	addobject LOCALID_RIVAL_DEXNAV_MAY
	applymovement LOCALID_RIVAL_DEXNAV_MAY, Route104_EventScript_RivalApproachPlayer_May_1_Movement_0
	waitmovement 0
	message Route104_EventScript_RivalApproachPlayer_May_1_Text_0
	waitmessage
	waitbuttonpress
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route104_EventScript_RivalApproachPlayer_May_1_Movement_1
	waitmovement 0
	applymovement LOCALID_RIVAL_DEXNAV_MAY, Route104_EventScript_RivalApproachPlayer_May_1_Movement_2
	waitmovement 0
	message Route104_EventScript_RivalApproachPlayer_May_1_Text_1
	waitmessage
	message Route104_EventScript_RivalApproachPlayer_May_1_Text_2
	waitmessage
	waitbuttonpress
	closemessage
	setflag FLAG_DEXNAV_GET
	message Route104_EventScript_RivalApproachPlayer_May_1_Text_3
	waitbuttonpress
	closemessage
	applymovement LOCALID_RIVAL_DEXNAV_MAY, Route104_EventScript_RivalApproachPlayer_May_1_Movement_3
	waitmovement 0
	setvar VAR_RIVAL_GIVES_DEXNAV, 1
	end


Route104_EventScript_RivalApproachPlayer_May_2::
	lock
	addobject LOCALID_RIVAL_DEXNAV_MAY
	applymovement LOCALID_RIVAL_DEXNAV_MAY, Route104_EventScript_RivalApproachPlayer_May_1_Movement_0
	waitmovement 0
	message Route104_EventScript_RivalApproachPlayer_May_1_Text_0
	waitmessage
	waitbuttonpress
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route104_EventScript_RivalApproachPlayer_May_1_Movement_1
	waitmovement 0
	applymovement LOCALID_RIVAL_DEXNAV_MAY, Route104_EventScript_RivalApproachPlayer_May_1_Movement_2
	waitmovement 0
	message Route104_EventScript_RivalApproachPlayer_May_1_Text_1
	waitmessage
	message Route104_EventScript_RivalApproachPlayer_May_1_Text_2
	waitmessage
	waitbuttonpress
	closemessage
	setflag FLAG_DEXNAV_GET
	msgbox Route104_EventScript_RivalApproachPlayer_May_1_Text_3
	waitbuttonpress
	closemessage
	applymovement LOCALID_RIVAL_DEXNAV_MAY, Route104_EventScript_RivalApproachPlayer_May_1_Movement_3
	waitmovement 0
	setvar VAR_RIVAL_GIVES_DEXNAV, 1
	end


Route104_EventScript_RivalApproachPlayer_Brendan_1::
	lock
	addobject LOCALID_RIVAL_DEXNAV_BRENDAN
	applymovement LOCALID_RIVAL_DEXNAV_BRENDAN, Route104_EventScript_RivalApproachPlayer_May_1_Movement_0
	waitmovement 0
	msgbox Route104_EventScript_RivalApproachPlayer_Brendan_1_Text_0
	waitbuttonpress
	closemessage
	applymovement LOCALID_RIVAL_DEXNAV_BRENDAN, Route104_EventScript_RivalApproachPlayer_May_1_Movement_2
	waitmovement 0
	msgbox Route104_EventScript_RivalApproachPlayer_May_1_Text_1
	waitbuttonpress
	closemessage
	msgbox Route104_EventScript_RivalApproachPlayer_Brendan_1_Text_1
	waitbuttonpress
	closemessage
	setflag FLAG_DEXNAV_GET
	msgbox Route104_EventScript_RivalApproachPlayer_May_1_Text_3
	waitbuttonpress
	closemessage
	applymovement LOCALID_RIVAL_DEXNAV_BRENDAN, Route104_EventScript_RivalApproachPlayer_Brendan_1_Movement_0
	waitmovement 0
	setvar VAR_RIVAL_GIVES_DEXNAV, 1
	end


Route104_EventScript_RivalApproachPlayer_Brendan_2::
	lock
	addobject LOCALID_RIVAL_DEXNAV_BRENDAN
	applymovement LOCALID_RIVAL_DEXNAV_BRENDAN, Route104_EventScript_RivalApproachPlayer_May_1_Movement_0
	waitmovement 0
	msgbox Route104_EventScript_RivalApproachPlayer_Brendan_1_Text_0
	waitbuttonpress
	closemessage
	applymovement LOCALID_RIVAL_DEXNAV_BRENDAN, Route104_EventScript_RivalApproachPlayer_Brendan_2_Movement_0
	waitmovement 0
	msgbox Route104_EventScript_RivalApproachPlayer_May_1_Text_1
	waitbuttonpress
	closemessage
	msgbox Route104_EventScript_RivalApproachPlayer_Brendan_1_Text_1
	waitbuttonpress
	closemessage
	setflag FLAG_DEXNAV_GET
	msgbox Route104_EventScript_RivalApproachPlayer_May_1_Text_3
	applymovement LOCALID_RIVAL_DEXNAV_BRENDAN, Route104_EventScript_RivalApproachPlayer_May_1_Movement_3
	waitmovement 0
	setvar VAR_RIVAL_GIVES_DEXNAV, 1
	end


Route104_EventScript_RivalApproachPlayer_May_1_Movement_0:
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

Route104_EventScript_RivalApproachPlayer_May_1_Movement_1:
	emote_question_mark
	delay_2
	face_right
	step_end

Route104_EventScript_RivalApproachPlayer_May_1_Movement_2:
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

Route104_EventScript_RivalApproachPlayer_May_1_Movement_3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

Route104_EventScript_RivalApproachPlayer_Brendan_1_Movement_0:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

Route104_EventScript_RivalApproachPlayer_Brendan_2_Movement_0:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

Route104_EventScript_RivalApproachPlayer_May_1_Text_0:
	.string "Heyyyyy {PLAYER}!$"

Route104_EventScript_RivalApproachPlayer_May_1_Text_1:
	.string "I was just looking for you!\n"
	.string "Have you found any rare Pokémon with\l"
	.string "the DexNav yet?$"

Route104_EventScript_RivalApproachPlayer_May_1_Text_2:
	.string "Whattttt, you haven't gotten your\n"
	.string "DexNav yet?\n"
	.string "Here have mine!\p"
	.string "I'm sure my dad has one more for me,\n"
	.string "since he didn't give you one.$"

Route104_EventScript_RivalApproachPlayer_May_1_Text_3:
	.string "anyways, I have to go find my dad.\n"
	.string "See you later!$"

Route104_EventScript_RivalApproachPlayer_Brendan_1_Text_0:
	.string "Whatsup, {PLAYER}!$"

Route104_EventScript_RivalApproachPlayer_Brendan_1_Text_1:
	.string "Oh, you haven't gotten your DexNav\n"
	.string "yet?\n"
	.string "Here have mine!\p"
	.string "I'm sure my dad has one more for me,\n"
	.string "since he didn't give you one.$"
