#ifndef GLFWPP_EVENT_H
#define GLFWPP_EVENT_H

#include <GLFW/glfw3.h>
#include <eventpp/callbacklist.h>
#include <functional>
#include <list>

namespace glfw
{
    template<typename... Args>
    struct Event: public eventpp::CallbackList<void(Args...)> {
        using Super = eventpp::CallbackList<void(Args...)>;
        using Super::Super;
        
        template<typename CallbackT>
        void setCallback(CallbackT&& callback) {
            static_cast<Super&>(*this) = {};
            Super::append(std::move(callback));
        }
    };

    inline void pollEvents()
    {
        glfwPollEvents();
    }

    inline void waitEvents()
    {
        glfwWaitEvents();
    }
    inline void waitEvents(double timeout_)
    {
        glfwWaitEventsTimeout(timeout_);
    }

    inline void postEmptyEvent()
    {
        glfwPostEmptyEvent();
    }
}  // namespace glfw

#endif  //GLFWPP_EVENT_H
