#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "glbase.h"
#include "sungui.h"
#include "xml_config.h"

namespace ygopro
{
    
    class Scene {
    public:
        virtual ~Scene() = default;
        virtual void Activate() = 0;
        virtual void Update() = 0;
        virtual void Draw() = 0;
        virtual void SetSceneSize(v2i sz) = 0;
        virtual recti GetScreenshotClip() = 0;
        virtual void MouseMove(sgui::MouseMoveEvent evt) = 0;
        virtual void MouseButtonDown(sgui::MouseButtonEvent evt) = 0;
        virtual void MouseButtonUp(sgui::MouseButtonEvent evt) = 0;
        virtual void KeyDown(sgui::KeyEvent evt) = 0;
        virtual void KeyUp(sgui::KeyEvent evt) = 0;
    };
    
    class SceneMgr : public Singleton<SceneMgr> {
    public:
        
        void Init();
        void Uninit();
        void InitDraw();
        void Update();
        void Draw();
        double GetGameTime();
        void SetFrameRate(double rate);
        void CheckFrameRate();
        void MouseMove(sgui::MouseMoveEvent evt);
        void MouseButtonDown(sgui::MouseButtonEvent evt);
        void MouseButtonUp(sgui::MouseButtonEvent evt);
        void KeyDown(sgui::KeyEvent evt);
        void KeyUp(sgui::KeyEvent evt);
        void SetSceneSize(v2i sz);
        void SetScene(std::shared_ptr<Scene> sc);
        void ScreenShot();
        std::shared_ptr<Scene> GetScene() { return current_scene; };
        void SetMousePosition(v2i pos) { mouse_pos = pos; }
        v2i GetMousePosition() { return mouse_pos; }
        
    protected:
        v2i scene_size;
        unsigned long long start_time = 0;
        std::shared_ptr<Scene> current_scene = nullptr;
        double frame_check = 0.0;
        double frame_time = 0.0;
        double frame_interval = 0.0;
        v2i mouse_pos = {0, 0};
    };

	extern CommonConfig commonCfg;
    extern CommonConfig stringCfg;
}

#endif