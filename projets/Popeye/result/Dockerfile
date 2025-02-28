FROM node:20-alpine
WORKDIR /app
COPY package.json ./
COPY server.js ./
COPY views ./views
RUN npm install
EXPOSE 80
CMD ["npm", "start"]