TARGET := my_runner

OBJ_PATH := bin
SRCS_BASE := 	main.c \
				global_cst.c \
				\
				\
				background_destroy.c \
				background_draw.c \
				background_init.c \
				background_update.c \
				\
				create_drawable.c \
				\
				\
				my_map_cmp.c \
				is_in_bounds.c \
				init_iced_btn.c \
				\
				\
				game_struct_destroy.c \
				game_struct_draw.c \
				game_struct_init.c \
				game_struct_handle_input.c \
				game_struct_update.c \
				game_struct_restart.c \
				\
				game_physic_load_world.c \
				game_physic_special_tiles.c \
				game_physic_get_tile_type.c \
				game_physic_get_corners.c \
				game_physic_resolve_missing_corners.c \
				\
				config_destroy.c \
				config_init.c \
				\
				tileset_init.c \
				\
				tilemap_destroy.c \
				tilemap_init.c \
				tilemap_draw.c \
				tilemap_draw_texture.c \
				tilemap_change_tile.c \
				tilemap_coords.c \
				tilemap_zoom.c \
				tilemap_move.c \
				tilemap_open.c \
				tilemap_resize.c \
				\
				player_init.c \
				player_handle_input.c \
				player_update.c \
				player_draw.c \
				player_destroy.c \
				player_cst.c \
				player_animation.c \
				player_effect.c \
				\
				\
				drawable_list_fcts.c \
				drawable_list_fcts_texture.c \
				remove_drawable.c \
				\
				asset_manager.c \
				asset_shaders.c \
				asset_manager_destroy.c \
				load_textures.c \
				\
				audio_manager_init.c \
				audio_manager_play.c \
				load_audio.c \
				audio_manager_update_volumes.c \
				\
				game_settings_init.c \
				game_settings_save.c \
				\
				game.c \
				states.c \
				\
				\
				button_destroy.c \
				button_draw.c \
				button_fcts.c \
				button_handle_input.c \
				button_init.c \
				button_update.c \
				\
				gui_manager_add_item.c \
				gui_manager_destroy_item.c \
				gui_manager_fcts.c \
				gui_manager_init.c \
				gui_manager_draw.c \
				\
				init_gui.c \
				\
				textfield_destroy.c \
				textfield_draw.c \
				textfield_handle_input.c \
				textfield_init.c \
				textfield_update.c \
				\
				click_text_destroy.c \
				click_text_draw.c \
				click_text_fcts.c \
				click_text_handle_input.c \
				click_text_init.c \
				click_text_update.c \
				\
				scrollbar_destroy.c \
				scrollbar_draw.c \
				scrollbar_handle_input.c \
				scrollbar_init.c \
				scrollbar_update.c \
				scrollbar_set_value.c \
				\
				text_button_destroy.c \
				text_button_draw.c \
				text_button_handle_input.c \
				text_button_init.c \
				text_button_update.c \
				\
				\
				game_create.c \
				game_cst.c \
				game_destroy.c \
				game_pause.c \
				game_resume.c \
				game_init.c \
				game_init_rects.c \
				game_progress_bar.c \
				game_texts.c \
				game_draw.c \
				game_update.c \
				game_handle_input.c \
				\
				game_pause_create.c \
				game_pause_cst.c \
				game_pause_init.c \
				game_pause_draw.c \
				game_pause_update.c \
				game_pause_handle_input.c \
				game_pause_destroy.c \
				game_pause_pause.c \
				game_pause_resume.c \
				game_pause_text.c \
				\
				level_end_create.c \
				level_end_init.c \
				level_end_update.c \
				level_end_pause.c \
				level_end_resume.c \
				level_end_destroy.c \
				level_end_handle_input.c \
				level_end_cst.c \
				level_end_draw.c \
				level_end_text.c \
				\
				level_select_create.c \
				level_select_destroy.c \
				level_select_draw.c \
				level_select_pause.c \
				level_select_resume.c \
				level_select_init.c \
				level_select_update.c \
				level_select_handle_input.c \
				level_select_cst.c \
				level_select_init_title.c \
				\
				menu_create.c \
				menu_cst.c \
				menu_destroy.c \
				menu_draw.c \
				menu_handle_input.c \
				menu_init.c \
				menu_pause.c \
				menu_resume.c \
				menu_update.c \
				init_click_texts.c \
				menu_init_drawables.c \
				\
				settings_create.c \
				settings_cst.c \
				settings_destroy.c \
				settings_draw.c \
				settings_handle_input.c \
				settings_init.c \
				settings_pause.c \
				settings_resume.c \
				settings_update.c \
				settings_init_scrolls.c \
				settings_init_texts.c \
				settings_init_buttons.c \
				settings_fields.c \
				settings_save_changes.c \
				\
				stats_create.c \
				stats_cst.c \
				stats_destroy.c \
				stats_draw.c \
				stats_handle_input.c \
				stats_init.c \
				stats_pause.c \
				stats_resume.c \
				stats_update.c \
				stats_init_texts.c \
				stats_level_texts.c \
				\
				\
				global_stats_init.c \
				global_stats_save.c

OBJS := $(addprefix $(OBJ_PATH)/, $(SRCS_BASE:.c=.o))
CC := gcc
CFLAGS := -Wall -Werror -pedantic
CFLAGS_LIB :=  -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -L./lib/ -lcontainer -lm -lmy -lphysics
CFLAGS_INCLUDE := -I./include/
MAKE_LIB := make -C lib/my/
MAKE_CONTAINERS := make -C lib/my_container/
DATAS_DIR = datas
MAKE_PHYSICS := make -C lib/my_physics/

all: make_libs $(DATAS_DIR) $(OBJ_PATH) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(CFLAGS_LIB)

clean:
	rm -rf $(OBJ_PATH)
	$(MAKE_LIB) clean
	$(MAKE_CONTAINERS) clean
	$(MAKE_PHYSICS) clean

fclean: clean
	rm -f $(TARGET)
	$(MAKE_LIB) fclean
	$(MAKE_CONTAINERS) fclean
	$(MAKE_PHYSICS) fclean
	rm -rf $(DATAS_DIR)

re: fclean all

make_libs:
	$(MAKE_LIB)
	$(MAKE_CONTAINERS)
	$(MAKE_PHYSICS)

$(OBJ_PATH)/%.o: ./srcs/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<

$(OBJ_PATH)/%.o: ./srcs/Drawables/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Drawables/Background/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<

$(OBJ_PATH)/%.o: ./srcs/Functions/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<

$(OBJ_PATH)/%.o: ./srcs/Game/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Game/Physic/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Game/TileMap/TileMap/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Game/TileMap/Config/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Game/TileMap/Tileset/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Game/Player/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<

$(OBJ_PATH)/%.o: ./srcs/GameEngine/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/GameEngine/asset_manager/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/GameEngine/audio_manager/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/GameEngine/drawables/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/GameEngine/settings/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<

$(OBJ_PATH)/%.o: ./srcs/GUI/GUI_manager/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/GUI/GUI_struct/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/GUI/textfield/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/GUI/button/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/GUI/click_text/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/GUI/scrollbar/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/GUI/text_button/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<

$(OBJ_PATH)/%.o: ./srcs/States/Game/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/States/GamePause/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/States/LevelEnd/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/States/LevelSelect/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/States/Menu/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/States/Settings/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/States/Stats/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<

$(OBJ_PATH)/%.o: ./srcs/Stats/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<

$(OBJ_PATH):
	mkdir $@

$(DATAS_DIR):
	mkdir $@

debug:
	echo $(OBJS)

.PHONY: clean fclean re all test make_libs tests_run create_datas