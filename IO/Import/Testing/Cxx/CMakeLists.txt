# This is an alternative  way to add a named test that uses a common executable
# Use this if it does not require MPI

vtk_add_test_cxx(vtkIOImportCxxTests tests
  OBJImporter-TwoTrianglesWithNegativeIndices,TestOBJImporter.cxx
    DATA{../Data/Input/TwoTrianglesWithNegativeIndices.obj}
    DATA{../Data/Input/TwoTrianglesWithNegativeIndices.mtl}
    DATA{../Data/Input/noise.png}
)

vtk_add_test_cxx(vtkIOImportCxxTests tests
  OBJImport-SolidAndTextured,TestOBJImporter.cxx
    DATA{../Data/Input/cube-scene.obj}
    DATA{../Data/Input/cube-scene.mtl}
    DATA{../Data/Input/noise.png}
)

vtk_add_test_cxx(vtkIOImportCxxTests tests
  OBJImport-MixedOrder1,TestOBJImporter.cxx
    DATA{../Data/Input/boxes_2.obj}
    DATA{../Data/Input/boxes_2.obj.mtl}
    DATA{../Data/Input/flare.jpg}
)

vtk_add_test_cxx(vtkIOImportCxxTests tests
  OBJImport-NoMTL,TestOBJImporter.cxx
    DATA{../Data/Input/boxes_3_no_mtl.obj}
    DATA{../Data/Input/boxes_2.obj.mtl}
    DATA{../Data/Input/flare.jpg}
)

vtk_add_test_cxx(vtkIOImportCxxTests tests
  OBJImport-MTLwithoutTextureFile,TestOBJImporter.cxx
    DATA{../Data/Input/boxes_4_mtl_no_texture.obj}
    DATA{../Data/Input/boxes_4_mtl_no_texture.obj.mtl}
)

vtk_add_test_cxx(vtkIOImportCxxTests tests
  TestOBJImporter-DuplicateMaps,TestOBJImporter.cxx
    DATA{../Data/Input/TestOBJImporter.obj}
    DATA{../Data/Input/TestOBJImporter.mtl}
    DATA{../Data/Input/TestOBJImporter.png}
)

vtk_add_test_cxx(vtkIOImportCxxTests tests
  TestOBJImporter-SharedMtl,TestOBJImporter.cxx
    DATA{../Data/Input/TestOBJImporter-SharedMtl.obj}
    DATA{../Data/Input/TestOBJImporter-SharedMtl.mtl}
)


vtk_add_test_cxx(vtkIOImportCxxTests tests
  TestOBJImporter-VtNoIndices,TestOBJImporter.cxx
    DATA{../Data/Input/TestOBJImporter-VtNoIndices.obj}
    DATA{../Data/Input/TestOBJImporter-VtNoIndices.mtl}
    DATA{../Data/Input/TestOBJImporter-VtNoIndices.png}
)


vtk_add_test_cxx(vtkIOImportCxxTests tests
  TestVRMLImporter.cxx,NO_VALID
  TestVRMLNormals.cxx
  )

vtk_add_test_cxx(vtkIOImportCxxTests tests
  TestGLTFImporter,TestGLTFImporter.cxx DATA{../Data/glTF/Avocado/Avocado.glb}
)

vtk_add_test_cxx(vtkIOImportCxxTests tests
  TestGLTFImporterPBR,TestGLTFImporter.cxx DATA{../Data/glTF/WaterBottle/WaterBottle.glb}
)

vtk_add_test_cxx(vtkIOImportCxxTests tests
  TestGLTFImporterKHRLightsPunctual,TestGLTFImporter.cxx DATA{../Data/glTF/Lights/lights.gltf}
)

vtk_test_cxx_executable(vtkIOImportCxxTests tests
  RENDERING_FACTORY)
