
#include <ecs/fck_ecs.h>
#include <fck.h>
#include <game/game_components.h>
#include <game/game_systems.h>

#include <fck_ui.h>

void app_start_instance(fck_ecs *ecs)
{
	fck_ecs_system_add(ecs, fck_ui_setup);

	fck_ecs_system_add(ecs, game_cammy_setup);
	// TODO: Remove font loading from fck
	// Setup and ammend to cammy for now - cammy is just a default sprite with position and size...
	// Move that all game shit to this layer
	fck_ecs_system_add(ecs, [](fck_ecs *ecs, fck_system_once_info *info) {
		fck_ecs_apply_with_entity(ecs, [ecs](fck_ecs::entity_type entity, game_position *position) {
			game_sprite *sprite = fck_ecs_component_create<game_sprite>(ecs, entity);
			sprite->texture = gen_png::BubbleGhostCat;
			sprite->src = {0.0f, 0.0f, 1000.0f, 1000.0f};
		});
	});

	fck_ecs_system_add(ecs, game_demo_ui_process);
	fck_ecs_system_add(ecs, game_render_process);
}

int main(int argc, char **argv)
{
	fck fck;
	fck_init(&fck, 1);

	fck_instance_info info;
	info.title = "Example";
	info.ip = "0.0.0.0";
	info.source_port = 0;
	info.destination_port = 0;

	fck_prepare(&fck, &info, app_start_instance);

	int exit_code = fck_run(&fck);
	SDL_Log("fck - exit code: %d", exit_code);

	return exit_code;
}