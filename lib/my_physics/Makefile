TARGET := libphysics.a

OBJ_PATH := bin
SRCS_BASE := 	pe_body_init.c \
				pe_body_destroy.c \
				pe_body_update.c \
				pe_body_compute_aabb.c \
				pe_body_compute_mass.c \
				pe_body_forces.c \
				pe_body_impulse.c \
				pe_body_rotate.c \
				pe_body_move.c \
				pe_body_add_contact.c \
				\
				\
				pe_collide_aabb_aabb.c \
				pe_collide_circle_circle.c \
				pe_collide_polygon_polygon_sat.c \
				pe_collide_polygon_polygon_utils.c \
				pe_collide_polygon_polygon.c \
				pe_collide_get_collide_aabb_id.c \
				pe_collide_polygone_circle.c \
				pe_collide_circle_polygone.c \
				pe_collide_bodies.c \
				pe_collide_body_from_parent.c \
				pe_positionnal_correction.c \
				pe_resolve_collision.c \
				pe_manifold.c \
				\
				\
				pe_constants.c \
				\
				\
				pe_binary_tree_best_sibling.c \
				pe_binary_tree_cost.c \
				pe_binary_tree_init.c \
				pe_binary_tree_insert_body.c \
				pe_binary_tree_raycast.c \
				pe_binary_tree_reinsert.c \
				pe_binary_tree_remove.c \
				pe_binary_tree_update.c \
				\
				pe_tree_node_init.c \
				\
				\
				pe_filter_init.c \
				\
				\
				pe_fixture_destroy.c \
				pe_fixture_init.c \
				pe_fixture_mass.c \
				\
				\
				pe_collision_table.c \
				\
				\
				pe_mass_data.c \
				pe_mass_data_set_zero.c \
				\
				\
				pe_raycast_aabb.c \
				pe_raycast_init.c \
				\
				\
				pe_aabb_area.c \
				pe_aabb_copy.c \
				pe_aabb_union.c \
				pe_aabb_from_shape.c \
				pe_aabb_init.c \
			 	pe_aabb_is_equal.c \
				\
				pe_init_specific_shapes.c \
				pe_shape_destroy.c \
				pe_shape_compute_mass_datas.c \
				\
				\
				pe_mat22_init.c \
				pe_mat22_rotate.c \
				pe_mat22_transpose.c \
				\
				pe_vec2_dot_product.c \
				pe_vec2_length_squared.c \
				pe_vec2_length.c \
				pe_vec2_normalize.c \
				pe_vec2_operands.c \
				pe_vec2_opposite.c \
				pe_vec2_operands_simple.c \
				pe_vec2f_cross_product.c \
				pe_vec2f.c \
				pe_vec2i.c \
				pe_vec2u.c \
				\
				\
				pe_world_add.c \
				pe_world_destroy.c \
				pe_world_init.c \
				pe_world_update.c \
				pe_world_handle_collisions.c
				

OBJS := $(addprefix $(OBJ_PATH)/, $(SRCS_BASE:.c=.o))
CC := gcc
CFLAGS := -Wall -Werror -pedantic
CFLAGS_LIB := -L../lib/ -lcontainer -lm -lmy
CFLAGS_INCLUDE := -I./ -I../../include/
INCLUDE_PATH := ../../include
INCLUDE_FOLDER := $(INCLUDE_PATH)/Physics

all: $(OBJ_PATH) $(INCLUDE_PATH) $(INCLUDE_FOLDER) $(TARGET) copy_header

$(TARGET): $(OBJS)
	ar -rc $@ $(OBJS)

clean:
	rm -rf $(OBJ_PATH)
	rm -rf $(INCLUDE_FOLDER)

fclean: clean
	rm -f $(TARGET)

re: fclean all

copy_header:
	cp -rf Physics/* $(INCLUDE_FOLDER)
	cp $(TARGET) ../$(TARGET)

$(OBJ_PATH)/%.o: ./srcs/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<

$(OBJ_PATH)/%.o: ./srcs/Physics/Body/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Physics/Collides/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Physics/Constants/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<

$(OBJ_PATH)/%.o: ./srcs/Physics/DynamicTree/BinaryTree/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Physics/DynamicTree/TreeNode/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<

$(OBJ_PATH)/%.o: ./srcs/Physics/Filter/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Physics/Fixture/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Physics/JumpTables/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Physics/MassData/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Physics/RayCast/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<

$(OBJ_PATH)/%.o: ./srcs/Physics/Shapes/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Physics/Shapes/AABB/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<

$(OBJ_PATH)/%.o: ./srcs/Physics/Utils/Vec2/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<
$(OBJ_PATH)/%.o: ./srcs/Physics/Utils/Mat22/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<

$(OBJ_PATH)/%.o: ./srcs/Physics/World/%.c
	$(CC) $(CFLAGS) -c $(CFLAGS_INCLUDE) -o $@ $<


$(OBJ_PATH):
	mkdir $@

$(INCLUDE_PATH):
	mkdir $@

$(INCLUDE_FOLDER):
	mkdir $@

debug:
	echo $(OBJS)

.PHONY: clean fclean re all test make_libs tests_run create_datas