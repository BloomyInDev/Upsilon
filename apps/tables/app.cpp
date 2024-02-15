#include "app.h"
#include "tables_icon.h"
#include "apps/apps_container.h"
#include "apps/i18n.h"

namespace Tables {

I18n::Message App::Descriptor::name() {
  return I18n::Message::TablesApp;
}

I18n::Message App::Descriptor::upperName() {
  return I18n::Message::TablesAppCapital;
}

const Image * App::Descriptor::icon() {
  return ImageStore::TablesIcon;
}


App * App::Snapshot::unpack(Container * container) {
  return new (container->currentAppBuffer()) App(this);
}

App::Descriptor * App::Snapshot::descriptor() {
  static Descriptor descriptor;
  return &descriptor;
}


App::App(Snapshot * snapshot) :
  ::App(snapshot, &m_stackViewController)
{
}

}
