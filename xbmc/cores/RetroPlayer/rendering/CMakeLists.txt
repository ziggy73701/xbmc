set(SOURCES GUIRenderSettings.cpp
            RPRenderFactory.cpp
            RPRenderManager.cpp
)

set(HEADERS GUIRenderSettings.h
            IRenderSettingsCallback.h
            RPRenderFactory.h
            RPRenderManager.h
)

core_add_library(rp-rendering)
