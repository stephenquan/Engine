#ifndef __Engine__
#define __Engine__

#include <QObject>
#include <QQmlEngine>
#include <QJSEngine>

class Engine : public QObject
{
    Q_OBJECT

public:
    Engine(QObject* parent = nullptr);
    Engine(QQmlEngine *engine, QJSEngine *scriptEngine, QObject* parent = nullptr);

    Q_INVOKABLE void clearComponentCache();
    Q_INVOKABLE void trimComponentCache();

public:
    static void registerTypes(const char *uri, int versionMajor = 1, int versionMinor = 0);

protected:
    QQmlEngine* m_engine;

    void connectSignals();
    void disconnectSignals();

    QQmlEngine* engine();

    static QObject *singletonProvider(QQmlEngine *engine, QJSEngine *scriptEngine);

};

#endif
