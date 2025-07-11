#!/bin/bash

if [[ -d esp_idf&& -n "$(ls -A esp_idf)" ]]; then
    sh esp_idf/install.sh

    if [ $? != 0 ]; then
        echo "Please install pre-requisites as per the failure logs of install.sh script and resolve the errors."
        exit 1
    fi
else
    echo "Please update the submodule to checkout esp-idf v4.2 in esp_idf"
    exit 1
fi

echo "esp-idf Setup is Completed. Run build.sh script to compile the build and generate the build package"