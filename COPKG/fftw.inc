@import "version.inc";
@import "outercurve.inc";

package {
    name: "fftw[${flavor}]";
    version: "${package-version}";
    arch : "${arch}";
    
    display-name: "fftw";
    location: "http://coapp.org/repository/${OutputFilename}";

    feed: "http://coapp.org/repository/packages.atom.xml";
    publisher: "CoApp Project";
}

files[exes] {
    root: @"..\output\vc10\${arch}\Release\bin";
    
    include: {
        "*.exe",
    };
    
    trim-path: all;
};


files[dlls] {
    root: @"..\output\vc10\${arch}\Release\bin";
  
    include: {
        "*.dll",
    };
    
    trim-path: all;
};

license[GPL] {
    license-url: "";
    license-type: "GPL";
}

files[files-to-sign] {
    include: { 
        exes,
        dlls
    };    
}

metadata {
    summary: "libfftw";
    description:  @"FFTW is a free collection of fast C routines for computing the Discrete Fourier Transform in one or more dimensions"; 

    icon: @"fftw.png";
    
    author-version : "3.3.1";
    bug-tracker: "https://github.com/coapp-packages/fftw/issues";
    stability : "0";
    licenses : {
        GPL
    };
}

compatability-policy {
    minimum: "3.3.1";
    maximum: "${OneLessThanCurrent}"; // this is the default
    versions : {
        "3.0",
    }; // if not specified, find the versions by looking at the feeds and finding all the major/minor versions in range.
}

application {
    include : {
        exes,
    };
}

manifest[things-that-need-them] {
    // all of our EXEs need to get the manifest entries for the assemblies we're creating in this package
    
    assembly : {
        fftw
    };
    
    include : { 
        exes
    };
}

assembly[fftw] {
    include : {
        dlls
    };
}

package-composition {
    symlinks : { 
        exes => @"${bin}\${each.Name}" = @"${packagedir}\${each.Name}";
    };
}

signing {
    attributes : {
        company="Outercurve Foundation",
        description="fftw",
        product-name="fftw",
        product-version="${package-version}",
        file-version="${package-version}",
    };
    
    replace-signature: true; 
    include: { 
        files-to-sign
    };    
}