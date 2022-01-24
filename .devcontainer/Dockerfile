ARG VARIANT=debian-10
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

COPY installImage.sh .
RUN chmod +x installImage.sh
RUN /installImage.sh

RUN apt-get -y update

USER vscode