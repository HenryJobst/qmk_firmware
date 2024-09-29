FROM python:3.13.0rc2-slim

WORKDIR /usr/src/app
COPY requirements.txt ./
RUN pip install --no-cache-dir -r requirements.txt
COPY ./KeymapBeautifier.py ./KeymapBeautifier.py

CMD [ "python", "./KeymapBeautifier.py", "-h" ]
