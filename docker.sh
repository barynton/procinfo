#!/bin/bash
set -xe

source_dir=$PWD
container=ubuntu_builder
image=ubuntu_builder

function docker_create {
    docker build -t $image .
}

function docker_run {
    set +e
    docker container stop $container
    docker container rm $container
    set -e
    docker run -it -v $source_dir:$source_dir --name $container $image
}

function docker_cmd {
    docker start -i $container
}

function docker_build {
    user=`id -u`:`id -g`
    docker start $container
    build_type=Debug
    if [ "$1" != "" ] ; then
        build_type=$1
    fi 
    docker exec $container /bin/bash -c "cd $source_dir && $source_dir/build.sh $build_type"
    # docker exec $container /bin/bash -c "chown -hR $user $source_dir/build_$build_type/ && chmod -R +r $source_dir/build_$build_type/"
}

function docker_test_run {
    user=`id -u`:`id -g`
    docker start $container
    build_type=Debug
    if [ "$1" != "" ] ; then
        build_type=$1
    fi 
    docker exec $container /bin/bash -c "cd '$source_dir/build_$build_type' && ctest"
}

function docker_test_coverage {
    user=`id -u`:`id -g`
    docker start $container

    docker exec $container /bin/bash -c "cd $source_dir && $source_dir/coverage.sh"
    # docker exec $container /bin/bash -c "chown -hR $user $source_dir/build_$build_type/ && chmod -R +r $source_dir/build_$build_type/"
}

docker_$1 $2 $3