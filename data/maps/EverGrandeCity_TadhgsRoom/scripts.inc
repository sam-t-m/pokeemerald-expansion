EverGrandeCity_TadhgsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_TadhgsRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_TadhgsRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_TadhgsRoom_OnWarp
	.byte 0

EverGrandeCity_TadhgsRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_TadhgsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_TadhgsRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_TadhgsRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 2, EverGrandeCity_TadhgsRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_TadhgsRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 3
	releaseall
	end

EverGrandeCity_TadhgsRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_TADHG, EverGrandeCity_TadhgsRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 3, EverGrandeCity_TadhgsRoom_EventScript_CloseDoor
	end

EverGrandeCity_TadhgsRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_TadhgsRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_TadhgsRoom_EventScript_Tadhg::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_TADHG, EverGrandeCity_TadhgsRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_TadhgsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_TADHG, EverGrandeCity_TadhgsRoom_Text_Defeat
	goto EverGrandeCity_TadhgsRoom_EventScript_Defeated
	end

EverGrandeCity_TadhgsRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_TadhgsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_TadhgsRoom_EventScript_Defeated::
	setflag FLAG_DEFEATED_ELITE_4_TADHG
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_TadhgsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_TadhgsRoom_Text_IntroSpeech:
	
	.string "Hey, congrats on making it this far\p"
	.string "Hold on, I better do the official\n"
	.string "spiel first\p"
	.string "Welcome, my name is Tadhg\n"
	.string "of the ELITE FOUR.\p"
	.string "It's ICE to meet you, haha\p"

EverGrandeCity_TadhgsRoom_Text_Defeat:
	.string "Good job\n"
	.string "You're more than halfway there now\p"
	.string "I hope you've got what it takes\p"
	.string "to go all the way$"

EverGrandeCity_TadhgsRoom_Text_PostBattleSpeech:
	.string "Head on through the door behind me$"


