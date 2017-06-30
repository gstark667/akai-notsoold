#include <QtWidgets/QMainWindow>
#include <QtNetwork/QTcpSocket>
#include <QtMultimedia/QAudioFormat>
#include <QtMultimedia/QAudioInput>
#include <QtMultimedia/QAudioOutput>


class Audio: public QMainWindow
{
    Q_OBJECT

private:
    QTcpSocket *m_sock;
    QAudioFormat *m_format;
    QAudioInput *m_input;
    QIODevice *m_inputStream;
    QAudioOutput *m_output;
    QIODevice *m_outputStream;

public:
    Audio();
    ~Audio();

private slots:
    void readPackets();
    void writePackets();
};
