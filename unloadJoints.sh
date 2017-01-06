# Stop the controller services
rosservice call /andreas_arm/controller_manager/switch_controller "{start_controllers: [], stop_controllers: ['alpha_position_controller', 'beta_position_controller'], strictness: 2}"
