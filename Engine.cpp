#include "Engine.h"
#include <QDebug>

Engine::Engine(QObject* parent) :
    QObject(parent),
    m_engine(qmlEngine(this))
{
    qDebug() << Q_FUNC_INFO;
}

Engine::Engine(QQmlEngine *engine, QJSEngine *scriptEngine, QObject* parent) :
    QObject(parent),
    m_engine(engine)
{
    qDebug() << Q_FUNC_INFO;
    Q_UNUSED(scriptEngine)
}

void Engine::connectSignals()
{
    qDebug() << Q_FUNC_INFO;
}

void Engine::disconnectSignals()
{
    qDebug() << Q_FUNC_INFO;
}

void Engine::registerTypes(const char* uri, int versionMajor, int versionMinor)
{
    qDebug() << Q_FUNC_INFO << uri << versionMajor << versionMinor;
    qmlRegisterSingletonType<Engine>(uri, versionMajor, versionMinor, "Engine", singletonProvider);
    qmlRegisterType<Engine>(uri, versionMajor, versionMinor, "Engine");
}

QObject *Engine::singletonProvider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    qDebug() << Q_FUNC_INFO;
    return new Engine(engine, scriptEngine);
}
