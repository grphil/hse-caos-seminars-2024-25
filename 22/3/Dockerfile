FROM python:3.13-alpine

WORKDIR /app
COPY . /app

RUN pip3 install -r requirements.txt

EXPOSE 8080

ENTRYPOINT ["python3", "app.py", "options-docker.yaml"]