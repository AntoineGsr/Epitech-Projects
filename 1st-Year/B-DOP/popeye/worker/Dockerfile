FROM maven:3.5-jdk-8-alpine AS builder
COPY . /app
WORKDIR /app
RUN mvn dependency:resolve
RUN mvn package

FROM openjdk:8-jre-alpine
#COPY --from=builder /app .
CMD [ "java", "-jar", "worker-jar-with-dependencies.jar" ]