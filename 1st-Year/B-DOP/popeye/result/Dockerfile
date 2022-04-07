FROM node:12-alpine
COPY . /app
WORKDIR /app
EXPOSE 80
RUN npm install .
CMD ["node", "server.js"]