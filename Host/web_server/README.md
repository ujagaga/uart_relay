# office-api-server
My personal web server with API for various automations. Based on FastAPI, it is intended to support embedded devices, 
so the authorization process is not very complex and not overly secure. To create a new user account or modify an existing one:

    tools/edit_user.py -h


## Installing dependencies

    sudo apt install -y uvicorn python3-pip ustreamer
    pip3 install fastapi python-multipart requests sqlalchemy jinja2
    
Run the server

    uvicorn sql_app.main:app --reload --host 0.0.0.0

## Authorization

To use this system an application must first login using username and password. The server will respond with a token. 
All further requests must provide this token as a http query parameter for API access or via browser cookie for the rest. 

## Streaming video from a webcam

Basic streaming using just ustreamer:

        sudo apt install ustreamer
        ustreamer --host=0.0.0.0 --port=8013 --device=/dev/video1 --drop-same-frames=30 --slowdown --user <username> --passwd <password>

For simplicity use

        ./tools/ustreamer.sh

