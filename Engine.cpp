#include "Engine.h"
#include <QDebug>

Engine::Engine(QObject* parent) :
    QObject(parent),
    m_engine(nullptr)
{
    qDebug() << Q_FUNC_INFO;
}

Engine::Engine(QQmlEngine *engine, QJSEngine *scriptEngine, QObject* parent) :
    QObject(parent),
    m_engine(engine)
{
    Q_UNUSED(scriptEngine)
    qDebug() << Q_FUNC_INFO;
    if (m_engine)
    {
        connectSignals();
    }
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

QQmlEngine* Engine::engine()
{
    if (m_engine)
    {
        return m_engine;
    }

    m_engine = qmlEngine(this);
    if (!m_engine)
    {
        return nullptr;
    }

    connectSignals();
}

void Engine::clearComponentCache()
{
    auto* _engine = engine();
    if (!_engine)
    {
        return;
    }
    _engine->clearComponentCache();
}

void Engine::trimComponentCache()
{
    auto* _engine = engine();
    if (!_engine)
    {
        return;
    }
    _engine->trimComponentCache();
}
