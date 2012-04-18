@import "version.inc" ;
@import "outercurve.inc" ;

package {
    name: "fftw-dev[${flavor}]";
    version: "${package-version}";
    arch : "${arch}";

    display-name: "fftw Developer library";
}

metadata {
    summary: "The fftw developer library";
    description: @"FFTW is a free collection of fast C routines for computing the Discrete Fourier Transform in one or more dimensions."; 

    icon: @"fftw.png";
    
    author-version : "3.3.1";
    bug-tracker: "https://github.com/coapp-packages/fftw/issues";
    stability : "0";
    licenses : {
        GPL
    };
}

files[libs] {
    root: @"..\output\vc10\${arch}\Release\bin\";
    
    include: {
        "*.lib",
    };
    
    trim-path: all;
};

requires {
    package: "fftw-dev-common-${package-version}-any-${Package.PublicKeyToken}";
    package: "fftw[${flavor}]-${package-version}-${Package.Architecture}-${Package.PublicKeyToken}";
}

developer-library[fftw] {
    libraries : {
        libs
    };
}