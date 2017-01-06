# Load the joints
rosservice call /andreas_arm/controller_manager/load_controller "name: 'alpha_position_controller'"
rosservice call /andreas_arm/controller_manager/load_controller "name: 'beta_position_controller'"
rosservice call /andreas_arm/controller_manager/load_controller "name: 'gamma_position_controller'"
rosservice call /andreas_arm/controller_manager/load_controller "name: 'delta_position_controller'"
rosservice call /andreas_arm/controller_manager/load_controller "name: 'epsilon_position_controller'"
rosservice call /andreas_arm/controller_manager/load_controller "name: 'zeta_position_controller'"

# Start the controller services
rosservice call /andreas_arm/controller_manager/switch_controller "{start_controllers: ['alpha_position_controller', 'beta_position_controller'], stop_controllers: [], strictness: 2}"
