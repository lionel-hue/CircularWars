# syntax=docker/dockerfile:1

FROM alpine:latest
WORKDIR /app
COPY . .
RUN chmod +x circular_wars
EXPOSE 8080
CMD ["./circular_wars"]
