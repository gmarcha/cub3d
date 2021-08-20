INVALID_MAPS=(
	map_empty_file_newline.cub
	map_empty_file.cub
	map_invalid_character.cub
	map_missing_ceil.cub
	map_missing_east.cub
	map_missing_floor.cub
	map_missing_north.cub
	map_missing_south.cub
	map_missing_west.cub
	map_multiple_ceil.cub
	map_multiple_east.cub
	map_multiple_floor.cub
	map_multiple_north.cub
	map_multiple_player.cub
	map_multiple_south.cub
	map_multiple_west.cub
	map_no_extension
	map_no_map.cub
	map_no_permission.cub
	map_unclosed_east.cub
	map_unclosed_north.cub
	map_unclosed_south.cub
	map_unclosed_west.cub
)

printf "env -i valgrind --leak-check=full ./cub3d maps/valid/map_north.cub\n"
env -i valgrind --leak-check=full ./cub3d maps/valid/map_north.cub
printf "========================================================================\n"

for i in ${INVALID_MAPS[@]}; do
	printf "valgrind --leak-check=full ./cub3d maps/invalid/%s\n" $i
	valgrind --leak-check=full ./cub3d maps/invalid/$i
	printf "========================================================================\n"
done
