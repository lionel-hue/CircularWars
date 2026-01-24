# syntax=docker/dockerfile:1

FROM node:lts-alpine
```
- **FROM node:lts-alpine**  
  Sets the base image to Node.js (long-term support version) on Alpine Linux, which is lightweight and good for production.

```
WORKDIR /app
```
- **WORKDIR /app**  
  Sets the working directory inside the container to `/app`. All subsequent commands will run from this directory.

```
COPY . .
```
- **COPY . .**  
  Copies all files from your project directory on your host into the `/app` directory in the container.

```
RUN yarn install --production
```
- **RUN yarn install --production**  
  Installs only the production dependencies using Yarn.

```
CMD ["node", "src/index.js"]
```
- **CMD ["node", "src/index.js"]**  
  Sets the default command to run your app using Node.js. Adjust the path if your entry point is different.

```
EXPOSE 3000
```
- **EXPOSE 3000**  
  Informs Docker that the container listens on port 3000. (You can change this to match your app’s port.)

---

**To build and run your Docker container:**

1. Build the image:
   ```sh
   docker build -t my-app .
   ```
2. Run the container:
   ```sh
   docker run -p 3000:3000 my-app
   ```

Replace `my-app` and the port if needed.# filepath: /home/lionel/Documents/MY_DOCUMENTS/Codes/CircularWars/dockerFile
# syntax=docker/dockerfile:1

FROM node:lts-alpine
```
- **FROM node:lts-alpine**  
  Sets the base image to Node.js (long-term support version) on Alpine Linux, which is lightweight and good for production.

```
WORKDIR /app
```
- **WORKDIR /app**  
  Sets the working directory inside the container to `/app`. All subsequent commands will run from this directory.

```
COPY . .
```
- **COPY . .**  
  Copies all files from your project directory on your host into the `/app` directory in the container.

```
RUN yarn install --production
```
- **RUN yarn install --production**  
  Installs only the production dependencies using Yarn.

```
CMD ["node", "src/index.js"]
```
- **CMD ["node", "src/index.js"]**  
  Sets the default command to run your app using Node.js. Adjust the path if your entry point is different.

```
EXPOSE 3000
```
- **EXPOSE 3000**  
  Informs Docker that the container listens on port 3000. (You can change this to match your app’s port.)

---

**To build and run your Docker container:**

1. Build the image:
   ```sh
   docker build -t my-app .
   ```
2. Run the container:
   ```sh
   docker run -p 3000:3000 my-app
   ```

Replace `my-app` and the port if needed.# syntax=docker/dockerfile:1

FROM node:lts-alpine
```
- **FROM node:lts-alpine**  
  Sets the base image to Node.js (long-term support version) on Alpine Linux, which is lightweight and good for production.

```
WORKDIR /app
```
- **WORKDIR /app**  
  Sets the working directory inside the container to `/app`. All subsequent commands will run from this directory.

```
COPY . .
```
- **COPY . .**  
  Copies all files from your project directory on your host into the `/app` directory in the container.

```
RUN yarn install --production
```
- **RUN yarn install --production**  
  Installs only the production dependencies using Yarn.

```
CMD ["node", "src/index.js"]
```
- **CMD ["node", "src/index.js"]**  
  Sets the default command to run your app using Node.js. Adjust the path if your entry point is different.

```
EXPOSE 3000
```
- **EXPOSE 3000**  
  Informs Docker that the container listens on port 3000. (You can change this to match your app’s port.)

---

**To build and run your Docker container:**

1. Build the image:
   ```sh
   docker build -t my-app .
   ```
2. Run the container:
   ```sh
   docker run -p 3000:3000 my-app
   ```

Replace `my-app` and the port if needed.# filepath: /home/lionel/Documents/MY_DOCUMENTS/Codes/CircularWars/dockerFile
# syntax=docker/dockerfile:1

FROM node:lts-alpine
```
- **FROM node:lts-alpine**  
  Sets the base image to Node.js (long-term support version) on Alpine Linux, which is lightweight and good for production.

```
WORKDIR /app
```
- **WORKDIR /app**  
  Sets the working directory inside the container to `/app`. All subsequent commands will run from this directory.

```
COPY . .
```
- **COPY . .**  
  Copies all files from your project directory on your host into the `/app` directory in the container.

```
RUN yarn install --production
```
- **RUN yarn install --production**  
  Installs only the production dependencies using Yarn.

```
CMD ["node", "src/index.js"]
```
- **CMD ["node", "src/index.js"]**  
  Sets the default command to run your app using Node.js. Adjust the path if your entry point is different.

```
EXPOSE 3000
```
- **EXPOSE 3000**  
  Informs Docker that the container listens on port 3000. (You can change this to match your app’s port.)

---

**To build and run your Docker container:**

1. Build the image:
   ```sh
   docker build -t my-app .
   ```
2. Run the container:
   ```sh
   docker run -p 3000:3000 my-app
   ```

Replace `my-app` and the port if needed.