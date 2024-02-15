apps += Tables::App
app_headers += apps/tables/app.h

app_stables_src = $(addprefix apps/tables/,\
  app.cpp \
)

apps_src += $(app_stables_src)

app_images += apps/tables/tables_icon.png

i18n_files += $(call i18n_without_universal_for,tables/base)

$(eval $(call depends_on_image,apps/tables/app.cpp,apps/tables/tables_icon.png))