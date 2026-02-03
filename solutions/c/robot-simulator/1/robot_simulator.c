#include "robot_simulator.h"

static const robot_direction_t directions[] = {
   DIRECTION_NORTH,
   DIRECTION_EAST,
   DIRECTION_SOUTH,
   DIRECTION_WEST,
};

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
	robot_position_t position = {
		.x = x,
		.y = y,
	};

	robot_status_t status = {
		.direction = direction,
		.position = position,
	};

	return status;
}

void robot_move(robot_status_t *robot, const char *commands)
{
	char* command = (char*) commands;

	while (*command)
	{
		switch (*(command++))
		{
			case 'R':
				robot->direction = directions[(robot->direction + 1) % 4];
				break;
			case 'L':
				robot->direction = directions[(robot->direction - 1) % 4];
				break;
			case 'A':
				switch (robot->direction)
				{
					case DIRECTION_NORTH:
						robot->position.y += 1;
						break;
					case DIRECTION_EAST:
						robot->position.x += 1;
						break;
					case DIRECTION_SOUTH:
						robot->position.y -= 1;
						break;
					case DIRECTION_WEST:
						robot->position.x -= 1;
						break;
					default:
						return;
				}
		}
	}
}
