#ifndef UIELEMENTROLEFILTER_HPP
#define UIELEMENTROLEFILTER_HPP

#include "CommonData.hpp"
#include "RemapFilterBase.hpp"

namespace org_pqrs_Karabiner {
  namespace RemapFilter {
    class UIElementRoleFilter : public RemapFilterBase {
    public:
      UIElementRoleFilter(unsigned int type) : RemapFilterBase(type) {}

      void initialize(const unsigned int* vec, size_t length) {
        for (size_t i = 0; i < length; ++i) {
          targets_.push_back(AddValue(vec[i]));
        }
      }

      bool isblocked(void) {
        if (get_type() == BRIDGE_FILTERTYPE_UIELEMENTROLE_NOT ||
            get_type() == BRIDGE_FILTERTYPE_UIELEMENTROLE_ONLY) {

          unsigned int current = CommonData::getcurrent_workspacedata().uielementrole;

          bool isnot = (get_type() == BRIDGE_FILTERTYPE_UIELEMENTROLE_NOT);

          for (size_t i = 0; i < targets_.size(); ++i) {
            if (targets_[i] == current) {
              return isnot ? true : false;
            }
          }

          return isnot ? false : true;
        }

        IOLOG_ERROR("UIElementRoleFilter::isblocked unknown type(%d)\n", get_type());
        return false;
      }

    private:
      Vector_AddValue targets_;
    };
  }
}

#endif
