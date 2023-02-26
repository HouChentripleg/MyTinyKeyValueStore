file(REMOVE_RECURSE
  "libTinySkipListLib.a"
  "libTinySkipListLib.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/TinySkipListLib.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
