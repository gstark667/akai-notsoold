#include "audio.h"

#include <iostream>


Audio::Audio(): QMainWindow()
{
    setObjectName(QStringLiteral("MainWindow"));

    m_format = new QAudioFormat();
    m_format->setChannelCount(2);
    m_format->setSampleRate(16000);
    m_format->setSampleSize(16);
    m_format->setCodec("audio/pcm");
    m_format->setByteOrder(QAudioFormat::LittleEndian);
    m_format->setSampleType(QAudioFormat::UnSignedInt);

    m_input = new QAudioInput(*m_format);
    m_input->setBufferSize(32000);
    m_inputStream = m_input->start();

    m_output = new QAudioOutput(*m_format);
    m_output->setBufferSize(32000);
    m_outputStream = m_output->start();

    m_sock = new QTcpSocket();
    m_sock->connectToHost(QStringLiteral("127.0.0.1"), 6666);

    connect(m_inputStream, &QIODevice::readyRead, this, &Audio::writePackets);
    connect(m_sock, &QTcpSocket::readyRead, this, &Audio::readPackets);
}

Audio::~Audio()
{
    m_input->stop();
    m_output->stop();
}

void Audio::writePackets()
{
    QByteArray data = m_inputStream->readAll();
    m_sock->write(data);
}


void Audio::readPackets()
{
    QByteArray data = m_sock->readAll();
    m_outputStream->write(data);
}

