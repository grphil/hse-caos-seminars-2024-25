FROM python:3.13-alpine

# создаем папку в контейнере
WORKDIR /app
# копируем локальные файлы в контейнер
COPY . /app

RUN pip3 install -r requirements.txt

# какой порт должен быть доступен снаружи
EXPOSE 8080

ENTRYPOINT ["python3", "app.py"]
