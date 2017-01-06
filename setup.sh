url=10.10.14.157:8000

mkdir -p andreas_arm/src
cd andreas_arm/src
    source /opt/ros/kinetic/setup.bash
    catkin_init_workspace
  cd ..
  catkin_make

  . devel/setup.bash
  cd src

    catkin_create_pkg andreas_arm_control roscpp rospy
    cd andreas_arm_control
      wget $url/README.txt
      mkdir launch config src

      cd launch
        wget $url/andreas_arm_control.launch
        wget $url/README.txt
      cd ..

      cd config
        wget $url/andreas_arm_control.yaml
        wget $url/README.txt
      cd ..

      cd src
        wget $url/README.txt
      cd ..

    cd ..

    catkin_create_pkg andreas_arm_gazebo
    cd andreas_arm_gazebo
      wget $url/README.txt
      mkdir launch worlds
      
      cd launch
        wget $url/README.txt
      cd ..

      cd worlds
        wget $url/README.txt
        wget $url/andreas_arm.world
      cd ..

    cd ..

    catkin_create_pkg andreas_arm_description
    cd andreas_arm_description
      wget $url/README.txt
      mkdir launch meshes urdf

      cd launch
        wget $url/README.txt
        wget $url/gazebo.launch
      cd ..

      cd meshes
        wget $url/README.txt
      cd ..

      cd urdf
        wget $url/README.txt
        wget $url/andreas_arm_description.xacro
      cd ..

    cd ..

cd ../..
