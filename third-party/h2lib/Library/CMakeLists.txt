add_library(h2lib
    aca.c
    amatrix.c
    avector.c
    basic.c
    bem2d.c
    bem3d.c
    block.c
    cluster.c
    clusterbasis.c
    clustergeometry.c
    clusteroperator.c
    curve2d.c
    dblock.c
    dcluster.c
    dclusterbasis.c
    dclusteroperator.c
    ddcluster.c
    dh2compression.c
    dh2matrix.c
    duniform.c
    eigensolvers.c
    factorizations.c
    gaussquad.c
    h2arith.c
    h2compression.c
    h2matrix.c
    h2update.c
    harith.c
    harith2.c
    hcoarsen.c
    helmholtzbem3d.c
    helmholtzoclbem3d.c
    hmatrix.c
    ie1d.c
    kernelmatrix.c
    krylov.c
    krylovsolvers.c
    laplacebem2d.c
    laplacebem3d.c
    laplaceoclbem3d.c
    macrosurface3d.c
    matrixnorms.c
    oclbem3d.c
    opencl.c
    parameters.c
    realavector.c
    rkmatrix.c
    settings.c
    singquad1d.c
    singquad2d.c
    sparsematrix.c
    sparsepattern.c
    surface3d.c
    tet3d.c
    tet3dp1.c
    tet3drt0.c
    tri2d.c
    tri2dp1.c
    tri2drt0.c
    truncation.c
    uniform.c
    visualize.c
)

if (BLAS_FOUND)
    message(STATUS "BLAS has been found, adding to 'h2lib'")
    target_compile_definitions(h2lib PUBLIC USE_BLAS=1)
    target_link_libraries(h2lib BLAS::BLAS)
endif ()

